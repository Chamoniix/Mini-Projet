#include <iostream>
#include "CImg.h"
#include "Grille.h"
#include "Graphisme.h"
#include "Joueur.h"
#include "Humain.h"
#include "Ordinateur.h"
#include "Jeu.h"

/*
Rapport : 1 page de sp�cification
			- Diagramme de classe
			- Senarios (txt et prgm)
		1 page Diagramme de classe UML

		1 page explication diagramme de classe
			(Agr�gation : le joueur s'occupera de d�truire les grilles)

		Annexe : Tous les .h comment�s (m�thode et nom de variable)
*/

using namespace std;
using namespace cimg_library;

int main() {
	srand(time(NULL));


	bool
		fin = false;




	// ************** Cr�ation d'une partie **************

	Jeu Partie;



	// D�s qu'une fen�tre est ferm�e, on ferme tout ou si fin du jeu
	do
	{
		fin = Partie.choix();
	} while (fin != true);


	return 0;
}