#include "Chargement_Images_Textures.h"



GLuint chargerTexture(char* str_FichierTexture)
{
		// Chargement de l'image dans une surface SDL
	SDL_Surface* surface_Texture_SDL;
	surface_Texture_SDL = IMG_Load(str_FichierTexture);
	if(surface_Texture_SDL == NULL) {
        fprintf(stderr, "Erreur de chargement de l'image %s\n", str_FichierTexture);
        fprintf(stderr, "%s\n" , SDL_GetError());
        exit(EXIT_FAILURE);
    }

    	// Declaration de l'ID
    GLuint ui_ID_Texture = 0;

    	// Génération de l'ID
    glGenTextures(1, &ui_ID_Texture);

    	// Verrouillage
    glBindTexture(GL_TEXTURE_2D, ui_ID_Texture);

    	// Format de l'image
    GLenum formatInterne = 0;
    GLenum format = 0;

    switch(surface_Texture_SDL->format->BytesPerPixel) {

    	case 3 :
    			// Format interne
			formatInterne = GL_RGB;

				// Format
			if(surface_Texture_SDL->format->Rmask == 0xff) {
				format = GL_RGB;
			} else {
				format = GL_BGR;
			}
			break;



		case 4 :
    			// Format interne
			formatInterne = GL_RGBA;

				// Format
			if(surface_Texture_SDL->format->Rmask == 0xff) {
				format = GL_RGBA;
		 	} else {
		 		format = GL_BGRA;
			}
			break;


				// Dans les autres cas, on arrête le chargement
		default : 
			fprintf(stderr, "Erreur, format de l'image inconnu : %s\n", str_FichierTexture);
			SDL_FreeSurface(surface_Texture_SDL);
			exit(EXIT_FAILURE);
			break;

	}
	
	// Application des filtres

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);


		// Copie des pixels
	glTexImage2D(GL_TEXTURE_2D, 0, formatInterne, surface_Texture_SDL->w, surface_Texture_SDL->h, 0, format, GL_UNSIGNED_BYTE, surface_Texture_SDL->pixels);


	    // Déverrouillage
    glBindTexture(GL_TEXTURE_2D, 0);


    	// Liberation de la surface SDL
    SDL_FreeSurface(surface_Texture_SDL);

    return(ui_ID_Texture);
}

