#ifndef __Jeu__
#define __Jeu__

#include "Joueur.h"
#include "Ordinateur.h"
#include "Humain.h"
#include <fstream>

class Jeu
{
	Joueur* J1_;
	Joueur* J2_;

public:
	Jeu();

	void creerPartie(char * nom, string type1, string type2);
	bool isClosed();
	void jouer();
	
	char tour();
	bool choix();
};

#endif