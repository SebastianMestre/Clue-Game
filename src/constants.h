#ifndef CLUE_CONSTANTS_H
#define CLUE_CONSTANTS_H
// constants.h

#define SUSPECT_COUNT (sizeof(SUSPECT_NAMES) / sizeof(*SUSPECT_NAMES))
#define WEAPON_COUNT (sizeof(WEAPON_NAMES) / sizeof(*WEAPON_NAMES))
#define PLACE_COUNT (sizeof(PLACE_NAMES) / sizeof(*PLACE_NAMES))

const char* PLACE_NAMES[] = {
  "Cocina", "Patio", "Spa",
  "Teatro", "Salon", "Observatorio",
  "Vestibulo", "Habitacion", "Comedor"
};

const char* SUSPECT_NAMES[] = {
  "Senorita Escarlata", "Coronel Mostaza",
  "Profesor Moradillo", "Senora Azulino",
  "Senor Verdi", "Senora Blanco"
};

const char* WEAPON_NAMES[] = {
  "revolver", "cuchillo", "lazo",
  "candelabro", "llave inglesa", "tubo de plomo"
};

#endif /* end of include guard: CLUE_CONSTANTS_H */
