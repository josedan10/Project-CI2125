unsigned short startGame () {
	unsigned short players;
  char preValidator[5]; 

  do {
	  printf("Introduzca el numero de jugadores: ");
    scanf("%s", preValidator);

    if (!inputIntValidator(preValidator)) {
      printf("\nERROR: Debes un introducir un numero\n");
      waitForKeyPress();
    }

    clearScreen();

  } while (!inputIntValidator(preValidator));

	players = atoi(preValidator);
	return players;
}

void addItemToInventory (Character *C, ItemNode *node) {
  node->next = *C->items;
  *C->items = node;

  printf("\nSe ha agregado %s a tu inventario.\n", node->item->name);
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

void reduceItemPoints (Character *C, Item *item) {
  C->aP -= item->cost;
}

// Pre: itemNode must be in land->items
void pickItemFromLand (Land *land, ItemNode *itemNode, unsigned short isFirst) {
  Character *myChar = land->character;
  ItemNode *inventoryItem = createItemNode();

  if (isFirst)
    inventoryItem->item = itemNode->item;
  else
    inventoryItem->item = itemNode->next->item;

  inventoryItem->next = NULL;

  deleteFromLandListItems(land, itemNode, isFirst);
  addItemToInventory(myChar, inventoryItem);

}

Character* useItem (Map *map, Character *attacker, Cord *cord) {

  if (itemValidator(map, attacker, cord)) {
    Item *item = getTopItemFromInventory(attacker->items);
    Land *land = getLandWithCord(map, cord);

    if (strcmp(item->name, "Restaurar")) {
      item->effect(land);
    } 
    else {
      
      if (rand() % 100 > land->character->evasion) {
        // No evadió
        item->effect(land);
        printf("\n%s fue afectado por %s\n", land->character->name, item->name);

      } else {

        printf("\nTu item fue evadido\n");
      }
    }

    reduceItemPoints(attacker, item);
    return (land->character->hP <= 0) ? land->character : NULL;
  }

  return NULL;

}


// Review optimization
Character* useSkill (Character *attacker, Map *map, Cord *cord, Skill *skill) {


  if (skillCostsValidator(map, attacker, cord, skill)) {

    if (rand() % 100 > getLandWithCord(map, cord)->character->evasion) {

      skill->effect(getLandWithCord(map, cord));
      printf("\nAtacaste al jugador %s.\n", getLandWithCord(map, cord)->character->name);

    } else
      printf("\nLa habilidad fue esquivada.\n");

    reducePoints(attacker, skill);
  } else
    printf("No tienes los requisitos suficientes para atacar\n");

  return (getLandWithCord(map, cord)->character != NULL && getLandWithCord(map, cord)->character->hP <= 0) ? getLandWithCord(map, cord)->character : NULL ;

} 

void printItems(ItemNode *itemNode, unsigned short type) {
  unsigned short i = 1;

  switch (type) {
    case 1:

      if (itemNode == NULL) {
        printf("[ ]\n\n");
      } else {
        ItemNode *aux = itemNode;

        printf("[ ");

        while (aux->next != NULL) {

          if (i % 6 == 0)
            printf("%s,\n", aux->item->name);
          else
            printf("%s, ", aux->item->name);

          aux = aux->next;
        }

        printf("%s ]\n\n", aux->item->name);

      }
      break;
    
    default:

      if (itemNode == NULL) {
        printf("No hay items\n\n");
      } else {
        ItemNode *aux = itemNode;

        printf("Lista de items\n");
        printf("______________\n");

        while (aux->next != NULL) {
          printf("\t%d) %s\n",i++, aux->item->name);
          aux = aux->next;
        }

        printf("\t%d) %s\n",i++, aux->item->name);

      }

      break;
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
      C->aP -= (abs(actualCord->col - destinyCords->col) > abs(actualCord->row - destinyCords->row)) ? abs(actualCord->col - destinyCords->col) : abs(actualCord->row - destinyCords->row);
      getLandWithCord(map, actualCord)->character = NULL;
    
    }

    changeCharacterPosition(C, getLandWithCord(map, destinyCords));
    seeLand(map, getCharacterCords(map, C));

    printf("\n\nDesplazamiento realizado a las coordenadas (%hu, %c).\n", destinyCords->row + 1, destinyCords->col);
  }
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
  
  if ((*land->items) != NULL) {

    unsigned short itemIndex = askForItem(land) - 1;
    ItemNode *itemAuxNode = (*land->items);
    ItemNode *auxNode = (*land->items);


    switch (itemIndex) {
      case 0:
        // Esta de primero
        pickItemFromLand(land, itemAuxNode, 1);
        break;

      default:

        while (itemIndex != 0) {
          itemAuxNode = itemAuxNode->next;
          itemIndex--;
        }

        while (itemAuxNode != auxNode->next) auxNode = auxNode->next;

        pickItemFromLand(land, auxNode, 0);

        break;
    }

    
    
  }
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

void removeFromTurns (Map *map, CharsListR *turns, Character *C) {
  
  unsigned short i = 0;
  Character *auxChar = (*turns)->chars[i];

  while (auxChar != C) {
    auxChar = (*turns)->chars[++i];
  }

  while (i < (*turns)->omega) {
    (*turns)->chars[i] = (*turns)->chars[i + 1];
    i++;
  }

  (*turns)->omega--;
  (*turns)->tam--;
  
  free(C);
  getLandWithCord(map, getCharacterCords(map, C))->character = NULL;
}

unsigned short resolveSystemMenu () {
  switch(clearAndPrintMenu(showSystemMenu)) {
    case 1:
      // Cargar
      break;
    
    case 2:
      // Guardar
      break;

    case 4:
      // Salir
      
      return !confirm("salir del juego");
      break;

  }
}

Character* cloneCharacter (Character *C) {
  Character *auxChar = (Character *) malloc(sizeof(Character));

  strcpy(auxChar->name, C->name);
  auxChar->aP = C->aP;
  auxChar->armor = C->armor;
  auxChar->damage = C->damage;
  auxChar->eP = C->eP;
  auxChar->evasion = auxChar->evasion;
  auxChar->hP = C->hP;
  auxChar->items = C->items;
  auxChar->playerId = C->playerId;
  auxChar->range = C->range;
  auxChar->skills = C->skills;
  auxChar->velocity = C->velocity;

  return auxChar;
}

void swap(Character *C1, Character *C2) {
  Character *auxCharacter = cloneCharacter(C1);
  C1 = C2;
  C2 = cloneCharacter(auxCharacter);
  free(auxCharacter);
}

void orderTurns (CharsListR *turns) {
  unsigned short n = (*turns)->tam, j;

  for (unsigned short i = 1; i < n; i++) {

    // insert i'th element A[i] into the already sorted A[1...i-1]

    // keep swapping the value in A[i] with previous element 
    // till it "bubbles" down the right place
    // (i.e. keep swapping till the previos element is smaller)

    j = i;

    while (j > 0 && (*turns)->chars[j - 1]->velocity > (*turns)->chars[j]->velocity) { // when i=1 there is no prev element
      swap( (*turns)->chars[j], (*turns)->chars[j - 1] );
      j--;

    } 
  }

}