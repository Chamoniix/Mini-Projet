#ifndef __Jeu__
#define __Jeu__

#include "Joueur.h"
#include "Ordinateur.h"
#include "Humain.h"

class Jeu
{
	Joueur* J1_;
	Joueur* J2_;

public :
	Jeu(char* nom, string type1, string type2);

	void creerPartie(char * nom, string type1, string type2);
	bool isClosed();
	void jouer();
	char tour();
	void choix();
};

#endif