#ifndef DECK_H
#define DECK_H

// deck.h

#include <stddef.h>
#include <stdio.h>

#include "../lib/util_memory.h"
#include "../lib/util_string.h"

enum card_type{SUSPECT = 0, WEAPON = 1, SCENE = 2};

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

const struct deck* deck_master();
const struct deck* deck_suspects();
const struct deck* deck_weapons();
const struct deck* deck_scenes();

void imprimir_mazo( struct deck deck );

struct card* card_new(struct card card);

#endif /* end of include guard: DECK_H */
