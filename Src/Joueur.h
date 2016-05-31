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
public:
	Joueur();
	void afficheGrille();
	//virtual bool tirer() = 0;
};
#endif