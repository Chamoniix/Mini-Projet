#include "Grille.h"


// Créer une grille initialisée à 0
Grille::Grille()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			grille_[i][j] = 0;
	}
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
			grilleTire_[i][j] = 0;
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
		cout << "| " << endl;
	}

}
void Grille::afficherGrilleTire()
{
	for (int i = 0; i < 10; i++)
	{
		cout << "| ";
		for (int j = 0; j < 10; j++)
		{
			cout << grilleTire_[i][j] << " ";


		}
		cout << "| " << endl;
	}

}

//Permet de passer quatre cases concécutives de la matrice à 1
bool Grille::ajouterBateau(int Ax, int Ay, int Bx, int By)
{
	// Bool est retrouné true si le bateau est correctement placé
	bool 
		ok = false,
		testPlaceLibre = true;

	int c = 0;
	// Colonne :
	if (Ax == Bx)
	{
		if (abs(Ay - By) == 3)
		{
			if (By < Ay)
			{
				c = By;
				By = Ay;
				Ay = c;
			}

			for (int i = Ay; i <= By; i++)
			{
				if (grille_[Ax][i] == 1)
				{
					testPlaceLibre = false;
					cout << "Erreur 3\n";
				}
			}
			if (testPlaceLibre == true)
			{
				for (int j = Ay; j <= By; j++)
					grille_[Ax][j] = 1;
				ok = true;
			}
		}
		else
			cout << "ERREUR1\n";

	}
	// Ligne : 
	else if (Ay == By)
	{
		if (abs(Ax - Bx) == 3)
		{
			if (Bx < Ax)
			{
				c = Bx;
				Bx = Ax;
				Ax = c;
			}

			for (int i = Ax; i <= Bx; i++)
			{
				if (grille_[i][Ay] == 1)
				{
					testPlaceLibre = false;
					cout << "Erreur 3\n";
				}
			}
			if (testPlaceLibre == true)
			{
				for (int i = Ax; i <= Bx; i++)
					grille_[i][Ay] = 1;
				ok = true;
			}
		}
		else
			cout << "ERREUR1\n";
	}
	else
		cout << "ERREUR2\n";

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

	for (int k = 0; k < 6;)
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
void Grille::sauver(ofstream &save) {
	if (save) {
		save << "Grille Bateaux  : " << endl;
		for (int x = 0; x < 10; x++) {
			for (int y = 0; y < 10; y++) {
				save << grille_[x][y] << endl;
			}
		}
		save << "Grille Tir  : " << endl;
		for (int x = 0; x < 10; x++) {
			for (int y = 0; y < 10; y++) {
				save << grilleTire_[x][y] << endl;
			}
		}
	}
	else cerr << "ERREUR DE SAUVEGARDE!!!" << endl;
}

void Grille::charger(ifstream &save) {


	string recup;
	if (save) {
		//Recuperation de la Grille de bateaux

		int* p = &grille_[0][0];
		for (int i = 0; i < 100; i++) {
			getline(save, recup);
			p[i] = stoi(recup);
		}
		getline(save, recup);
		//Récupération de la grille de tir
		int* t = &grilleTire_[0][0];
		for (int i = 0; i < 100; i++) {
			getline(save, recup);
			t[i] = stoi(recup);
		}
	}
	else cerr << "ERREUR DE CHARGEMENT !!!!" << endl;


}