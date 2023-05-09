#ifndef __EVALUATION_DEPLACEMENT_H__
#define __EVALUATION_DEPLACEMENT_H__

#include "main_Traverse.h"


typedef struct Deplacement Deplacement;

void SautPionCarreIA1(int** plateau, int y, int x, int a);
void SautPionCarreIA(int** plateau, int y, int x);
void SautPionLosangeIA1(int** plateau, int y, int x, int a);
void SautPionLosangeIA(int** plateau, int y, int x);
void SautPionCercleIA(int** plateau, int y, int x);
void SautPionTriangleIA1(int** plateau, int y, int x , int a, int evalMax);
void SautPionTriangleIA(int** plateau, int y, int x, int evalMax);
void calculDeplacementPossibe(int** plateau, int i, int j);
Deplacement* creer_Deplacement(void);
Deplacement* ajouter(Deplacement* teteListe, int i, int j , int k, int l);
Deplacement* transition(int** plateau, int evalMax);




#endif
