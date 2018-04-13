#include <stdio.h>

#include "player.h"
#include "constants.h"
#include "macros.h"

#define forn(chklist, list) \
aux = sizeof(list)/sizeof(int); \
for(int i=0; i<aux; i++) \
  printf("%i%s%c", i, chklist[list[i]], (i == aux-1 ? '\n' : '\t'));

#define formatInput(var, size, expression) while(1){ \
  printf(expression); scanf("%c", &response); \
  int num = response - '1'; \
  if(!isdigit(num) || num >= size){ \
    printf("Numeros entre 1 y %i por favor...\n", size); \
    continue; } \
  var = num; \
  break; \
}

void imprimirBaraja(player_t jugador){
  int aux;

  printf("Sospechosos en mano / vistos:\n");
  forn(SUSPECT_NAMES, jugador.suspects);

  printf("Habitaciones en mano / vistas:\n");
  forn(PLACE_NAMES, jugador.places);

  printf("Armas en mano / vistas:\n");
  forn(WEAPON_NAMES, jugador.weapons);
}

void generarAcusacion(acusacion recipiente){
  ///invento una struct acusacion que contiene 3 ints: uno para el sospechoso,
  ///uno para el arma y uno para el lugar

  ///en constants generar un jugador que tenga todas las cartas para asi
  ///poder usar la funcion imprimirBaraja para imprimir SUSPECT_NAMES, PLACE_NAMES y WEAPON_NAMES
  imprimirBaraja(mazo);

  printf("Selecciona ahora, utilizando indices, un sospechoso, habitacion");
  printf(" y arma para tu acusacion...\n");

  char response;

  formatInput(recipiente.sospechoso, SUSPECT_COUNT, "Sospechoso: ");

  formatInput(recipiente.habitacion, PLACE_COUNT, "Habitacion: ");

  formatInput(recipiente.arma, WEAPON_COUNT, "Arma: ");
}
