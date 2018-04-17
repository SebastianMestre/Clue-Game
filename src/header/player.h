#ifndef PLAYER_H
#define PLAYER_H
// player.h

#include <stdlib.h>

#include "constants.h"
#include "random_list.h"
#include "turno.h"

struct jugador{
  char *player_name; //cambio necesario para el menu
  int location;
  // TODO: reemplazar int[] por array dinamico de cartas
  // uso -1 como terminador
  int suspect[SUSPECT_COUNT + 1];
  int weapon[WEAPON_COUNT + 1];
  int place[PLACE_COUNT + 1];
};

typedef struct jugador player_t;

const player_t mazo = {NULL,-1,{0,1,2,3,4,5,-1},{0,1,2,3,4,5,-1},{0,1,2,3,4,5,6,7,8,-1}};

void player_deal(player_t* players, size_t playerCount, sospecha_t* solucion);

#endif /* end of include guard: PLAYER_H */
