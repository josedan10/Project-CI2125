unsigned short startGame () {
	unsigned short players;
	printf("Introduzca el numero de jugadores: ");
	scanf("%hu", &players);

	return players;
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

void addItemToInventory (Character *C, Item *item) {
  ItemNode *node = (ItemNode *) malloc(sizeof(ItemNode));
  node->item = item;
  node->next = *C->items;
  *C->items = node;

  printf("\nSe ha añadido %s a tu inventario.\n", item->name);
}

void dropItemToLand (Character *C, Land *land) {
  ItemNode *itemNode = (*C->items);
  (*C->items) = (*C->items)->next;

  addItemsToLandList(land, itemNode);

  printf("Dejaste %s en el terreno.\n", itemNode->item->name);
}

// Pre: itemNode must be in land->items
void pickItemFromLand (Land *land, ItemNode *itemNode) {
  Character *myChar = land->character;

  addItemToInventory(myChar, itemNode->item);
  deleteFromLandListItems(land, itemNode);

  printf("Se ha guardado %s en tu inventario.\n", itemNode->item->name);
}