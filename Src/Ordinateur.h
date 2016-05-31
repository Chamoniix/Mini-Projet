#ifndef __ORDINATEUR__
#define __ORDINATEUR__

#include "Joueur.h"
#include "time.h"
#include "Graphisme.h"


class Ordinateur :public Joueur
{
public:
	Ordinateur(char* nom);
	void creerGrilleOrdi();
	bool tirer(Grille* matriceEnnemie);
};







#endif