void heal(Land *land) {

  land->character->hP += land->character->hP * 0.3;
  printf("\n\nUsaste una pocion de salud");

  // Delete itemNode
  popItem(land->character->items);

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

  // Delete itemNode
  popItem(land->character->items);
}

Item* createEnergyPotion () {

  Item *energyPotion = (Item *) malloc(sizeof(Item));


  strcpy(energyPotion->name, "Pocion de energia");
  energyPotion->range = 0;
  energyPotion->cost = 3;
  energyPotion->effect = restoreEnergy;

  return energyPotion;
}

Item* createNullGrenade () {
  Item *nullGrenade = (Item *) malloc(sizeof(Item));


  strcpy(nullGrenade->name, "Granada nulificadora");
  nullGrenade->range = 5;
  nullGrenade->cost = 5;
  nullGrenade->effect = none;

  return nullGrenade;
}

void nullGrenade(Land *land) {
  land->effect = none;
  printf("\n\nUsaste una granada nulificadora");

  // Delete itemNode
  popItem(land->character->items);
}