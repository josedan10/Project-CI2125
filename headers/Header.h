#include <stdio.h>

int mostrarMenuPrincipal() {
	short opc;

	printf("\n1. Mostrar tablero\n"
		"2. Consultar casilla\n"
		"3. Atacar\n"
		"4. Moverse\n"
		"5. Usar habilidad\n"
		"6. Usar item\n"
		"7. Terminar turno\n"
		"8. Inventario\n"
		"9. Men� sistema\n"
		"\nSelecciona una opcion: ");

	scanf("%i", &opc);

	return opc;

}