#ifndef PLAYER_H
#define PLAYER_H
// player.h

#include "constants.h"

struct jugador{
  int location;
  // TODO: reemplazar int[] por array dinamico de cartas
  int suspects[SUSPECT_COUNT + 1];
  int weapons[WEAPON_COUNT + 1];
  int places[PLACE_COUNT + 1];
};

typedef struct jugador player_t;

void player_deal(size_t playerCount);

#endif /* end of include guard: PLAYER_H */
