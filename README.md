# Project-CI2126 (RPG-Game)  

### Save Game  

**Players.txt** 

~~_Num. players-_: 3~~

| PlayerId | Name | HP | Energy Points | Damage | Range | Armor | Evasion | Velocity | Action Points |
|----------|------|----|---------------|--------|-------|-------|---------|----------|---------------|
| 1534523  | Buster | 70 | 50 | 20 | 2 | 74 | 30 | 1 | 2 |
| 4565751  | Rangel | 57 | 40 | 30 | 2 | 14 | 27 | 2 | 0 |
| 5348502  | Richard | 63 | 89 | 17 | 3 | 68 | 32 | 3 | 0 |

In the file

```
1534523 Buster 70 50 20 2 74 30 1 2
4565751 Rangel 57 40 30 2 14 27 2 0
5348502 Richard 63 89 17 3 68 32 3 0
```
Load Players

```C
#include <stdio.h>

int loadPlayers (CharactersList *charList) {
  FILE *file;
  unsigned short tam;
  Character * newChar;
  
  printf("Loading players..");
  
  if (file = fopen("players.txt", "r") != NULL) {
  
    while (!feof(file)) {
      newChar = (Character *) malloc(sizeof(Character));
      fscanf("%d %s %d %d %d %d %d %d %d %d", 
            newChar->playerId,
            newChar->name,
            newChar->hP,
            newChar->eP,
            newChar->damage,
            newChar->range,
            newChar->armor,
            newChar->evasion,
            newChar->velocity,
            newChar->actionPoints
      );
      
      addToCharsList(charsList, newChar);
      free(newChar);
    }
    
  } else {
  
    printf("Error loading players...");
    return 0;
  }

}


```