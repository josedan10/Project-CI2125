typedef struct personaje {

} Personaje;

typedef struct terreno {
	Personaje *personaje;
	//Efecto
	//Items
} Terreno;

typedef struct item {
	char nombre[32];
	unsigned int costo;
	unsigned int rango;
	// Efecto como apuntador a funcion
} Item;