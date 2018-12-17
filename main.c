#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#include "headers/structs.h"
#include "headers/menus.h"
#include "headers/land.h"
#include "headers/constructors.h"
#include "headers/soHelpers.h"
#include "headers/actions.h"
#include "headers/items.h"

// SO {1: Windows, 2: Linux}

int main(){

    CharsListR turns;
    Character *character;
    Land *land = createLand();

	printf("Bienvenido a JUEGUITO :v\n\n");

    turns = createNewCharsListR(startGame());

    for (int i = 0; i < turns->capacity; i++) {

        character = createNewCharacter(i);
        queuePlayer(character, turns);
        free(character);
    }

    Item *item = createEnergyPotion();
    addItemToInventory (turns->chars[0], item);

    printf("\nNombre de la Poción: %s", (*turns->chars)->items->item->name);
    (*turns->chars)->items->item->effect((*turns->chars));

    dropItemToLand(turns->chars[0], land);

    // clearAndPrintMenu(mostrarMenuPrincipal);

    #if SO == 1
        system("PAUSE");
    #endif

    return 0;
}
