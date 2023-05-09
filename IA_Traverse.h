#ifndef __IA_TRAVERS_H__
#define __IA_TRAVERS_H__

#include "main_Traverse.h"

typedef struct Deplacement Deplacement;

struct Deplacement{
    Coordonnee debutCoupJoue;
    Coordonnee finCoupJoue;
    Deplacement* suivant;
};

int evaluation(int** plateau);
void jouerCoup(int** plateau, Deplacement* coup);
void annulerCoup(int** plateau, Deplacement* coup);
int Valeur_absolue(int nombre);
int max( int a, int b);
int min( int a, int b);
int AlphaBeta(int** plateau, int profondeur, int alpha, int beta, int evalMax);
void CoupRacine(int** plateau, int profondeur, int alpha, int beta, int evalMax);
void jouerIA(int** plateau, Donnees* etat_Actuel_Partie);

#endif
