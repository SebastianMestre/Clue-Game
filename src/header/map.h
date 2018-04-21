#ifndef MAP_H
#define MAP_H

#include <stddef.h>
#include "player.h"

// map.h

struct map{
  size_t size;
  char** nombres;
  int* pasadizos;
  bool* ocupado;
};

struct map map_new(size_t size, int* pasadizos/*, char* nombres[]*/);

bool map_occupied(struct map* this, int index);

int map_pasadizo(struct map* , int index);

#endif /* end of include guard: MAP_H */
