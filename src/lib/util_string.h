#ifndef UTIL_STRING_H
#define UTIL_STRING_H

// util_string.h
#include <string.h>
#include <stdlib.h>

// returns ownership of a new string equal to the one passed
// devuelve propiedad sobre un nuevo string igual al argumento
char* str_dupl(const char* value_in);

#endif /* end of include guard: UTIL_STRING_H */
