#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define ASCII_A 65
#define ASCII_T 84
#include "headers/soHelpers.h"

void waitForKeyPress() {
  #if SO == 1
    system("PAUSE");  
  #endif 
}

unsigned short inputIntValidator(char *);
unsigned short inputRange(int, int, int);

#include "headers/structs.h"
#include "headers/effects.h"
#include "headers/skills.h"
#include "headers/characters.h"
#include "headers/land.h"
#include "headers/map.h"
#include "headers/items.h"
#include "headers/validators.h"
#include "headers/menus.h"
#include "headers/getters.h"
#include "headers/actions.h"

int main(){

	printf("Bienvenido a JUEGUITO :v\n\n");

    Character *character, *isDead;
    Cord *randomCord;
    Land *land;
    unsigned short isInGame = 1, turnCounter = 0, notFinishTurn;
    CharsListR turns = createNewCharsListR(startGame());
    Map *map = createMap();

    createRandomItemsInMap(map);

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
        notFinishTurn = 1;
        
        do {
            
            switch (showMainMenu(map, character)) {
                case 1:
                    // Ver mapa
                    clearScreen();
                    printMap(map);
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
                    isDead = attack(map, character);

                    if (isDead != NULL) {
                        removeFromTurns(turns, isDead);
                    }

                    if (turns->tam == 1) printf("\nEL GANADOR ES %s\n", character->name);

                    waitForKeyPress();
                    break;

                case 4:
                    // Moverse
                    clearScreen();
                    moveCharacterToCords(map, character, askForCords());
                    waitForKeyPress();
                    break;

                case 5:
                    // Usar habilidad
                    clearScreen();
                    isDead = useSkill(character, map, askForCords(), askForSkillToUse(map, character));

                    if (isDead != NULL) {
                        removeFromTurns(turns, isDead);
                    }

                    if (turns->tam == 1) printf("\nEL GANADOR ES %s\n", character->name);
                    
                    waitForKeyPress();
                    break;

                case 6:
                    // Usar item
                    clearScreen();
                    isDead =  useItem(character, getLandWithCord(map, askForCords()));

                    if (isDead != NULL) {
                        removeFromTurns(turns, isDead);
                    }

                    if (turns->tam == 1) printf("\nEL GANADOR ES %s\n", character->name);
                    
                    waitForKeyPress();
                    break;
                    waitForKeyPress();
                    break;

                case 7:
                    // Terminar turno
                    clearScreen();
                    if (confirm("terminar turno"))
                        notFinishTurn = 0;

                    waitForKeyPress();
                    break;

                case 8:
                    // Inventario
                    clearScreen();
                    // showCharacterInventory(Character *C);
                    inventoryActions(map, character);
                    waitForKeyPress();
                    break;

                case 9:
                    // Menu de sistema
                    notFinishTurn = resolveSystemMenu();
                    isInGame = notFinishTurn;
                    break;
                    
            }
            
        } while (character->aP > 0 && notFinishTurn);

        turnCounter++;

        if (turnCounter == turns->capacity) turnCounter = turns->alfa;

        character = turns->chars[turnCounter];
        printf("\nHa terminado tu turno\n");
        waitForKeyPress();
    } while (isInGame);

    printf("\n\nEl juego ha terminado\n");
    
    waitForKeyPress();
}
