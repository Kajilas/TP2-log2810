#ifndef ETAT_H
#define ETAT_H

#include "Transition.h"
#include <vector>
#include <string>


using namespace std;

class Etat {

public:

	// Constructeur et destructeur
	Etat(unsigned int id) : id_(id), sortie_(-1) {}
	~Etat() {}

	// Indique s'il existe une transition portant l'etiquette e partant de l'etat courant
	bool existeTransition(char e) const;

	// Indique l'ensemble des états de destination portant l'étiquette e
	vector<Etat*> cible(char e) const;

	// Indique l'ensemble des états de destination partant de l'état courant
	vector<Etat*> cible() const;

	// Ajouter une transition sortant de l'état présent vers l'état e 
	void ajouterTransition(char* etiquette, Etat* e);

	// Parcours la liste de transition et en ressort une liste de chaque étiquette
	vector<char> listerEtiquettes() const;

	void ajouterSortie(int sortie) { sortie_ = sortie; }

private:
	int sortie_;
	unsigned int id_;
	vector<Etat*> etats_;
	vector<Transition*> transitions_;


};

#endif
