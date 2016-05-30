#ifndef __GRILLE__
#define __GRILLE__

#include <iostream>
#include <stdlib.h>
using namespace std;

class Grille
{
	//Attributs de Grille :

	int grille_[10][10];
	int grilleTire_[10][10];
	/*
	- 0 : Case sans bateau 
	...
	*/

public :
	//Méthode de Grille :
	// Initialise une grille vide
	Grille();
	//Ajoute un bateau dans la grille , appel 4fois de cette fonction en début de partie
	bool ajouterBateau(int Ax, int Ay, int Bx, int By);
	// Ajoute un bateau pour la grille de l'ordinateur :
	
	void CreerGrilleOrdi();
	void CreerGrilleJoueur();

	//Retourne la valeur d'une case :
	int GetXY(int X, int Y) { return grille_[X][Y]; };
	//Setter
	void SetXY(int X, int Y, int i){ grille_[X][Y] = i; };
	//Donne le resultat du tir (Touché ou non) 
	bool tirer(int x, int y);
	// Défini aléatoirement une case sur laqeulle l'IA tire, idem pour les tirs ennemis
	bool tireEnnemieAlea(void);
	
	void afficherGrille();

	bool testFinPartie();
};



#endif