#include <iostream>
#include "CImg.h"
#include "Grille.h"
#include "Graphisme.h"
#include "Joueur.h"
#include "Humain.h"
#include "Ordinateur.h"
#include "Jeu.h"
#include <string>

using namespace std;
using namespace cimg_library;

int main() {
	srand(time(NULL));

	char
		*nomOrdi = "Ordinateur";

	bool
		fin = false,
		tire;

	string
		player = "Joueur1";

	

	// ************** Cr�ation d'une partie **************



	Jeu Partie(nomOrdi, "Humain", "Ordi");


	cout << "************** Debut du game *****************\n";

	// D�s qu'une fen�tre est ferm�e, on ferme tout ou si fin du jeu
	do 
	{

		Partie.choix();
	} while (Partie.isClosed() && fin != true);


	return 0;
}
