#ifndef MAP_H
#define MAP_H

#include "stddef.h"

// map.h

struct map{
  size_t size;
  char** nombres;
  int* pasadizos;
};

int map_pasadizo(struct map* , struct player*);

struct map map_new(size_t size, int* pasadizos, char* nombres[]);

#endif /* end of include guard: MAP_H */
