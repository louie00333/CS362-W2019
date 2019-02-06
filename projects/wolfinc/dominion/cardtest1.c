/*
 * cardtest1.c
 *
 
 */

/*
 * Include the following lines in your makefile:
 *
 * cardtest4: cardtest4.c dominion.o rngs.o
 *      gcc -o cardtest1 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
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
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G, Gtest;
    struct gameState *G_ptr = &G;
    struct gameState *Gtest_ptr = &Gtest;
    initializeGame(numPlayer, k, seed, G_ptr);

    // Test: 'SMITHY' card
    printf("----------------TESTING CARD: SMITHY---------------\n");

    // Test 1
    memcpy(Gtest_ptr, G_ptr, sizeof(struct gameState));
    cardEffect(smithy, choice1, choice2, choice3, Gtest_ptr, handpos, &bonus);
    printf("hand count = %d, expected = %d\n", Gtest.handCount[thisPlayer], G.handCount[thisPlayer] + 2);
	printf("deck count = %d, expected = %d\n", Gtest.deckCount[thisPlayer], G.deckCount[thisPlayer] - 3);
	//assert(Gtest.handCount[thisPlayer] == G.handCount[thisPlayer] + 2);
	assert(Gtest.deckCount[thisPlayer] == G.deckCount[thisPlayer] - 3);
    printf("TEST - \'SMITHY\' PASSED\n");
}
