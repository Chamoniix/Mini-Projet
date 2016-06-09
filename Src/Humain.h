#ifndef __HUMAIN__
#define __HUMAIN__

#include "Joueur.h"
#include "Graphisme.h"
#include <String>

class Humain : public Joueur
{
	
public:
	Humain();
	Humain(int i);
	Humain(ifstream &save);
	bool tirer(Grille* matriceEnnemie, int scoreEnnemie);
	void charger(ifstream &file);
	void sauver(string nom);

};

#endif