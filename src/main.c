#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "random_list.h"
#include "macros.h"
#include "player.h"

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

  player_deal(players, playerCount);

  

  printf("%d\n", playerCount);

  return 0;
}
