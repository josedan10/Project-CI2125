#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define ASCII_A 65
#define ASCII_T 84

#include "headers/soHelpers.h"
#include "headers/structs.h"
#include "headers/effects.h"
#include "headers/skills.h"
#include "headers/characters.h"
#include "headers/land.h"
#include "headers/map.h"
#include "headers/items.h"
#include "headers/menus.h"
#include "headers/validators.h"
#include "headers/getters.h"
#include "headers/actions.h"

int main(){

	printf("Bienvenido a JUEGUITO :v\n\n");

    Character *character;
    Land *land;
    Cord *randomCord;
    unsigned short isInGame = 1, turnCounter = 0, finishTurn;
    CharsListR turns = createNewCharsListR(startGame());
    Map *map = createMap();

    // User options;
    unsigned short opt;

    srand(time(NULL));


    for (int i = 0; i < turns->capacity; i++) {

        printf("Jugador %d/%d", i + 1, turns->capacity);

        character = createNewCharacter(i);
        queuePlayer(character, turns);

        // Random positions for players
        do {
            randomCord = createCord(65 + rand() % (84 + 1 - 65), 1 + rand() % 10);

        } while (!isFree(map, randomCord));

        moveCharacterToCords(map, turns->chars[i], randomCord);
        free(character);
        waitForKeyPress();
        clearScreen();
    }

    character = turns->chars[turnCounter];
    do {

        character->aP += 5;
        finishTurn = 0;
        
        do {
            
            switch (showMainMenu(character)) {
                case 1:
                    // Ver mapa
                    clearScreen();
                    // printMap();
                    waitForKeyPress();
                    break;

                case 2:
                    // Consultar casilla
                    clearScreen();
                    seeLand(map, askForCords());
                    waitForKeyPress();
                    break;
                
                case 3:
                    // Atacar
                    clearScreen();
                    attack(map, character);
                    waitForKeyPress();
                    break;

                case 4:
                    // Moverse
                    clearScreen();
                    moveCharacterToCords(map, character, askForCords());

                case 5:
                    // Usar habilidad
                    clearScreen();
                    useSkill(character, map, askForCords(), askForSkillToUse(map, character));
                    waitForKeyPress();
                    break;

                case 6:
                    // Usar item
                    clearScreen();
                    land = getLandWithCord(map, askForCords());
                    useItem(character, land);
                    waitForKeyPress();
                    break;

                case 7:
                    // Terminar turno
                    clearScreen();
                    if (confirm("terminar turno"))
                        finishTurn = 1;

                    waitForKeyPress();
                    break;

                case 8:
                    // Inventario
                    clearScreen();
                    // showCharacterInventory(Character *C);
                    inventoryActions(map, character);
                    waitForKeyPress();
                    break;                    
            }

            clearScreen();
            
        } while (character->aP > 0 || finishTurn);

        turnCounter++;

        if (turnCounter == turns->capacity) turnCounter = 0;

        character = turns->chars[turnCounter];
        // waitForKeyPress();
    } while (isInGame);
    
    #if SO == 1
        system("PAUSE");
    #endif

    return 0;
}
