#include "Humain.h"

Humain::Humain():Joueur(){

	bool bateauOK = false;
	string nom;
	int *xy1 = new int[2];
	int *xy2 = new int[2];

	// Demande du nom
	cout << "Quel est votre nom ?  :   "; cin >> nom; cout << endl;
	nom_ = (char*)nom.c_str();

	// Création de l'affichage attaché à la grille
	grid_ = new Graph(nom_, matrice_);
	

	// Création des bateaux :
	for (int k = 1; k <= 4;)
	{
		// On actualise la fenêtre :
		grid_->affiche();

		if (k == 1)
			cout << "*" << k << "ier bateau : cliquez sur les 2 cases reliant le tableau \n";
		else
			cout << "*" << k << "eme bateau : cliquez sur les 2 cases reliant le tableau \n";

		// Récupère 2 clic :
		grid_->clic(xy1);
		grid_->clic(xy2);

		// Ajout tu bateau à la grille Joueur :
		bateauOK = matrice_->ajouterBateau(*xy1, *(xy1 + 1), *xy2, *(xy2 + 1));

		if (bateauOK)
		{
			grid_->affiche();
			k++;
		}
	}
}

bool Humain::tirer(Grille* matriceEnnemie){

	int
		*xy = new int[2],
		x,
		y;

	cout << "Tour Joueur : \n";
	cout << "CLiquez sur la case ou vous voulez tirer.\n";
	
	grid_->clic(xy);
	x = *xy;
	y = *(xy + 1);

	if (matriceEnnemie->GetXY(x, y) == 0)
	{
		cout << "Rate Humain ! \n";
		return false;
	}
	else if (matriceEnnemie->GetXY(x, y) == 1)
	{
		cout << "Touche Humain ! \n";
		return true;
	}
}