#ifndef __AFFICHAGE_GRAPHIQUE_H__
#define __AFFICHAGE_GRAPHIQUE_H__


#include "main_Traverse.h"


void myText(int x, int y, char* text);

void ecrire_nombre_0(int x, int y);

void ecrire_nombre_1(int x, int y);

void ecrire_nombre_2(int x, int y);

void ecrire_nombre_3(int x, int y);

void ecrire_nombre_4(int x, int y);

void ecrire_nombre_5(int x, int y);

void ecrire_nombre_6(int x, int y);

void ecrire_nombre_7(int x, int y);

void ecrire_nombre_8(int x, int y);

void ecrire_nombre_9(int x, int y);


void afficher_tour(int nombreTour);
void ecranVictoire(int partie_Fini);

void affichageComplet(int** plateau, Coordonnee positionPiece, Donnees* etat_Actuel_Partie);
void affichageBandeau(Donnees* etat_Actuel_Partie);
void afficherPlateau(int** plateau, Coordonnee positionPiece);
void afficherGrille(void);
void afficherPieces(int** plateau);
void dessinerCarre(void);
void dessinerTriangle(void);
void dessinerLosange(void);
void dessinerCercle(void);
void dessinerCase(void);
void afficherPieceActuelle(Coordonnee positionPiece);


#endif