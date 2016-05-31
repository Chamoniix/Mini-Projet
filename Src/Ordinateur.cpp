#include "Ordinateur.h"

Ordinateur::Ordinateur(char *nom) :Joueur()
{
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

/*bool Ordinateur::tirer(){
	int X, Y;
	srand(time(NULL));
	X = rand() % 10;
	Y = rand() % 10;
	return	matrice_->tirer(X, Y);
}*/