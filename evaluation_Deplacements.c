#include "evaluation_Deplacements.h"


void SautPionCarreIA1(int** plateau, int y, int x, int a)
{
	if((y + 2*a <= 9) && (y + 2*a >= 0)) {
		if(plateau[y + a][x] != CASE_VIDE && plateau[y + a][x] != DEPLACEMENT_POSSIBLE  && plateau[y + 2*a][x] == CASE_VIDE){
        	plateau[y + 2*a][x] = DEPLACEMENT_POSSIBLE;
        	SautPionCarreIA(plateau, y + 2*a, x);
    	}
	}
	if((x + 2*a <= 9) && (x + 2*a >= 0)) {
	    if(plateau[y][x + a] != CASE_VIDE && plateau[y][x + a] != DEPLACEMENT_POSSIBLE  &&  plateau[y][x + 2*a] == CASE_VIDE){
	        plateau[y][x + 2*a] = DEPLACEMENT_POSSIBLE;
			SautPionCarreIA(plateau, y, x + 2*a);
	    }
	}
}
void SautPionCarreIA(int** plateau, int y, int x)
{
	SautPionCarreIA1(plateau, y, x, 1);
	SautPionCarreIA1(plateau, y, x, -1);
}









void SautPionLosangeIA1(int** plateau, int y, int x, int a)
{
	if((x + 2*a <= 9) && (x + 2*a >= 0) && (y + 2*a <= 9) && (y + 2*a >= 0)) {
	    if(plateau[y + a][x + a] != CASE_VIDE && plateau[y + a][x + a] != DEPLACEMENT_POSSIBLE  &&  plateau[y + 2*a][x + 2*a] == CASE_VIDE){
	        plateau[y + 2*a][x + 2*a] = DEPLACEMENT_POSSIBLE;
	        SautPionLosangeIA(plateau, y + 2*a, x + 2*a);
	    }
	}
    
    if((x - 2*a <= 9) && (x - 2*a >= 0) && (y + 2*a <= 9) && (y + 2*a >= 0)) {
	    if(plateau[y + a][x - a] != CASE_VIDE  &&  plateau[y + a][x - a] != DEPLACEMENT_POSSIBLE  &&  plateau[y + 2*a][x - 2*a] == CASE_VIDE){
	        plateau[y + 2*a][x - 2*a] = DEPLACEMENT_POSSIBLE;
	        SautPionLosangeIA(plateau, y + 2*a, x - 2*a);
	    }
	}
}
void SautPionLosangeIA(int** plateau, int y, int x)
{
	SautPionLosangeIA1(plateau, y, x, 1);
	SautPionLosangeIA1(plateau, y, x, -1);
}









void SautPionCercleIA(int** plateau, int y, int x)
{
	SautPionCarreIA(plateau, y, x);
	SautPionLosangeIA(plateau, y, x);
}










void SautPionTriangleIA1(int** plateau, int y, int x , int a, int evalMax)
{
	if(x - 2*a <= 9 && x - 2*a >= 0 && y - 2*a <= 9 && y - 2*a >= 0) {
	    if(plateau[y - a][x - a] != CASE_VIDE  &&  plateau[y - a][x - a] != DEPLACEMENT_POSSIBLE  &&  plateau[y - 2*a][x - 2*a] == CASE_VIDE){
	        plateau[y - 2*a][x - 2*a] = DEPLACEMENT_POSSIBLE;
	        SautPionTriangleIA(plateau, y - 2*a, x - 2*a, evalMax);
	    }
	}
    
    if(x + 2*a <= 9 && x + 2*a >= 0 && y - 2*a <= 9 && y - 2*a >= 0) {
	    if(plateau[y - a][x + a] != CASE_VIDE  &&  plateau[y - a][x + a] != DEPLACEMENT_POSSIBLE  &&  plateau[y - 2*a][x + 2*a] == CASE_VIDE){
	        plateau[y - 2*a][x + 2*a] = DEPLACEMENT_POSSIBLE;
	        SautPionTriangleIA(plateau, y - 2*a, x + 2*a, evalMax);
	    }
	}
    
    if((y + 2*a <= 9) && (y + 2*a >= 0)) {
	    if(plateau[y + a][x] != CASE_VIDE  &&  plateau[y + a][x] != DEPLACEMENT_POSSIBLE  &&  plateau[y + 2*a][x] == CASE_VIDE){
	        plateau[y + 2*a][x] = DEPLACEMENT_POSSIBLE;
	        SautPionTriangleIA(plateau, y + 2*a, x, evalMax);
	    }
	}
}
void SautPionTriangleIA(int** plateau, int y, int x, int evalMax)
{
	int a;
	if(evalMax) {
		a = -1;
	} else {
		a = 1;
	}
	SautPionTriangleIA1(plateau, y, x, a, evalMax);
}















void calculDeplacementPossibe(int** plateau, int i, int j)
{
    Coordonnee pion;
    pion.x = j;
    pion.y = i;
    switch (plateau[i][j]) {
        case CASE_CARRE_J1 :
            deplacementPionCarre(plateau, pion);
            SautPionCarreIA(plateau, i, j);
            break;
        case CASE_TRIANGLE_J1 :
            deplacementPionTriangle(plateau, pion, 0);
            SautPionTriangleIA(plateau, i, j, 0);
            break;
        case CASE_LOSANGE_J1 :
            deplacementPionLosange(plateau, pion);
            SautPionLosangeIA(plateau, i, j);
            break;    
        case CASE_CERCLE_J1 :
            deplacementPionCercle(plateau, pion);
            SautPionCercleIA(plateau, i, j);
            break;            
        case CASE_CARRE_J2 :
            deplacementPionCarre(plateau, pion);
            SautPionCarreIA(plateau, i, j);
            break;
        case CASE_TRIANGLE_J2 :
            deplacementPionTriangle(plateau, pion, 1);
            SautPionTriangleIA(plateau, i, j, 1);
            break;
        case CASE_LOSANGE_J2 :
            deplacementPionLosange(plateau, pion);
            SautPionLosangeIA(plateau, i, j);
            break;    
        case CASE_CERCLE_J2 :
            deplacementPionCercle(plateau, pion);
            SautPionCercleIA(plateau, i, j);
            break;
        default :
            break;   
    }
}





Deplacement* creer_Deplacement(void)
{
    Deplacement* liste;
    liste = (Deplacement*) malloc(sizeof(Deplacement));
    return (liste);
}

Deplacement* ajouter(Deplacement* teteListe, int i, int j , int k, int l)
{
    Deplacement* p = creer_Deplacement();
    p->debutCoupJoue.x = j;
    p->debutCoupJoue.y = i;
    p->finCoupJoue.x = l;
    p->finCoupJoue.y = k;
    p->suivant = teteListe;
    return(p);
}




Deplacement* transition(int** plateau, int evalMax)
{
    Deplacement* listeCoupPossible = NULL;    
    for (int i = 0; i < TAILLE_PLATEAU; i++){
        for (int j = 0; j < TAILLE_PLATEAU; j++){
            if(evalMax){
                if((plateau[i][j] == CASE_CARRE_J2) || (plateau[i][j] == CASE_TRIANGLE_J2) || (plateau[i][j] == CASE_LOSANGE_J2) || (plateau[i][j] == CASE_CERCLE_J2)) {
                        
                    calculDeplacementPossibe(plateau, i, j);
                    SuppressionDeplacementsInterdis(plateau, 1);
                    
                }
            } else {
                if((plateau[i][j] == CASE_CARRE_J1) || (plateau[i][j] == CASE_TRIANGLE_J1) || (plateau[i][j] == CASE_LOSANGE_J1) || (plateau[i][j] == CASE_CERCLE_J1)) {
                    calculDeplacementPossibe(plateau, i, j);
                    SuppressionDeplacementsInterdis(plateau, 0);                    
                }
            } 
            
            for (int n = 0; n < TAILLE_PLATEAU; n++){
                for (int m = 0; m < TAILLE_PLATEAU; m++){
                    if(plateau[n][m] == DEPLACEMENT_POSSIBLE){
                        listeCoupPossible = ajouter(listeCoupPossible, i, j, n, m);
                    }
                }
            }
            clearDeplacement(plateau);
        }
    }
    return(listeCoupPossible);
}