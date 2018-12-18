/* typedef struct skill {
 * 	char name[16];
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

    strcpy(skill->name, "Congelar");
    skill->energyCost = 4;
    skill->actionCost = 4;
    skill->range = 3;
    skill->effect = freeze;

    return skill;
}

Skill* createFireSkill(){               //Incendia la casilla objetivo y causa 30% de da�o a los puntos de salud
                                   //ACTUALES del personaje parado sobre el terreno objetivo.
    Skill *skill = (Skill *) malloc(sizeof(Skill));

    strcpy(skill->name, "Incendiar");
    skill->energyCost = 2;
    skill->actionCost = 7;
    skill->range = 3;
    skill->effect = restore;

    return skill;

}

Skill* createRestoreSkill(){             //Cura el 30% de los puntos de salud del personaje
                                //que se encuentre parado sobre el terreno objetivo.
    Skill *skill = (Skill *) malloc(sizeof(Skill));
    strcpy(skill->name, "Restaurar");
    skill->energyCost = 5;
    skill->actionCost = 4;
    skill->range = 2;
    skill->effect = restore;

    return skill;
}

Skill *createElectrocuteSkill(){         //Electrifica la casilla objetivo y elimina el 50% de la cantidad de puntos de energ�a TOTAL
                                //del personaje parado sobre el terreno objetivo
    Skill *skill = (Skill *) malloc(sizeof(Skill));
    strcpy(skill->name, "Electrocutar");
    skill->energyCost = 10;
    skill->actionCost = 5;
    skill->range = 4;
    skill->effect = electrocute;

    return skill;
}

unsigned short addToSkills (Character *C, Skill *skill) {

  SkillNode *skillNode = (SkillNode *) malloc(sizeof(SkillNode));
  skillNode->skill = skill;

  // Agregar al inicio
  if ((*C->skills) == NULL || strcmp(skill->name, (*C->skills)->skill->name)) {
    skillNode->next = (*C->skills);
    (*C->skills) = skillNode;


  } else {

    SkillNode *auxSkill = (*C->skills);

    // Insertar ordenadamente
    while (auxSkill->next != NULL && strcmp(skill->name, auxSkill->skill->name) > 0)
      auxSkill = auxSkill->next;

    if (auxSkill->next == NULL || strcmp(skill->name, auxSkill->skill->name) > 0) {

      skillNode->next = auxSkill->next;
      auxSkill->next = skillNode;

    } else {

      return 0;
    }
  }

  return 1;

}

void reducePoints (Character *C, Skill *skill) {
  C->aP -= skill->actionCost;
  C->eP -= skill->energyCost;
}
