#include "util_console.h"
// util_console.c

void clear_screen(){
  #ifdef _WIN32
  system("cls");
  #else
  system("clear");
  #endif
}
