#include <stdlib.h>
#include <assert.h>
#include "constants.h"
#include "random_list.h"
#include "macros.h"
// random_list.c

int* makeIntList(unsigned int start, unsigned int end){
  if(DEBUG) assert(start < end);

  int len = end - start;
  int* res = malloc(len * sizeof(int));
  for(int i = 0; i < len; i++){
    res[i] = i + start;
  }
  return res;
}

void shuffleIntList(int* p_list, unsigned int len){
  for(int i = 1; i < len; i++){
    int ran = rand() % i;
    swap(p_list[i], p_list[ran], int);
  }
}
