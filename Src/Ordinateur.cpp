#include "Ordinateur.h"

Ordinateur::Ordinateur(char *nom) :Joueur()
{
	nom_ = nom;
	grid_ = new Graph(nom, matrice_);

	matrice_->CreerGrilleOrdi();
	grid_->affiche();
};

void Ordinateur::creerGrilleOrdi()
{
	bool
		testPlaceLibre = true;
	int
		x,
		y,
		oriente,
		BateauOK = 0;

	for (int k = 0; k < 4;)
	{
		testPlaceLibre = true;

		x = rand() % 10;
		y = rand() % 10;

		oriente = rand() % 2;

		if (oriente == 0) // Colonne
		{
			if (x < 7)
			{

				for (int i = x; i <= x + 3; i++)
				{
					if (matrice_->GetXY(i,y) == 1)
						testPlaceLibre = false;
				}

				if (testPlaceLibre == true)
				{
					for (int i = x; i <= x + 3; i++)
						matrice_->SetXY(i,y,1);

					k++;
				}
			}
		}
		else if (oriente == 1) // ligne
		{
			if (y < 7)
			{

				for (int i = y; i <= y + 3; i++)
				{
					if (matrice_->GetXY(x,i) == 1)
						testPlaceLibre = false;
				}

				if (testPlaceLibre == true)
				{
					for (int i = y; i <= y + 3; i++)
						matrice_->SetXY(x,i,1);

					k++;
				}
			}
		}
	}



}

bool Ordinateur::tirer(Grille* matriceEnnemie)
{
	cout << "Tour Ordinateur : ";
	cout << endl;
	int X, Y;
	bool 
		dispo = false,
		touche = false;
	srand(time(NULL));

	while (dispo != true)
	{
		X = rand() % 10;
		Y = rand() % 10;

		if (matrice_->GetXYTire(X, Y) == 0)
			dispo = true;
		else if (matrice_->GetXYTire(X, Y) == 1)
			dispo = false;
	}

	if (matriceEnnemie->GetXY(X, Y) == 0)
	{
		matriceEnnemie->SetXY(X, Y, 3);
		cout << "Rate Ordi ! \n";
		touche = false;
	}
	else if (matriceEnnemie->GetXY(X, Y) == 1)
	{
		matriceEnnemie->SetXY(X, Y, 2);
		cout << "Touche Ordi! \n";
		touche =  true;
	}

	matrice_->SetXYTire(X, Y, 1);
	matrice_->afficherGrilleTire();
	return touche;
}