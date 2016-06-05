#include "Jeu.h"

Jeu::Jeu(char * nom, string type1, string type2)
{
	
}

void Jeu::creerPartie(char * nom, string type1, string type2)
{
	if (type1 == "Ordi")
		J1_ = new Ordinateur(nom);
	else if (type1 == "Humain")
		J1_ = new Humain();

	if (type2 == "Ordi")
		J2_ = new Ordinateur(nom);
	else if (type2 == "Humain")
		J2_ = new Humain();

	system("cls");
}

bool Jeu :: isClosed()
{
	bool isClosed =  !J1_->isClosed() && !J1_->isKeyESC() && !J2_->isKeyQ() && !J2_->isClosed() && !J2_->isKeyESC() && !J2_->isKeyQ();
	return isClosed;
}

char Jeu::tour()
{
	bool tire = false;
	char continu = 'n';

	cout << "~~ Debut du tour ~~\n\n";

	J1_->afficheGrille();
	J2_->afficheGrille();

	//TODO : Ne plus afficher J2_ mais afficher J1_ Grille tire et Grille bateaux
	//TODO : changer la grille de Tirer par getGraphTire()

	cout << "Tour du Joueur 1  :\n";
	tire = J1_->tirer(J2_->getGrille(), J2_->getGraph());

	cout << "Tour du Joueur 2 :  \n" ;
	tire = J2_->tirer(J1_->getGrille(), J2_->getGraph());

	cout << "Voulez vous continuer ? (o/n)  ";
	cin >> continu; cout << endl;

	return continu;


}

void Jeu::choix()
{
	int choix = 0;

	char *nomOrdi = "Ordinateur";

	cout << "Que voulez vous faire ?  :  \n";
	cout << "  -  1  : Nouvelle partie\n";
	cout << "  -  2  : Reprendre partie\n";
	cout << "  -  3  : Sauvegarder\n";
	cout << "  -  4  : Charger\n";
	cout << "  -  5  : Aide\n";
	cout << "  -  6  : Quitter\n";

	cin >> choix;
	
	if (choix == 1)
	{
		creerPartie(nomOrdi, "Humain", "Ordi");
		jouer();

	}

	else if (choix == 5)
	{
				
		system("cls");
		ifstream aide("Aide.txt");
		if (!aide)
			cout << "Erreur ouverture Aide \n";
		else
		{
			string aff;
			while (getline(aide, aff))
			{
				cout << aff << endl;
			}
			system("pause");
		}
		system("cls");

	}

}

void Jeu::jouer()
{
	char continu = 'o';
	while (continu != 'n')
		continu = tour();

	system("cls");
}