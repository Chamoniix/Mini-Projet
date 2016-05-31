#ifndef __JOUEUR__
#define __JOUEUR__

#include "Graphisme.h"
#include "Grille.h"
#include <string>
class Joueur
{
protected:
	Grille* matrice_;
	Graph* grid_;
	char * nom_;
public:
	Joueur();
	void afficheGrille();
	Grille* getGrille() { return matrice_; };
	virtual bool tirer(Grille* matriceEnnemie);
	bool isClosed() { return grid_->isClosed(); };
	bool isKeyESC() { return grid_->isKeyESC(); };
	bool isKeyQ() { return grid_->isKeyQ(); };
	char* getNom() { return nom_; };
};
#endif