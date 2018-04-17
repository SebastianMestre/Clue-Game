// deck.h

enum card_type{SUSPECT, WEAPON, SCENE};

struct card{
  enum card_type type;
  unsigned short id;
};

struct deck{
  size_t size;
  card_t *data;
};

// devuelve el nombre de una carta
const char* name_card(struct card card);
