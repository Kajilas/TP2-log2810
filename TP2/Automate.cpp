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

	for (int i = 0; i < nbEtats_; i++)
		ajouterEtat(new Etat(i));

	std::string line;

	while (!reader.eof()) {

		getline(reader, line);

		if (line != "") {

			if (line[0] == 'I') {
				etatInitial_ = etats_[line[2] - 48];
			}

			if (type_ == MEALY) {
				if (line.size() == 7) {
					char etiquette[2] = { line[2], line[4] };
					etats_[line[0] - 48]->ajouterTransition(etiquette, etats_[line[6] - 48]);
				}
			}

			else if (type_ == MOORE) {
				if (line.size() == 7) {
					char etiquette[1] = { line[2] };

					etats_[line[0] - 48]->ajouterTransition(etiquette, etats_[line[6] - 48]);
					etats_[line[0] - 48]->ajouterSortie(line[4] - 48);
				}

				if (line.size() == 5) {
					char etiquette[1] = { line[2] };
					etats_[line[0] - 48]->ajouterTransition(etiquette, etats_[line[4] - 48]);
				}
			}

			else
				std::cout << "Ligne incorrecte !" << std::endl;
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
	return out;
}