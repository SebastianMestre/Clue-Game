#include "random_list.h"
// random_list.c

int* makeIntList(int start, int end){
  int len = end - start;
  int* res = malloc(len * sizeof(int));
  for(int i = 0; i < len; i++){
    res[i] = i + start;
  }
  return res;
}

void shuffleIntList(int* p_list, int len){
  for(int i = 1; i < len; i++){
    int ran = rand() % (i+1);
    swap(p_list[i], p_list[ran], int);
  }
}
