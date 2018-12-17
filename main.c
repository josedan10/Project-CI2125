#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "headers/menus.h"
#include "headers/soHelpers.h"
#include "headers/constructors.h"
#include "headers/actions.h"

// SO {1: Windows, 2: Linux}

int main(){

    CharsListR turnos;
    Character *character;

	printf("Bienvenido a JUEGUITO :v\n\n");

    turnos = createNewCharsListR(startGame());

    for (int i = 0; i < turnos->capacity; i++) {

        character = createNewCharacter(i);
        queuePlayer(character, turnos);
        free(character);
    }

    clearAndPrintMenu(mostrarMenuPrincipal);

    #if SO == 1
        system("PAUSE");
    #endif

    return 0;
}
