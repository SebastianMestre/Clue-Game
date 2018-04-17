#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "random_list.h"
#include "macros.h"
#include "player.h"
#include "movement.h"
#include "turno.h"

#define MIN_PLAYER_COUNT 3
#define MAX_PLAYER_COUNT 6


int main(){
  player_t players[MAX_PLAYER_COUNT];
  srand(time(NULL));

  int playerCount = 0;
  while (true) {
    puts("Ingrese la cantidad de jugadores :");
    scanf("%d\n", &playerCount);
    if (playerCount < MIN_PLAYER_COUNT) {
      printf("Se requieren al menos %d jugadores\n", MIN_PLAYER_COUNT);
    } else if (playerCount > MAX_PLAYER_COUNT) {
      printf("Se permiten a lo sumo %d jugadores\n", MAX_PLAYER_COUNT);
    } else {
      break;
    }
  }

  sospecha_t solucion; // asignar solucion

  player_deal(players, playerCount, &solucion);

  // init
  bool finish_game = true;
  int turno = 0;

  bool habitaciones[] = {0,0,0,0,0,0,0,0,0};
  int *initial_position = makeIntList(0, playerCount);
  shuffleIntList(initial_position, playerCount);

  for(int i=0; i<playerCount; i++){
    printf("Ingrese nombre jugador: ");
    scanf("%s", players[i].player_name);
    printf("%s se encuentra en %s", players[i].player_name, PLACE_NAMES[initial_position[i]]);
    habitaciones[initial_position[i]] = 1;
  }

  do{
    if(players[turno].player_name == NULL){
      // metodo para detectar jugadores eliminados
      turno++; turno %= playerCount;
      continue;
    }

    makeAMove(players[turno], habitaciones, 9);
    // clrscreen
    printf("\t\tMENU\tJugador: %s\n", players[turno].player_name);
    printf("1- Imprimir baraja\n");
    printf("2- Levantar una sospecha\n");
    printf("3- Realizar una acusacion\n");

    int choice; formatInput(choice, 3, "Escoja una opcion: ");

    switch(choice){
      case 0:
        // clrscreen
        imprimirBaraja(players[turno]);
        // todo lo que esta en el do while hay que juntarlo en una funcion
        // menu(exclude) con exclude = opcion a omitir
        menu(0);
      break;
      case 1:{
        // clrscreen
        sospecha_t nuevaSospecha;
        generarSospecha(nuevaSospecha);

        // function consult other players sospecha
      }break;
      case 2:{
        // clrscreen
        sospecha_t nuevaAcusacion;
        generarSospecha(nuevaAcusacion);

        if( solucion.suspect == nuevaAcusacion.suspect &&
            solucion.weapon == nuevaAcusacion.weapon &&
            solucion.place == nuevaAcusacion.place )
          finish_game = false;
        else
          players[turno].player_name = NULL;
      }break;
    }

    turno++; turno %= playerCount;
  }while(finish_game);



  printf("%d\n", playerCount);

  return 0;
}
