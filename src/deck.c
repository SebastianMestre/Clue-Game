#include "./header/deck.h"

const char* name_card(struct card card){
  return "hola";
}

void deck_pushCard(struct deck* this, struct card card){
  if(this->size == 0 || this->data == NULL){
    this->size = 1;
    this->data = safe_malloc(sizeof(*this->data));
  }else{
    this->size++;
    this->data = safe_realloc(this->data, sizeof(*this->data) * this->size);
  }
  this->data[this->size - 1] = card;
}
