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
	printf("randomtestcard3: Tribute\n");
    srand(time(NULL));

    struct gameState state, test;
    int tests = 500,
    seed = 30,
    handPos = 4, 
    currentPlayer = 0,
    nextPlayer = 1,
    numPlayers = 2,
    cardsInHands = 5;

    int k[10] = {adventurer, council_room, feast, gardens, mine,
                 minion, tribute, village, baron, great_hall};

    int kAll[27] = {
        curse,
        estate,
        duchy,
        province,
        copper,
        silver,
        gold,
        adventurer,
        council_room,
        feast,
        gardens,
        mine,
        remodel,
        smithy,
        village,
        baron,
        great_hall,
        minion,
        steward,
        tribute,
        ambassador,
        cutpurse,
        embargo,
        outpost,
        salvager,
        sea_hag,
        treasure_map};
    for (int i = 0; i < tests; i++)
    {
        printf("\n*** Begin Test %d / %d ***\n", i+1, tests);
        memset(&state, 23, sizeof(struct gameState));

        //choice1 not actually needed in the function....
        int choice1 = (rand() % 2); // if rand returns even, then zero, no discard; if odd, then 1 and discard the card, gain 4
        printf("choice1: %d\n", choice1);

        printf("initializeGame\n");
        initializeGame(numPlayers, k, seed, &state);

        
        int card, i;

        for (i = 0; i < 4; i++)
        {
            card = (rand() % 27);
            state.hand[currentPlayer][i] = kAll[card];
        }
        
        for (i = 0; i < 5; i++)
        {
            card = rand() % 27;
            state.hand[nextPlayer][i] = kAll[card];
        }

        for (i = 0; i < state.deckCount[nextPlayer]; i++)
        {
            card = rand() % 27;
            state.deck[nextPlayer][i] = card;
        }

        state.handCount[currentPlayer] = cardsInHands;
        state.handCount[nextPlayer] = cardsInHands;
        state.hand[currentPlayer][4] = tribute;

		printf("memcpy\n");
        memcpy(&test, &state, sizeof(struct gameState));

        int tributeRevealedCards[2] = {-1, -1};
        
// matianc function signature: 
// int playCardTribute(int *tributeRevealedCards, struct gameState *state, int currentPlayer, int nextPlayer)

        playCardTribute(tributeRevealedCards, &state, currentPlayer, nextPlayer);

        if (state.numActions > test.numActions)
        {
            printf("Pass: numActions incremented\n");
        }
        else
        {
            printf("Fail: numActions NOT incremented\n");
        }

        if (state.coins > test.coins)
        {
            printf("Pass: coins added\n");
        }
        else
        {
            printf("Fail: coins NOT added\n");
        }
        
        if (state.discardCount[currentPlayer] == test.discardCount[currentPlayer] == 5)
        {
            printf("Pass: 5 cards discarded\n");
        }
        else
        {
            printf("Fail: 5 cards NOT discarded\n");
        }

        if (state.handCount[currentPlayer] == 4)
        {
            printf("Pass: 4 cards drawn\n");
        }
        else
        {
            printf("Fail: 4 cards NOT drawn\n");
        }
    }

    return 0;
}