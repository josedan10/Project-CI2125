#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#include "headers/soHelpers.h"
#include "headers/structs.h"
#include "headers/effects.h"
#include "headers/menus.h"
#include "headers/skills.h"
#include "headers/characters.h"
#include "headers/land.h"
#include "headers/map.h"
#include "headers/items.h"
#include "headers/actions.h"

int main(){

    CharsListR turns;
    Character *character;
    Land *land = createLand();
    Map *map = createMap();

	printf("Bienvenido a JUEGUITO :v\n\n");

    turns = createNewCharsListR(startGame());

    for (int i = 0; i < turns->capacity; i++) {

        character = createNewCharacter(i);
        queuePlayer(character, turns);
        free(character);
    }

    if (isFree(land)) printf("\nEsta casilla esta desocupada\n");
    else printf("\nEsta casilla esta ocupada\n");

    addItemToInventory (turns->chars[0], createEnergyPotion());
    addItemToInventory (turns->chars[0], createHealthPotion());
    land->character = turns->chars[0];

    if (isFree(land)) printf("\nEsta casilla esta desocupada\n");
    else printf("\nEsta casilla esta ocupada\n");


    // testing effect
    (*(*turns->chars)->items)->item->effect(land);

    switch(confirm("dejar este item en el terreno")) {

        case 1:
            dropItemToLand(turns->chars[0], land);
            break;

        case 2:
            printf("Accion cancelada");
            break;
    }


    // clearAndPrintMenu(mostrarMenuPrincipal);

    #if SO == 1
        system("PAUSE");
    #endif

    return 0;
}
