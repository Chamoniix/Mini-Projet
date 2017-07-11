#include "Joueur.h"

Joueur::Joueur()
{
	matrice_ = new Grille();
	score_ = 0;
}


void Joueur::afficheGrille()
{
	grid_->affiche();
	grid_->afficheTir();
}

void Joueur::fermerGrille()
{
	grid_->fermer();
	grid_->fermerTir();

}

bool Joueur::tirer(Grille* matriceEnnemie, int scoreEnnemie)
{
	return false;
}


void Joueur::sauver(string nom)
{
}

void Joueur::charger(ifstream &file)
{

}