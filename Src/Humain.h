#ifndef __HUMAIN__
#define __HUMAIN__

#include "Joueur.h"
#include "Graphisme.h"
#include <String>

class Humain : public Joueur
{

public:
	Humain();
	bool tirer(Grille* matriceEnnemie);
	
};

#endif