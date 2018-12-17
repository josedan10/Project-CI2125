typedef struct item {
	char name[32];
	unsigned int cost;
	unsigned int range;
	void(*effect)();
} Item;

typedef struct itemNode {
	Item *item;
	struct itemNode *next;
} ItemNode;

typedef ItemNode *ListItems;
typedef ItemNode *HeapItems;

typedef struct land {
	struct character *character;
	void(*effect)();
	ListItems items;
} Land;

typedef struct skill {
	char name[16];
	unsigned short energyCost;
	unsigned short actionCost;
	unsigned short range;
	void(*effect)();

} Skill;

typedef struct skillNode {
	Skill *skill;
	struct skillNode *next;

} SkillNode;

typedef SkillNode *SkillsList;

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
	unsigned short aP;
	unsigned short playerId;

} Character;

typedef struct charsListC {
	unsigned short tam;
	unsigned short alfa;
	unsigned short omega;
	Character **chars;
	unsigned short capacity;

} CharsListC;

typedef CharsListC *CharsListR;

typedef struct col {
	char letter;
	Land **lands;
} Col;

typedef struct map {
	Col **cols;
} Map;

typedef struct coord {
	char col;
	unsigned short row;
} Cord;