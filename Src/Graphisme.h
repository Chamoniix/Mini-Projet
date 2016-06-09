#ifndef __GRAPH__
#define __GRAPH__

#include "CImg.h"
#include "Grille.h"
#include <iostream>
using namespace std;
using namespace cimg_library;



class Graph {
	CImg <unsigned char>
		*fenetre_,
		*fenetreTir_;
	CImgDisplay
		*disp_,
		*dispTir_;
	Grille * matrice_;


public:
	Graph(char* nomFenetre, Grille * matrice);

	void affiche();
	void afficheTir();

	void fermer() { disp_->close(); };
	void fermerTir() { dispTir_->close(); };

	void clic(int *xy);
	bool clicTir(int *xy);
	bool isClosed() { return disp_->is_closed(); };
	bool isKeyESC() { return disp_->is_keyESC(); };
	bool isKeyQ() { return disp_->is_keyQ(); };
	bool isKeyM(){ return dispTir_->is_keyM(); };
	unsigned int button() { return disp_->button(); };
	int mouseX() { return disp_->mouse_x(); };
	int mouseY() { return disp_->mouse_y(); };
	int height() { return disp_->height(); };
	int width() { return disp_->width(); };
	void fillCase(int i, int j, unsigned char couleur[]);
};



#endif