// map.c

#include "./header/map.h"

struct map map_new(size_t size, int* pasadizos/*, char* nombres[]*/){
  struct map this;
  this.size = size;

  this.pasadizos = malloc(sizeof(*this.pasadizos) * size);
  // this.nombres = malloc(sizeof(*this.nombres) * size);
  this.ocupado = malloc(sizeof(*this.ocupado) * size);

  for(int i = 0; i < size; i ++){
    this.pasadizos[i] = pasadizos[i];
    // this.nombres[i] = str_dupl(nombres[i]);
    this.ocupado[i] = false;
  }

  return this;
}

int map_pasadizo(struct map* this, int index){
  assert(index >= 0);
  assert(index <  this->size);

  return this->pasadizos[index];
}

bool map_occupied(struct map* this, int index){
  return this->ocupado[index];
}
