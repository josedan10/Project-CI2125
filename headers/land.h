Land* createLand () {
	Land *l = (Land *) malloc(sizeof(Land));
	l->items = NULL;

	return l;
}

void addItemsToLandList (Land *land, ItemNode *newNode) {
	ItemNode *landAux = land->items;

	if (landAux != NULL) {

		if (strcmp(landAux->item->name, newNode->item->name) > 0) {
			// Comparación con el primer elemento para ver si se inserta al inicio

			newNode->next = landAux;
			land->items = newNode;

		} else {
			// Comparación con el resto de elementos

			while (landAux->next != NULL && strcmp(landAux->item->name, newNode->item->name) > 0)
				landAux = landAux->next;

			newNode->next = landAux->next;
			landAux->next = newNode;
		}
	} else {

		// La lista está vacía
		land->items = newNode;
	}
}