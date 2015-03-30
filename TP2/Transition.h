#pragma once

class Etat;
#include <vector>
#include "Etat.h"


class Transition {

public:
	// Constructreur et destructeur
	Transition(Etat* eEntrant, Etat* eSortant, std::vector<char> etiquette) : eEntrant_(eEntrant), eSortant_(eSortant), etiquette_(etiquette) {}
	~Transition() {}

	// Méthode d'accès
	Etat* getEtatEntrant() { return eEntrant_; }
	Etat* getEtatSortant() { return eSortant_; }
	std::vector<char> getEtiquette() { return etiquette_; }

private:
	Etat* eEntrant_;
	Etat* eSortant_;
	std::vector<char> etiquette_;;
};