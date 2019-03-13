//
// Random Testing Card: Great_Hall 
//
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h> 
#include <assert.h>
#include <stdlib.h>
#include <time.h>



int main(){
    //consistant values
    int seed = 10;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    int i = 0;
    int players = 2;
    struct gameState G, cleanGame;
	struct gameState *G_ptr = &G;
	clock_t begin = clock();
	srand(time(NULL));

    //Varied Values
    int hand_count;
    int deck_count;
    int actions;
    
    // Iterate through MAX_DECK/2 times to capture most cases that can occur
    for(;i < MAX_DECK/2; i++)
    {
    	memcpy(G_ptr, &cleanGame, sizeof(struct gameState));
		initializeGame(players, k, seed, G_ptr);

        deck_count  = rand() % (MAX_DECK); 
        hand_count  = rand() % (MAX_HAND);
        actions     = rand() % 3;
        G.handCount[0] = hand_count;
        G.deckCount[0] = deck_count;
        G.numActions   = actions;
        printf("deck_count Pre: %i\n",G.deckCount[0]);
        printf("hand_count Pre: %i\n",G.handCount[0]);
        printf("actions    Pre: %i\n",G.numActions);

        cardEffect(great_hall, 0,0,0, G_ptr, 0,0);

        printf("deck_count Post: %i\n",G.deckCount[0]);
        printf("hand_count Post: %i\n",G.handCount[0]);
        printf("actions    Post: %i\n",G.numActions);
      
		printf("----Test %i----\n",i);
        if(G.numActions == (actions + 1))
            printf("SUCCESSFUL: Actions incremented\n");
        else
        {
            printf("FAILED: Actions not incremented\n");
            exit(200);
        }
        if(G.deckCount[0] == (deck_count - 1))
            printf("SUCCESSFUL: Deck decremented\n");
        else
        {
            printf("FAILED: Deck not decremented\n");
            exit(200);
        }
        if(G.handCount[0] == hand_count)
            printf("SUCCESSFUL: Hand static\n");
        else
        {
            printf("FAILED: Hand not static\n");
            exit(200);
        }
    }
    clock_t end = clock();
	long double exec_time = end - begin;
	printf("All tests ran successfully\nExecution Time: %Lf\n",exec_time);


}
