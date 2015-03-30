#pragma once

class Etat;
#include "Etat.h"
#include <string>

class Transition {

public:
	// Constructreur et destructeur
	Transition(Etat* entree, Etat* sortie, char* etiquette) : entrant_(entree), sortant_(sortie), etiquette_(etiquette) {}
	~Transition() {}

	// Méthode d'accès
	std::string getEtiquette();
	Etat* getEtatEntrant();
	Etat* getEtatSortant();

private:
	Etat* entrant_;
	Etat* sortant_;
	char* etiquette_;
};