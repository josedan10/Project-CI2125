#include <stdio.h>
#include <stdlib.h>
#include "headers/menus.h"
#include "headers/constructors.h"

// SO {1: Windows, 2: Linux}
#define SO 1

int main(){

    unsigned short players;
    Character *character;

	printf("Bienvenido a JUEGUITO :v\n\n");

    players = iniciarJuego();

    // for (int i = 0; i < players; i++) {

    // }

    character = createNewPlayer(1);

    #if SO == 1
        system("PAUSE");
    #endif

    return 0;
}
