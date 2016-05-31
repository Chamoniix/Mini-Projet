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

	char
		*nomOrdi = "Ordinateur1";

	bool
		fin = false,
		tire;

	string
		player = "Joueur1";

	

	// ************** Création d'une partie **************

	Humain J1;

	Ordinateur J2(nomOrdi);




	cout << "************** Debut du game *****************\n";

	// Dès qu'une fenêtre est fermée, on ferme tout ou si fin du jeu
	while (!J1.isClosed() && !J1.isKeyESC() && !J2.isKeyQ() && !J2.isClosed() && !J2.isKeyESC() && !J2.isKeyQ() && fin != true)
	{
		
		J1.afficheGrille();
		J2.afficheGrille();

		if (player == "Joueur1")
		{
			tire = J1.tirer(J2.getGrille());
			

			player = "Joueur2";

		}
		else if (player == "Joueur2")
		{
			tire = J2.tirer(J1.getGrille());

			player = "Joueur1";

		}



	}


	return 0;
}
