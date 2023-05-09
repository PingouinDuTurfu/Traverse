#ifndef DEPLACEMENT_H
#define DEPLACEMENT_H

#include "main_Traverse.h"


int nombreSautPossibles(int** plateau);

void deplacementPionCarre(int** plateau, Coordonnee coordsPionCarre);
void deplacementPionTriangle(int** plateau, Coordonnee coordsPionTriangle, int joueur);
void deplacementPionLosange(int** plateau, Coordonnee coordsPionLosange);
void deplacementPionCercle(int** plateau, Coordonnee coordsPionCercle);

void SuppressionDeplacementsInterdis(int** plateau, int joueur);

void SautPionCarre(int** plateau, Coordonnee coordsPionCarre);
void SautPionTriangle(int** plateau, Coordonnee coordsPionTriangle, int joueur);
void SautPionLosange(int** plateau, Coordonnee coordsPionLosange);
void SautPionCercle(int** plateau, Coordonnee coordsPionCercle);
void suiteDeSauts(int** plateau, Coordonnee positionClic, int case1, int joueur, Donnees* etat_Actuel_Partie);

#endif

