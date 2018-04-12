// player.c

void player_deal(){

  // player index (mod playerCount)
  int player_idx = 0;
  int* randlist;

  randlist = makeIntList(0, SUSPECT_COUNT);
  shuffleIntList(randlist, SUSPECT_COUNT);

  for(int i = 0; i < SUSPECT_COUNT; i++; player_idx++){
    players[player_idx % playerCount].suspects[i / playerCount] = randlist[i];
    players[player_idx % playerCount].suspects[i / playerCount + 1] = -1;
  }

  free(randlist);

  randlist = makeIntList(0, WEAPON_COUNT);
  shuffleIntList(randlist, WEAPON_COUNT);

  for(int i = 0; i < WEAPON_COUNT; i++; player_idx++){
    players[player_idx % playerCount].weapons[i / playerCount] = randlist[i];
    players[player_idx % playerCount].weapons[i / playerCount + 1] = -1;
  }

  free(randlist);

  randlist = makeIntList(0, PLACE_COUNT);
  shuffleIntList(randlist, PLACE_COUNT);

  for(int i = 0; i < PLACE_COUNT; i++; player_idx++){
    players[player_idx % playerCount].places[i / playerCount] = randlist[i];
    players[player_idx % playerCount].places[i / playerCount + 1] = -1;
  }

}
