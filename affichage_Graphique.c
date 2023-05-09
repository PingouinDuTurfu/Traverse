#include "affichage_Graphique.h"


// default FONT
const GLubyte GL_FONT_DATA[] [8]= {
{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},	//  0
{0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff},	//  1
}; 

void myText(int x, int y, char* text)
{
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glRasterPos2i(x,y+8);
	for( int i = 0; i < (int) strlen(text); ++i ){
		glBitmap(8, 8, 0.0, 0.0, 8, 0, GL_FONT_DATA[text[i]-48] );
	}
}

void ecrire_nombre_0(int x, int y)
{


	myText( x, y, "111111");
	myText( x, y+6, "111111");
	myText( x, y+12, "110011");
	myText( x, y+18, "110011");
	myText( x, y+24, "110011");
	myText( x, y+30, "110011");
	myText( x, y+36, "110011");
	myText( x, y+42, "110011");
	myText( x, y+48, "111111");
	myText( x, y+54, "111111");

}

void ecrire_nombre_1(int x, int y)
{


	myText( x, y, "001111");
	myText( x, y+6, "001111");
	for(int i = 2; i < 10; i++){
		myText( x, y+(6*i), "000011");
	}

}

void ecrire_nombre_2(int x, int y)
{


	myText( x, y, "111111");
	myText( x, y+6, "111111");
	myText( x, y+12, "000011");
	myText( x, y+18, "000011");
	myText( x, y+24, "111111");
	myText( x, y+30, "111111");
	myText( x, y+36, "110000");
	myText( x, y+42, "110000");
	myText( x, y+48, "111111");
	myText( x, y+54, "111111");

}

void ecrire_nombre_3(int x, int y)
{


	myText( x, y, "111111");
	myText( x, y+6, "111111");
	myText( x, y+12, "000011");
	myText( x, y+18, "000011");
	myText( x, y+24, "111111");
	myText( x, y+30, "111111");
	myText( x, y+36, "000011");
	myText( x, y+42, "000011");
	myText( x, y+48, "111111");
	myText( x, y+54, "111111");

}

void ecrire_nombre_4(int x, int y)
{

	myText( x, y, "110011");
	myText( x, y+6, "110011");
	myText( x, y+12, "110011");
	myText( x, y+18, "110011");
	myText( x, y+24, "111111");
	myText( x, y+30, "111111");
	myText( x, y+36, "000011");
	myText( x, y+42, "000011");
	myText( x, y+48, "000011");
	myText( x, y+54, "000011");

}

void ecrire_nombre_5(int x, int y)
{


	myText( x, y, "111111");
	myText( x, y+6, "111111");
	myText( x, y+12, "110000");
	myText( x, y+18, "110000");
	myText( x, y+24, "111111");
	myText( x, y+30, "111111");
	myText( x, y+36, "000011");
	myText( x, y+42, "000011");
	myText( x, y+48, "111111");
	myText( x, y+54, "111111");

}

void ecrire_nombre_6(int x, int y)
{


	myText( x, y, "111111");
	myText( x, y+6, "111111");
	myText( x, y+12, "110000");
	myText( x, y+18, "110000");
	myText( x, y+24, "111111");
	myText( x, y+30, "111111");
	myText( x, y+36, "110011");
	myText( x, y+42, "110011");
	myText( x, y+48, "111111");
	myText( x, y+54, "111111");

}

void ecrire_nombre_7(int x, int y)
{


	myText( x, y, "111111");
	myText( x, y+6, "111111");
	for(int i = 2; i < 10; i++){
		myText( x, y+(6*i), "000011");
	}

}

void ecrire_nombre_8(int x, int y)
{


	myText( x, y, "111111");
	myText( x, y+6, "111111");
	myText( x, y+12, "110011");
	myText( x, y+18, "110011");
	myText( x, y+24, "111111");
	myText( x, y+30, "111111");
	myText( x, y+36, "110011");
	myText( x, y+42, "110011");
	myText( x, y+48, "111111");
	myText( x, y+54, "111111");

}

void ecrire_nombre_9(int x, int y)
{
	myText( x, y, "111111");
	myText( x, y+6, "111111");
	myText( x, y+12, "110011");
	myText( x, y+18, "110011");
	myText( x, y+24, "111111");
	myText( x, y+30, "111111");
	myText( x, y+36, "000011");
	myText( x, y+42, "000011");
	myText( x, y+48, "111111");
	myText( x, y+54, "111111");
}	


void afficher_tour(int nombreTour)
{
	int chiffre[5]; 
	int increment=0;
	while(nombreTour != 0){
		chiffre[increment] = nombreTour%10;
		nombreTour = nombreTour/10;
		increment ++;
	}

	for(int i=increment-1; i>=0; i--){
		switch(chiffre[i]){
			case 0 : ecrire_nombre_0(620+(increment - i)*40, 500); break;
			case 1 : ecrire_nombre_1(620+(increment - i)*40, 500); break;
			case 2 : ecrire_nombre_2(620+(increment - i)*40, 500); break;
			case 3 : ecrire_nombre_3(620+(increment - i)*40, 500); break;
			case 4 : ecrire_nombre_4(620+(increment - i)*40, 500); break;
			case 5 : ecrire_nombre_5(620+(increment - i)*40, 500); break;
			case 6 : ecrire_nombre_6(620+(increment - i)*40, 500); break;
			case 7 : ecrire_nombre_7(620+(increment - i)*40, 500); break;
			case 8 : ecrire_nombre_8(620+(increment - i)*40, 500); break;
			case 9 : ecrire_nombre_9(620+(increment - i)*40, 500); break;
			default : break; 

		}
	}
}



void ecranVictoire(int partie_Fini)
{
	GLuint ecran;
	if(partie_Fini > 0 && partie_Fini < 10) {
		ecran = chargerTexture("Texture/victoire_egalite.png");
	}
	if(partie_Fini >= 10 && partie_Fini < 20) {
		ecran = chargerTexture("Texture/victoire_rouge.png");
	}
	if(partie_Fini >= 20 && partie_Fini < 30) {
		ecran = chargerTexture("Texture/victoire_vert.png");
	}
	if(partie_Fini >= 30 && partie_Fini < 40) {
		ecran = chargerTexture("Texture/victoire_violet.png");
	}
	if(partie_Fini >= 40) {
		ecran = chargerTexture("Texture/victoire_orange.png");
	}
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ecran);
	glMatrixMode( GL_MODELVIEW );
    glClear(GL_COLOR_BUFFER_BIT) ;
    glLoadIdentity();

	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
		glTexCoord2d(1, 0);  glVertex2d(1, 1);
		glTexCoord2d(1, 1);  glVertex2d(1, -1);
		glTexCoord2d(0, 1);  glVertex2d(-1, -1);
		glTexCoord2d(0, 0);  glVertex2d(-1, 1);
	glEnd();

	glDisable(GL_TEXTURE_2D);

	glFlush();
    SDL_GL_SwapBuffers();
    SDL_Delay(3000);
}




void affichageComplet(int** plateau, Coordonnee positionPiece, Donnees* etat_Actuel_Partie)
{
	affichageBandeau(etat_Actuel_Partie);
	afficherPlateau(plateau, positionPiece);
}



void affichageBandeau(Donnees* etat_Actuel_Partie)
{
	glMatrixMode( GL_MODELVIEW );
    glClear(GL_COLOR_BUFFER_BIT) ;
    glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, etat_Actuel_Partie->textures[0]);
    glLoadIdentity();
	glColor3ub(255, 255, 255);
	switch((etat_Actuel_Partie->nombreTours-1) % (etat_Actuel_Partie->nombreJoueurs)) {
		case 0 :
			glBindTexture(GL_TEXTURE_2D, etat_Actuel_Partie->textures[0]);
			break;
		case 1 :
			glBindTexture(GL_TEXTURE_2D, etat_Actuel_Partie->textures[1]);
			break;
		case 2 :
			glBindTexture(GL_TEXTURE_2D, etat_Actuel_Partie->textures[2]);
			break;
		case 3 :
			glBindTexture(GL_TEXTURE_2D, etat_Actuel_Partie->textures[3]);
			break;
		default : break;
	}
	glBegin(GL_QUADS);
		glTexCoord2d(1, 0);  glVertex2d(1, 1);
		glTexCoord2d(1, 1);  glVertex2d(1, -1);
		glTexCoord2d(0, 1);  glVertex2d(-1, -1);
		glTexCoord2d(0, 0);  glVertex2d(-1, 1);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	gluOrtho2D(0,800,600,0);
	afficher_tour(etat_Actuel_Partie->nombreTours);
}





void afficherPlateau(int** plateau, Coordonnee positionPiece)
{
    glLoadIdentity();

	afficherGrille();

	if(positionPiece.x != -1) {
		afficherPieceActuelle(positionPiece);
	}
	afficherPieces(plateau);


    glFlush();
    SDL_GL_SwapBuffers();
}



void afficherGrille(void)
{
	for(int i = 0; i < 10; ++i) {
		for(int j = 0; j < 10; j++) {
			if((j + 9*i)%2 == 0) {
				glColor3ub(254, 254, 254);
			} else {
				glColor3ub(139, 139, 139);
			}
			glBegin(GL_QUADS);
			    glVertex2d(-1 + 0.15*j, 1 - 0.2*i);
			    glVertex2d(-1 + 0.15*j, 0.8 - 0.2*i);
			    glVertex2d(-0.85 + 0.15*j, 0.8 - 0.2*i);
			    glVertex2d(-0.85 + 0.15*j, 1 - 0.2*i);
			glEnd();
		}
	}
}



void afficherPieces(int** plateau)
{
	for(int i = 0; i < 10; ++i) {
		for(int j = 0; j < 10; j++) {
			glPushMatrix();
			glTranslated(-0.925 + 0.15*j, 0.9 - 0.2*i, 0);
			switch(plateau[i][j]) {
				case CASE_CARRE_J1 :
					glColor3ub(199, 44, 72);
					dessinerCarre();
					break;

				case CASE_TRIANGLE_J1 :
					glColor3ub(199, 44, 72);
					dessinerTriangle();
					break;

				case CASE_LOSANGE_J1 :
					glColor3ub(199, 44, 72);
					dessinerLosange();
					break;

				case CASE_CERCLE_J1 :
					glColor3ub(199, 44, 72);
					dessinerCercle();
					break;

				case CASE_CARRE_J2 :
					glColor3ub(20, 148, 20);
					dessinerCarre();
					break;

				case CASE_TRIANGLE_J2 :
					glColor3ub(20, 148, 20);
					dessinerTriangle();
					break;

				case CASE_LOSANGE_J2 :
					glColor3ub(20, 148, 20);
					dessinerLosange();
					break;

				case CASE_CERCLE_J2 :
					glColor3ub(20, 148, 20);
					dessinerCercle();
					break;

				case CASE_CARRE_J3 :
					glColor3ub(121, 28, 248);
					dessinerCarre();
					break;

				case CASE_TRIANGLE_J3 :
					glColor3ub(121, 28, 248);
					dessinerTriangle();
					break;

				case CASE_LOSANGE_J3 :
					glColor3ub(121, 28, 248);
					dessinerLosange();
					break;

				case CASE_CERCLE_J3 :
					glColor3ub(121, 28, 248);
					dessinerCercle();
					break;

				case CASE_CARRE_J4 :
					glColor3ub(237, 127, 16);
					dessinerCarre();
					break;

				case CASE_TRIANGLE_J4 :
					glColor3ub(237, 127, 16);
					dessinerTriangle();
					break;

				case CASE_LOSANGE_J4 :
					glColor3ub(237, 127, 16);
					dessinerLosange();
					break;

				case CASE_CERCLE_J4 :
					glColor3ub(237, 127, 16);
					dessinerCercle();
					break;

				case DEPLACEMENT_POSSIBLE :
					glColor3ub(44, 117, 255);
					dessinerCase();
					break;

				case SAUT_POSSIBLE :
					glColor3ub(135, 233, 144);
					dessinerCase();
					break;

				default :
					break;
			}
			glPopMatrix();
		}
	}
}






void dessinerCarre(void)
{
	glBegin(GL_QUADS);
		glVertex2d(-0.05, 0.06);
		glVertex2d(0.05, 0.06);
		glVertex2d(0.05, -0.06);
		glVertex2d(-0.05, -0.06);
	glEnd();
}


void dessinerTriangle(void)
{
	glBegin(GL_TRIANGLES);
		glVertex2d( 0, 0.06);
		glVertex2d(0.055, -0.06);
		glVertex2d(-0.055, -0.06);
	glEnd();
}


void dessinerLosange(void)
{
	glBegin(GL_QUADS);
		glVertex2d(0, 0.07);
		glVertex2d(0.06, 0);
		glVertex2d(0, -0.07);
		glVertex2d(-0.06, 0);
	glEnd();
}



void dessinerCercle(void)
{
	glScalef(0.75, 1, 1);
	GLUquadric* params = gluNewQuadric();
	gluQuadricDrawStyle(params, GLU_FILL);
	gluDisk(params, 0, 0.07, 100, 1);

	gluDeleteQuadric(params);
}


void dessinerCase(void)
{
	glBegin(GL_QUADS);
		glVertex2d(-0.075, 0.1);
		glVertex2d(-0.075, -0.1);
		glVertex2d(0.075, -0.1);
		glVertex2d(0.075, 0.1);
	glEnd();

	glBegin(GL_LINE_LOOP);
		glColor3ub(255, 255, 255);
		glVertex2d(-0.075, 0.1);
		glVertex2d(-0.075, -0.1);
		glVertex2d(0.075, -0.1);
		glVertex2d(0.075, 0.1);
	glEnd();
}




void afficherPieceActuelle(Coordonnee positionPiece)
{
	glBegin(GL_QUADS);
		glColor3ub(239, 216, 9);
		glVertex2d(-1 + 0.15*positionPiece.x, 1 - 0.2*positionPiece.y);
		glVertex2d(-1 + 0.15*positionPiece.x, 0.8 - 0.2*positionPiece.y);
		glVertex2d(-0.85 + 0.15*positionPiece.x, 0.8 - 0.2*positionPiece.y);
		glVertex2d(-0.85 + 0.15*positionPiece.x, 1 - 0.2*positionPiece.y);
	glEnd();
}