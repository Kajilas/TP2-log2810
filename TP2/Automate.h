#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Etat.h"

#define MOORE 0
#define MEALY 1


class Automate {

public:
	Automate() : type_(-1), nbEtats_(0) {}
	~Automate() {}
	Automate(std::string file);

	// Cree un fichier correspondant a l'automate courant
	void genererFichierAutomate(std::string file);

	//TODO: Calcule le parcours de sortie avec la chaine de caracteres en entree
	std::string calculerSortie(std::string mot);

	//TODO: Retourne l'automate de Moore minimale equivalent a l'automate courant
	Automate* minimiserMoore();

	//TODO: Convertisseurs de machines
	Automate* convertMooreToMealy();
	Automate* convertMealyToMoore();

	//TODO: methode isReactif de la classe Etat
	bool isReactif() const;
	bool isDeterministe() const;

	void ajouterEtat(Etat* e) { etats_.push_back(e); }

	Etat* getEtatInitial() const { return etatInitial_; }
	std::string getType() const;
	unsigned int getNbEtats() const { return nbEtats_; }

	// Permet d'afficher l'automate
	friend std::ostream &operator<<(std::ostream &out, const Automate &a);


private:
	int type_;
	unsigned int nbEtats_;
	std::vector<Etat*> etats_;
	Etat* etatInitial_;

};