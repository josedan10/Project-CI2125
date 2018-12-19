Cord* askForCords() {
  char col;
  unsigned short row;

  do {
    printf("\nIntroduce las coordenadas\n\n");
    printf("\nFila (1, 2, 3, 4, 5, 6, 7, 8, 9, 10)\n");
    
    printf("Fila: ");
    // scanf("%d");
    scanf("%d", &row);

  } while (row < 1 || row > 10);

  do {
    printf("\nPor favor Ingrese las coordenadas\n");
    printf("\nColumnas (A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T)\n");

    printf("Columna: ");
    scanf("%d");
    scanf("%c", &col);

  } while (col < ASCII_A || col > ASCII_T);

  Cord *cord = createCord(col, row);

  return cord;
}

Skill* askForSkillToUse(Map *map, Character *C) {

  unsigned short opt;

  showCharacterSkills(map, C);
  printf("\nSelecciona la habilidad que deseas usar: ");
  scanf("%hu", &opt);

  //TODO: Validate skill in list

  return C->skills[opt - 1]->skill;
}

unsigned short askForItem(Land *land) {

  unsigned short opt;
  printf("\nSelecciona el item que deseas recoger.\n");
  printItems((*land->items));

  scanf("%hu", &opt);
  return opt;
}