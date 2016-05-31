#include "Graphisme.h"

Graph::Graph(char* nom, Grille * matrice)
{
	matrice_ = matrice;

	unsigned char
		bleu[3] { 255, 255, 255 };

	// Déclare une mage
	fenetre_ = new CImg <unsigned char> (500, 500, 1, 3, 0);

	// Déssine une grille 10x10 sur l'image
	for (int i = 1; i<10; i++)
		fenetre_->draw_line(0, 50 * i, 500, 50 * i, bleu);

	for (int j = 1; j<10; j++)
		fenetre_->draw_line(50 * j, 0, 50 * j, 500, bleu);

	// Déclare une fenêtre nommée :
	disp_ = new CImgDisplay(*fenetre_, nom, 0, false, false);

	// Centre la fenetre :
	disp_->move((CImgDisplay::screen_width() - disp_->width()) / 2,
		(CImgDisplay::screen_height() - disp_->height()) / 2);



}

void Graph::affiche()
{
	unsigned char
		rouge[3] { 255, 0, 0 },
		vert[3]  { 0, 255, 0 },
		bleu[3]  { 0, 0, 255 };

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
				fenetre_->draw_line(5 + j * 50, 5 + i * 50, 45 + j * 50, 45 + i * 50, vert);
				fenetre_->draw_line(5 + j * 50, 45 + i * 50, 45 + j * 50, 5 + i * 50, vert);

			}
			else if (matrice_->GetXY(i, j) == 3)
			{
				fenetre_->draw_line(5 + j * 50, 5 + i * 50, 45 + j * 50, 45 + i * 50, bleu);
				fenetre_->draw_line(5 + j * 50, 45 + i * 50, 45 + j * 50, 5 + i * 50, bleu);

			}
		}
	}


	fenetre_->display(*disp_); 

}

void Graph::clic(int *xy)
{
	bool clic = false;

	while (!disp_->is_closed() && !disp_->is_keyESC() && !disp_->is_keyQ() && clic==false) 
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