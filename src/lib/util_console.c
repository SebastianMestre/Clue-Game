// util_console.c

void clear_screen(){
  #ifdef WINDOWS
  system("cls");
  #else
  system("clear");
  #endif
}
