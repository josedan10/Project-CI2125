unsigned short skillCostsValidator (Map *map, Character *attacker, Cord *cord, Skill *skill) {

  unsigned short validator = 1;

  // Primero se verifica que esté en el rango de ataque.

  if (!isInRange(cord, getCharacterCords(map, attacker), skill->range)) {
    printf("\nLa casilla esta fuera de rango.\n");
    validator = 0;

  } else if (isFree(map, cord)) {
    printf("\nLa casilla que intentas atacar esta vacia.\n");
    validator = 0;

  } else if (attacker->aP < skill->actionCost && attacker->eP < skill->energyCost) {
    printf("\nNo tienes los requisitos suficientes para atacar");
    validator = 0;
  }

  return validator;
}

unsigned short attackValidator (Map *map, Character *C, Cord *targetCord) {

  unsigned short attack = 1;

  if (!isInRange(targetCord, getCharacterCords(map, C), C->range)) {
  
    printf("\nNo tienes el rango suficiente para atacar esta casilla\n");
    attack = 0;

  } else if (isFree(map, targetCord)) {
    printf("\nNo hay enemigos en esta casilla\n");
    attack = 0;

  } else if (C->aP < 2) {
    printf("\nNo tienes suficientes puntos de accion\n");
    attack = 0;

  }

  return attack;
}

unsigned short movementValidator (Map *map, Cord *actual, Cord *destiny, Character *C) {

  if (actual == NULL) return 1;

  if (!isFree(map, destiny)) {

    printf("\n\nMOVIMIENTO NO PERMITIDO: No puedes moverte a estas coordenadas. Ya hay un jugador en ese lugar.\n");
    return 0;

  } else if (abs(actual->col - destiny->col) + abs(actual->row - destiny->row) > C->aP) {
    printf("\n\nMOVIMIENTO NO PERMITIDO: Necesitas mas puntos de accion\n");
    return 0;

  }
   
  return 1;
}

unsigned short itemValidator (Map *map, Character *C, Cord *targetCord) {
  unsigned short validator = 1;

  if (!isNotEmptyInventory(C->items)) {
    printf("\nTu inventario esta vacio\n");
    validator = 0;

  } else if (!isInRange(getCharacterCords(map, C), targetCord, (*C->items)->item->range)) {
    printf("\nLa casilla elegida no esta en el rango de uso del item\n");
    validator = 0;
  } else if ((*C->items)->item->cost > C->aP) {
    printf("\nNo tienes suficientes puntos de accion\n");
    validator = 0;
  }

  return validator;
}

unsigned short inputIntValidator (char *a) {
  int max = strlen(a), i;

  while (i < max && isdigit(a[i])) i++;

  return i == max;
}

unsigned short inputRange (int i, int limitInf, int limitSup) {
  return i > limitInf && i < limitSup;
}