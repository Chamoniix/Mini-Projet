#include <iostream>
#include "CImg.h"
#include "Grille.h"
#include "Graphisme.h"
#include "Joueur.h"
#include "Humain.h"
#include "Ordinateur.h"
#include <string>

using namespace std;
using namespace cimg_library;

int main() {
	srand(time(NULL));

	char * nomAlier = "Alier",
		*nomEnemie = "Ennemie",
		*nomOrdi = "Ordinateur1";

	bool
		ok;

	int
		i,
		x1,
		y1,
		x2,
		y2,
		*xy1,
		*xy2;

	xy1 = new int[2];
	xy2 = new int[2];

	

	// ************** Création d'une partie **************

	Humain J1;

	Ordinateur J2(nomOrdi);




	cout << "************** Debut du game *****************\n";


	while (1)
	{
		
		J1.afficheGrille();
		J2.afficheGrille();



	}


	return 0;
}
