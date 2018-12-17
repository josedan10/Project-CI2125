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

void popItem(HeapItems *items) {

  //delete ItemNode from Inventory
  ItemNode *aux = *items;
  *items = (*items)->next;

  free(aux);  
}