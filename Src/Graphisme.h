#ifndef __GRAPH__
#define __GRAPH__

#include "CImg.h"
#include "Grille.h"
#include <iostream>
using namespace std;
using namespace cimg_library;



class Graph {
	CImg <unsigned char> * fenetre_;
	CImgDisplay* disp_;
	Grille * matrice_;


public :
	Graph(char* nomFenetre, Grille * matrice);

	void affiche();

	void clic(int *xy);

	bool isClosed(){ return disp_->is_closed(); };
	bool isKeyESC(){ return disp_->is_keyESC(); };
	bool isKeyQ(){ return disp_->is_keyQ(); };
	unsigned int button(){ return disp_->button(); };
	int mouseX(){ return disp_->mouse_x(); };
	int mouseY(){ return disp_->mouse_y(); };
	int height(){ return disp_->height(); };
	int width(){ return disp_->width(); };
};




#endif