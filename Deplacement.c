#include "Deplacement.h"



void deplacementPionCarre1(int** plateau, Coordonnee coordsPion, int a)
{
	if(coordsPion.y + a <= 9 && coordsPion.y + a >= 0) {
		if(plateau[coordsPion.y + a][coordsPion.x] == CASE_VIDE){
        	plateau[coordsPion.y + a][coordsPion.x] = DEPLACEMENT_POSSIBLE;
    	}
	}
    if(coordsPion.x + a <= 9 && coordsPion.x + a >= 1) {
	    if(plateau[coordsPion.y][coordsPion.x + a] == CASE_VIDE){
	        plateau[coordsPion.y][coordsPion.x + a] = DEPLACEMENT_POSSIBLE;
	    }
	}
}
void deplacementPionCarre(int** plateau, Coordonnee coordsPion)
{

	deplacementPionCarre1(plateau, coordsPion, 1);
	deplacementPionCarre1(plateau, coordsPion, -1);
}





void deplacementPionTriangle1(int** plateau, Coordonnee coordsPion, int a, int b)
{
	if(coordsPion.x - a + b <= 9 && coordsPion.x - a + b >= 0 && coordsPion.y - a - b <= 9 && coordsPion.y - a - b >= 0) {
	    if(plateau[coordsPion.y - a - b][coordsPion.x - a + b] == CASE_VIDE){
	        plateau[coordsPion.y - a - b][coordsPion.x - a + b] = DEPLACEMENT_POSSIBLE;
	    }
	}
    
    if(coordsPion.x + a + b <= 9 && coordsPion.x + a + b >= 0 && coordsPion.y - a + b <= 9 && coordsPion.y - a + b >= 0) {
	    if(plateau[coordsPion.y - a + b][coordsPion.x + a + b] == CASE_VIDE){
	        plateau[coordsPion.y - a + b][coordsPion.x + a + b] = DEPLACEMENT_POSSIBLE;
	    }
	}
    
    if(coordsPion.x - b <= 9 && coordsPion.x - b >= 0 && coordsPion.y + a <= 9 && coordsPion.y + a >= 0) {
	    if(plateau[coordsPion.y + a][coordsPion.x - b] == CASE_VIDE){
	        plateau[coordsPion.y + a][coordsPion.x - b] = DEPLACEMENT_POSSIBLE;
	    }
	}
	
}
void deplacementPionTriangle(int** plateau, Coordonnee coordsPion, int joueur)
{
	int a;
	int b;
	switch(joueur) {
		case 0 :
			a = 1;
			b = 0;
			break;

		case 1 :
			a = -1;
			b = 0;
			break;

		case 2 :
			a = 0;
			b = 1;
			break;

		case 3 :
			a = 0;
			b = -1;
			break;


		default :
			break;
	}
	
	deplacementPionTriangle1(plateau, coordsPion, a, b);
}




void deplacementPionLosange1(int** plateau, Coordonnee coordsPion, int a)
{
	if(coordsPion.x + a <= 9 && coordsPion.x + a >= 0 && coordsPion.y + a <= 9 && coordsPion.y + a >= 0) {
	    if(plateau[coordsPion.y + a][coordsPion.x + a] == CASE_VIDE){
	        plateau[coordsPion.y + a][coordsPion.x + a] = DEPLACEMENT_POSSIBLE;
	    }
	}
    
    if(coordsPion.x - a <= 9 && coordsPion.x - a >= 0 && coordsPion.y + a <= 9 && coordsPion.y + a >= 0) {
	    if(plateau[coordsPion.y + a][coordsPion.x - a] == CASE_VIDE){
	        plateau[coordsPion.y + a][coordsPion.x - a] = DEPLACEMENT_POSSIBLE;
	    }
	}
}
void deplacementPionLosange(int** plateau, Coordonnee coordsPion)
{
	deplacementPionLosange1(plateau, coordsPion, 1);
	deplacementPionLosange1(plateau, coordsPion, -1);
}






void deplacementPionCercle(int** plateau, Coordonnee coordsPion)
{
	deplacementPionCarre(plateau, coordsPion);
	deplacementPionLosange(plateau, coordsPion);	
}



void SautPionCarre1(int** plateau, Coordonnee coordsPion, int a)
{
	if(coordsPion.y + 2*a <= 9 && coordsPion.y + 2*a >= 0) {
		if(plateau[coordsPion.y + a][coordsPion.x] != CASE_VIDE  && plateau[coordsPion.y + 2*a][coordsPion.x] == CASE_VIDE){
        	plateau[coordsPion.y + 2*a][coordsPion.x] = SAUT_POSSIBLE;
    	}
	}
	if(coordsPion.x + 2*a <= 9 && coordsPion.x + 2*a >= 0) {
	    if(plateau[coordsPion.y][coordsPion.x + a] != CASE_VIDE  &&  plateau[coordsPion.y][coordsPion.x + 2*a] == CASE_VIDE){
	        plateau[coordsPion.y][coordsPion.x + 2*a] = SAUT_POSSIBLE;
	    }
	}
}
void SautPionCarre(int** plateau, Coordonnee coordsPion)
{
	SautPionCarre1(plateau, coordsPion, 1);
	SautPionCarre1(plateau, coordsPion, -1);
}



void SautPionTriangle1(int** plateau, Coordonnee coordsPion, int a, int b)
{
	if(coordsPion.x - 2*a + 2*b <= 9 && coordsPion.x - 2*a + 2*b >= 0 && coordsPion.y - 2*a - 2*b <= 9 && coordsPion.y - 2*a - 2*b >= 0) {
	    if(plateau[coordsPion.y - a - b][coordsPion.x - a + b] != CASE_VIDE  &&  plateau[coordsPion.y - 2*a - 2*b][coordsPion.x - 2*a + 2*b] == CASE_VIDE){
	        plateau[coordsPion.y - 2*a - 2*b][coordsPion.x - 2*a + 2*b] = SAUT_POSSIBLE;
	    }
	}
    
    if(coordsPion.x + 2*a + 2*b <= 9 && coordsPion.x + 2*a + 2*b >= 0 && coordsPion.y - 2*a + 2*b <= 9 && coordsPion.y - 2*a + 2*b >= 0) {
	    if(plateau[coordsPion.y - a + b][coordsPion.x + a + b] != CASE_VIDE  &&  plateau[coordsPion.y - 2*a + 2*b][coordsPion.x + 2*a + 2*b] == CASE_VIDE){
	        plateau[coordsPion.y - 2*a + 2*b][coordsPion.x + 2*a + 2*b] = SAUT_POSSIBLE;
	    }
	}
    
    if(coordsPion.x - 2*b <= 9 && coordsPion.x - 2*b >= 0 && coordsPion.y + 2*a <= 9 && coordsPion.y + 2*a >= 0) {
	    if(plateau[coordsPion.y + a][coordsPion.x - b] != CASE_VIDE  &&  plateau[coordsPion.y + 2*a][coordsPion.x - 2*b] == CASE_VIDE){
	        plateau[coordsPion.y + 2*a][coordsPion.x - 2*b] = SAUT_POSSIBLE;
	    }
	}
}

void SautPionTriangle(int** plateau, Coordonnee coordsPion, int joueur)
{
	int a;
	int b;
	switch(joueur) {
		case 0 :
			a = 1;
			b = 0;
			break;

		case 1 :
			a = -1;
			b = 0;
			break;

		case 2 :
			a = 0;
			b = 1;
			break;

		case 3 :
			a = 0;
			b = -1;
			break;


		default :
			break;
	}
	
	SautPionTriangle1(plateau, coordsPion, a, b);
}



void SautPionLosange1(int** plateau, Coordonnee coordsPion, int a)
{
	if(coordsPion.x + 2*a <= 9 && coordsPion.x + 2*a >= 0 && coordsPion.y + 2*a <= 9 && coordsPion.y + 2*a >= 0) {
	    if(plateau[coordsPion.y + a][coordsPion.x + a] != CASE_VIDE  &&  plateau[coordsPion.y + 2*a][coordsPion.x + 2*a] == CASE_VIDE){
	        plateau[coordsPion.y + 2*a][coordsPion.x + 2*a] = SAUT_POSSIBLE;
	    }
	}
    
    if(coordsPion.x - 2*a <= 9 && coordsPion.x - 2*a >= 0 && coordsPion.y + 2*a <= 9 && coordsPion.y + 2*a >= 0) {
	    if(plateau[coordsPion.y + a][coordsPion.x - a] != CASE_VIDE  &&  plateau[coordsPion.y + 2*a][coordsPion.x - 2*a] == CASE_VIDE){
	        plateau[coordsPion.y + 2*a][coordsPion.x - 2*a] = SAUT_POSSIBLE;
	    }
	}
}
void SautPionLosange(int** plateau, Coordonnee coordsPion)
{
	SautPionLosange1(plateau, coordsPion, 1);
	SautPionLosange1(plateau, coordsPion, -1);
}




void SautPionCercle(int** plateau, Coordonnee coordsPion)
{
	SautPionCarre(plateau, coordsPion);
	SautPionLosange(plateau, coordsPion);
}





void SuppressionDeplacementsInterdis(int** plateau, int joueur)
{
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			if((plateau[i][j] == DEPLACEMENT_POSSIBLE || plateau[i][j] == SAUT_POSSIBLE)  &&  joueur < 2  &&  (j == 0 || j == 9)) {
				plateau[i][j] = CASE_VIDE;
			}

			if((plateau[i][j] == DEPLACEMENT_POSSIBLE || plateau[i][j] == SAUT_POSSIBLE)  &&  joueur > 1  &&  (i == 0 || i == 9)) {
				plateau[i][j] = CASE_VIDE;
			}
		}
	}
}


int nombreSautPossibles(int** plateau)
{
	int compteur = 0;
	for(int i = 0; i < TAILLE_PLATEAU; i++) {
        	for(int j = 0; j < TAILLE_PLATEAU; j++){
            		if(plateau[i][j] == SAUT_POSSIBLE){
                		compteur++;
           		 }
       		 }
   	 }
    return(compteur);
}




void suiteDeSautsJ1(int** plateau, Coordonnee positionClic, int case1)
{
	switch(case1) {
		case CASE_CARRE_J1 :
			SautPionCarre(plateau, positionClic);
			break;

		case CASE_TRIANGLE_J1 :
			SautPionTriangle(plateau, positionClic, 0);
			break;

		case CASE_LOSANGE_J1 :
			SautPionLosange(plateau, positionClic);
			break;

		case CASE_CERCLE_J1 :
			SautPionCercle(plateau, positionClic);
			break;

		default :
			break;
	}
}
void suiteDeSautsJ2(int** plateau, Coordonnee positionClic, int case1)
{
	switch(case1) {
		case CASE_CARRE_J2 :
			SautPionCarre(plateau, positionClic);
			break;

		case CASE_TRIANGLE_J2 :
			SautPionTriangle(plateau, positionClic, 1);
			break;

		case CASE_LOSANGE_J2 :
			SautPionLosange(plateau, positionClic);
			break;

		case CASE_CERCLE_J2 :
			SautPionCercle(plateau, positionClic);
			break;

		default :
			break;
	}
}
void suiteDeSautsJ3(int** plateau, Coordonnee positionClic, int case1)
{
	switch(case1) {
		case CASE_CARRE_J3 :
			SautPionCarre(plateau, positionClic);
			break;

		case CASE_TRIANGLE_J3 :
			SautPionTriangle(plateau, positionClic, 2);
			break;

		case CASE_LOSANGE_J3 :
			SautPionLosange(plateau, positionClic);
			break;

		case CASE_CERCLE_J3 :
			SautPionCercle(plateau, positionClic);
			break;

		default :
			break;
	}
}
void suiteDeSautsJ4(int** plateau, Coordonnee positionClic, int case1)
{
	switch(case1) {
		case CASE_CARRE_J4 :
			SautPionCarre(plateau, positionClic);
			break;

		case CASE_TRIANGLE_J4 :
			SautPionTriangle(plateau, positionClic, 3);
			break;

		case CASE_LOSANGE_J4 :
			SautPionLosange(plateau, positionClic);
			break;

		case CASE_CERCLE_J4 :
			SautPionCercle(plateau, positionClic);
			break;

		default :
			break;
	}
}

void suiteDeSauts(int** plateau, Coordonnee positionClic, int case1, int joueur, Donnees* etat_Actuel_Partie)
{
	switch(joueur) {

		case 0 : 
			suiteDeSautsJ1(plateau, positionClic, case1);
			break;

		case 1 : 
			suiteDeSautsJ2(plateau, positionClic, case1);
			break;

		case 2 : 
			suiteDeSautsJ3(plateau, positionClic, case1);
			break;

		case 3 : 
			suiteDeSautsJ4(plateau, positionClic, case1);
			break;

		default :
			break;
	}

	if(nombreSautPossibles(plateau) > 0) {
		afficherPlateau(plateau, positionClic);


		int case2;
		Coordonnee positionClic2;

		do {
			positionClic2 = positionCliquee();
			case2 = plateau[positionClic2.y][positionClic2.x];

		} while(case2 != SAUT_POSSIBLE  &&  (positionClic2.x != positionClic.x || positionClic2.y != positionClic.y) );
		
		if(case2 == SAUT_POSSIBLE) {
			plateau[positionClic2.y][positionClic2.x] = plateau[positionClic.y][positionClic.x];
			plateau[positionClic.y][positionClic.x] = POSITION_INITIALE;
			clearDeplacement(plateau);
			suiteDeSauts(plateau, positionClic2, case1, joueur, etat_Actuel_Partie);
		} else {
			clearDeplacement(plateau);
			clearPositionInitiale(plateau);
		}	
	} else {
		clearDeplacement(plateau);
		clearPositionInitiale(plateau);
	}
	
}
