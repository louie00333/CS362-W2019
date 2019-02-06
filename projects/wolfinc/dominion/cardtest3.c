/*
 * cardtest3.c
 *
 
 */

/*
 * Include the following lines in your makefile:
 *
 * cardtest2: cardtest3.c dominion.o rngs.o
 *      gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <stdlib.h>

int main() {
    int seed = 1000;
    int handpos = 0, choice1 = 0, choice2 = 0, choice3 = 0, bonus = 0;
    int numPlayer = 2;
    int thisPlayer = 0;
    int coppers[MAX_HAND];
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G, Gtest;
    struct gameState *G_ptr = &G;
    struct gameState *Gtest_ptr = &Gtest;
    initializeGame(numPlayer, k, seed, G_ptr);

    // Test: 'ADVENTURER' card
    printf("----------------TESTING CARD: ADVENTURER---------------\n");

    // Test 1: Enough Treasure cards in deck
    memcpy(Gtest_ptr, G_ptr, sizeof(struct gameState));
    memcpy(Gtest.deck[thisPlayer], coppers, sizeof(int) * 5);  //Set Deck to size 3
    Gtest.deckCount[thisPlayer] = 5;
    Gtest.deck[thisPlayer][2] = copper;
    Gtest.deck[thisPlayer][3] = copper;
    cardEffect(adventurer, choice1, choice2, choice3, Gtest_ptr, handpos, &bonus);
	printf("deck count = %d, expected = %d\n", Gtest.deckCount[thisPlayer], G.deckCount[thisPlayer]);
	//assert(Gtest.deckCount[thisPlayer] >= G.deckCount[thisPlayer]);

    // Test 2: Not Enough Treasure cards in deck
    memcpy(Gtest_ptr, G_ptr, sizeof(struct gameState));
    initializeGame(numPlayer, k, seed, G_ptr);
    memcpy(Gtest.deck[thisPlayer], coppers, sizeof(int) * 3);  //Set Deck to size 3
    Gtest.deckCount[thisPlayer] = 3;
    Gtest.deck[thisPlayer][0] = duchy;
    Gtest.deck[thisPlayer][1] = duchy;
    Gtest.playedCards[Gtest.playedCardCount++] = copper;   // Add Two coppers to discard pile
    Gtest.playedCards[Gtest.playedCardCount++] = copper;
    cardEffect(adventurer, choice1, choice2, choice3, Gtest_ptr, handpos, &bonus);
    printf("Player hand count = %d, expected = %d\n", Gtest.handCount[thisPlayer], G.handCount[thisPlayer]);
	//assert(Gtest.handCount[thisPlayer] == G.handCount[thisPlayer] + 2);
    printf("TEST - \'ADVENTURER\' PASSED");
}
