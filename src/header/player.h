// player.h
#include "util_string.h"
#include "deck.h"

typedef struct player{
  char* name;
  deck_t hand;
} player_t;

// devuelve un nuevo jugador con el nombre que se pasa y una mano vacia
player_t new_player(const char* name_in);
