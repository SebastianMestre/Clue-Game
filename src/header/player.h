#ifndef PLAYER_H
#define PLAYER_H

// player.h
#include "../lib/util_string.h"
#include "deck.h"

typedef struct player{
  char* name;
  struct deck hand;
} player_t;

// devuelve un nuevo jugador con el nombre que se pasa y una mano vacia
player_t player_new(const char* name_in);

void player_pushCard(struct player* this, struct card carta);

#endif /* end of include guard: PLAYER_H */
