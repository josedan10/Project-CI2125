unsigned short skillCostsValidator (Character *C, Skill *skill) {

  // If this return 1 you can attack  
  return (C->aP > skill->actionCost && C->eP > skill->energyCost);
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