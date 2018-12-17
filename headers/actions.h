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

unsigned short isInRange(Land *target, Land *actualPos) {



}

void attack () {
  
}