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

  printf("\nEstadisticas:\n");
  printf("%s\n", newCharacter->name);
  printf("HP: %d\n", newCharacter->hP);
  printf("Evasion: %d\n", newCharacter->evasion);
  printf("Armadura: %d\n", newCharacter->armor);
  printf("Velocidad: %d\n", newCharacter->velocity);
  printf("Dano: %d\n", newCharacter->damage);

  return newCharacter;
}
