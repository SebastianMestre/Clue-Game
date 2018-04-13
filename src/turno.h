#ifndef TURNO_H
#define TURNO_H

#include <stdio.h>
#include "player.h"
#include "constants.h"
#include "macros.h"

struct tripla{
  int sospechoso;
  int arma;
  int habitacion;
};

typedef struct tripla sospecha_t;

void imprimirBaraja(player_t jugador);
void generarAcusacion(sospecha_t recipiente);

#endif /* end of include guard: TURNO_H */
