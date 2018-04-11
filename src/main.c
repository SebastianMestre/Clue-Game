#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define swap(a,b,T) do{T temp = a; a = b; b = temp;}while(0)

// const int MIN_PLAYER_COUNT = 3;
// const int MAX_PLAYER_COUNT = 6;
// const int SUSPECT_COUNT = 6;
// const int WEAPON_COUNT = 6;
// const int PLACE_COUNT = 9;

#define MIN_PLAYER_COUNT 3
#define MAX_PLAYER_COUNT 6
#define SUSPECT_COUNT 6
#define WEAPON_COUNT 6
#define PLACE_COUNT 9

struct jugador{
  int location;
  // TODO: reemplazar int[] por array dinamico de cartas
  int suspects[SUSPECT_COUNT + 1];
  int weapons[WEAPON_COUNT + 1];
  int places[PLACE_COUNT + 1];
};

typedef struct jugador player_t;


player_t players[MAX_PLAYER_COUNT];
int playerCount = 0;

const char PLACE_NAMES [][30] = {
  "Cocina", "Patio", "Spa",
  "Teatro", "Salon", "Observatorio",
  "Vestibulo", "Habitacion", "Comedor"
};

const char SUSPECT_NAMES [][30] = {
  "Senorita Escarlata", "Coronel Mostaza",
  "Profesor Moradillo", "Senora Azulino",
  "Senor Verdi", "Senora Blanco"
};

const char WEAPON_NAMES [][30] = {
  "revolver", "cuchillo", "lazo",
  "candelabro", "llave inglesa", "tubo de plomo"
};

int main(){
  srand(time(NULL));

  while (true) {
    puts("Ingrese la cantidad de jugadores :");
    scanf("%d\n", &playerCount);
    if (playerCount < MIN_PLAYER_COUNT) {
      printf("Se requieren al menos %d jugadores", MIN_PLAYER_COUNT);
    } else if (playerCount > MAX_PLAYER_COUNT) {
      printf("Se permiten a lo sumo %d jugadores", MAX_PLAYER_COUNT);
    } else {
      break;
    }
  }

  int *randlist = makeIntList(0, SUSPECT_COUNT);
  shuffleIntList(randlist, SUSPECT_COUNT);

  for(int i = 0; i < SUSPECT_COUNT; i++){
    players[i % playerCount].suspects[i / playerCount] = 0;
  }

  free(randlist);


  printf("%d\n", playerCount);

  return 0;
}
