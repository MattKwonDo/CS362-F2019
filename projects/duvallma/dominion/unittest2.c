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

    // set variable states
printf(‘begin testing gainCard():\n’);
int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall }; 


struct gameState G;

int coppers[MAX_HAND];
int silvers[MAX_HAND];
int golds[MAX_HAND];

// set the state of your variables so that you will trigger the bug for feast

// clear the game state
memset(&G, 23, sizeof(struct gameState)); 

// initialize a new game 
initializeGame(numPlayer, k, seed, &G); 

// set variables
int numPlayersArgument = argv[1];

// call the function being tested
initializeGame(atoi(argv[1]), k, atoi(argv[1]), &G);

// assert whether assumptions passed or failed
assert(G->numPlayers == numPlayersArgument);


}