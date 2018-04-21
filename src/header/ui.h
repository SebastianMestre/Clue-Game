#ifndef UI_H
#define UI_H

// ui.h

#include <stdbool.h>

#include "player.h"
#include "map.h"
#include "movement.h"
#include "solution.h"

#include "../lib/util_memory.h"

void ui_init(
  struct map* map,
  struct solution* solution,
  struct player** player_arr,
  size_t *player_arr_size
);

// devuelve un valor que indica que el juego continua
bool ui_manager(
  struct map* map,
  struct solution* solution,
  struct player* player_arr,
  size_t player_arr_size,
  size_t turn
);

void ui_movement(
  struct map* map,
  struct player* player
);

void ui_accusation(
  struct solution* solution,
  struct player* player
);

void ui_suspicion(
  struct map* map,
  struct player* player,
  struct player* player_arr,
  size_t player_arr_size
);

#endif /* end of include guard: UI_H */
