#ifndef TRAVERSE_H
#define TRAVERSE_H

#include "main_Traverse.h"

typedef struct {
	int nombreTours;
	GLuint textures[4];
	int jcj;
	int nombreJoueurs;
	int profondeur;
} Donnees;


typedef struct {
    int x;
    int y;
} Coordonnee;



int** generationPlateau(int nombreJoueurs);
int partieFini(int*** plateaux, Donnees* etat_Actuel_Partie);
int unDansBase(int** plateau);

int verifPlateauIdentique(int*** plateaux, int nombreTours);

void choixPieceJ1(int** plateau, Coordonnee* positionClic, int* case1);
void choixPieceJ2(int** plateau, Coordonnee* positionClic, int* case1);
void choixPieceJ3(int** plateau, Coordonnee* positionClic, int* case1);
void choixPieceJ4(int** plateau, Coordonnee* positionClic, int* case1);
int victoire(int** plateau);

void tour_Joueur(int** plateau, int joueur, Donnees* etat_Actuel_Partie);
void Traverse(int*** plateaux, Donnees* etat_Actuel_Partie);
void clearDeplacement(int** plateau);
void clearPositionInitiale(int** plateau);
Coordonnee positionCliquee(void);
void copierTableau(int** tab2, int** tab1);

void lancerTraverse(int nombreJoueurs, int jcj, int dificulte);
void relancerTraverse(void);

void initialiserEtatPartie(Donnees* etat_Actuel_Partie, int jcj);



#endif
