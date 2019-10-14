#ifndef _DOMINION_HELPERS_H
#define _DOMINION_HELPERS_H

#include "dominion.h"

int drawCard(int player, struct gameState *state);
int updateCoins(int player, struct gameState *state, int bonus);
int discardCard(int handPos, int currentPlayer, struct gameState *state,
                int trashFlag);
int gainCard(int supplyPos, struct gameState *state, int toFlag, int player);
int getCost(int cardNumber);

int playCardBaron(int choice1, struct gameState *state, int currentPlayer);
int playCardMinion(int choice1, int choice2, struct gameState *state, int currentPlayer, int handPos);
int playCardAmbassador(int choice1, int choice2, int handPos, struct gameState *state, int currentPlayer);
int playCardTribute(int choice1, int *tributeRevealedCards, struct gameState *state, int currentPlayer, int nextPlayer);
int playCardMine(int choice1, int choice2, int handPos, struct gameState *state, int currentPlayer);

int cardEffect(int card, int choice1, int choice2, int choice3,
               struct gameState *state, int handPos, int *bonus);


#endif
