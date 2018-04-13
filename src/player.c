#include "player.h"
// player.c

#define PLAYER_SHUFFLE_DEAL(lista1, lista1_size, property, lista2_size, index2) do{     \
  int* randlist = makeIntList(0, (lista2_size));                                \
  shuffleIntList(randlist, (lista2_size));                                      \
  for(int i = 0; i < (lista2_size); i++; (index2)++){                           \
    lista1[(index2) % (lista1_size)].property[i / (lista1_size)] = randlist[i]; \
    lista1[(index2) % (lista1_size)].property[i / (lista1_size) + 1] = -1;      \
  }                                                                             \
  free(randlist);                                                               \
}while(0)


void player_deal(player_t* players, size_t playerCount){

  // player index (mod playerCount)
  int player_idx = 0;

  PLAYER_SHUFFLE_DEAL(players, playerCount, suspects, SUSPECT_COUNT, player_idx);

  PLAYER_SHUFFLE_DEAL(players, playerCount, weapons, WEAPON_COUNT, player_idx);

  PLAYER_SHUFFLE_DEAL(players, playerCount, places, PLACE_COUNT, player_idx);
}

#undef PLAYER_SHUFFLE_DEAL
