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