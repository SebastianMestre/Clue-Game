#include <stdbool.h>
#include <stdio.h>

const int MIN_PLAYER_COUNT = 3;
const int MIN_PLAYER_COUNT = 6;
int playerCount = 0;

int main(){

  while (true) {
    scanf("%d\n", &playerCount);
    if (playerCount < MIN_PLAYER_COUNT) {
      printf("Se requieren al menos %d jugadores", MIN_PLAYER_COUNT);
    } else if (playerCount > MAX_PLAYER_COUNT) {
      printf("Se permiten a lo sumo %d jugadores", MAX_PLAYER_COUNT);
    } else {
      break;
    }
  }

  printf("%d\n", playerCount);

  return 0;
}
