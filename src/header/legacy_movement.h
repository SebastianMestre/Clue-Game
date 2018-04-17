#ifndef MOVEMENT_H
#define MOVEMENT_H
// movement.h

#include <stdbool.h>
#include <stdio.h>
#include <assert.h>

#include "constants.h"
#include "macros.h"
#include "player.h"

void makeAMove(player_t player, bool *habitaciones, size_t nHabitaciones);

#endif
