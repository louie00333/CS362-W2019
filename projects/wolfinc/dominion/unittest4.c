/* -----------------------------------------------------------------------
 * UnitTest3
 * gainCard()
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
    int supplyPos = 0; //Pick first card as test card
    // Test 'gainCard()' function

    // Iterate through 'gainCard '
    printf("Testing toFlag\n");
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        initializeGame(numPlayer, k, seed, G_ptr);
        G.supplyCount[0] = 0;
        
        supplyCount(supplyPos, G_ptr);
        int gotCard = gainCard(supplyPos, G_ptr, 0, 0);
        assert(gotCard == -1);
        printf("Test without supp: PASS\n");

        //Test i == 1
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        initializeGame(numPlayer, k, seed, G_ptr);
        G.supplyCount[supplyPos] = 10;
        int beforeAdd = G.deckCount[0];
        gainCard(supplyPos, G_ptr, 1, 0);
        int afterAdd =  G.deckCount[0];
        assert(beforeAdd == afterAdd - 1);
        printf("Deck addition: PASS\n");

        //Test i == 2
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        initializeGame(numPlayer, k, seed, G_ptr);
        G.supplyCount[supplyPos] = 10;
        beforeAdd = G.handCount[0];
        gainCard(supplyPos, G_ptr, 2, 0);
        afterAdd =  G.handCount[0];
        assert(beforeAdd == afterAdd - 1);
        printf("Hand addition: PASS\n");
    
    printf("All tests Passed!\n");
}