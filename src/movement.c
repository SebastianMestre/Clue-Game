// movement.c

#include "./header/movement.h"

int move_possible (
  int **arr_out,
  int step_count,
  struct player* player_in,
  struct map* map_in
){
  int *temp = malloc(sizeof(int) * map_in->size);
  int size = 0;

  // Duplicacion de codigo. esto se podria pasar a una funcion...
  for(int i = 1, it = player_in->location.id ; i < step_count; i++){
    // operacion en modulo, ya que el mapa es un anillo
    it = it + 1 % map_in->size;

    if(!map_occupied(map_in, it)){
      temp[size++] = it;
    }
  }

  for (int i = 1, it = player_in->location.id; i < step_count; i++) {
    /* HACK: evitamos el comportamien raro del modulo de nros
     * negativos en C sumando la identidad aditiva del modulo
     */
    it = (it - 1 + map_in->size) % map_in->size;

    if (!map_occupied(map_in, it)) {
      temp[size++] = it;
    }
  }
  
  // El jugador tambien tiene la opcion de quedarse en su posicion
  temp[size++] = player_in->location.id;

  *arr_out = malloc(sizeof(int) * size);
  for(int i = 0; i < size; i++){
    (*arr_out)[i] = temp[i];
  }

  free(temp);

  return size;
}
