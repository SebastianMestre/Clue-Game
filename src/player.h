#ifndef PLAYER_H
#define PLAYER_H
// player.h

#include <stdlib.h>

#include "constants.h"
#include "random_list.h"

struct jugador{
  int location;
  // TODO: reemplazar int[] por array dinamico de cartas
  // uso -1 como terminador
  int suspects[SUSPECT_COUNT + 1];
  int weapons[WEAPON_COUNT + 1];
  int places[PLACE_COUNT + 1];
};

typedef struct jugador player_t;

void player_deal(player_t* players, size_t playerCount);

#endif /* end of include guard: PLAYER_H */
