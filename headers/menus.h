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
		   "9. Menú sistema\n"
		   "\nSelecciona una opcion: ");

	scanf("%i", &opc);

	return opc;

}

int mostrarMenuItems(){
	short opc;

	printf("\n\n1. Recoger item"
		   "\n2. Soltar item"
		   "\n3. Equipar item"
		   "\n4. Consultar tope"
		   "\n5. Volver"
		   "\nSelecciona una opcion: ");

	scanf("%i", &opc);

	return opc;

}

int mostrarMenuSistema(){
	short opc;

	printf("\n\n1. Guardar"
		   "\n2. Cargar"
		   "\n3. Volver"
		   "\n4. Salir"
		   "\nSelecciona una opcion: ");

	scanf("%i", &opc);

	return opc;

}
