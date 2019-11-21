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
	printf("randomtestcard1: Baron\n");
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

        if


    }

    return 0;
}