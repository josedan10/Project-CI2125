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
  ItemNode *itemNode = (*C->items);
  (*C->items) = (*C->items)->next;

  addItemsToLandList(land, itemNode);

  printf("\nDejaste %s en el terreno.\n", itemNode->item->name);
}

// Pre: itemNode must be in land->items
void pickItemFromLand (Land *land, ItemNode *itemNode) {
  Character *myChar = land->character;

  addItemToInventory(myChar, itemNode->item);
  deleteFromLandListItems(land, itemNode);

  printf("\nSe ha guardado %s en tu inventario.\n", itemNode->item->name);
}

unsigned short isInRange(Cord *target, Cord *cord, unsigned short range) {

  return range > abs(target->col - cord->col) && range > abs(target->row - cord->row);

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

    printf("No tienes los requisitos suficientes para atacar");
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

void seeLand (Map *map, Cord *cord) {
  Land *land = getLandWithCord(map, cord);
  Character *C = land->character;

  printf("\nDetalles del Terreno (%hu, %c)\n\n", cord->row + 1, cord->col);

  printf("Personaje\n");
  printf("_________\n\n");
  showCharacterDetails(map, C);

  printf("Items\n");
  printf("_____\n\n");
  printItems(land->items);

  printf("Efectos\n");
  printf("_______\n\n");
  printEffect(land->effect);
}

void moveCharacterToCords(Map* map, Character *C, Cord *destinyCords) {
  if (isFree(map, destinyCords)) {

    Land *land = getLandWithCord(map, destinyCords);
    changeCharacterPosition(C, getLandWithCord(map, destinyCords));

    seeLand(map, getCharacterCords(map, C));

    printf("\n\nDesplazamiento realizado a las coordenadas (%hu, %c).\n", destinyCords->row + 1, destinyCords->col);

  } else {

    printf("\n\nMOVIMIENTO NO PERMITIDO: No puedes moverte a estas coordenadas. Ya hay un jugador en ese lugar.\n");
  }
}

void waitForKeyPress() {
  #if SO == 1
    system("PAUSE");  
  #endif 
}

void attack(Map *map, Character *C) {
  puts("Direccion del ataque");
  Cord *cord = askForCords();

  if (isInRange(cord, getCharacterCords(map, C), C->range)) {
    // attack
  }

}