#include "main_Traverse.h"


int** generationPlateau(int nombreJoueurs)
{
	int** plateau = (int**) malloc(TAILLE_PLATEAU*sizeof(int*));
    for(int i = 0; i < TAILLE_PLATEAU; i++){
        plateau[i] = (int*) malloc (TAILLE_PLATEAU*sizeof(int));
        for (int j = 0; j < TAILLE_PLATEAU; j++){
            plateau[i][j] = CASE_VIDE;
        }
    }
    if(nombreJoueurs >= 1) {
    	plateau[9][1] = CASE_CARRE_J1;
	    plateau[9][2] = CASE_TRIANGLE_J1;
	    plateau[9][3] = CASE_LOSANGE_J1;
	    plateau[9][4] = CASE_CERCLE_J1;
	    plateau[9][5] = CASE_CERCLE_J1;
	    plateau[9][6] = CASE_LOSANGE_J1;
	    plateau[9][7] = CASE_TRIANGLE_J1;
	    plateau[9][8] = CASE_CARRE_J1;
    }
    if(nombreJoueurs >= 2) {
    	plateau[0][1] = CASE_CARRE_J2;
    	plateau[0][2] = CASE_TRIANGLE_J2;
    	plateau[0][3] = CASE_LOSANGE_J2;
	    plateau[0][4] = CASE_CERCLE_J2;
	    plateau[0][5] = CASE_CERCLE_J2;
	    plateau[0][6] = CASE_LOSANGE_J2;
	    plateau[0][7] = CASE_TRIANGLE_J2;
	    plateau[0][8] = CASE_CARRE_J2;
    }
    if(nombreJoueurs >= 3) {
    	plateau[1][0] = CASE_CARRE_J3;
    	plateau[2][0] = CASE_TRIANGLE_J3;
    	plateau[3][0] = CASE_LOSANGE_J3;
	    plateau[4][0] = CASE_CERCLE_J3;
	    plateau[5][0] = CASE_CERCLE_J3;
	    plateau[6][0] = CASE_LOSANGE_J3;
	    plateau[7][0] = CASE_TRIANGLE_J3;
	    plateau[8][0] = CASE_CARRE_J3;
    }
    if(nombreJoueurs >= 4) {
    	plateau[1][9] = CASE_CARRE_J4;
    	plateau[2][9] = CASE_TRIANGLE_J4;
    	plateau[3][9] = CASE_LOSANGE_J4;
	    plateau[4][9] = CASE_CERCLE_J4;
	    plateau[5][9] = CASE_CERCLE_J4;
	    plateau[6][9] = CASE_LOSANGE_J4;
	    plateau[7][9] = CASE_TRIANGLE_J4;
	    plateau[8][9] = CASE_CARRE_J4;
    }

    return(plateau);

}



int verifPlateauIdentique(int*** plateaux, int nombreTours)
{
    int plateau_identique = 0;
    int compteur;
    int retour;

    for(int i = 0; i < nombreTours; i++) {
    	compteur = 0;
        for(int j = 0; j < TAILLE_PLATEAU; j++) {
            for(int k = 0; k < TAILLE_PLATEAU; k++){
                if(plateaux[nombreTours][j][k] == plateaux[i][j][k]){
                    compteur++;
                }
            }
        }
        if(compteur == 100) {
        	plateau_identique++;
        }
    }

    if(plateau_identique > 1){
        retour = 1;
    } else {
        retour = 0;
    }

    return(retour);
}





int unDansBase(int** plateau)
{
	int verif = 0;
	for(int i = 0; i < TAILLE_PLATEAU; i++) {
			if(plateau[0][i] == CASE_CARRE_J2 || plateau[0][i] == CASE_TRIANGLE_J2 || plateau[0][i] == CASE_LOSANGE_J2 || plateau[0][i] == CASE_CERCLE_J2) {
				verif = 1;
			}
			if(plateau[9][i] == CASE_CARRE_J1 || plateau[9][i] == CASE_TRIANGLE_J1 || plateau[9][i] == CASE_LOSANGE_J1 || plateau[9][i] == CASE_CERCLE_J1) {
				verif = 1;
			}
			if(plateau[i][9] == CASE_CARRE_J4 || plateau[i][9] == CASE_TRIANGLE_J4 || plateau[i][9] == CASE_LOSANGE_J4 || plateau[i][9] == CASE_CERCLE_J4) {
				verif = 1;
			}
			if(plateau[i][0] == CASE_CARRE_J3 || plateau[i][0] == CASE_TRIANGLE_J3 || plateau[i][0] == CASE_LOSANGE_J3 || plateau[i][0] == CASE_CERCLE_J3) {
				verif = 1;
			}
	}
	return(verif);
}


int victoire(int** plateau)
{
    int result = 0;
    
    int nombre_pions_joueur_arrives[4];
    
    for (int i=0; i<4; i++){
        nombre_pions_joueur_arrives[i] = 0;
    }

    for (int i=0; i<TAILLE_PLATEAU; i++){
        
        if(plateau[0][i] == CASE_CARRE_J1 || plateau[0][i] == CASE_TRIANGLE_J1 || plateau[0][i] == CASE_LOSANGE_J1 || plateau[0][i] == CASE_CERCLE_J1){
            nombre_pions_joueur_arrives[0] ++;
        }
        
        if(plateau[9][i] == CASE_CARRE_J2 || plateau[9][i] == CASE_TRIANGLE_J2 || plateau[9][i] == CASE_LOSANGE_J2 || plateau[9][i] == CASE_CERCLE_J2) {
            nombre_pions_joueur_arrives[1] ++;
        }
        
        if(plateau[i][9] == CASE_CARRE_J3 || plateau[i][9] == CASE_TRIANGLE_J3 || plateau[i][9] == CASE_LOSANGE_J3 || plateau[i][9] == CASE_CERCLE_J3) {
            nombre_pions_joueur_arrives[2] ++;
        }
        
        if(plateau[i][0] == CASE_CARRE_J4 || plateau[i][0] == CASE_TRIANGLE_J4 || plateau[i][0] == CASE_LOSANGE_J4 || plateau[i][0] == CASE_CERCLE_J4) {
			nombre_pions_joueur_arrives[3] ++;
        }
    }
    
    for (int i=0; i<4; i++){
        if(nombre_pions_joueur_arrives[i] == 8){
            result = 10*(i+1);
        }
    }
    
    
    return(result);
}


int partieFini(int*** plateaux, Donnees* etat_Actuel_Partie)
{
	int fini = 0;
	if(etat_Actuel_Partie->nombreTours >= 30*etat_Actuel_Partie->nombreJoueurs) {
		fini += unDansBase(plateaux[etat_Actuel_Partie->nombreTours]);
	}

	fini += verifPlateauIdentique(plateaux, etat_Actuel_Partie->nombreTours);
    fini += victoire(plateaux[etat_Actuel_Partie->nombreTours]);
    
	return(fini);
}



void choixPieceJ1(int** plateau, Coordonnee* positionClic, int* case1)
{
	do {
		*positionClic = positionCliquee();
		*case1 = plateau[positionClic->y][positionClic->x];
	} while( (*case1 != CASE_CARRE_J1) && (*case1 != CASE_TRIANGLE_J1) && (*case1 != CASE_LOSANGE_J1) && (*case1 != CASE_CERCLE_J1) );

	switch(*case1) {
		case CASE_CARRE_J1 :
			SautPionCarre(plateau, *positionClic);
			deplacementPionCarre(plateau, *positionClic);
			break;

		case CASE_TRIANGLE_J1 :
			SautPionTriangle(plateau, *positionClic, 0);
			deplacementPionTriangle(plateau, *positionClic, 0);
			break;

		case CASE_LOSANGE_J1 :
			SautPionLosange(plateau, *positionClic);
			deplacementPionLosange(plateau, *positionClic);
			break;

		case CASE_CERCLE_J1 :
			SautPionCercle(plateau, *positionClic);
			deplacementPionCercle(plateau, *positionClic);
			break;

		default :
			break;
	}
	SuppressionDeplacementsInterdis(plateau, 0);
}

void choixPieceJ2(int** plateau, Coordonnee* positionClic, int* case1)
{
	do {
		*positionClic = positionCliquee();
		*case1 = plateau[positionClic->y][positionClic->x];
	} while( (*case1 != CASE_CARRE_J2) && (*case1 != CASE_TRIANGLE_J2) && (*case1 != CASE_LOSANGE_J2) && (*case1 != CASE_CERCLE_J2) );

	switch(*case1) {
		case CASE_CARRE_J2 :
			SautPionCarre(plateau, *positionClic);
			deplacementPionCarre(plateau, *positionClic);
			break;

		case CASE_TRIANGLE_J2 :
			SautPionTriangle(plateau, *positionClic, 1);
			deplacementPionTriangle(plateau, *positionClic, 1);
			break;

		case CASE_LOSANGE_J2 :
			SautPionLosange(plateau, *positionClic);
			deplacementPionLosange(plateau, *positionClic);
			break;

		case CASE_CERCLE_J2 :
			SautPionCercle(plateau, *positionClic);
			deplacementPionCercle(plateau, *positionClic);
			break;

		default :
			break;
	}
	SuppressionDeplacementsInterdis(plateau, 1);
}

void choixPieceJ3(int** plateau, Coordonnee* positionClic, int* case1)
{
	do {
		*positionClic = positionCliquee();
		*case1 = plateau[positionClic->y][positionClic->x];
	} while( (*case1 != CASE_CARRE_J3) && (*case1 != CASE_TRIANGLE_J3) && (*case1 != CASE_LOSANGE_J3) && (*case1 != CASE_CERCLE_J3) );

	switch(*case1) {
		case CASE_CARRE_J3 :
			SautPionCarre(plateau, *positionClic);
			deplacementPionCarre(plateau, *positionClic);
			break;

		case CASE_TRIANGLE_J3 :
			SautPionTriangle(plateau, *positionClic, 2);
			deplacementPionTriangle(plateau, *positionClic, 2);
			break;

		case CASE_LOSANGE_J3 :
			SautPionLosange(plateau, *positionClic);
			deplacementPionLosange(plateau, *positionClic);
			break;

		case CASE_CERCLE_J3 :
			SautPionCercle(plateau, *positionClic);
			deplacementPionCercle(plateau, *positionClic);
			break;

		default :
			break;
	}
	SuppressionDeplacementsInterdis(plateau, 2);
}

void choixPieceJ4(int** plateau, Coordonnee* positionClic, int* case1)
{
	do {
		*positionClic = positionCliquee();
		*case1 = plateau[positionClic->y][positionClic->x];
	} while( (*case1 != CASE_CARRE_J4) && (*case1 != CASE_TRIANGLE_J4) && (*case1 != CASE_LOSANGE_J4) && (*case1 != CASE_CERCLE_J4) );

	switch(*case1) {
		case CASE_CARRE_J4 :
			SautPionCarre(plateau, *positionClic);
			deplacementPionCarre(plateau, *positionClic);
			break;

		case CASE_TRIANGLE_J4 :
			SautPionTriangle(plateau, *positionClic, 3);
			deplacementPionTriangle(plateau, *positionClic, 3);
			break;

		case CASE_LOSANGE_J4 :
			SautPionLosange(plateau, *positionClic);
			deplacementPionLosange(plateau, *positionClic);
			break;

		case CASE_CERCLE_J4 :
			SautPionCercle(plateau, *positionClic);
			deplacementPionCercle(plateau, *positionClic);
			break;

		default :
			break;
	}
	SuppressionDeplacementsInterdis(plateau, 3);
}




void tour_Joueur(int** plateau, int joueur, Donnees* etat_Actuel_Partie)
{
	Coordonnee positionClic;
	positionClic.x = -1;
	positionClic.y = -1;
	affichageComplet(plateau, positionClic, etat_Actuel_Partie);
	int case1;
	
	switch(joueur) {
		case 0 :
			choixPieceJ1(plateau, &positionClic, &case1);
			break;
		case 1 :
			choixPieceJ2(plateau, &positionClic, &case1);
			break;
		case 2 :
			choixPieceJ3(plateau, &positionClic, &case1);
			break;
		case 3 :
			choixPieceJ4(plateau, &positionClic, &case1);
			break;
	}
		
	affichageComplet(plateau, positionClic, etat_Actuel_Partie);
	Coordonnee positionClic2;
	int case2;

	do {
		positionClic2 = positionCliquee();
		case2 = plateau[positionClic2.y][positionClic2.x];
	} while( case2 != DEPLACEMENT_POSSIBLE  &&  case2 != SAUT_POSSIBLE  &&  (positionClic2.x != positionClic.x || positionClic2.y != positionClic.y) );
	
	switch(case2) {
		case DEPLACEMENT_POSSIBLE :
			plateau[positionClic2.y][positionClic2.x] = plateau[positionClic.y][positionClic.x];
			plateau[positionClic.y][positionClic.x] = CASE_VIDE;
			clearDeplacement(plateau);
			clearPositionInitiale(plateau);
			break;

		case SAUT_POSSIBLE :
			plateau[positionClic2.y][positionClic2.x] = plateau[positionClic.y][positionClic.x];
			plateau[positionClic.y][positionClic.x] = POSITION_INITIALE;
			clearDeplacement(plateau);
			suiteDeSauts(plateau, positionClic2, case1, joueur, etat_Actuel_Partie);
			break;

		default :
			clearDeplacement(plateau);
			clearPositionInitiale(plateau);
			tour_Joueur(plateau, joueur, etat_Actuel_Partie);
			break;
	}
	positionClic.x = -1;
	positionClic.y = -1;
	affichageComplet(plateau, positionClic, etat_Actuel_Partie);
}




void clearDeplacement(int** plateau)
{
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			if(plateau[i][j] == DEPLACEMENT_POSSIBLE  ||  plateau[i][j] == SAUT_POSSIBLE) {
				plateau[i][j] = CASE_VIDE;
			}
		}
	}
}

void clearPositionInitiale(int** plateau)
{
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			if(plateau[i][j] == POSITION_INITIALE) {
				plateau[i][j] = CASE_VIDE;
			}
		}
	}
}
	







Coordonnee positionCliquee(void)
{
	int clic = 0;
	Coordonnee positionClic;
	SDL_Event event;
	while(clic == 0) {
		SDL_WaitEvent(&event);
		switch(event.type) {
			case SDL_QUIT : 
				SDL_Quit();
				exit(1);
				break;

			case SDL_MOUSEBUTTONDOWN :
				if(event.button.button == SDL_BUTTON_LEFT) {
					positionClic.x = (int) 10*4/3*(  ((double)event.button.x) / ((double)LONGUEUR_FENETRE)  );
					positionClic.y = (int) 10*(  ((double)event.button.y) / ((double)LARGEUR_FENETRE)  );
				}
				if(positionClic.x <= 9 && positionClic.x >= 0 && positionClic.y <= 9 && positionClic.y >= 0) {
					clic = 1;
				}
				break;

			default :
				break;
		}	
	}
	
	return(positionClic);
}



void copierTableau(int** tab2, int** tab1)
{
	for (int i = 0; i < TAILLE_PLATEAU; i++) {
		for (int j = 0; j < TAILLE_PLATEAU; j++) {
			tab2[i][j] = tab1[i][j];
		}
	}
}





void initialiserEtatPartie(Donnees* etat_Actuel_Partie, int jcj)
{
	etat_Actuel_Partie->nombreTours = 0;;
	etat_Actuel_Partie->jcj = jcj;
	etat_Actuel_Partie->textures[0] = chargerTexture("Texture/bandeau_rouge.png");
	etat_Actuel_Partie->textures[1] = chargerTexture("Texture/bandeau_vert.png");
	etat_Actuel_Partie->textures[2] = chargerTexture("Texture/bandeau_violet.png");
	etat_Actuel_Partie->textures[3] = chargerTexture("Texture/bandeau_orange.png");
}





void Traverse(int*** plateaux, Donnees* etat_Actuel_Partie)
{

	int joueur = (etat_Actuel_Partie->nombreTours) % (etat_Actuel_Partie->nombreJoueurs);
	int partie_Fini = 0;
	
	while(!partie_Fini) {
		etat_Actuel_Partie->nombreTours++;
		plateaux = (int***) realloc(plateaux, (etat_Actuel_Partie->nombreTours + 1)*sizeof(int**));
		
		plateaux[etat_Actuel_Partie->nombreTours] = (int**) malloc(TAILLE_PLATEAU*sizeof(int*));
		for(int i = 0; i < TAILLE_PLATEAU; i++) {
			plateaux[etat_Actuel_Partie->nombreTours][i] = (int*) malloc(TAILLE_PLATEAU*sizeof(int));
		}

		copierTableau(plateaux[etat_Actuel_Partie->nombreTours], plateaux[etat_Actuel_Partie->nombreTours - 1]);
		
			Coordonnee positionClic;
			positionClic.x = -1;
			positionClic.y = -1;
			affichageComplet(plateaux[etat_Actuel_Partie->nombreTours], positionClic, etat_Actuel_Partie);
		if(etat_Actuel_Partie->jcj ||  joueur == 0) {
			tour_Joueur(plateaux[etat_Actuel_Partie->nombreTours], joueur, etat_Actuel_Partie);
		} else {        
	        jouerIA (plateaux[etat_Actuel_Partie->nombreTours], etat_Actuel_Partie);
	        Coordonnee positionClic;
	        positionClic.x = -1;
	        positionClic.y = -1;
	        afficherPlateau(plateaux[etat_Actuel_Partie->nombreTours], positionClic);
	    }
        
        
		joueur = (joueur + 1)%(etat_Actuel_Partie->nombreJoueurs);
		
		partie_Fini = partieFini(plateaux, etat_Actuel_Partie);
        SauvegardePartieEnCours(plateaux, etat_Actuel_Partie);
	}
	
	ecranVictoire(partie_Fini);

}




void lancerTraverse(int nombreJoueurs, int jcj, int dificulte)
{
	Donnees etat_Actuel_Partie;
	initialiserEtatPartie(&etat_Actuel_Partie, jcj);
	etat_Actuel_Partie.nombreJoueurs = nombreJoueurs;
	etat_Actuel_Partie.profondeur = dificulte;
	int*** plateaux = NULL;
	plateaux = (int***) malloc(1*sizeof(int**));
	plateaux[0] = generationPlateau(nombreJoueurs);
	Traverse(plateaux, &etat_Actuel_Partie);
}



void relancerTraverse(void)
{
	Donnees etat_Actuel_Partie;
	initialiserEtatPartie(&etat_Actuel_Partie, 0);
	int*** plateaux = NULL;
	plateaux = recupererPartieEnCours(&etat_Actuel_Partie);
	Traverse(plateaux, &etat_Actuel_Partie);
}
