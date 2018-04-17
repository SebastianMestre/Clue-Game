// map.c

int map_pasadizo(struct map* , struct player*){
  assert(player->location >= 0);
  assert(player->location <  map->size);

  return map->pasadizos[player->location];
}

struct map map_new(size_t size, int* pasadizos, char* nombres[]){
  struct map this;
  this.size = size;

  this.pasadizos = malloc(sizeof(*this.pasadizos) * size);
  this.nombres = malloc(sizeof(*this.nombres) * size);

  for(int i = 0; i < size; i ++){
    this.pasadizos[i] = pasadizos[i];
    this.nombres[i] = str_dupl(nombres[i]);
  }
}
