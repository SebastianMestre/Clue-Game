#include "stddef.h"
#include <stdio.h>


#include "header/ui.h"
#include "header/map.h"
#include "header/player.h"
#include "header/solution.h"

int main(){
  struct map map;
  struct player* players;
  size_t player_count;
  struct solution solution;
  size_t turn;

  ui_init(&map, &solution, &players, &player_count);

  while(
    if(
    ui_manager(
      &map, &solution, players, player_count,
      turn++
    )) // mirar DOCSTRING de ui_manager
      break;
  );

  return 0;
}
