#include "main.h"

void clear_screen(){
  #ifdef WINDOWS
  system("cls");
  #else
  system("clear");
  #endif
}

int main(){
  struct map map;
  struct player* players;
  size_t player_count;
  struct solution solution;
  size_t turn;

  srand(time(NULL));

  ui_init(&map, &solution, &players, &player_count);

  // printf("sos: %s\n", name_card(solution.suspect));
  // printf("arm: %s\n", name_card(solution.weapon));
  // printf("lug: %s\n", name_card(solution.scene));

  while(
    ui_manager(
      &map, &solution, players, player_count,
      turn++
    )
  );

  puts("Presione ENTER para continuar...");
  getchar();

  return 0;
}
