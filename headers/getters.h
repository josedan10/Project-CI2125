Cord* askForCords() {
  char col;
  unsigned short row;
  unsigned short i;
  char preValidator[2];

  do {
    printf("\nIntroduce las coordenadas\n\n");
    printf("\nFila ( ");
    for (i = 1; i <= 9; i++) printf("%d, ", i);
    printf("%d )\n", i);
    
    printf("Fila: ");
    // scanf("%d");
    scanf("%s", preValidator);
    
    if (!inputIntValidator(preValidator) || !inputRange(atoi(preValidator), 0, 11))
      printf("\n\nERROR: caracter no valido o fuera de rango\n");

  } while (!inputIntValidator(preValidator) || !inputRange(atoi(preValidator), 0, 11));

  do {
    printf("\nColumnas ( \n");
    for (i = 65; i < 84; i++) printf("%c, ", i);
    printf("%c )\n", i);

    printf("Columna: ");
    scanf("%d");
    scanf("%c", &col);

  } while (!isColCord(col));

  col = toupper(col);
  row = atoi(preValidator);

  Cord *cord = createCord(col, row);

  return cord;
}

Skill* askForSkillToUse(Map *map, Character *C) {

  unsigned short opt, total;
  char preValidator[2];

  total = showCharacterSkills(map, C);

  do {
    printf("\nSelecciona la habilidad que deseas usar: ");
    scanf("%s", preValidator);

    if (!inputIntValidator(preValidator) || !inputRange( atoi(preValidator), 0, total + 1))
      printf("\nERROR: los valores ingresados no corresponden a una habilidad disponible\n");    

  } while (!inputIntValidator(preValidator) || !inputRange( atoi(preValidator), 0, total + 1));

  opt = atoi(preValidator);

  //TODO: Validate skill in list

  return C->skills[opt - 1]->skill;
}

unsigned short askForItem(Land *land) {

  unsigned short opt;
  printf("\nSelecciona el item que deseas recoger.\n");
  printItems((*land->items), 2);

  scanf("%hu", &opt);
  return opt;
}