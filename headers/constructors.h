#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structs.h"

Character* createNewPlayer(int velocity) {
  
  int hab;
  Character *newCharacter = (Character*) malloc(sizeof(Character));
  srand(time(NULL));

  printf("\nDefine un nombre para tu personaje (maximo 15 caracteres): ");
  scanf("%*c%[^\n]", newCharacter->name);

  printf("\nElige una habilidad\n");
  printf("1) Congelar\n2) Incendiar\n3) Restaurar\n4) Electrocutar\n");
  
  scanf("%d", &hab);
  // scanf("%d", &hab);

  printf("%d\n", hab);

  newCharacter->hP = 100;
  newCharacter->eP = 100;
  newCharacter->armor = 100;
  newCharacter->actionPoints = 0;
  newCharacter->evasion = rand() % 100;
  newCharacter->velocity = velocity;
  newCharacter->damage = rand() % 60;
  
  switch (hab) {
    case 1:
      printf("\nElegiste 'congelar'.\n");

      // Crear nueva habilidad

      break;

    case 2:
      printf("\nElegiste 'incendiar'.\n");

      // Crear nueva habilidad

      break;
    
    case 3:
      printf("\nElegiste 'restaurar'.\n");

      // Crear nueva habilidad

      break;
    
    case 4:
      printf("\nElegiste 'electrocutar'.\n");

      // Crear nueva habilidad

      break;
    
    default:
      printf("\nNo elegiste ninguna habilidad.\n");

      // Crear nueva habilidad

      break;
  }

  printf("\nEstadisticas:\n");
  printf("%s\n", newCharacter->name);
  printf("HP: %d\n", newCharacter->hP);
  printf("Evasion: %d\n", newCharacter->evasion);
  printf("Armadura: %d\n", newCharacter->armor);
  printf("Velocidad: %d\n", newCharacter->velocity);
  printf("Dano: %d\n", newCharacter->damage);

  return newCharacter;

}