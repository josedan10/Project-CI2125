/* typedef struct skill {
 * 	char nombre[16];
 * 	unsigned short energyCost;
 * 	unsigned short actionCost;
 * 	unsigned short range;
 * 	void(*effect)();
 *
 * } Skill;
 */

Skill* createFreezeSkill(){             //Congela la casilla objetivo y reduce a cero los puntos de acci�n
                                //que tenga el personaje parado sobre el terreno objetivo
    Skill *skill = (Skill *) malloc(sizeof(Skill));

    strcpy(skill->nombre, "Congelar");
    skill->energyCost = 4;
    skill->actionCost = 4;
    skill->range = 3;
    skill->effect = freeze;

    return skill;
}

Skill* createFireSkill(){               //Incendia la casilla objetivo y causa 30% de da�o a los puntos de salud
                                   //ACTUALES del personaje parado sobre el terreno objetivo.
    Skill *skill = (Skill *) malloc(sizeof(Skill));

    strcpy(skill->nombre, "Incendiar");
    skill->energyCost = 2;
    skill->actionCost = 7;
    skill->range = 3;
    skill->effect = restore;

    // if((skill->energyCost) >= 2 && (skill->actionCost) >= 7){

    // }
    // else printf("\n\nNo tienes suficientes puntos para realizar esta accion");

    return skill;

}

Skill* createRestoreSkill(){             //Cura el 30% de los puntos de salud del personaje
                                //que se encuentre parado sobre el terreno objetivo.
    Skill *skill = (Skill *) malloc(sizeof(Skill));
    strcpy(skill->nombre, "Restaurar");
    skill->energyCost = 5;
    skill->actionCost = 4;
    skill->range = 2;
    skill->effect = restore;

    return skill;

    // if((skill->energyCost) >= 5 && (skill->actionCost) >= 4){


    // }
    // else printf("\n\nNo tienes suficientes puntos para realizar esta accion");

}

void HabElectrocutar(){         //Electrifica la casilla objetivo y elimina el 50% de la cantidad de puntos de energ�a TOTAL
                                //del personaje parado sobre el terreno objetivo
    Skill *skill = (Skill *) malloc(sizeof(Skill));
    strcpy(skill->nombre, "Electrocutar");
    skill->energyCost = 10;
    skill->actionCost = 5;
    skill->range = 4;

    return skill;

    // if((skill->energyCost) >= 10 && (skill->actionCost) >= 5){


    // }
    // else printf("\n\nNo tienes suficientes puntos para realizar esta accion");
}
