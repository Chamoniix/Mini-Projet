#include <iostream>
#include "CImg.h"
#include "Grille.h"
#include "Graphisme.h"
#include "Joueur.h"
#include "Humain.h"
#include "Ordinateur.h"
#include "Jeu.h"

/*
Rapport : 1 page de spécification
			- Diagramme de classe
			- Senarios (txt et prgm)
		1 page Diagramme de classe UML

		1 page explication diagramme de classe
			(Agrégation : le joueur s'occupera de détruire les grilles)

		Annexe : Tous les .h commentés (méthode et nom de variable)
*/

using namespace std;
using namespace cimg_library;

int main() {
	srand(time(NULL));


	bool
		fin = false;




	// ************** Création d'une partie **************

	Jeu Partie;



	// Dès qu'une fenêtre est fermée, on ferme tout ou si fin du jeu
	do
	{
		fin = Partie.choix();
	} while (fin != true);


	return 0;
}