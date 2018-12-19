Col* createCol (char letter){
  Col *C = (Col *) malloc(sizeof(Col));
  C->letter = letter;
  C->lands = (Land **) malloc(sizeof(Land *) * 10);

  // agregamos los terrenos en la fila

  for (unsigned short j = 0; j < 10; j++) {
    (C->lands)[j] = createLand();
  }

  return C;
}

Map* createMap() {
  Map *map = (Map *) malloc(sizeof(Map));

  map->cols = (Col **) malloc(sizeof(Col *) * 20);
  
  for (unsigned short i = 0; i < 20; i++) {

    map->cols[i] = createCol((char)(i + 65));
  }

  return map;
}

// Pre: col pertenece a map->letters, row > 0 y row < 10 

Cord* createCord (char col, unsigned short row) {
  Cord *cord = (Cord *) malloc(sizeof(Cord));
  cord->col = col;
  cord->row = --row;

  return cord;
}

Land* getLandWithCord (Map *map, Cord *cord) {
  return map->cols[cord->col - ASCII_A]->lands[cord->row];
}

void printMap (Map *map) {
  unsigned short j = 0, i, row = 1;
  Land *landAux;

  printf("   ");
  for (i = 0; i < 20; i++)
    printf("%c ", (char) (i + 65));

  printf("\n");

  while (j < 10) {

    for (i = 0; i < 20; i++) {
      if (i == 0) {
        if (j < 9)
          printf("%d  ", j + 1);
        else
          printf("%d ", j + 1);
      }

      landAux = map->cols[i]->lands[j];

      if (landAux->character != NULL) 
        printf("%c ", toupper(landAux->character->name[0]));

      else if ((*landAux->items) != NULL) 
        printf("%c ", '*');
      
      else if (landAux->effect != none)
        printf("%c ", 178);

      else
        printf("%c ", 176);

      if (i == 19) {
        printf("\n\n");
        j++;
      }
    }
  }
}

unsigned short isInRange(Cord *target, Cord *cord, unsigned short range) {

  return range >= abs(target->col - cord->col) && range > abs(target->row - cord->row);

}