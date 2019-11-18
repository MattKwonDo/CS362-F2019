/*
unit test for mine
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
    int i;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int seed = 1000;
    int numPlayers = 2;
    int player=0;
	struct gameState state;
    struct gameState test;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	int count1 = 0;
	int count2 = 0;

	// initialize game state and cards
	initializeGame(numPlayers, k, seed, &state);

	// copy game state for testing
	memcpy(&test, &state, sizeof(struct gameState));
	cardEffect(mine, choice1, choice2, choice3, &state, handpos, &bonus);

	player = whoseTurn(&test);
	
	
	//Check the player hands count
	if(test.handCount[player]-1 == state.handCount[player])
		printf("Passed where hand count is correct\n");
	else
		printf("Failed where hand count is not correct\n");
	
	
	//Check players hand
	if(state.hand[player][test.handCount[player]] != -1)
		printf("Passed where Smithy card was added to the players hand\n");
	else
		printf("Failed where Smithy card was not added to the players hand\n");

	
	//Check if player played this card
	if(test.playedCardCount+2 == state.playedCardCount)
		printf("Passed where player played Smithy card\n");
	else
		printf("Failed where player did not play Smithy card\n");
	
	
	//Count cards in hand
	for (i = 0; i < state.handCount[0]; i++)
        if(state.hand[0][i] = smithy);
			count1++;
		
	for (i = 0; i < test.handCount[0]; i++)
        if(test.hand[0][i] = smithy);
			count2++;
	
	if(count1 == count2-1)
		printf("Passed where there is no variance in smithy cards\n");
	else
		printf("Failed where there is a variance in smithy cards\n");
	
	
	//Discard Test: Check if card was discarded
	if(test.discardCount[player] == state.discardCount[player])
		printf("Passed where the Smithy was discarded\n");	
	else
		printf("Failed where the Smithy was not discarded.\n");
	



}