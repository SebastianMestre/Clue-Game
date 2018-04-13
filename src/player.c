#include "player.h"
// player.c

#define PLAYER_SHUFFLE_DEAL(lowcase,upcase) do{                                 \
    int* randlist = makeIntList(0, CAT(upcase,_COUNT));                         \
    shuffleIntList(randlist, CAT(upcase,_COUNT));                               \
    for(int i = 0; i < CAT(upcase, _COUNT); i++; player_idx++){                 \
      players[player_idx % playerCount].lowcase[i / playerCount] = randlist[i]; \
      players[player_idx % playerCount].lowcase[i / playerCount + 1] = -1;      \
    }                                                                           \
    free(randlist);                                                             \
  }while(0)

void player_deal(size_t playerCount){

  // player index (mod playerCount)
  int player_idx = 0;

  PLAYER_SHUFFLE_DEAL(suspects,SUSPECT);

  PLAYER_SHUFFLE_DEAL(weapons,WEAPON);

  PLAYER_SHUFFLE_DEAL(places,PLACE);
}

#undef PLAYER_SHUFFLE_DEAL
