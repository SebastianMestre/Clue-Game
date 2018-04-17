#include "movement.h"
// movement.c

#define forMov(mode, expression) \
for(int i = 0; i < tiradaDado; i++){ \
  int aux = player->location + (i*mode); \
  aux = expression; \
  if(!cpHabitaciones[aux]){ \
    cpHabitaciones[aux] = 1; \
    habitacionesAnunciadas[it++] = aux; \
}}

int map_pasadizo(struct map* , struct player*){
  assert(player->location >= 0);
  assert(player->location <  map->size);

  return map->pasadizos[player->location];
}

void makeAMove(player_t* jugador, bool *habitaciones, size_t nHabitaciones){
  ///si pasadizo es -1 el jugador no se encuentra en una esquina y por lo tanto
  ///no se mueve por un pasadizo
  int pasadizo = mapCorners(jugador->location);

  ///la condicion del while es tal para abreviar un if y un while(1)
  while(pasadizo != -1){
    printf("Queres tomar el pasadizo hacia %s?[Y/n] ", PLACE_NAMES[pasadizo]);
    char response; scanf("%c", &response);

    if(response != 'Y' && response != 'n'){
      printf("'Y' o 'n' por favor...\n");
      continue;
    } else if (response == 'Y') {
      habitaciones[jugador->location] = false;
      habitaciones[pasadizo] = true;

      jugador->location = pasadizo;
      return;
    }

    break;
  }

  int tiradaDado = rand() % 6 + 1; ///establecido asi por conveniencia en el for
  printf("La tirada de dado dio: %i. ", tiradaDado);
  printf("Las posiciones a las que te podes mover son: \n");

  bool cpHabitaciones[nHabitaciones];
  int habitacionesAnunciadas[nHabitaciones], it = 0;
  habitacionesAnunciadas[it++] = jugador->location;
  cp(habitaciones, cpHabitaciones, nHabitaciones);

  forMov(1, (aux % nHabitaciones));
  forMov(-1, (aux<0 ? nHabitaciones-aux : aux));

  for(int i=0; i<it; i++)
    printf("%s%c", PLACE_NAMES[habitacionesAnunciadas[i]], (i == it-1 ? '\n' : ','));

  int num;
  formatInput(num, it, "A cual de las habitaciones se quiere mover?[Nro] ");
  /*while(1){
    printf();
    scanf("%c", &response);
    int num = response - '1'; //de esta forma i queda indizado en 0

    if(!isdigit(num) || num >= it){
      printf("Numeros entre 1 y %i por favor...\n", it);
      continue;
    }

    break;
  }*/
  habitaciones[jugador->location] = false;
  jugador->location = habitacionesAnunciadas[num];

  habitaciones[jugador->location] = true;
}

#undef forMov
