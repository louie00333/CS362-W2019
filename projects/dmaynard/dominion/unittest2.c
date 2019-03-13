/* -----------------------------------------------------------------------
 * UnitTest2
 * numHandCards()
 * -----------------------------------------------------------------------
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

// set NOISY_TEST to 0 to remove printfs from output
#define NOISY_TEST 1

int main() {
    int seed = 1000;
    int numPlayer = 2;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G;
    struct gameState *G_ptr = &G;
    int maxHandCount = 5;

    // Test 'numHandCards()' function

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, G_ptr);
    G_ptr->handCount[whoseTurn(G_ptr)] = 0;
    int count = G_ptr->handCount[whoseTurn(G_ptr)];
    int count2 = numHandCards(G_ptr);
    printf("handCards = %i\n", count);
    printf("Current handCount = %i\nCurrent Game handCount = %i\n", count, (int) numHandCards(G_ptr));
    assert(count == count2);
    

    printf("numHandCards() == Passed!\n");

}
