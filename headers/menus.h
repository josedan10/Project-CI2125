unsigned short mostrarMenuPrincipal(Character *C) {
	unsigned short opc;
	clearScreen();

	printf("%s esta jugando\n", C->name);

	printf("1. Mostrar tablero\n"
		   "2. Consultar casilla\n"
		   "3. Atacar\n"
		   "4. Moverse\n"
		   "5. Usar habilidad\n"
		   "6. Usar item\n"
		   "7. Terminar turno\n"
		   "8. Inventario\n"
		   "9. Menu sistema\n"
		   "\nSelecciona una opcion: ");

	scanf("%hu", &opc);

	return opc;
}

unsigned short mostrarMenuItems(){
	unsigned short opc;

	fseek(stdin,0,SEEK_END);
	printf("\n\n1. Recoger item"
		   "\n2. Soltar item"
		   "\n3. Equipar item"
		   "\n4. Consultar tope"
		   "\n5. Volver"
		   "\nSelecciona una opcion: ");

	scanf("%hu", &opc);

	return opc;

}

unsigned short mostrarMenuSistema(){
	unsigned short opc;

	printf("\n\n1. Guardar"
		   "\n2. Cargar"
		   "\n3. Volver"
		   "\n4. Salir"
		   "\nSelecciona una opcion: ");

	scanf("%hu", &opc);

	return opc;
}

unsigned short confirm(char *accion) {
	unsigned short opc;

	printf("Estas seguro de que deseas %s ?", accion);
	printf("\n\n1) Si.\n2) No.\n");
	scanf("%hu", &opc);

	return opc;
}