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

// unsigned short isInRange(Map *map, Land *target, Cord *cord) {

//   Land *auxTarget = NULL;
//   Land *auxActualPos = NULL;
//   Land *auxPointer;
//   char colLetter;
//   unsigned short rowNum, i, j;

//   while (unsigned short i = 0; i < 20; i ++) {
//     // recorremos primero las columnas
//     for (unsigned short j = 0; j < 10; j++) {

//       auxPointer = map->cols[i]->lands[j] 
    
//     }

//   }

// }

void attack (Character *attacker, Map *map, Cord *cord, Skill *skill) {

  // Primero se verifica que esté en el rango de ataque.
  // Para es la función isInRange
  if (isFree(map, cord)) {
    printf("\nLa casilla que intentas atacar esta vacia.\n");
    return;
  }

  if (!skillCostsValidator(attacker, skill)) {

    printf("No tienes los requisitos suficientes para atacar");
    return;
  }

  printf("Atacaste");  
}