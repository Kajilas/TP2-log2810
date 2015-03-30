#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Etat.h"

#define MOORE 0
#define MEALY 1

using namespace std;


class Automate {

public:
	Automate() : type_(-1), nbEtats_(0) {}
	~Automate() {}
	Automate(string file);

	// Calcule le parcours de sortie avec la chaine de caractreres en entree
	string calculerSortie(string mot);

	// Cree un fichier correspondant a l'automate courant
	void genererFichierAutomate(string file);

	// Retourne l'automate de Moore minimale equivalent a l'automate courant
	Automate* minimiserMoore();

	// Convertisseurs de machines
	Automate* convertMooreToMealy();
	Automate* convertMealyToMoore();

	void ajouterEtat(Etat* e) { etats_.push_back(e); }

	Etat* getEtatInitial() const { return etatInitial_; }
	bool estDeterministe() const;
	bool estReactif() const;

	string getType() const;
	unsigned int getNbEtats() const { return nbEtats_; }

	// Permet d'afficher l'automate
	friend ostream &operator<<(ostream &out, const Automate &a);


private:
	int type_;
	unsigned int nbEtats_;
	vector<Etat*> etats_;
	Etat* etatInitial_;

};

#endif