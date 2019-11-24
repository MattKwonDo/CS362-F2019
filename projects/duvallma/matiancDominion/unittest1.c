/*
unit test for baron
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

void main(int argc, char** argv)
{
        printf("\n***   Mine Test   ***\n");
    // set variable states
    printf('begin testing gainCard():\n');
    int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall }; 

    struct gameState G;

    int coppers[MAX_HAND];
    int silvers[MAX_HAND];
    int golds[MAX_HAND];

    // set the state of your variables so that you will trigger the bug for feast

    // clear the game state
    memset(&G, 23, sizeof(struct gameState)); 

    int numPlayer = 2;
    int seed = 1;

    // initialize a new game 
    int r = initializeGame(numPlayer, k, seed, &G); 

    // set variables
    int card = 5; //comes from array above
    int choice1 = 1;
    int choice2 = 2;
    int choice3 = 4;
    int handPos = 0;
    int bonus = 0;
    int tempDeckCount = state->deckCount[player] + 1;

    // set supply of choice2 to zero
    G>supplyCount[i] = 10;

    // call the function being tested
    int cardEffect(card, choice1, choice2, choice3, G, handPos, &bonus);

    // assert whether assumptions passed or failed
    // assert that the card is in player’s deck / played pile
        assert(G->deckCount[player] == tempDeckCount 
    && 
    state->deck[ player ][ state->deckCount[player] ] == choice2); 

}