void showCharacterDetails (Character *C) {
  printf("\nEstadisticas:\n");
  printf("%s\n", C->name);
  printf("HP: %d\n", C->hP);
  printf("Evasion: %d\n", C->evasion);
  printf("Armadura: %d\n", C->armor);
  printf("Velocidad: %d\n", C->velocity);
  printf("Dano: %d\n", C->damage);
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
  newCharacter->armor = 100;
  newCharacter->actionPoints = 0;
  newCharacter->evasion = rand() % 101;
  newCharacter->velocity = ++velocity;
  newCharacter->damage = rand() % 60;

  showCharacterDetails(newCharacter);

  return newCharacter;
}

void queuePlayer (Character *C, CharsListR CList) {
int hab;
  Character *newChar = (Character *) malloc(sizeof(Character));

  //Clon the Character
  strcpy(newChar->name, C->name);
  newChar->armor = C->armor;
  newChar->damage = C->damage;
  newChar->eP = C->eP;
  newChar->evasion = C->evasion;
  newChar->actionPoints = C->actionPoints;
  newChar->playerId = C->playerId;
  newChar->hP = C->hP;
  newChar->velocity = C->velocity;
  newChar->items = (HeapItems *)malloc(sizeof(HeapItems));
  newChar->skills = (SkillsList *)malloc(sizeof(SkillsList));

  (*newChar->items) = NULL;
  (*newChar->skills) = NULL;

  // Create character habilities asignation

  printf("\nElige una habilidad\n");
  printf("1) Congelar\n2) Incendiar\n3) Restaurar\n4) Electrocutar\n");

  scanf("%d", &hab);
  // scanf("%d", &hab);

  printf("%d\n", hab);

  switch (hab) {
    case 1:
      printf("\nElegiste 'congelar'.\n");

      // Crear nueva habilidad

      break;

    case 2:
      printf("\nElegiste 'incendiar'.\n");

      // Crear nueva habilidad

      break;
    
    case 3:
      printf("\nElegiste 'restaurar'.\n");

      // Crear nueva habilidad

      break;
    
    case 4:
      printf("\nElegiste 'electrocutar'.\n");

      // Crear nueva habilidad

      break;
    
    default:
      printf("\nNo elegiste ninguna habilidad.\n");

      // Crear nueva habilidad

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