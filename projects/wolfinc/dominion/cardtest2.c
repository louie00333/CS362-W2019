/*
 * cardtest2.c
 *
 
 */

/*
 * Include the following lines in your makefile:
 *
 * cardtest2: cardtest2.c dominion.o rngs.o
 *      gcc -o cardtest2 -g  cardtest2.c dominion.o rngs.o $(CFLAGS)
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

    // Test: 'GREAT_HALL' card
    printf("----------------TESTING CARD: GREAT_HALL---------------\n");

    // Test 1
    memcpy(Gtest_ptr, G_ptr, sizeof(struct gameState));
    cardEffect(great_hall, choice1, choice2, choice3, Gtest_ptr, handpos, &bonus);

    printf("hand count = %d, expected = %d\n", Gtest.handCount[thisPlayer], G.handCount[thisPlayer]);
	printf("deck count = %d, expected = %d\n", Gtest.deckCount[thisPlayer], G.deckCount[thisPlayer] - 1);
    printf("Action count = %d, expected = %d\n", Gtest.numActions, G.numActions+1);

	assert(Gtest.handCount[thisPlayer] == G.handCount[thisPlayer]);
	assert(Gtest.deckCount[thisPlayer] == G.deckCount[thisPlayer] - 1);
    assert(Gtest.numActions == G.numActions+1);
    printf("TEST - \'GREAT_HALL\' PASSED");
}
