void fire(Land *land) {
	// Incendia al jugador y le resta el 30% de su vida actual.

	short auxArmor = land->character->armor;
	auxArmor = auxArmor - land->character->hP * 0.3;

	if (auxArmor < 0) {
		// La armadura no soport� todo el da�o.

		land->character->hP += auxArmor;
		land->character->armor = 0;
	} else {
		// La armadura absorbi� todo el da�o.

		land->character->armor = auxArmor;
	}

	land->effect = typeFire;
}

void freeze(Land *land) {
	// Congela al jugador y no le permite realizar ninguna acci�n.
	land->character->aP = 0;
	land->effect = typeFreeze;
}	

void restore(Land *land) {
	// Restaura el 30% de la salud
	land->character->hP += land->character->hP * 0.3;
	land->effect = typeRestore;
}

void electrocute(Land *land) {
	// Disminuye a la mitad los puntos de energía del jugador
	land->character->eP -= ceil(land->character->eP / 2);
	land->effect = typeElectrocute;
}

void fireDescription() {
	printf("\nEsta habilidad causa un dano igual al 30% de la vida actual del objetivo\n");
}

void freezeDescription() {
	printf("\nEsta habilidad elimina todos los puntos de accion del objetivo\n");
}

void restoreDescription() {
	printf("\nEsta habilidad restaura el 30% de la vida actual del jugador\n");
}

void electrocuteDescription() {
	printf("\nEsta habilidad disminuye el 50% de los puntos de energia del objetivo\n");
}