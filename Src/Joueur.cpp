#include "Joueur.h"

Joueur::Joueur()
{
	matrice_= new Grille();
}

void Joueur::afficheGrille()
{
	grid_->affiche();
}