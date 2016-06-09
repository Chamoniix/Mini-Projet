#include "Graphisme.h"

Graph::Graph(char* nom, Grille * matrice)
{
	matrice_ = matrice;
	unsigned char
		blanc[3]{ 255, 255, 255 };

	// Déclare une image
	fenetre_ = new CImg <unsigned char>(500, 500, 1, 3, 0);
	fenetreTir_ = new CImg<unsigned char>(500, 500, 1, 3, 0);
	// Déssine une grille 10x10 sur l'image
	for (int i = 1; i < 10; i++)
	{
		fenetre_->draw_line(0, 50 * i, 500, 50 * i, blanc);
		fenetreTir_->draw_line(0, 50 * i, 500, 50 * i, blanc);
	};
	for (int j = 1; j < 10; j++)
	{
		fenetre_->draw_line(50 * j, 0, 50 * j, 500, blanc);
		fenetreTir_->draw_line(50 * j, 0, 50 * j, 500, blanc);
	}
	// Déclare une fenêtre nommée :
	disp_ = new CImgDisplay(*fenetre_, nom, 0, false, false);
	dispTir_ = new CImgDisplay(*fenetreTir_, "fenetre de tir", 0, false, false);
	// Position de la fentre sur l'ecran :
	disp_->move((CImgDisplay::screen_width() - disp_->width()) / 2,
		(CImgDisplay::screen_height() - disp_->height()) / 2);
	dispTir_->move((CImgDisplay::screen_width() - dispTir_->width()) / 2 + dispTir_->width(),
		(CImgDisplay::screen_height() - dispTir_->height()) / 2);



}

void Graph::affiche()
{
	unsigned char
		rouge[3]{ 255, 0, 0 },
		gris[3]{ 160, 160, 160 },
		cyan[3]{ 0, 255, 255 };

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (matrice_->GetXY(i, j) == 0)
			{
			}
			else if (matrice_->GetXY(i, j) == 1)
				fenetre_->draw_fill(j * 50 + 15, i * 50 + 10, rouge);
			else if (matrice_->GetXY(i, j) == 2)
			{
				fenetre_->draw_fill(j * 50 + 15, i * 50 + 10, gris);

			}
			else if (matrice_->GetXY(i, j) == 3)
			{
				fenetre_->draw_line(5 + j * 50, 5 + i * 50, 45 + j * 50, 45 + i * 50, cyan);
				fenetre_->draw_line(5 + j * 50, 45 + i * 50, 45 + j * 50, 5 + i * 50, cyan);

			}
		}
	}


	fenetre_->display(*disp_);

}

void Graph::afficheTir()
{
	unsigned char
		cyan[3]{ 0,255,255 },
		rouge[3]{ 255,0,0 };
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (matrice_->GetXYTire(i, j) == 0)
			{
			}
			else if (matrice_->GetXYTire(i, j) == 2)
			{
				fenetreTir_->draw_line(5 + j * 50, 5 + i * 50, 45 + j * 50, 45 + i * 50, rouge);
				fenetreTir_->draw_line(5 + j * 50, 45 + i * 50, 45 + j * 50, 5 + i * 50, rouge);
			}
			else if (matrice_->GetXYTire(i, j) == 3)
			{
				fenetreTir_->draw_circle(j * 50 + 25, i * 50 + 25, 25, cyan, 1, ~0U);
			}
		}
	}
	fenetreTir_->display(*dispTir_);
}
void Graph::clic(int *xy)
{
	bool clic = false;

	while (!disp_->is_closed() && !disp_->is_keyESC() && !disp_->is_keyQ() && clic == false)
	{
		affiche();

		if (disp_->button() & 1)
		{
			cout << "CLIC\n";

			*xy = 10 * disp_->mouse_y() / disp_->height();
			xy++;
			*xy = 10 * disp_->mouse_x() / disp_->width();

			disp_->wait();
			clic = true;

		}
	}
}

bool Graph::clicTir(int* xy)
{
	bool clic = false,
		isM = false;

	while (clic == false)
	{

		afficheTir();

		if (isKeyM())
			isM = true;
		
		if (dispTir_->button() & 1)
		{

			*xy = 10 * dispTir_->mouse_y() / dispTir_->height();
			xy++;
			*xy = 10 * dispTir_->mouse_x() / disp_->width();

			clic = true;

		}
	}
	return isM;
}


void Graph::fillCase(int i, int j, unsigned char couleur[])
{
	fenetre_->draw_fill(j * 50 + 15, i * 50 + 10, couleur);
	affiche();
}