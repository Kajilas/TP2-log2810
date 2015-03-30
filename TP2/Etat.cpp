#include "stdafx.h"
#include "Etat.h"

void Etat::ajouterTransition(char* etiquette, Etat* e) {
	transitions_.push_back(new Transition(this, e, etiquette));
}