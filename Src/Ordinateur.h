#ifndef __ORDINATEUR__
#define __ORDINATEUR__

#include "Joueur.h"
#include "time.h"
#include "Graphisme.h"
#include <Windows.h>

class Ordinateur :public Joueur
{
public:
	Ordinateur(char* nom);
	Ordinateur(int i);
	void creerGrilleOrdi();
	bool tirer(Grille* matriceEnnemie, int scoreEnnemie);
	void charger(ifstream &file);
	void sauver(string nom);
};







#endif