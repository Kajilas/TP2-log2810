#pragma once

class Transition;
#include "Transition.h"
#include <vector>

class Etat {

public:

	// Constructeur et destructeur
	Etat(unsigned int id) : id_(id), sortie_(-1) {}
	~Etat() {}

	// Indique s'il existe une transition portant l'etiquette e partant de l'etat courant
	bool existeTransition(char e) const;

	// Indique l'ensemble des états de destination portant l'étiquette e
	std::vector<Etat*> cible(char e) const;

	// Indique l'ensemble des états de destination partant de l'état courant
	std::vector<Etat*> cible() const;

	// Ajouter une transition sortant de l'état présent vers l'état e 
	void ajouterTransition(char* etiquette, Etat* e);

	// Parcours la liste de transition et en ressort une liste de chaque étiquette
	std::vector<char> listerEtiquettes() const;

	void ajouterSortie(int sortie) { sortie_ = sortie; }

private:
	int sortie_;
	unsigned int id_;
	std::vector<Etat*> etats_;
	std::vector<Transition*> transitions_;


};