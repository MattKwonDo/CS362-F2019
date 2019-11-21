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
    int tests = 500;
    int seed = 30;
    int handPos = 0, player = 0;
    int numPlayers = 2;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
                 minion, tribute, village, baron, great_hall};

    for (int i = 0; i < tests; i++)
    {
        printf("\n*** Begin Test %d / %d ***\n", i+1, tests);
        memset(&state, 23, sizeof(struct gameState));

        int choice1 = (rand() % 2); // if rand returns even, then zero, no discard; if odd, then 1 and discard the card, gain 4
        printf("choice: %d\n", choice1);
        
        printf("initializeGame\n");
        initializeGame(numPlayers, k, seed, &state);


        state.handCount[player] = 5;
        state.hand[player][4] = baron;
        state.hand[player][3] = (rand() % 2) == 0 ? copper : estate; //if rand returns even, copper; if odd, estate
        printf("2nd to last card: %d\n", state.hand[player][3]);
          
		printf("memcpy\n");
        memcpy(&test, &state, sizeof(struct gameState));


        playCardBaron(choice1, &state, player);

        if (state.numBuys == test.numBuys + 1) // numBuys should be incremented
        {
            printf("Pass: numBuys incremented\n");
        }
        else if (state.numBuys != test.numBuys + 1)
        {
            printf("Fail: numBuys NOT incremented\n");
        }

        if (!choice1 && state.supplyCount[estate] > 0 && state.handCount[player] == test.handCount[player] + 1) //not discarding a card
        {
            printf("Pass: choosing to add a card results in handCount incremented\n");
        }
        else if (!choice1 && state.supplyCount[estate] > 0 && state.handCount[player] != test.handCount[player] + 1)
        {
            printf("Fail: choosing to add a card results in handcount NOT incremented\n");
        }

        if (choice1 == 1 && state.handCount[player] == test.handCount[player] - 1) // if discard an estate card to gain 4 and hand count is decremented
        {
            printf("Pass: choosing to discard a card results in handcount decremented\n");
        }
        else if (choice1 == 1 && state.handCount[player] != test.handCount[player] - 1) 
        {
            printf("Fail: choosing to discard a card results in handcount not decremented\n");
        }

        if (choice1 && state.hand[player][3] == copper) { // if TRY to discard an estate card to gain 4 but can't
            if (state.supplyCount[estate] > 0 && state.supplyCount[estate] == test.supplyCount[estate] - 1) // if supply count is decremented as a result
            {
                printf("Pass: supply count decremented when erroneously tring to discard an estate card\n");
            }
            else if (state.supplyCount[estate] > 0 && state.supplyCount[estate] != test.supplyCount[estate] - 1)
            {
                printf("Fail: supply count NOT decremented when erroneously tring to discard an estate card\n");
            }
        }
    }
};