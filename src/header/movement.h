#ifndef MOVEMENT_H
#define MOVEMENT_H

int move_possible (
  int *arr_out,
  int step_count,
  struct player* player_in,
  struct map* map_in
);

#endif /* end of include guard: MOVEMENT_H */
