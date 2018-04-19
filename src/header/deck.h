#ifndef DECK_H
#define DECK_H

// deck.h

#include <stddef.h>

#include "../lib/util_memory.h"

enum card_type{SUSPECT, WEAPON, SCENE};

struct card{
  enum card_type type;
  unsigned short id;
};

struct deck{
  size_t size;
  struct card *data;
};

// devuelve el nombre de una carta
const char* name_card(struct card card);

void deck_pushCard(struct deck* this, struct card card);

#endif /* end of include guard: DECK_H */
