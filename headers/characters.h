Cord* getCharacterCords (Map *map, Character *C) {
  unsigned short i, j = i = 0;
  char letter;
  int pos;
  Cord * cords = NULL;
  Character *Char;

  while (i < 20 && cords == NULL) {
    for (j = 0; j < 10; j ++) {

      letter = map->cols[i]->letter;
      pos = j+1;
      Char = map->cols[i]->lands[j]->character;


      if (Char != NULL && Char == C) {
        cords = (Cord *) malloc(sizeof(Cord));
        cords->col = map->cols[i]->letter;
        cords->row = j;
        
        break;
      }
    }

    if (j != 10) break;

    i++;
  }

  return cords;     
}

void showCharacterDetails (Map *map, Character *C) {

  if (C != NULL) {

    // printf("\nEstadisticas:\n");
    if (map != NULL) {

      Cord *cord = getCharacterCords(map, C);
      printf("Posicion en el mapa: (%hu, %c)\n", cord->row + 1, cord->col);
    }

    printf("%s\n", C->name);
    printf("HP: %d\n", C->hP);
    printf("Puntos de energia: %d\n", C->eP);
    printf("Evasion: %d\n", C->evasion);
    printf("Armadura: %d\n", C->armor);
    printf("Velocidad: %d\n", C->velocity);
    printf("Dano: %d\n", C->damage);
    printf("Puntos de Accion: %d\n", C->aP);
    printf("Rango: %d\n", C->range);


  } else {
    printf("No hay personaje.\n");
  }

  printf("\n");
}

CharsListR createNewCharsListR(unsigned short players) {
  CharsListR CListR = malloc(sizeof(CharsListC));  
  CListR->capacity = players;
  CListR->alfa = CListR->omega = 0;
  CListR->chars = (Character **) malloc(players * sizeof(Character  *));
  CListR->tam = 0;

  return CListR;
}

Character* createNewCharacter (unsigned int velocity) {

  Character *newCharacter = (Character*) malloc(sizeof(Character));
  srand(time(NULL));

  printf("\nDefine un nombre para tu personaje (maximo 15 caracteres): ");
  scanf("%*c%[^\n]", newCharacter->name);

  newCharacter->hP = 100;
  newCharacter->eP = 100;
  newCharacter->aP = 0;
  newCharacter->armor = 100;
  newCharacter->evasion = rand() % 31;
  newCharacter->velocity = ++velocity;
  newCharacter->damage = 1 + rand() % 40;
  newCharacter->range = 1 + rand() % 4;

  showCharacterDetails(NULL, newCharacter);

  return newCharacter;
}

void queuePlayer (Character *C, CharsListR CList) {
int hab;
  Character *newChar = (Character *) malloc(sizeof(Character));
  char preValidator [2];

  //Clon the Character
  strcpy(newChar->name, C->name);
  newChar->armor = C->armor;
  newChar->damage = C->damage;
  newChar->eP = C->eP;
  newChar->evasion = C->evasion;
  newChar->aP = C->aP;
  newChar->playerId = C->playerId;
  newChar->hP = C->hP;
  newChar->velocity = C->velocity;
  newChar->range = C->range;
  newChar->items = (HeapItems *)malloc(sizeof(HeapItems));
  newChar->skills = (SkillsList *)malloc(sizeof(SkillsList));

  (*newChar->items) = NULL;
  (*newChar->skills) = NULL;

  // Create character habilities asignation

  do {
    printf("\nElige una habilidad\n");
    printf("1) Congelar\n");
    freezeDescription();

    printf("2) Incendiar\n");
    fireDescription();

    printf("3) Restaurar\n");
    restoreDescription();

    printf("4) Electrocutar\n");
    electrocuteDescription();

    scanf("%s", preValidator);

    if (!inputIntValidator(preValidator) || !inputRange(atoi(preValidator), 0, 5)) {
      printf("\n\nERROR: Opcion no permitida\n");
      waitForKeyPress();
    }

  } while (!inputIntValidator(preValidator) || !inputRange(atoi(preValidator), 0, 5));

  hab = atoi(preValidator);

  switch (hab) {
    case 1:
      printf("\nElegiste 'congelar'.\n");
      // Crear nueva habilidad
      addToSkills(newChar, createFreezeSkill());
      break;

    case 2:
      printf("\nElegiste 'incendiar'.\n");
      // Crear nueva habilidad
      addToSkills(newChar, createFireSkill());

      break;
    
    case 3:
      printf("\nElegiste 'restaurar'.\n");
      // Crear nueva habilidad
      addToSkills(newChar, createRestoreSkill());

      break;
    
    case 4:
      printf("\nElegiste 'electrocutar'.\n");
      // Crear nueva habilidad
      addToSkills(newChar, createElectrocuteSkill());

      break;
  }

  (CList->chars)[CList->omega] = newChar;
  CList->omega = (CList->omega + 1) % CList->capacity;
  CList->tam++;

  if (CList->capacity == CList->tam) {
    // The queue is full

    int newSize = (int) 1.3 * CList->capacity;
    Character **newList = (Character **) malloc(sizeof(Character *) * newSize);
    
    unsigned short i;
    for (i = 0; i < CList->capacity; i++)
      newList[i] = (CList->chars)[(CList->alfa + i) % CList->capacity];

    free(CList->chars);
    CList->alfa = 0;
    CList->omega = i;
    CList->capacity = newSize;
    CList->chars = newList;
    
  }
}

void popItem(HeapItems *items) {

  //delete ItemNode from Inventory
  ItemNode *aux = *items;
  *items = (*items)->next;

  free(aux);  
}

void changeCharacterPosition (Character *C, Land *land) {
  land->character = C;

}

void showCharacterSkills (Map *map, Character *C) {

  showCharacterDetails(map, C);
  printf("Tus habilidades\n");
  printf("_______________\n");

  SkillNode *auxNode = (*C->skills);
  unsigned short i = 0;

  while (auxNode != NULL) {
    i++;
    printf("\n%d) %s\n", i, auxNode->skill->name);
    printf("\t- Rango: %d\n", auxNode->skill->range);
    printf("\t- Puntos de accion: %d\n", auxNode->skill->actionCost);
    printf("\t- Energia: %d\n", auxNode->skill->energyCost);

    auxNode = auxNode->next;
  }
}

unsigned short isNotEmptyInventory(HeapItems *items) {
  return (*items) != NULL;
}

unsigned short isAlive(Character *C) {
  return C->hP > 0;
}

// void showCharacterInventory (Character C*) {
//   printf("Inventario\n");
//   printf("__________\n");

//   ItemNode *auxNode = (*C->items);

//   while (auxNode != NULL) {
//     printf("- ")
//   }
  
// }