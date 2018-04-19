#include <stdio.h>

#include "./header/ui.h"

#include "./lib/util_random_list.h"
#include "./lib/util_memory.h"

void ui_init(
  struct map* map,
  struct solution* solution,
  struct player** player_arr,
  size_t *player_arr_size
){
  const int MIN_PLAYER_COUNT = 3;
  const int MAX_PLAYER_COUNT = 6;

  puts("Ingrese la cantidad de jugadores.");

  printf(
    "Debe ser un numero en [%d,%d] :",
    MIN_PLAYER_COUNT,
    MAX_PLAYER_COUNT
  );

  size_t temp = 0;

  while(MIN_PLAYER_COUNT > temp || temp > MAX_PLAYER_COUNT){
    scanf("%d%*c", &temp);
    if (temp < MIN_PLAYER_COUNT) {
      puts("El valor es muy bajo, volve a intentar.");
    } else if (temp > MAX_PLAYER_COUNT) {
      puts("El valor es muy alto, volve a intentar.");
    }
  }

  *player_arr = safe_malloc(sizeof(**player_arr) * temp);
  *player_arr_size = temp;

  char BUFFER[1024];
  for(int i = 0; i < temp; i++){
    printf("Ingrese el nombre del %d. jugador.", i+1);
    scanf("%1023[^\n]%*c", BUFFER);

    (*player_arr)[i] = player_new(BUFFER);
  }

  int* randlist = makeIntList(0, temp);

}
