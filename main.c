#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#include "headers/soHelpers.h"
#include "headers/structs.h"
#include "headers/menus.h"
#include "headers/characters.h"
#include "headers/land.h"
#include "headers/items.h"
#include "headers/actions.h"

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
    Item *item2 = createHealthPotion();

    addItemToInventory (turns->chars[0], item);
    addItemToInventory (turns->chars[0], item2);
    land->character = turns->chars[0];


    // testing effect
    (*(*turns->chars)->items)->item->effect(land);

    dropItemToLand(turns->chars[0], land);

    // clearAndPrintMenu(mostrarMenuPrincipal);

    #if SO == 1
        system("PAUSE");
    #endif

    return 0;
}
