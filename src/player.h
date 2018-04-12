#ifndef PLAYER_H
#define PLAYER_H

#include "constants.c"

struct jugador{
  int location;
  // TODO: reemplazar int[] por array dinamico de cartas
  int suspects[SUSPECT_COUNT + 1];
  int weapons[WEAPON_COUNT + 1];
  int places[PLACE_COUNT + 1];
};

typedef struct jugador player_t;

#endif /* end of include guard: PLAYER_H */
