void heal(Land *land) {

  land->character->hP += land->character->hP * 0.3;
  printf("\n\nUsaste una pocion de salud");

}

Item* createHealthPotion () {

  Item *healthPotion = (Item *) malloc(sizeof(Item));


  strcpy(healthPotion->name, "Pocion de salud");
  healthPotion->range = 0;
  healthPotion->cost = 3;
  healthPotion->effect = heal;

  return healthPotion;
}

void restoreEnergy(Land *land) {

  land->character->eP += land->character->eP * 0.3;
  printf("\n\nUsaste una pocion de energia");

}

Item* createEnergyPotion () {

  Item *energyPotion = (Item *) malloc(sizeof(Item));


  strcpy(energyPotion->name, "Pocion de energia");
  energyPotion->range = 0;
  energyPotion->cost = 3;
  energyPotion->effect = restoreEnergy;

  return energyPotion;
}

void nullGrenade(Land *land) {
  land->effect = none;
  printf("\n\nUsaste una granada nulificadora");

}

Item* createNullGrenade () {
  Item *nullGrenade = (Item *) malloc(sizeof(Item));


  strcpy(nullGrenade->name, "Granada nulificadora");
  nullGrenade->range = 5;
  nullGrenade->cost = 5;
  nullGrenade->effect = nullGrenade;

  return nullGrenade;
}

ItemNode* createItemNode (){
  ItemNode *node = (ItemNode *) malloc(sizeof(ItemNode));
  node->item = NULL;
  node->next = NULL;
  return node;
}

Item* getTopItemFromInventory(HeapItems *items) {
  return (*items)->item;
}

void createRandomItemsInMap (Map *map) {
  srand(time(NULL));

  unsigned short totalItems = rand() % 14 + 1;
  Land *randomLand;
  ItemNode *itemNode;

  for (unsigned short i = 0; i < totalItems; i++) {
    randomLand = getLandWithCord(map, createCord((char) (rand() % 20 + 65), rand() % 9 + 1));
    itemNode = createItemNode();

    switch (rand() % 3) {
      case 0:
        // Pocion restauradora
        itemNode->item = createHealthPotion();
        break;

      case 1:
        // Pocion energizante
        itemNode->item = createEnergyPotion();
        break;

      case 2:
        // Granada nulificadora
        itemNode->item = createNullGrenade();
        break;
    }

    addItemsToLandList(randomLand, itemNode);
  }
}