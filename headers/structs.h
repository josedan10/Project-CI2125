typedef struct skill {
	char nombre[16];
	unsigned short energyCost;
	unsigned short actionCost;
	unsigned short range;
	(void)(*efect)(void);

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
	unsigned short actionPoints;
	unsigned short playerId;

} Character;

typedef struct land {
	Character *character;
	void(*efect)(Land *);
	ListItems *items;
} Land;

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