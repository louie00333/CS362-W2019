//
// Random Testing Card: Outpost 
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
	struct gameState G, cleanGame;
	struct gameState *G_ptr = &G;
	clock_t begin = clock();
	srand(time(NULL));
	 
// Random Variables	 
	int players;
	int outpost_played;	

	// Run 12 times (for 6*2 players*options)
	for(; i < 12 ;i++)
	{
		// Random Num of Players
		players = rand() % 6 + 2;	//At most game will have 6 players and at 2east 1
		memcpy(G_ptr, &cleanGame, sizeof(struct gameState));
		initializeGame(players, k, seed, G_ptr);
		
		// Random Num choice of Outpost played or not
		outpost_played = rand() % 2;
		if(outpost_played)
			cardEffect(outpost, 0, 0, 0, G_ptr, 0, 0);
		printf("----Test %i----\n",i);
		printf("Players: %i 	outpost_played: %i\n",players, outpost_played);
		if(outpost_played == G.outpostPlayed)
			printf("SUCCESSFUL: Outpost card played flag, correctly identified\n");
		else{
			printf("FAILED: Incorrect Output\n");
			exit(200);
		}
	}
	clock_t end = clock();
	long double exec_time = end - begin;
	printf("All tests ran successfully\nExecution Time: %Lf\n",exec_time);

}