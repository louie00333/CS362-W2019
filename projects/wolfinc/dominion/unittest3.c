/* -----------------------------------------------------------------------
 * UnitTest3
 * isGameOver()
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

    // Test 'isGameOver()' function

    // TEST1: Province Cards
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, G_ptr);
    G.supplyCount[province] = 0;
    assert(isGameOver(G_ptr) == 1);
    printf("TEST1.1 PASS\n");

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, G_ptr);
    G.supplyCount[province] = 1;
    assert(isGameOver(G_ptr) == 0);
    printf("TEST1.2 PASS\n"); 

    // TEST2: Three supply piles
    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, G_ptr);
    G.supplyCount[1] = 0;
    G.supplyCount[2] = 0;
    G.supplyCount[3] = 0;
    assert(isGameOver(G_ptr) == 1);
    printf("TEST2.1 PASS\n"); 
    

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, G_ptr);
    G.supplyCount[23] = 0;
    G.supplyCount[22] = 0;
    G.supplyCount[21] = 0;
    assert(isGameOver(G_ptr) == 1);
    printf("TEST2.2 PASS\n"); 

    memset(&G, 23, sizeof(struct gameState));   // clear the game state
    initializeGame(numPlayer, k, seed, G_ptr);
    for(int i = 0; i < 24; i++)
    {
        G.supplyCount[i] = 0;
    }
    assert(isGameOver(G_ptr) == 1);
    printf("TEST2.3 PASS\n"); 

    printf("All Tests Passed!\n");

}
