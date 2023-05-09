
#ifndef MAIN_TRAVERSE_H
#define MAIN_TRAVERSE_H

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <limits.h>

#include "Chargement_Images_Textures.h"
#include "Traverse.h"
#include "IA_Traverse.h"
#include "Deplacement.h"
#include "Sauvegarde.h"
#include "Menu_Traverse.h"
#include "evaluation_Deplacements.h"
#include "affichage_Graphique.h"



#define TAILLE_PLATEAU 10

#define CASE_VIDE 99
#define CASE_CARRE_J1 11
#define CASE_TRIANGLE_J1 12
#define CASE_LOSANGE_J1 13
#define CASE_CERCLE_J1 14
#define CASE_CARRE_J2 21
#define CASE_TRIANGLE_J2 22
#define CASE_LOSANGE_J2 23
#define CASE_CERCLE_J2 24
#define CASE_CARRE_J3 31
#define CASE_TRIANGLE_J3 32
#define CASE_LOSANGE_J3 33
#define CASE_CERCLE_J3 34
#define CASE_CARRE_J4 41
#define CASE_TRIANGLE_J4 42
#define CASE_LOSANGE_J4 43
#define CASE_CERCLE_J4 44

#define DEPLACEMENT_POSSIBLE 100
#define SAUT_POSSIBLE 101
#define POSITION_INITIALE 102




#define LONGUEUR_FENETRE 1200
#define LARGEUR_FENETRE 900



#endif
