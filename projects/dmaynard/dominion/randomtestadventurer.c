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


/*  Function for referance
void adventurerFunction(int currentPlayer, struct gameState *state, int drawntreasure, int cardDrawn, int temphand[MAX_HAND], int z)
{
  while(drawntreasure<2){
  if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
    shuffle(currentPlayer, state);
  }
  drawCard(currentPlayer, state);
  cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
  if (cardDrawn == gold || cardDrawn == silver || cardDrawn == gold)
    drawntreasure++;
  else{
    temphand[z]=cardDrawn;
    state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
    z++;
  }
*/
int main(){

//consistant values
	int seed = 10;
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
    int players = 2;
    int deck_size = 20;
    int g = 0, i = 0, l = 0, h = 0;
	struct gameState G, cleanGame;
	struct gameState *G_ptr = &G;
	clock_t begin = clock();
	srand(time(NULL));

// Random Variables
    int money_to_add;
    int money_type;

    // Randomly choose number of moneys to add to the players deck
    // From: 0 - 2
    money_to_add = rand() % 2 + 1;
    int money_location_add[money_to_add];
    printf("Adding %i golds\n",money_to_add);

    // Choose where to add the money into the deck
    for(;g < money_to_add; g++)
         {money_location_add[g] = rand() % deck_size;
         printf("added money@g = %i\n",money_location_add[g]);
         }
    printf("deck size: %i\n",deck_size);
    // initialize game
    memcpy(G_ptr, &cleanGame, sizeof(struct gameState));
	  initializeGame(players, k, seed, G_ptr);

    // Initialize players
    // organize the players deck to either have a duchy or a gold
    G.deckCount[0] = deck_size;
    for(;i < deck_size; i++)
    {
        if(money_location_add[l] == i)
        {
            l++;
            G.deck[0][i] = gold;
            printf("Gold Added\n");
        }
        else
        {
            G.deck[0][i] = duchy;
            printf("Duchy Added\n");
        }
    }

    // Play Adventurer 
    cardEffect(adventurer, 0, 0, 0, G_ptr, 0, 0);
    printf("adventurer played\n"); 
    for(;h < G.handCount[0]; h++)
    {
      if(G.hand[0][h] == gold)
      {
        printf("found Gold\n");
      }
    }
    assert(h < money_to_add);
    printf("Adventurer collected correct amount of cards!\nTest Passed\n");
}
