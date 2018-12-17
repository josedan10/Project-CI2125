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

    Character *character;
    Land *land;
    Cord *randomCord;
    CharsListR turns = createNewCharsListR(startGame());
    Map *map = createMap();

    srand(time(NULL));

	printf("Bienvenido a JUEGUITO :v\n\n");

    for (int i = 0; i < turns->capacity; i++) {

        printf("Jugador %d/%d", i + 1, turns->capacity);

        character = createNewCharacter(i);
        queuePlayer(character, turns);

        // Random positions for players
        do {
            randomCord = createCord(65 + rand() % ((65 + 19) + 1 - 65), 1 + rand() % (10 + 1 - 1));

        } while (!isFree(map, randomCord));

        moveCharacterToCords(map, NULL, randomCord);
        free(character);
    }


    if (isFree(map, createCord('A', 1))) printf("\nEsta casilla esta desocupada\n");
    else printf("\nEsta casilla esta ocupada\n");

    addItemToInventory (turns->chars[0], createEnergyPotion());
    addItemToInventory (turns->chars[0], createHealthPotion());

    Item *item = getTopItemFromInventory(turns->chars[0]->items);
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
