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
  char letters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T'};

  Map *map = (Map *) malloc(sizeof(Map));

  map->cols = (Col **) malloc(sizeof(Col *) * 20);
  
  for (unsigned short i = 0; i < 20; i++) {

    map->cols[i] = createCol(letters[i]);
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
  // Print the map;
}

unsigned short isInRange(Cord *target, Cord *cord, unsigned short range) {

  return range > abs(target->col - cord->col) && range > abs(target->row - cord->row);

}