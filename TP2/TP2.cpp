// TP2.cpp�: d�finit le point d'entr�e pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include "Automate.h"


int _tmain(int argc, _TCHAR* argv[])
{
	using namespace std;

	Automate automate("machine_test.txt");
	cout << automate;

	return 0;
}

