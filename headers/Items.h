void heal(Character *C) {

  C->hP += C->hP * 0.3;
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

void restoreEnergy(Character *C) {

  C->eP += C->eP * 0.3;
}

Item* createEnergyPotion () {

  Item *energyPotion = (Item *) malloc(sizeof(Item));


  strcpy(energyPotion->name, "Pocion de energia");
  energyPotion->range = 0;
  energyPotion->cost = 3;
  energyPotion->effect = restoreEnergy;

  return energyPotion;
}