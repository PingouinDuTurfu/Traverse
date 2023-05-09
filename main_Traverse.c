#include "main_Traverse.h"



int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_VIDEO);
	glutInit(&argc, argv);
	glutInitWindowSize(LONGUEUR_FENETRE, LARGEUR_FENETRE);
    SDL_WM_SetCaption("Traverse", NULL);
    SDL_SetVideoMode(LONGUEUR_FENETRE, LARGEUR_FENETRE, 32, SDL_OPENGL);
    SDL_Surface* icone = IMG_Load("Texture/Logo.png");
    SDL_WM_SetIcon(icone, NULL);
    glEnable(GL_LINE_SMOOTH);

    

    menu();

	SDL_Quit();
	return 0;
}

