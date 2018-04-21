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

  for(int i = 0; i < player_count; i++){
    puts(players[i].name);
  }

  getchar();

  while(
    ui_manager(
      &map, &solution, players, player_count,
      turn++
    )
  );

  return 0;
}
