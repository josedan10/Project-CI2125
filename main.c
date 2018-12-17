#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "headers/menus.h"
#include "headers/soHelpers.h"
#include "headers/constructors.h"
#include "headers/actions.h"
#include "headers/items.h"

// SO {1: Windows, 2: Linux}

int main(){

    CharsListR turns;
    Character *character;

	printf("Bienvenido a JUEGUITO :v\n\n");

    turns = createNewCharsListR(startGame());

    for (int i = 0; i < turns->capacity; i++) {

        character = createNewCharacter(i);
        queuePlayer(character, turns);
        free(character);
    }

    Item *item = createEnergyPotion();
    addItemsToInventory(turns->chars[0], item);

    // (*turns->chars[0]->items)->effect();

    // clearAndPrintMenu(mostrarMenuPrincipal);

    #if SO == 1
        system("PAUSE");
    #endif

    return 0;
}
