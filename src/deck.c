#include "./header/deck.h"

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

const struct deck* deck_master(){
  const int SUSPECT_COUNT = 6;
  const int WEAPON_COUNT = 6;
  const int SCENE_COUNT = 9;
  static struct deck master = {0, NULL};

  if(master.size == 0){
    deck_pushCard(&master, (struct card){SUSPECT, 0});
    deck_pushCard(&master, (struct card){SUSPECT, 1});
    deck_pushCard(&master, (struct card){SUSPECT, 2});
    deck_pushCard(&master, (struct card){SUSPECT, 3});
    deck_pushCard(&master, (struct card){SUSPECT, 4});
    deck_pushCard(&master, (struct card){SUSPECT, 5});
    deck_pushCard(&master, (struct card){WEAPON, 0});
    deck_pushCard(&master, (struct card){WEAPON, 1});
    deck_pushCard(&master, (struct card){WEAPON, 2});
    deck_pushCard(&master, (struct card){WEAPON, 3});
    deck_pushCard(&master, (struct card){WEAPON, 4});
    deck_pushCard(&master, (struct card){WEAPON, 5});
    deck_pushCard(&master, (struct card){SCENE, 0});
    deck_pushCard(&master, (struct card){SCENE, 1});
    deck_pushCard(&master, (struct card){SCENE, 2});
    deck_pushCard(&master, (struct card){SCENE, 3});
    deck_pushCard(&master, (struct card){SCENE, 4});
    deck_pushCard(&master, (struct card){SCENE, 5});
    deck_pushCard(&master, (struct card){SCENE, 6});
    deck_pushCard(&master, (struct card){SCENE, 7});
    deck_pushCard(&master, (struct card){SCENE, 8});
  }

  return &master;
}

const struct deck* deck_suspects(){
  const int SUSPECT_COUNT = 6;
  static struct deck suspects = {0, NULL};

  if(suspects.size == 0){
    deck_pushCard(&suspects, (struct card){SUSPECT, 0});
    deck_pushCard(&suspects, (struct card){SUSPECT, 1});
    deck_pushCard(&suspects, (struct card){SUSPECT, 2});
    deck_pushCard(&suspects, (struct card){SUSPECT, 3});
    deck_pushCard(&suspects, (struct card){SUSPECT, 4});
    deck_pushCard(&suspects, (struct card){SUSPECT, 5});
  }

  return &suspects;
}

const struct deck* deck_weapons(){
  const int WEAPON_COUNT = 6;
  static struct deck weapons = {0, NULL};

  if(weapons.size == 0){
    deck_pushCard(&weapons, (struct card){WEAPON, 0});
    deck_pushCard(&weapons, (struct card){WEAPON, 1});
    deck_pushCard(&weapons, (struct card){WEAPON, 2});
    deck_pushCard(&weapons, (struct card){WEAPON, 3});
    deck_pushCard(&weapons, (struct card){WEAPON, 4});
    deck_pushCard(&weapons, (struct card){WEAPON, 5});
  }

  return &weapons;
}

const struct deck* deck_scenes(){
  const int SCENE_COUNT = 9;
  static struct deck scenes = {0, NULL};

  if(scenes.size == 0){
    deck_pushCard(&scenes, (struct card){SCENE, 0});
    deck_pushCard(&scenes, (struct card){SCENE, 1});
    deck_pushCard(&scenes, (struct card){SCENE, 2});
    deck_pushCard(&scenes, (struct card){SCENE, 3});
    deck_pushCard(&scenes, (struct card){SCENE, 4});
    deck_pushCard(&scenes, (struct card){SCENE, 5});
    deck_pushCard(&scenes, (struct card){SCENE, 6});
    deck_pushCard(&scenes, (struct card){SCENE, 7});
    deck_pushCard(&scenes, (struct card){SCENE, 8});
  }

  return &scenes;
}

const char* name_card(struct card card){
  const char* names_suspects[] = {
    "Srta. Escarlata", "Crnl. Mostaza", "Prof. Moradillo",
    "Sra. Azulino", "Sr. Verdi", "Sra. Blanco"
  };
  const char* names_weapons[] = {
    "Revolver", "Cuchillo", "Lazo",
    "Candelabro", "Llave inglesa", "Tubo de plomo"
  };
  const char* names_scenes[] = {
    "Cocina", "Patio", "Spa",
    "Teatro", "Salon", "Vestibulo",
    "Observatorio", "Habitacion de huespedes", "Comedor"
  };

  switch (card.type) {
    case SUSPECT:
      return names_suspects[card.id];
      break;
    case WEAPON:
      return names_weapons[card.id];
      break;
    case SCENE:
      return names_scenes[card.id];
      break;
  }

}


void imprimir_mazo( struct deck deck ){
  for(int i = 0; i < deck.size; i++){
    printf("\t%d. %s\n", i, name_card(deck.data[i]));
  }
}
