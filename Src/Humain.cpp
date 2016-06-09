#include "Humain.h"

Humain::Humain() :Joueur() {

	bool bateauOK = false;
	int *xy1 = new int[2];
	int *xy2 = new int[2];
	unsigned char
		rose[3]{ 236, 79, 131 },
		noir[3]{ 0, 0, 0 };

	// Demande du nom
	cout << "Quel est votre nom ?  :   "; cin >> nomString_; cout << endl;
	nom_ = (char*)nomString_.c_str();

	// Création de l'affichage attaché à la grille
	grid_ = new Graph(nom_, matrice_);

	system("cls");
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << "~       Creation d'une partie      ~\n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;

	cout << "Placez vos bateux en clicant sur la grille portant votre nom.\n" << endl << endl;

	// Création des bateaux :
	for (int k = 1; k <= 6;)
	{
		// On actualise la fenêtre :
		grid_->affiche();

		if (k == 1)
			cout << "*" << k << "ier bateau : cliquez sur les 2 cases reliant le tableau \n";
		else
			cout << "*" << k << "eme bateau : cliquez sur les 2 cases reliant le tableau \n";

		// Récupère 2 clic :
		grid_->clic(xy1);
		grid_->fillCase(*xy1, *(xy1 + 1), rose);
		grid_->clic(xy2);
		grid_->fillCase(*xy1, *(xy1 + 1), noir);

		// Ajout du bateau à la grille Joueur :
		bateauOK = matrice_->ajouterBateau(*xy1, *(xy1 + 1), *xy2, *(xy2 + 1));

		if (bateauOK)
		{
			grid_->affiche();
			system("cls");
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			cout << "~       Creation d'une partie      ~\n";
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
			cout << "Placez vos bateux en clicant sur la grille portant votre nom.\n" << endl << endl;
			cout << "BATEAU numero "<< k << " correctement place.\n\nBateau suivant : \n";
			k++;
		}

	}
}

Humain::Humain(int i) :Joueur() {
	grid_ = new Graph(nom_, matrice_);

}

Humain::Humain(ifstream &save) :Joueur() {
	nom_ = "Partie Chargée";
	matrice_->charger(save);
	grid_ = new Graph(nom_, matrice_);
	grid_->affiche();
	grid_->afficheTir();
}

bool Humain::tirer(Grille* matriceEnnemie, int scoreEnnemie) {

	int
		*xy = new int[2],
		x,
		y;

	bool
		isM = false;

	afficheGrille();
	do {
		isM = grid_->clicTir(xy);
		x = *xy;
		y = *(xy + 1);
	} while (matrice_->GetXYTire(x, y) != 0);

	if (!isM)
	{
	

		if (matriceEnnemie->GetXY(x, y) == 0)
		{
			system("cls");
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			cout << "~           Partie en cours        ~\n";
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl << endl;

			cout << "Conseils : \n";
			cout << "  - Cliez sur la fenetre \"fenetre de tir\" pour tirer.\n";
			cout << "  - Rond bleu = rate  et Croix rouge = touche.\n";
			cout << "  - Appuyez sur la touche 'M' puis RECLIQUEZ sur la 'fenetre de tir' pour revenir au menu.\n" << endl << endl;
			cout << "Tour du Joueur 1  :   ";
			cout << "Rate ! \n";
			matrice_->SetXYTire(x, y, 3);
		}
		else if (matriceEnnemie->GetXY(x, y) == 1)
		{
			system("cls");
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			cout << "~           Partie en cours        ~\n";
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl << endl;

			cout << "Conseils : \n";
			cout << "  - Cliez sur la fenetre \"fenetre de tir\" pour tirer.\n";
			cout << "  - Rond bleu = rate  et Croix rouge = touche.\n";
			cout << "  - Appuyez sur la touche 'M' puis RECLIQUEZ sur la 'fenetre de tir' pour revenir au menu.\n" << endl << endl;
			cout << "Tour du Joueur 1  :   ";
			cout << "Touche ! \n";
			itScore();
			matrice_->SetXYTire(x, y, 2);
		}
		return false;
	}
	else
	{
		return true;
	}
}

void Humain::charger(ifstream &file)
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

void Humain::sauver(string nom)
{
	string nomFichier;
	nomFichier = nomString_;
	nomFichier += ".txt";


	ofstream file(nomFichier);

	file << "Nom : " << nom_ << endl;
	matrice_->sauver(file);


}
