#include "stdafx.h"
#include "Automate.h"

Automate::Automate(string file) {

	ifstream reader(file.c_str(), ifstream::in);
	
	string type;
	reader >> type;
	
	if (type == "Moore")
		type_ = MOORE;
	else if (type == "Mealy")
		type_ = MEALY;

	reader >> nbEtats_;

	for (int i = 0; i < nbEtats_; i++)
		ajouterEtat(new Etat(i));

	string line;

	while (!reader.eof()) {

		getline(reader, line);

		if (line != "") {

			if (line[0] == 'I') {
				etatInitial_ = etats_[line[2]];
			}

			if (type_ == MEALY) {
				if (line.size() == 7) {
					char etiquette[2] = { line[2], line[4] };
					etats_[line[0]]->ajouterTransition(etiquette, etats_[line[6]]);
				}
			}

			else if (type_ == MOORE) {
				if (line.size() == 7) {
					char etiquette[1] = { line[2] };

					etats_[line[0]]->ajouterTransition(etiquette, etats_[line[6]]);
					etats_[line[0]]->ajouterSortie(line[4]);
				}

				if (line.size() == 5) {
					char etiquette[1] = { line[2] };
					etats_[line[0]]->ajouterTransition(etiquette, etats_[line[4]]);
				}
			}

			else
				cout << "Ligne incorrecte !" << endl;
		}
	}

	reader.close();
}

string Automate::getType() const {
	
	if (type_ == MOORE)
		return "Moore";
	else if (type_ == MEALY)
		return "Mealy";

	return "No type";
}

ostream &operator<<(ostream &out, const Automate &a) {
	out << "Type: " << a.getType() << endl;
	out << "Nb d'etats: " << a.getNbEtats() << endl;
	return out;
}