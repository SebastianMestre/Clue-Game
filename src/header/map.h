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

int map_pasadizo(struct map* this, int index); 
//podria pasarse una copia(pasar el objeto) del map unicamente ya que no se modifica nada en el
//si es cierto que es mas pesado pasar el objeto pero una recomendacion es que te (si te parece)
//acostumbres a pensar en que vas a usar el parametro por que es mas facil ver un objeto que esta
//siendo pasado y pensar que no lo vas a modificar

#endif /* end of include guard: MAP_H */
