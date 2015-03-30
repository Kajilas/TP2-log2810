#include "stdafx.h"
#include "Automate.h"

Automate::Automate(std::string file) {

	std::ifstream reader(file.c_str(), std::ifstream::in);
	
	std::string type;
	reader >> type;
	
	if (type == "Moore")
		type_ = MOORE;
	else if (type == "Mealy")
		type_ = MEALY;

	reader >> nbEtats_;

	for (unsigned int i = 0; i < nbEtats_; i++)
		ajouterEtat(new Etat(i));

	std::string line;

	while (!reader.eof()) {

		getline(reader, line);

		if (line != "") {

			if (line[0] == 'I') {

				if (line[2] == 'T') {
					etats_[line[4] - 48]->setTerminal();
					etatInitial_ = etats_[line[4] - 48];
				}

				else
					etatInitial_ = etats_[line[2] - 48];
			}

			else if (line[0] == 'T')
				etats_[line[2] - 48]->setTerminal();

			else if (type_ == MEALY) {
				if (line.size() == 7) {
					std::vector<char> etiquette;
					etiquette.push_back(line[2]);
					etiquette.push_back(line[4]);

					etats_[line[0] - 48]->ajouterTransition(etats_[line[6] - 48], etiquette);
				}
			}

			else if (type_ == MOORE) {
				if (line.size() == 7) {
					std::vector<char> etiquette;
					etiquette.push_back(line[2]);

					etats_[line[0] - 48]->ajouterTransition(etats_[line[6] - 48], etiquette);
					etats_[line[0] - 48]->ajouterSortie(line[4]);
				}

				if (line.size() == 5) {
					std::vector<char> etiquette;
					etiquette.push_back(line[2]);

					etats_[line[0] - 48]->ajouterTransition(etats_[line[4] - 48], etiquette);
				}
			}

			else
				std::cout << "Erreur dans la ligne : \n" << line << std::endl;
		}
	}

	reader.close();
}

std::string Automate::getType() const {
	
	if (type_ == MOORE)
		return "Moore";
	else if (type_ == MEALY)
		return "Mealy";

	return "No type";
}

std::ostream &operator<<(std::ostream &out, const Automate &a) {
	out << "Type: " << a.getType() << std::endl;
	out << "Nb d'etats: " << a.getNbEtats() << std::endl;

	std::string det = a.isDeterministe() ? "Oui" : "Non";
	out << "Deterministe: " << det << std::endl;

	std::string reac = a.isReactif() ? "Oui" : "Non";
	out << "Reactif: " << reac << std::endl;

	return out;
}

void Automate::genererFichierAutomate(std::string file) {

	std::ofstream output(file);

	output << getType() + " " << getNbEtats() << "\n";

	if (etatInitial_->isTerminal())
		output << "I T " << getEtatInitial()->getId();

	else
		output << "I " << getEtatInitial()->getId();


	if (type_ == MEALY) {

		for (int i = 0; i < nbEtats_; i++) {

			if (etats_[i]->isTerminal() && etats_[i] != etatInitial_)
				output << "\nT " << i;

			for (int j = 0; j < etats_[i]->getNbTransitions(); j++) {
				output << "\n" << i << " ";
				output << etats_[i]->getTransition(j)->getEtiquette()[0] << " ";
				output << etats_[i]->getTransition(j)->getEtiquette()[1] << " ";
				output << etats_[i]->getTransition(j)->getEtatSortant()->getId();
			}
		}
	}
	
	else if (type_ == MOORE) {

		for (int i = 0; i < nbEtats_; i++) {

			if (etats_[i]->isTerminal() && etats_[i] != etatInitial_)
				output << "\nT " << i;

			output << "\n" << i << " " << etats_[i]->getTransition(0)->getEtiquette()[0] << " "
				<< etats_[i]->getSortie() << " " << etats_[i]->getTransition(0)->getEtatSortant()->getId();

			for (int j = 1; j < etats_[i]->getNbTransitions(); j++) {
				output << "\n" << i << " ";
				output << etats_[i]->getTransition(j)->getEtiquette()[0] << " ";
				output << etats_[i]->getTransition(j)->getEtatSortant()->getId();
			}
		}
	}

	output.close();
}

std::string Automate::calculerSortie(std::string mot) {
	return "";
}

bool Automate::isDeterministe() const {

	for (int i = 0; i < etats_.size(); i++) {
		if (!etats_[i]->isDeterministe())
			return false;
	}

	return true;
}

bool Automate::isReactif() const {

	for (int i = 0; i < etats_.size(); i++) {
		if (!etats_[i]->isReactif())
			return false;
	}

	return true;
}