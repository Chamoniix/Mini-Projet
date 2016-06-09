#ifndef __JOUEUR__
#define __JOUEUR__

#include "Graphisme.h"
#include "Grille.h"
#include <string>
#include <fstream>

class Joueur
{
protected:
	string nomString_;
	Grille* matrice_;
	Graph* grid_;
	char * nom_;
	int score_;
public:
	Joueur();
	void afficheGrille();
	void fermerGrille();
	Grille* getGrille() { return matrice_; }
	void itScore() { score_++; }
	int getScore() { return score_; }
	virtual bool tirer(Grille* matriceEnnemie, int scoreEnnemie);
	bool isClosed() { return grid_->isClosed(); }
	bool isKeyESC() { return grid_->isKeyESC(); }
	bool isKeyQ() { return grid_->isKeyQ(); }
	bool isKeyM() { return grid_->isKeyM(); }
	char* getNom() { return nom_; }
	string getNomString() { return nomString_; }
	virtual void sauver(string nom);
	virtual void charger(ifstream &file);
};
#endif