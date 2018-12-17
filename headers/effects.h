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
}

void freeze(Land *land) {
	// Congela al jugador y no le permite realizar ninguna acci�n.
	land->character->actionPoints = 0;
}	

void restore(Land *land) {
	// Restaura el 30% de la salud
	land->character->hP += land->character->hP * 0.3;
}

void electrocute(Land *land) {
	// Disminuye a la mitad los puntos de energía del jugador
	land->character->eP -= ceil(land->character->eP / 2);
}