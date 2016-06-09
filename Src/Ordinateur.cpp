#include "Ordinateur.h"

Ordinateur::Ordinateur(char *nom) :Joueur()
{
	nom_ = nom;
	//grid_ = new Graph(nom, matrice_);

	matrice_->CreerGrilleOrdi();
}
Ordinateur::Ordinateur(int i)
{
	nom_ = "Ordi";
	grid_ = new Graph(nom_, matrice_);
}



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
					if (matrice_->GetXY(i, y) == 1)
						testPlaceLibre = false;
				}

				if (testPlaceLibre == true)
				{
					for (int i = x; i <= x + 3; i++)
						matrice_->SetXY(i, y, 1);

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
					if (matrice_->GetXY(x, i) == 1)
						testPlaceLibre = false;
				}

				if (testPlaceLibre == true)
				{
					for (int i = y; i <= y + 3; i++)
						matrice_->SetXY(x, i, 1);

					k++;
				}
			}
		}
	}



}

bool Ordinateur::tirer(Grille* matriceEnnemie, int scoreEnnemie)
{
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
		cout << "Tour du Joueur 2 :   ";
		cout << "Rate ! \n" << endl << endl;
		cout << "    SCORE :     # Huamin : " << scoreEnnemie << " - Ordinateur : " << score_ << " # \n";
		touche = false;
	}
	else if (matriceEnnemie->GetXY(X, Y) == 1)
	{
		matriceEnnemie->SetXY(X, Y, 2);
		itScore();
		cout << "Tour du Joueur 2 :   ";
		cout << "Touche ! \n" << endl << endl;
		cout << "    SCORE :     # Huamin : " << scoreEnnemie << " - Ordinateur : " << score_ << " # \n";
		touche = true;
	}

	matrice_->SetXYTire(X, Y, 1);
	//matrice_->afficherGrilleTire();
	return touche;
}

void Ordinateur::charger(ifstream& file)
{
	string ligne = "";

	// On récupère le nom dans ligne
	getline(file, ligne);
	ligne = ligne.substr(6, ligne.size() - 6);

	// On récuère le nom : 
	nomString_ = ligne;

	if (nom_ == NULL)
		nom_ = new char;

	nom_ = (char *)ligne.c_str();

	getline(file, ligne);

	// On charge les deux matrices en mémoire :
	matrice_->charger(file);

}

void Ordinateur::sauver(string nom)
{
	string nomFichier;
	nomFichier = nom;
	nomFichier += ".txt";

	// ios::app permet de ne pas remplacer le fichier s'il existe deja
	ofstream file(nomFichier, ios::app);

	file << "Nom : " << nom_ << endl;
	matrice_->sauver(file);
}
