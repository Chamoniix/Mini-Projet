#include <iostream>
#include "CImg.h"
#include "Grille.h"
#include "Graphisme.h"
#include <string>

using namespace std;
using namespace cimg_library;

int main() {
	cout << "Coucou \n ";
	srand(time(NULL));

	char * nomAlier = "Alier",
		*nomEnemie = "Ennemie";

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

	Grille MatriceJoueur;
	//MatriceJoueur.CreerGrilleJoueur();
	MatriceJoueur.afficherGrille();
	Graph gridAlier(nomAlier, &MatriceJoueur);

	Grille MatriceOrdi;
	MatriceOrdi.CreerGrilleOrdi();
	Graph gridEnemie(nomEnemie, &MatriceOrdi);

	MatriceOrdi.afficherGrille();


	
	for (int k = 1; k <= 4;)
	{
		gridEnemie.affiche();

		if (k == 1)
			cout << "*" << k << "ier bateau : cliquez sur les 2 cases reliant le tableau \n";
		else
			cout << "*" << k << "eme bateau : cliquez sur les 2 cases reliant le tableau \n";

		gridAlier.clic(xy1);
		gridAlier.clic(xy2);

		cout << *xy1 << " , " << *(xy1 + 1) << " , " << *xy2 << " , " << *(xy2 + 1) << endl;

		MatriceJoueur.ajouterBateau(*xy1, *(xy1 + 1), *xy2, *(xy2 + 1));

		k++;


		// Affichage :
		gridAlier.affiche();
		gridEnemie.affiche();

	}  

			
	
	cout << "************** Debut du game *****************\n";


	while (!gridAlier.isClosed() && !gridAlier.isKeyESC() && !gridAlier.isKeyQ())
	{
		
		gridAlier.affiche();
		gridEnemie.affiche();



	}


	return 0;
}
