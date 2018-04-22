#include "./header/ui.h"

void ui_init(
  struct map* map,
  struct solution* solution,
  struct player** player_arr,
  size_t *player_arr_size
){
  const int MIN_PLAYER_COUNT = 3;
  const int MAX_PLAYER_COUNT = 6;

  puts("Ingrese la cantidad de jugadores.");

  printf(
    "Debe ser un numero en [%d,%d] :",
    MIN_PLAYER_COUNT,
    MAX_PLAYER_COUNT
  );

  size_t temp = 0;

  while(MIN_PLAYER_COUNT > temp || temp > MAX_PLAYER_COUNT){
    scanf("%d%*c", &temp);
    if (temp < MIN_PLAYER_COUNT) {
      puts("El valor es muy bajo, volve a intentar.");
    } else if (temp > MAX_PLAYER_COUNT) {
      puts("El valor es muy alto, volve a intentar.");
    }
  }

  *player_arr = safe_malloc(sizeof(**player_arr) * temp);
  *player_arr_size = temp;

  char BUFFER[1024];
  for(int i = 0; i < temp; i++){
    printf("Ingrese el nombre del %d. jugador.", i+1);
    scanf("%1023[^\n]%*c", BUFFER);

    (*player_arr)[i] = player_new(BUFFER);
  }

  int pasadizos[] = {5, -1, 7, -1, -1, 0, -1, 2, -1};
  int map_size = 9;
  *map = map_new(map_size, pasadizos);

  // indice para repartir cartas. esto evita que un jugador tenga mas de 1 carta mas que otros.
  // si se terminan de repartir las cartas de sospechoso y el ultimo jugador en recibir una
  // carta es el jugador 0, el primero en recibir una carta de arma sera el jugador 1
  int player_idx = 0;

  // crea una lista de enteros con tantas entradas como sospechosos existen
  // esta lista se guarda en la "memoria dinamica"
  int* randlist = makeIntList(0, deck_suspects()->size);

  // la lista se mezcla para crear un orden aleatorio
  shuffleIntList(randlist, deck_suspects()->size);

  // se selecciona el victimario como el primer elemento en el orden mezclado
  solution->suspect = deck_suspects()->data[randlist[0]];

  // se reparten el resto de las cartas de sospechoso a los jugadores
  for(int i = 1; i < deck_suspects()->size; i++){
    player_pushCard(*player_arr + player_idx, deck_suspects()->data[randlist[i]]);

    // incrementa el indice de jugador en modulo, devuelve el indice a 0 al pasar por el ultimo jugador
    player_idx = (player_idx + 1) % *player_arr_size;
  }

  // la lista se vuelve a crear con un tamano distinto mas adelante
  // por lo que se libera la memoria reservada
  free(randlist);

  // el mismo procedimiento se repite para las posibles armas
  randlist = makeIntList(0, deck_weapons()->size);
  shuffleIntList(randlist, deck_weapons()->size);
  solution->weapon = deck_weapons()->data[randlist[0]];
  for(int i = 1; i < deck_weapons()->size; i++){
    player_pushCard(*player_arr + player_idx, deck_weapons()->data[randlist[i]]);
    player_idx = (player_idx + 1) % *player_arr_size;
  }
  free(randlist);

  // y una vez mas para las posibles localizaciones
  randlist = makeIntList(0, deck_scenes()->size);
  shuffleIntList(randlist, deck_scenes()->size);
  solution->suspect = deck_scenes()->data[randlist[0]];
  for(int i = 1; i < deck_scenes()->size; i++){
    player_pushCard(*player_arr + player_idx, deck_scenes()->data[randlist[i]]);
    player_idx = (player_idx + 1) % *player_arr_size;
  }
  free(randlist);
}


bool ui_manager(
  struct map* map,
  struct solution* solution,
  struct player* player_arr,
  size_t player_arr_size,
  size_t turn
){
  /// DOCSTRING: returns true when the game must end and false when the game continues
  struct player* current_player = player_arr + (turn % player_arr_size);

  // saltea el jugador ectual si este acuso incorrectamente en un turno anterior
  if(!current_player->vivo)
    return true;

  ui_movement(map, current_player);

  int num;
  char response;

  menu_completo:
  printf("\t\tMENU\tPlayer: %s\n", current_player->name);
  printf("1-Mostrar mazo\n");
  printf("2-Generar una sospecha\n");
  printf("3-Realizar una acusacion\n");

  tomar_input:
  scanf("%c", &response);
  num = response - '0'; 

  if(num<1 || num>3){
    puts("Numeros entre 1 y 3, por favor. Volve a intentar:");
    goto tomar_input;
  }

  switch (num) {
    case 1:
      imprimir_mazo(current_player->hand);
      goto menu_completo;
    break;
    case 2:
      ui_suspicion(map, current_player, player_arr, player_arr_size);
    break;
    case 3:
      return ui_acussation(solution, current_player);
    break;
  }
  return true;
}

void ui_movement(
  struct map* map,
  struct player* player
){

  int pasadizo = map_pasadizo(map , player->location.id);
  if (pasadizo != -1 && !map_occupied(map, pasadizo)){
    printf("Usted puede moverse por el pasadizo hacia %s\n", name_card({SCENE, pasadizo}));
    puts("Quiere moverse? [Y/n]: ");

    char option;
    validate_option:

    scanf("%c%*c", &option);

    if(option == 'Y' || option == 'y'){
      // moverse x pasadizo
      map->ocupado[player->location.id] = false;
      player->location.id = pasadizo;
      map->ocupado[player->location.id] = true;

      return;
    }else if(option == 'N' || option == 'n'){
      // moverse x pasillo a.k.a. nada
    }else{
      puts("opcion invalida, ingrese [Y/n]");
      goto validate_option;
    }

  }
  int dado = (rand() % 6) + 1;
  int* movidas_posibles;
  int movidas_posibles_size = move_possible(&movidas_posibles, dado, player, map);

  puts("Las habitaciones a las que se puede mover son:");
  
  for(int i=0; i<movidas_posibles_size; i++){
    printf("%s(%i)%s", deck_scenes()->data[movidas_posibles[i]], i,
          (i%3==0 || i==movidas_posibles_size-1 ? "\n" : ", "));
  }
  
  puts("A que habitacion desea moverse?[Nro] ");
  
  int choice;
  validate_input_movement:
  
  scanf("%i%*c", &choice);
  
  if(input < 0 || choice >= movidas_posibles_size){
    printf("Introduzca un numero entre 0 y %i por favor...\n", movidas_posibles_size);
    goto validate_input_movement;
  } else {
    map->ocupado[player->location.id] = false;
    player->location.id = deck_scenes()->data[movidas_posibles[choice]].id;
    map->ocupado[player->location.id] = true;
  }
  
  free(movidas_posibles);
}

void ui_suspicion(
  struct map* map,
  struct player* player,
  struct player* player_arr,
  size_t player_arr_size
){
  char *msg[3] = {"sospechoso","arma","habitacion"};
  card sospecha[3];

  struct deck decks[3] = {
    *deck_suspects(),
    *deck_weapons(),
    (struct deck){0, NULL}
  };

  deck_pushCard(&decks[2], player->location);

  for(int i = 0; i < 3; i++){
    printf("Ingrese el %s", msg[i]);
    puts("Opciones:");
    imprimir_mazo(decks[i]);

    puts("Ingrese el nro de la carta que elige"); 
    //por ahi es algo muy especifico para cuando estemos mirando el formato de impresion pero pienso que es necesario
    int opcion;

    validate_input_option:
    scanf("%i%*c", &opcion);

    if(opcion < 0){
      puts("el numero es muy bajo, intenta otra vez.");
      goto validate_input_option;
    } else if(opcion > decks[i].size){
      puts("el numero es muy alto, intenta otra vez.");
      goto validate_input_option;
    }
    
    sospecha[i] = decks[i].data[opcion]; 
    // arregla el problema de tener que mapear la opcion de habitacion(1 sola) a la player->location
  }
  
  // diferencia entre player y el principio del arreglo de players = "turno"
  int it = player - player_arr;
  for(int i = 0; i < player_arr_size-1; i++){//no incluimos al jugador de la deduccion
    it = it + 1 % player_arr_size;

    struct deck tempdeck = {0, NULL};

    for(int j = 0; j < player_arr[it].hand.size; j++){
      if(player_arr[it].hand.data[j] == sospecha[player_arr[it].hand.data[j].type]){
        deck_pushCard(&tempdeck, player_arr[it].hand.data[j]);
      }
    }

    if(tempdeck.size){
      //clrscreen
      printf("jugador %s, eliga una carta para mostrar.", player_arr[it].name);
      puts("Listo?. presione ENTER.");

      getchar();

      puts("Opciones:");
      imprimir_mazo(tempdeck);

      int opcion;
      validate_pista:
      scanf("%d%*c", &opcion);

      if(opcion < 0 || opcion >= tempdeck.size){
        printf("Numeros entre 0 y %d", tempdeck.size-1);
        goto validate_pista;
      }

      //clrscreen

      printf("Le refutan: %s\n", name_card(tempdeck.data[opcion]));
      puts("Presione ENTER para continuar.");

      getchar();
      break;
    }
  }
}

bool ui_accusation(
  struct solution* solution,
  struct player* player
){
  /// DOCSTRING: returns true when the player win and false when him fail
  char *msg[3] = {"sospechoso","arma","habitacion"};
  int sospecha[3];

  struct deck decks[3] = {
    *deck_suspects(),
    *deck_weapons(),
    *deck_scenes()
  };

  for(int i = 0; i < 3; i++){
    printf("Ingrese el %s", msg[i]);
    puts("Opciones:");
    for(int j = 0; j < decks[i].size; j++){
      printf("%d. %s\n", i, name_card(decks[i].data[j]));
    }

    int opcion;

    validate_input_option:
    scanf("%i%*c", &opcion);

    if(opcion < 0){
      puts("el numero es muy bajo, intenta otra vez.");
      goto validate_input_option;
    } else if(opcion > decks[i].size){
      puts("el numero es muy alto, intenta otra vez.");
      goto validate_input_option;
    }

    sospecha[i] = opcion;
  }

  bool iguales =
    (sospecha[0] == solution->suspect.id)&&
    (sospecha[1] == solution->weapon.id)&&
    (sospecha[2] == solution->scene.id);

  if(iguales){
    printf("\n\n\tFin del juego! victoria de %s!", player->name);
    return false;
  }else{
    player->vivo = false;
    return true;
  }
}
