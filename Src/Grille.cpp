#include "Grille.h"


// Créer une grille initialisée à 0
Grille::Grille()
{
	for (int i = 0; i < 10; i++)
	{

		for (int j = 0; j < 10; j++)
			grille_[i][j] = 0;
	}
}

// Permet d'afficher la grille dans la console
void Grille::afficherGrille()
{
	for (int i = 0; i < 10; i++)
	{
		cout << "| ";
		for (int j = 0; j < 10; j++)
		{
			cout << grille_[i][j] << " ";
			
			
		}
		cout << "| "<<endl;
	}
		
}

//Permet de passer quatre cases concécutives de la matrice à 1
bool Grille::ajouterBateau(int Ax, int Ay, int Bx, int By)
{
	// Bool est retrouné true si le bateau est correctement placé
	bool ok=false;



	/*
	(0,0)  ->  (0,3)  : même COLONNE : Xdeb = Ydeb
	
	*/
	if (Ax == Bx)
	{
		if (abs(Ay - By) == 3)
		{
			for (int j = Ay; j <= By; j++)
				grille_[Ax][j] = 1;
			ok = true;
		}
		else
			cout << "ERREUR1";
		
	}
	/*
	(0,0)  ->  (3,0)  : même LIGNE : Xdeb = Ydeb

	*/
	else if (Ay == By)
	{
		if (abs(Ax - Bx) == 3)
		{
			for (int i = Ax; i <= Bx; i++)
				grille_[i][Ay] = 1;
			ok = true;
		}
		else
			cout << "ERREUR1";
	}
	else
		cout << "ERREUR2";

	return ok;
}

void Grille::CreerGrilleOrdi()
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
					if (grille_[i][y] == 1)
						testPlaceLibre = false;
				}

				if (testPlaceLibre == true)
				{
					for (int i = x; i <= x + 3; i++)
						grille_[i][y] = 1;
					
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
					if (grille_[x][i] == 1)
						testPlaceLibre = false;
				}

				if (testPlaceLibre == true)
				{
					for (int i = y; i <= y + 3; i++)
						grille_[x][i] = 1;

					k++;
				}
			}
		}
	}

	
}

void Grille::CreerGrilleJoueur()
{
	for (int i = 0; i < 4; i++)
	{
		int ax, ay, bx, by;
		cout << "Entrez Ax, Ay, Bx, By \n";
		cin >> ax >> ay >> bx >> by;
		ajouterBateau(ax, ay, bx, by);
	}
}