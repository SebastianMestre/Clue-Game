#ifndef DEAL_H
#define DEAL_H

// deal.h

#include "player.h"
#include "deck.h"
#include "solution.h"

void deal_procedure (
  struct deck *deck_in,
  struct solution *solution_out,
  // considerar usar un array mejorado
  struct player *player_array_out,
  size_t player_array_size
);

#endif /* end of include guard: DEAL_H */
