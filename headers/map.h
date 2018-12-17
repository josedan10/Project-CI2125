Col* createCol (char letter){
  Col *C = (Col *) malloc(sizeof(Col));
  C->letter = letter;
  C->land = (Land **) malloc(sizeof(Land *) * 10);

  // agregamos los terrenos en la fila

  for (unsigned short j = 0; j < 10; j++) {
    (C->land)[j] = createLand();
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