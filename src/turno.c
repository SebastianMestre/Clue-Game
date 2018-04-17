#include "turno.h"
// turno.c

#define forn(chklist, list) \
for(int i=0; list[i] != -1; i++) \
  printf("%i %s%c", i, chklist[list[i]], (list[i+1] == -1 ? '\n' : '\t'));


void imprimirBaraja(player_t jugador){

  printf("Sospechosos en mano / vistos:\n");
  forn(SUSPECT_NAMES, jugador.suspect);

  printf("Habitaciones en mano / vistas:\n");
  forn(PLACE_NAMES, jugador.place);

  printf("Armas en mano / vistas:\n");
  forn(WEAPON_NAMES, jugador.weapon);
}

void generarSospecha(sospecha_t recipiente){
  ///invento una struct sospecha_t que contiene 3 ints: uno para el sospechoso,
  ///uno para el arma y uno para el lugar

  ///en constants generar un jugador que tenga todas las cartas para asi
  ///poder usar la funcion imprimirBaraja para imprimir SUSPECT_NAMES, PLACE_NAMES y WEAPON_NAMES
  imprimirBaraja(mazo);

  printf("\n\nSelecciona ahora, utilizando indices, un sospechoso, habitacion");
  printf(" y arma para tu acusacion...\n");

  char response;

  formatInput(recipiente.suspect, SUSPECT_COUNT, "Sospechoso: ");

  formatInput(recipiente.place, PLACE_COUNT, "Habitacion: ");

  formatInput(recipiente.weapon, WEAPON_COUNT, "Arma: ");
}

#undef forn
