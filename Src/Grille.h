#ifndef __GRILLE__
#define __GRILLE__

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
using namespace std;

class Grille
{
	//Attributs de Grille :

	int grille_[10][10];
	int grilleTire_[10][10];
	/*
	- 0 : Case sans bateau
	- 1 : Case avec bateau
	- 2 : Tir touch�/bateau touch�
	- 3 : Tir rat�
	*/

public:
	//M�thode de Grille :
	// Initialise une grille vide
	Grille();
	//Ajoute un bateau dans la grille , appel 4fois de cette fonction en d�but de partie
	bool ajouterBateau(int Ax, int Ay, int Bx, int By);
	// Ajoute un bateau pour la grille de l'ordinateur :

	void CreerGrilleOrdi();

	//Retourne la valeur d'une case :
	int GetXY(int X, int Y) { return grille_[X][Y]; };
	int GetXYTire(int X, int Y) { return grilleTire_[X][Y]; };
	//Setter
	void SetXY(int X, int Y, int i) { grille_[X][Y] = i; };
	void SetXYTire(int X, int Y, int i) { grilleTire_[X][Y] = i; };
	//Donne le resultat du tir (Touch� ou non) 
	//bool tirer(int x, int y);
	// D�fini al�atoirement une case sur laqeulle l'IA tire, idem pour les tirs ennemis
	//bool tireEnnemieAlea(void);

	void afficherGrille();
	void afficherGrilleTire();

	void sauver(ofstream &save);
	void charger(ifstream &save);
	//bool testFinPartie();
};



#endif