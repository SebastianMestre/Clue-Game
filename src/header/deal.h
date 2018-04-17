// deal.h

#include "player.h"
#include "deck.h"
#include "solution.h"

void deal_procedure (
  deck_t     *deck_in,
  solution_t *solution_out,
  // considerar usar un array mejorado
  player_t   *player_array_out,
  size_t      player_array_size
);
