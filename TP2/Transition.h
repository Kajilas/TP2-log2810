#ifndef TRANSITION_H
#define TRANSITION_H

#include <string>

using namespace std;


class Transition {

public:
	// Constructreur et destructeur
	Transition(Etat* entree, Etat* sortie, char* etiquette) : entrant_(entree), sortant_(sortie), etiquette_(etiquette) {}
	~Transition() {}

	// Méthode d'accès
	string getEtiquette();
	Etat* getEtatEntrant();
	Etat* getEtatSortant();

private:
	Etat* entrant_;
	Etat* sortant_;
	char* etiquette_;
};

#endif