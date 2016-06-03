#include "Humain.h"

Humain::Humain():Joueur(){

	bool bateauOK = false;
	string nom;
	int *xy1 = new int[2];
	int *xy2 = new int[2];

	// Demande du nom
	cout << "Quel est votre nom ?  :   "; cin >> nom; cout << endl;
	nom_ = (char*)nom.c_str();

	// Cr�ation de l'affichage attach� � la grille
	grid_ = new Graph(nom_, matrice_);
	

	// Cr�ation des bateaux :
	for (int k = 1; k <= 4;)
	{
		// On actualise la fen�tre :
		grid_->affiche();

		if (k == 1)
			cout << "*" << k << "ier bateau : cliquez sur les 2 cases reliant le tableau \n";
		else
			cout << "*" << k << "eme bateau : cliquez sur les 2 cases reliant le tableau \n";

		// R�cup�re 2 clic :
		grid_->clic(xy1);
		grid_->clic(xy2);

		// Ajout tu bateau � la grille Joueur :
		bateauOK = matrice_->ajouterBateau(*xy1, *(xy1 + 1), *xy2, *(xy2 + 1));

		if (bateauOK)
		{
			grid_->affiche();
			k++;
		}
	}
}

bool Humain::tirer(Grille* matriceEnnemie, Graph* gridEnnemie){

	int
		*xy = new int[2],
		x,
		y;

	//cout << "Tour Joueur : \n";
	cout << "CLiquez sur la case ou vous voulez tirer.\n";
	
	gridEnnemie->clic(xy);
	x = *xy;
	y = *(xy + 1);

	if (matriceEnnemie->GetXY(x, y) == 0)
	{
		matrice_->SetXYTire(x, y, 1);
		cout << "Rate	 ! \n";
		return false;
	}
	else if (matriceEnnemie->GetXY(x, y) == 1)
	{
		matrice_->SetXYTire(x, y, 2);
		cout << "Touche ! \n";
		return true;
	}
}