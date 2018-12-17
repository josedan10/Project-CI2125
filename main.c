#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define ASCII_A 65

#include "headers/soHelpers.h"
#include "headers/structs.h"
#include "headers/effects.h"
#include "headers/skills.h"
#include "headers/characters.h"
#include "headers/land.h"
#include "headers/map.h"
#include "headers/items.h"
#include "headers/menus.h"
#include "headers/actions.h"

int main(){

    CharsListR turns;
    Character *character;
    Land *land;
    Map *map = createMap();

	printf("Bienvenido a JUEGUITO :v\n\n");

    turns = createNewCharsListR(startGame());

    for (int i = 0; i < turns->capacity; i++) {

        character = createNewCharacter(i);
        queuePlayer(character, turns);
        free(character);
    }

    if (isFree(map, createCord('A', 1))) printf("\nEsta casilla esta desocupada\n");
    else printf("\nEsta casilla esta ocupada\n");

    addItemToInventory (turns->chars[0], createEnergyPotion());
    addItemToInventory (turns->chars[0], createHealthPotion());
    map->cols[0]->lands[0]->character = turns->chars[0];
    map->cols[1]->lands[1]->character = turns->chars[1];

    land = map->cols[0]->lands[0];

    if (isFree(map, createCord('A', 1))) printf("\nEsta casilla esta desocupada\n");
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

    seeLand(map, createCord('A', 1));

    turns->chars[0]->aP = 20;

    useSkill(turns->chars[0], map, createCord('B', 2), turns->chars[0]->skills[0]->skill);

    moveCharacterToCords(map, getCharacterCords(map, turns->chars[0]), createCord('B', 1));


    // clearAndPrintMenu(mostrarMenuPrincipal);

    #if SO == 1
        system("PAUSE");
    #endif

    return 0;
}
