#include "IA_Traverse.h"



int evaluation(int** plateau)
{
    int utilite = 0;
    for (int i = 0; i < TAILLE_PLATEAU; i++) {
        for (int j = 0; j < TAILLE_PLATEAU; j++) {
            if((plateau[i][j] == CASE_CARRE_J2) || (plateau[i][j] == CASE_TRIANGLE_J2) || (plateau[i][j] == CASE_LOSANGE_J2) || (plateau[i][j] == CASE_CERCLE_J2)) {
                if(i == 0) {
                    utilite -= 1000;
                }
                for (int k = 1; k < TAILLE_PLATEAU-1; k++) {
                    if((plateau[TAILLE_PLATEAU-1][k] != CASE_CARRE_J2) && (plateau[TAILLE_PLATEAU-1][k] != CASE_TRIANGLE_J2) && (plateau[TAILLE_PLATEAU-1][k] != CASE_LOSANGE_J2) && (plateau[TAILLE_PLATEAU-1][k] != CASE_CERCLE_J2)) {
                        utilite -= 10*Valeur_absolue(TAILLE_PLATEAU-1-i) + Valeur_absolue(j - k); // La distance a une case d'arrivee libre
                    }
                }
            } else if((plateau[i][j] == CASE_CARRE_J1) || (plateau[i][j] == CASE_TRIANGLE_J1) || (plateau[i][j] == CASE_LOSANGE_J1) || (plateau[i][j] == CASE_CERCLE_J1)) {
                if(i == TAILLE_PLATEAU-1) {
                    utilite += 1000;
                }
                for (int k = 1; k < TAILLE_PLATEAU-1; k++) {
                    if((plateau[0][k] != CASE_CARRE_J1) && (plateau[0][k] != CASE_TRIANGLE_J1) && (plateau[0][k] != CASE_LOSANGE_J1) && (plateau[0][k] != CASE_CERCLE_J1)) {
                        utilite += 10*Valeur_absolue(i) + Valeur_absolue(j - k); // La distance a une case d'arrivee libre
                    }
                }
            }
        }
    }
    return(utilite);
}




void jouerCoup(int** plateau, Deplacement* coup)
{
    plateau[coup->finCoupJoue.y][coup->finCoupJoue.x] = plateau[coup->debutCoupJoue.y][coup->debutCoupJoue.x];
    plateau[coup->debutCoupJoue.y][coup->debutCoupJoue.x] = CASE_VIDE;
}

void annulerCoup(int** plateau, Deplacement* coup)
{
    plateau[coup->debutCoupJoue.y][coup->debutCoupJoue.x] = plateau[coup->finCoupJoue.y][coup->finCoupJoue.x];
    plateau[coup->finCoupJoue.y][coup->finCoupJoue.x] = CASE_VIDE;
}


int Valeur_absolue(int nombre)
{
    if(nombre < 0) {
        nombre = -nombre;
    }
    return(nombre);
}

int max(int a, int b)
{
    int resultat = a;
    if(resultat < b) {
        resultat = b;
    }
    return(resultat);
}

int min(int a, int b)
{
    int resultat = a;
    if(resultat > b) {
        resultat = b;
    }
    return(resultat);
}



int AlphaBeta(int** plateau, int profondeur, int alpha, int beta, int evalMax)
{
    int resultat;
    Deplacement* listeCoupPossible;
    Deplacement* coup; 
    if(profondeur == 0  ||  victoire(plateau)) {
        resultat = evaluation(plateau);
    } else {
        if(evalMax) {  // Joueur Max
            alpha = INT_MIN;
            listeCoupPossible = transition(plateau, evalMax);
            coup = listeCoupPossible;
            while(coup != NULL  &&  alpha < beta) {
                jouerCoup(plateau, coup);
                alpha = max(alpha, AlphaBeta(plateau, profondeur - 1, alpha, beta, 0));
                annulerCoup(plateau, coup);
                coup = coup->suivant;
            }
            resultat = alpha;
        } else {  // Joueur Min
            beta = INT_MAX;
            listeCoupPossible = transition(plateau, evalMax);
            coup = listeCoupPossible;
            while(coup != NULL  &&  alpha < beta) {
                jouerCoup(plateau, coup);
                beta = min(beta, AlphaBeta(plateau, profondeur - 1, alpha, beta, 1));
                annulerCoup(plateau, coup);
                coup = coup->suivant;
            }
            resultat = beta;
        }
        free(listeCoupPossible);
    }

    return(resultat);
}




void CoupRacine(int** plateau, int profondeur, int alpha, int beta, int evalMax)
{
    Deplacement* CoupOptimal;
    int evaluationIntermediaire;
    Deplacement* listeCoupPossible;
    Deplacement* coup; 
    if(evalMax) {  // Joueur Max
        alpha = INT_MIN;
        listeCoupPossible = transition(plateau, evalMax);
        coup = listeCoupPossible; 
        while(coup != NULL  &&  alpha < beta) {
            jouerCoup(plateau, coup);
            evaluationIntermediaire = AlphaBeta(plateau, profondeur - 1, alpha, beta, 0);
            if(evaluationIntermediaire > alpha) {
                alpha = evaluationIntermediaire;
                CoupOptimal = coup;
            }
            annulerCoup(plateau, coup);
            coup = coup->suivant;
        }
    } else {  // Joueur Min
        beta = INT_MAX;
        listeCoupPossible = transition(plateau, evalMax);
        coup = listeCoupPossible;
        while(coup != NULL  &&  alpha < beta) {
            jouerCoup(plateau, coup);
            evaluationIntermediaire = AlphaBeta(plateau, profondeur - 1, alpha, beta, 1);
            if(evaluationIntermediaire < beta) {
                beta = evaluationIntermediaire;
                CoupOptimal = coup;
            }
            annulerCoup(plateau, coup);
            coup = coup->suivant;
        }
    }
    jouerCoup(plateau, CoupOptimal);
    free(listeCoupPossible);
}




void jouerIA(int** plateau, Donnees* etat_Actuel_Partie)
{
    CoupRacine(plateau, etat_Actuel_Partie->profondeur, INT_MIN, INT_MAX, 1);
}

