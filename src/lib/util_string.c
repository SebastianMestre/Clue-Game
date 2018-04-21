#include "util_string.h"
// util_string.c

char* str_dupl(const char* value_in){
  return strcpy(malloc(strlen(value_in) + 1), value_in);
}
