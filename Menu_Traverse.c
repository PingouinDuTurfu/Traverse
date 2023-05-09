#include "Menu_Traverse.h"
#include "main_Traverse.h"





void menu(void)
{
	affichageMenu();
	int choix = choixMenu();
	switch(choix) {
		case 1 :
			menuNombreJoueur();
			break;

		case 2 :
			relancerTraverse();
			break;
		default :
			break;
	}
}





void affichageMenu(void)
{
	GLuint textureMenu = chargerTexture("Texture/menu_1.png");
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureMenu);
	glMatrixMode( GL_MODELVIEW );
    glClear(GL_COLOR_BUFFER_BIT) ;
    glLoadIdentity();

	glBegin(GL_QUADS);
		glTexCoord2d(1, 0);  glVertex2d(1, 1);
		glTexCoord2d(1, 1);  glVertex2d(1, -1);
		glTexCoord2d(0, 1);  glVertex2d(-1, -1);
		glTexCoord2d(0, 0);  glVertex2d(-1, 1);
	glEnd();

	glDisable(GL_TEXTURE_2D);

	glFlush();
    SDL_GL_SwapBuffers();
}




int choixMenu(void)
{
	int choix = 0;

	double x;
	double y;
	SDL_Event event;
	while(choix == 0) {
		SDL_WaitEvent(&event);
		switch(event.type) {
			case SDL_QUIT : 
				SDL_Quit();
				exit(EXIT_SUCCESS);
				break;

			case SDL_MOUSEBUTTONDOWN :
				if(event.button.button == SDL_BUTTON_LEFT) {
					x = ((double)event.button.x) / ((double)LONGUEUR_FENETRE);
					y = ((double)event.button.y) / ((double)LARGEUR_FENETRE);
				}
				break;

			default :
				break;
		}

		if(x >= 0.25 && x <= 0.75 && y >= 0.47 && y <= 0.62) {
			choix = 1;
		}
		if(x >= 0.25 && x <= 0.75 && y >= 0.67 && y <= 0.82) {
			choix = 2;
		}
	}
	return(choix);
}





int choixJoueur(void)
{
	int choix = 0;

	double x;
	double y;
	SDL_Event event;
	while(choix == 0) {
		SDL_WaitEvent(&event);
		switch(event.type) {
			case SDL_QUIT : 
				SDL_Quit();
				exit(EXIT_SUCCESS);
				break;

			case SDL_MOUSEBUTTONDOWN :
				if(event.button.button == SDL_BUTTON_LEFT) {
					x = ((double)event.button.x) / ((double)LONGUEUR_FENETRE);
					y = ((double)event.button.y) / ((double)LARGEUR_FENETRE);
				}
				break;

			default :
				break;
		}

		if(x >= 0.25 && x <= 0.78 && y >= 0.044 && y <= 0.233) {
			choix = 1;
		}
		if(x >= 0.25 && x <= 0.78 && y >= 0.278 && y <= 0.467) {
			choix = 2;
		}
		if(x >= 0.25 && x <= 0.78 && y >= 0.511 && y <= 0.7) {
			choix = 3;
		}
		if(x >= 0.25 && x <= 0.78 && y >= 0.744 && y <= 0.933) {
			choix = 4;
		}

	}
	return(choix);
}





int choixDificule(void)
{
	int choix = 0;

	double x;
	double y;
	SDL_Event event;
	while(choix == 0) {
		SDL_WaitEvent(&event);
		switch(event.type) {
			case SDL_QUIT : 
				SDL_Quit();
				exit(EXIT_SUCCESS);
				break;

			case SDL_MOUSEBUTTONDOWN :
				if(event.button.button == SDL_BUTTON_LEFT) {
					x = ((double)event.button.x) / ((double)LONGUEUR_FENETRE);
					y = ((double)event.button.y) / ((double)LARGEUR_FENETRE);
				}
				break;

			default :
				break;
		}
		if(x >= 0.25 && x <= 0.78 && y >= 0.278 && y <= 0.467) {
			choix = 1;
		}
		if(x >= 0.25 && x <= 0.78 && y >= 0.511 && y <= 0.7) {
			choix = 3;
		}
		if(x >= 0.25 && x <= 0.78 && y >= 0.744 && y <= 0.933) {
			choix = 5;
		}

	}
	return(choix);
}


void menuNombreJoueur(void)
{
	afficherChoixJoueur();
	int nombreJoueur = choixJoueur();
	if(nombreJoueur == 1) {
		Difficulte();
	} else {
		lancerTraverse(nombreJoueur, 1, 0);
	}
}




void Difficulte(void)
{
	afficherChoixDifficulte();
	int choix = choixDificule();
	lancerTraverse(2, 0, choix);
}


void afficherChoixDifficulte(void)
{
	GLuint textureMenuChoixDifficulte = chargerTexture("Texture/menu_3.png");
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureMenuChoixDifficulte);
	glMatrixMode( GL_MODELVIEW );
    glClear(GL_COLOR_BUFFER_BIT) ;
    glLoadIdentity();

	glBegin(GL_QUADS);
		glTexCoord2d(1, 0);  glVertex2d(1, 1);
		glTexCoord2d(1, 1);  glVertex2d(1, -1);
		glTexCoord2d(0, 1);  glVertex2d(-1, -1);
		glTexCoord2d(0, 0);  glVertex2d(-1, 1);
	glEnd();

	glDisable(GL_TEXTURE_2D);

	glFlush();
    SDL_GL_SwapBuffers();
}




void afficherChoixJoueur(void)
{
	GLuint textureMenuChoixJoueur = chargerTexture("Texture/menu_2.png");
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, textureMenuChoixJoueur);
	glMatrixMode( GL_MODELVIEW );
    glClear(GL_COLOR_BUFFER_BIT) ;
    glLoadIdentity();

	glBegin(GL_QUADS);
		glTexCoord2d(1, 0);  glVertex2d(1, 1);
		glTexCoord2d(1, 1);  glVertex2d(1, -1);
		glTexCoord2d(0, 1);  glVertex2d(-1, -1);
		glTexCoord2d(0, 0);  glVertex2d(-1, 1);
	glEnd();

	glDisable(GL_TEXTURE_2D);

	glFlush();
    SDL_GL_SwapBuffers();
}