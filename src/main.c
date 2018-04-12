#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "random_list.h"
#include "macros.h"
#include "player.h"

#define MIN_PLAYER_COUNT 3
#define MAX_PLAYER_COUNT 6

player_t players[MAX_PLAYER_COUNT];

int main(){
  srand(time(NULL));

  unsigned int playerCount;

  while (true) {
    puts("Ingrese la cantidad de jugadores :");

    char input[5];
    scanf("%5s", input);
    playerCount = (unsigned int) strtoul(input, NULL, 10);
    purge_input_buffer()

    if (playerCount < MIN_PLAYER_COUNT) {
      printf("Se requieren al menos %d jugadores", MIN_PLAYER_COUNT);
    } else if (playerCount > MAX_PLAYER_COUNT) {
      printf("Se permiten a lo sumo %d jugadores", MAX_PLAYER_COUNT);
    } else {
      break;
    }
  }

  int * randlist;
  
  randlist = makeIntList(0, SUSPECT_COUNT);
  shuffleIntList(randlist, SUSPECT_COUNT);

  for(int i = 0; i < SUSPECT_COUNT; i++){
    players[i % playerCount].suspects[i / playerCount] = randlist[i];
    players[i % playerCount].suspects[i / playerCount + 1] = -1;
  }

  free(randlist);


  printf("%d\n", playerCount);

  return 0;
}
