#include "player.h"
// player.c

player_t player_new(const char* name_in){
  return (player_t){str_dupl(name_in), {0, NULL}};
}

void player_pushCard(struct player* this, pista_t carta){
  deck_pushCard(&this->deck, carta);
}
