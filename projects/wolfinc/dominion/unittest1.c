/* -----------------------------------------------------------------------
 * UnitTest1
 * whoseturn()
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
	printf("Test: whoseturn()\n");
    // Test 'whoseturn()' function 4 individual times
    for(int i = 0; i < numPlayer; i++)
    {                
        memset(&G, 23, sizeof(struct gameState));   // clear the game state
        initializeGame(numPlayer, k, seed, G_ptr);
        int turn1 = whoseTurn(G_ptr);
        int turn2 = G.whoseTurn;
        printf("turn = %i\nG.whoseturn() = %i\n", (int)turn1, (int)turn2);
        assert(turn1 == turn2);
    }
		printf("TEST PASSED\n");
}
