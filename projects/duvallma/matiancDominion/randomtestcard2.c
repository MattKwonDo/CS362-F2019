#include "dominion.h"
#include "dominion_helpers.h"
#include <assert.h>
#include "rngs.h"

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	printf("randomtestcard1: Minion\n");
    srand(time(NULL));

    struct gameState state, test;
    int tests = 500,
    seed = 30,
    handPos = 4, 
    player = 0,
    numPlayers = 2,
    cardsInHands = 5;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
                 minion, tribute, village, baron, great_hall};

    for (int i = 0; i < tests; i++)
    {
        printf("\n*** Begin Test %d / %d ***\n", i+1, tests);
        memset(&state, 23, sizeof(struct gameState));

        int choice1 = (rand() % 2); // if rand returns even, then zero, no discard; if odd, then 1 and discard the card, gain 4
        printf("choice1: %d\n", choice1);
        int choice2 = !choice1;
        printf("choice2: %d\n", choice2);

        printf("initializeGame\n");
        initializeGame(numPlayers, k, seed, &state);


        state.handCount[player] = cardsInHands;
        state.hand[player][4] = minion;
        state.hand[player][3] = (rand() % 2) == 0 ? copper : estate; //if rand returns even, copper; if odd, estate
        printf("2nd to last card: %d\n", state.hand[player][3]);

		printf("memcpy\n");
        memcpy(&test, &state, sizeof(struct gameState));


        playCardMinion(choice1, choice2, &state, player, handPos);

        if (state.numActions == test.numActions + 1) // numBuys should be incremented
        {
            printf("Pass: numActions incremented correctly\n");
        }
        else if (state.numActions != test.numActions + 1)
        {
            printf("Fail: numActions NOT incremented correctly\n");
        }

        if (state.hand[player][4] == -1 && state.hand[player][4] != test.hand[player][4]) // minion should be discarded
        {
            printf("Pass: minion discarded correctly\n");
        }
        else if (state.hand[player][4] != -1 && state.hand[player][4] == minion)
        {
            printf("Fail: minion NOT discarded correctly\n");
        }

        if (choice1)
        {
            if (state.coins == test.coins + 2)
            {
                printf("Pass: 2 coins added\n");
            }
            else if (state.coins != test.coins + 2)
            {
                printf("Fail: 2 coins NOT added\n");
            }
        }
        else if (choice2)
        {
            if (state.discardCount[player] == test.discardCount[player] == 5)
            {
                printf("Pass: 5 cards discarded\n");
            }
            else
            {
                printf("Fail: 5 cards NOT discarded\n");
            }

            if (state.handCount[player] == 4)
            {
                printf("Pass: 4 cards drawn\n");
            }
            else
            {
                printf("Fail: 4 cards NOT drawn\n");
            }
        }
    }

    return 0;
};