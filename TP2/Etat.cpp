#include "stdafx.h"
#include "Etat.h"

bool Etat::existeTransition(char e) const {

	for (unsigned int i = 0; i < transitions_.size(); i++) {

		if (transitions_[i]->getEtiquette()[0] == 'e')
			return true;
	}

	return false;
}

std::vector<Etat*> Etat::cible() const {

	std::vector<Etat*> etats_;

	for (unsigned int i = 0; i < transitions_.size(); i++)
		etats_.push_back(transitions_[i]->getEtatSortant());

	return etats_;
}

void Etat::ajouterTransition(Etat* sortant, std::vector<char> etiquette) {
	transitions_.push_back(new Transition(this, sortant, etiquette));
}

bool Etat::isDeterministe() const {
	
	std::vector<char> etiquettes;

	for (int i = 0; i < transitions_.size(); i++) {
		etiquettes.push_back(transitions_[i]->getEtiquette()[0]);
	}

	for (int i = 0; i < etiquettes.size() - 1; i++)
	{
		if (etiquettes[i] == etiquettes[i + 1])
			return false;
	}

	return true;
}

bool Etat::isReactif() const {

	std::vector<char> etiquettes;

	for (int i = 0; i < transitions_.size(); i++) {
		etiquettes.push_back(transitions_[i]->getEtiquette()[0]);
	}

	for (int i = 0; i < etiquettes.size() - 1; i++)
	{
		if (etiquettes[i] == etiquettes[i + 1])
			return false;
	}

	return true;
}