#include <stdlib.h>
#include <time.h> 

struct land;
struct listItems;
struct character;

typedef struct land {
	struct character *character;
	void(*efect)(struct land *);
	struct listItems *items;
} Land;

typedef struct skill {
	char nombre[16];
	unsigned short energyCost;
	unsigned short actionCost;
	unsigned short range;
	void(*effect)(struct Land *);

} Skill;

typedef struct skillNode {
	Skill *skill;
	struct skillNode *next;

} SkillNode;

typedef SkillNode *SkillsList;

typedef struct item {
	char name[32];
	unsigned int cost;
	unsigned int range;
	void(*efecto)(Land *);
} Item;

typedef struct itemNode {
	Item *item;
	struct itemNode *next;
} ItemNode;

typedef ItemNode *ListItems;
typedef ItemNode *HeapItems;

typedef struct character {

	char name[16];
	unsigned short hP;
	unsigned short eP;
	HeapItems *items;
	SkillsList *skills;
	unsigned short damage;
	unsigned short armor;
	unsigned short evasion;
	unsigned short velocity;
	unsigned short actionPoints;
	unsigned short playerId;

} Character;