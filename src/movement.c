#include "constants.h"
#include "macros.h"
#include "player.h"
#include <stdbool.h>
#include <stdio.h>

#define forMov(mode, expression) \
for(int i = 0; i < tiradaDado; i++){ \
  int aux = player.location + (i*mode); \
  aux = expression; \
  if(!cpHabitaciones[aux]){ \
    cpHabitaciones[aux] = 1; \
    habitacionesAnunciadas[it++] = aux; \
}}
#define isdigit(n) (n > -1 && n < 10)


int mapCorners(int corner){
  switch (corner) {
    case 0:
      return 5;
    case 2:
      return 7;
    case 5:
      return 0;
    case 7:
      return 2;
    default:
      return -1;
  }
}

void makeAMove(player_t jugador, bool *habitaciones, size_t nHabitaciones){
  ///si pasadizo es -1 el jugador no se encuentra en una esquina y por lo tanto
  ///no se mueve por un pasadizo
  int pasadizo = mapCorners(jugador.location);

  ///la condicion del while es tal para abreviar un if y un while(1)
  while(pasadizo != -1){
    printf("Queres tomar el pasadizo hacia %s?[Y/n] ", PLACE_NAMES[pasadizo]);
    char response; scanf("%c", &response);

    if(response != 'Y' && response != 'n'){
      printf("'Y' o 'n' por favor...\n");
      continue;
    } else if(response == 'Y') {
      habitaciones[jugador.location] = 0;
      habitaciones[pasadizo] = 1;
      
      jugador.location = pasadizo;      
      return;
    }

    break;
  }

  int tiradaDado = rand() % 6 + 1; ///establecido asi por conveniencia en el for
  printf("La tirada de dado dio: %i. ", tiradaDado);
  printf("Las posiciones a las que te podes mover son: \n");

  bool cpHabitaciones[nHabitaciones];
  int habitacionesAnunciadas[nHabitaciones], it=0;
  cp(habitaciones, cpHabitaciones, nHabitaciones);

  forMov(1, (aux % nHabitaciones));
  forMov(-1, (aux<0 ? nHabitaciones-aux : aux));
  
  for(int i=0; i<it; i++)
    printf("%c%c", habitacionesAnunciadas[i], (i == it-1 ? '\n' : ','));

  while(1){
    printf("A cual de las habitaciones se quiere mover?[Nro] ");
    scanf("%c", &response); 
    int num = response - '1'; //de esta forma i queda indizado en 0
    
    if(!isdigit(num) || num >= it){
      printf("Numeros entre 1 y %i por favor...\n", it); 
      continue;
    }
    
    habitaciones[jugador.location] = 0;    
    jugador.location = habitacionesAnunciadas[num];
    
    habitaciones[jugador.location] = 1;
    break;
  }
}
