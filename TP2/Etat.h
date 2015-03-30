#pragma once

class Transition;
#include "Transition.h"
#include <vector>

class Etat {

public:

	// Constructeur et destructeur
	Etat() : id_(-1), sortie_(-1), terminal_(false) {}
	Etat(int id) : id_(id), sortie_(-1), terminal_(false) {}
	~Etat() {}

	// Indique s'il existe une transition portant l'etiquette e partant de l'etat courant
	bool existeTransition(char e) const;

	// Indique l'ensemble des états de destination partant de l'état courant
	std::vector<Etat*> cible() const;

	// Ajouter une transition sortant de l'état présent vers l'état e 
	void ajouterTransition(Etat* sortant, std::vector<char> etiquette);

	// Sortie pour machine de Moore
	void ajouterSortie(char sortie) { sortie_ = sortie; }

	int getId() const { return id_; }
	char getSortie() const { return sortie_; }
	int getNbTransitions() const { return transitions_.size(); }

	// Etat terminal
	void setTerminal() { terminal_ = true; }
	bool isTerminal() const { return terminal_; }

	bool isDeterministe() const;
	bool isReactif() const;

	// Retourne la transition # id
	Transition* getTransition(unsigned int id) const { return transitions_[id]; }

private:
	int id_;
	char sortie_;
	bool terminal_;
	std::vector<Transition*> transitions_;

};