#include "Jeu.h"

Jeu::Jeu()
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

bool Jeu::isClosed()
{
	//TODO : Vérifier si fenêtre de tire fermée
	bool isClosed = !J1_->isClosed() && !J1_->isKeyESC();
	return isClosed;
}

char Jeu::tour()
{
	bool isM = false;
	char continu = 'o';
/*
	system("cls");
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "~           Partie en cours        ~\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl << endl;

	cout << "Conseils : \n";
	cout << "  - Cliez sur la fenetre \"fenetre de tir\" pour tirer.\n";
	cout << "  - Rond bleu = rate  et Croix rouge = touche.\n";
	cout << "  - Appuyez sur la touche 'M' pour revenir au menu.\n" << endl << endl;*/

	J1_->afficheGrille();

	//cout << "Tour du Joueur 1  :   ";
	isM = J1_->tirer(J2_->getGrille(), J2_->getScore());

	if (!isM)
	{
		//cout << "Tour du Joueur 2 :   ";
		J2_->tirer(J1_->getGrille(), J1_->getScore());

		J1_->afficheGrille();
	}
	else
		continu = 'n';

	
	if (J1_->getScore() >= 24 || J2_->getScore() >= 24)
	{
		continu = 'n';
		system("cls");
		cout << endl << endl << endl << endl << endl << "                    FIN DE LA PARTIE\n";
		if (J1_->getScore() >= 24)
			cout << "                  VICTOIRE HUMAIN !!!\n" << endl << endl << endl << endl << endl;
		else
			cout << "                 VICTOIRE Ordinateur !!!\n" << endl << endl << endl << endl << endl;
		system("PAUSE");
	}
	return continu;


}

bool Jeu::choix()
{
	int choix = 0;
	bool fin = false;
	char *nomOrdi = "Ordinateur";

	cout << "*********************************************\n";
	cout << "*           Menu Bataille Navale            *\n";
	cout << "*********************************************\n"<<endl;

	cout << "Que voulez vous faire ?  :  \n";
	cout << "  -  1  : Nouvelle partie\n";
	cout << "  -  2  : Reprendre partie\n";
	cout << "  -  3  : Sauvegarder\n";
	cout << "  -  4  : Charger\n";
	cout << "  -  5  : Aide\n";
	cout << "  -  6  : Quitter\n";

	cin >> choix;
	system("cls");
	if (choix == 1)
	{
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "~       Creation d'une partie      ~\n";
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl<< endl;
		creerPartie(nomOrdi, "Humain", "Ordi");
		jouer();

	}

	else if (choix == 2)
		jouer();

	else if (choix == 3)
	{
		J1_->sauver("Coco");
		J2_->sauver(J1_->getNomString());

	}
	else if (choix == 4)
	{
		string fileName;
		cout << "Entrez le nom du fichier de sauvegarde  : ";
		cin >> fileName;
		ifstream file(fileName);
		if (!file)
			cout << "Erreur d'ouverture du fichier\n";
		else
		{
			if (J1_ == NULL)
				J1_ = new Humain(0);


			if (J2_ == NULL)
				J2_ = new Ordinateur(0);


			J1_->charger(file);
			J2_->charger(file);

			cout << "Chargement bien effectue.\n";
			getchar();
			J1_->afficheGrille();
			jouer();
		}

	}
		

	else if (choix == 5)
	{
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
		cout << "~               Aide               ~\n";
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl << endl;

		ifstream aide("Aide.txt");
		if (!aide)
		{
			cout << "Erreur ouverture Aide \n";
			system("PAUSE");
		}
		else
		{
			string aff;
			while (getline(aide, aff))
			{
				cout << aff << endl;
			}
			system("PAUSE");
		}
		system("cls");

	}
	else if (choix == 6)
		return true;

}

void Jeu::jouer()
{
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "~           Partie en cours        ~\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl << endl;

	cout << "Conseils : \n";
	cout << "  - Cliez sur la fenetre \"fenetre de tir\" pour tirer.\n";
	cout << "  - Rond bleu = rate  et Croix rouge = touche.\n";
	cout << "  - Appuyez sur la touche 'M' pour revenir au menu.\n" << endl << endl;

	char continu = 'o';
	while (continu != 'n')
		continu = tour();


	system("cls");
}