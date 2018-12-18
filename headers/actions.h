unsigned short startGame () {
	unsigned short players;
	printf("Introduzca el numero de jugadores: ");
	scanf("%hu", &players);

	return players;
}

void addItemToInventory (Character *C, Item *item) {
  ItemNode *node = (ItemNode *) malloc(sizeof(ItemNode));
  node->item = item;
  node->next = *C->items;
  *C->items = node;

  printf("\nSe ha agregado %s a tu inventario.\n", item->name);
}

void dropItemToLand (Character *C, Land *land) {

  if (isNotEmptyInventory(C->items)) {

    ItemNode *itemNode = (*C->items);
    (*C->items) = (*C->items)->next;
    addItemsToLandList(land, itemNode);

    printf("\nDejaste %s en el terreno.\n", itemNode->item->name);
  } else {
    printf("\n\nTu inventario esta vacio\n");
  }

}

// Pre: itemNode must be in land->items
void pickItemFromLand (Land *land, ItemNode *itemNode) {
  Character *myChar = land->character;

  addItemToInventory(myChar, itemNode->item);
  deleteFromLandListItems(land, itemNode);

  printf("\nSe ha guardado %s en tu inventario.\n", itemNode->item->name);
}

void useItem (Character *attacker, Land *land) {
  getTopItemFromInventory(attacker->items);
}


// Review optimization
void useSkill (Character *attacker, Map *map, Cord *cord, Skill *skill) {

  // Primero se verifica que esté en el rango de ataque.

  if (!isInRange(cord, getCharacterCords(map, attacker), skill->range)) {
    printf("\nLa casilla esta fuera de rango.\n");
    return;
  }
  
  // Para es la función isInRange
  if (isFree(map, cord)) {
    printf("\nLa casilla que intentas atacar esta vacia.\n");
    return;
  }

  if (!skillCostsValidator(attacker, skill)) {

    printf("No tienes los requisitos suficientes para atacar\n");
    return;
  }

  skill->effect(getLandWithCord(map, cord));
  reducePoints(attacker, skill);
  printf("\nAtacaste al jugador %s.\n", getLandWithCord(map, cord)->character->name);
}

void printItems(ItemNode *itemNode) {

  if (itemNode == NULL) {
    printf("[ ]\n\n");
  } else {
    ItemNode *aux = itemNode;

    printf("[ ");

    while (aux->next != NULL) printf("%s, ", aux->item->name);

    printf("%s ]\n\n", aux->item->name);

  }
}

void printEffect(TypeEffect effect) {
  switch (effect) {
    case 1:
      printf("Incendiar\n");
      break;

    case 2:
      printf("Congelar\n");
      break;
    
    case 3:
      printf("Restaurar\n");
      break;
    
    case 4:
      printf("Electrocutar\n");
      break;
  }
}

void moveCharacterToCords(Map* map, Character *C, Cord *destinyCords) {

  Cord *actualCord = getCharacterCords(map, C);

  if (movementValidator(map, actualCord, destinyCords, C)) {

    if (actualCord != NULL){
      C->aP -= abs(actualCord->col - destinyCords->col) + abs(actualCord->row - destinyCords->row);
      getLandWithCord(map, actualCord)->character = NULL;
    
    }

    changeCharacterPosition(C, getLandWithCord(map, destinyCords));
    seeLand(map, getCharacterCords(map, C));

    printf("\n\nDesplazamiento realizado a las coordenadas (%hu, %c).\n", destinyCords->row + 1, destinyCords->col);
  }
}

void waitForKeyPress() {
  #if SO == 1
    system("PAUSE");  
  #endif 
}

Character* executeAttack (Character *C, Land *land) {
  // Disminuimos los puntos de accion
  C->aP -= 2;

  if (rand() % 101 > C->evasion) {
    // No pudo evadirse el ataque
    short damageTotal = C->damage - (land->character->armor);

    if (damageTotal < 0) {
      land->character->armor -= C->damage;
    } else {
      land->character->armor = 0;
      land->character->hP -= damageTotal;
    }

    printf("\nAtacaste a %s\n", land->character->name);

    if (!isAlive(land->character)) {
      printf("\n%s fue eliminado\n", land->character->name);
      return land->character;
    }

  } else {
    printf("\nEl ataque fue evadido\n");
  }

  return NULL;
}

Character* attack(Map *map, Character *C) {
  puts("Direccion del ataque");
  Cord *cord = askForCords();

  if (attackValidator(map, C, cord)) {
    // Se puede atacar
    return executeAttack (C, getLandWithCord(map, cord));
  }

  return NULL;
}

void showTopInventory (Character *C) {

  if (isNotEmptyInventory(C->items)) {

    Item *item = getTopItemFromInventory(C->items);

    printf("En el tope tienes %s\n\n", item->name);
    printf("Detalles del item\n");
    printf("_________________\n\n");

    printf("\t- Costo: %d puntos de accion.\n", item->cost);
    printf("\t- Rango: %d.\n", item->range);
  } else {
    printf("Tu inventario esta vacio.\n");
  }
}

void getItemFromLand (Land *land, Character *C) {
  
  if ((*land->items) != NULL)
    pickItemFromLand(land, land->items[askForItem(land)]);
  else
    printf("\nNo hay items en esta area\n");
}

void inventoryActions (Map *map, Character *C) {

  unsigned short opt;

  do {

    switch (opt = showInventoryMenu(C)) {
      case 1:
        // Recoger Item
        getItemFromLand(getLandWithCord(map, getCharacterCords(map, C)), C);
        waitForKeyPress();
        break;
      
      case 2:
        // Soltar item
        dropItemToLand(C, getLandWithCord(map, getCharacterCords(map, C)));
        waitForKeyPress();
        break;

      case 3:
        // Equipar Item
        break;
      
      case 4:
        // Consultar tope
        showTopInventory(C);
        waitForKeyPress();
        break;

      case 5:
        // Volver
        if (!confirm("volver al menu principal"))
          opt = 6;
        
        // waitForKeyPress();
        break;
    }
  } while (opt != 5);
}

void removeFromTurns (CharsListR turns, Character *C) {
  
  unsigned short i = 0;
  Character *auxChar = turns->chars[i];

  while (auxChar != C) {
    auxChar = turns->chars[++i];
  }

  while (i < turns->omega) {
    turns[i] = turns[i + 1];
    i++;
  }

  turns->omega--;
  turns->tam--;
}