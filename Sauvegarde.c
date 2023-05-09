#include "Sauvegarde.h"




void SauvegardePartieEnCours(int*** plateaux, Donnees* etat_Actuel_Partie)
{
	char Sauvegarde[40] = "Sauvegarde/sauvegarde_Partie_En_Cours";
	FILE* p_File = NULL;
	p_File = fopen(Sauvegarde, "w");
	if(p_File == NULL) {
		fprintf(stderr, "Impossible de sauvegarder\n");
	} else {
		char chaine[10];
		sprintf(chaine, "%d\n", etat_Actuel_Partie->jcj);
		fputs(chaine, p_File);
		sprintf(chaine, "%d\n", etat_Actuel_Partie->profondeur);
		fputs(chaine, p_File);
		sprintf(chaine, "%d\n", etat_Actuel_Partie->nombreJoueurs);
		fputs(chaine, p_File);
		sprintf(chaine, "%d\n", etat_Actuel_Partie->nombreTours);
		fputs(chaine, p_File);
		for(int i = 0; i <= etat_Actuel_Partie->nombreTours; i++) {
			for(int j = 0; j < TAILLE_PLATEAU; j++) {
				for (int k = 0; k < TAILLE_PLATEAU; k++) {
					sprintf(chaine, "%d,", plateaux[i][j][k]);
					fputs(chaine, p_File);
				}
			}
			fputs("\n", p_File);
		}
		fclose(p_File);
	}
}


int*** recupererPartieEnCours(Donnees* etat_Actuel_Partie)
{
	char Sauvegarde[40] = "Sauvegarde/sauvegarde_Partie_En_Cours";
	FILE* p_File = NULL;
	int*** plateaux = NULL;
	p_File = fopen(Sauvegarde, "r");
	if(p_File == NULL) {
		fprintf(stderr, "Impossible de sauvegarder\n");
	} else {
		char chaine[10];
		fgets(chaine, 10, p_File);
		etat_Actuel_Partie->jcj = (int) strtol(chaine, NULL, 10);
		fgets(chaine, 10, p_File);
		etat_Actuel_Partie->profondeur = (int) strtol(chaine, NULL, 10);
		fgets(chaine, 10, p_File);
		etat_Actuel_Partie->nombreJoueurs = (int) strtol(chaine, NULL, 10);
		fgets(chaine, 10, p_File);
		etat_Actuel_Partie->nombreTours = (int) strtol(chaine, NULL, 10);


		plateaux = (int***) malloc((etat_Actuel_Partie->nombreTours + 1)*sizeof(int**));
		for(int i = 0; i <= etat_Actuel_Partie->nombreTours; i++) {
			plateaux[i] = (int**) malloc(TAILLE_PLATEAU*sizeof(int*));
			for(int j = 0; j < TAILLE_PLATEAU; j++) {
				plateaux[i][j] = (int*) malloc(TAILLE_PLATEAU*sizeof(int));
			}
		}

		int nb;
		for(int i = 0; i <= etat_Actuel_Partie->nombreTours; i++) {
			for(int j = 0; j < TAILLE_PLATEAU; j++) {
				for (int k = 0; k < TAILLE_PLATEAU; k++) {
					fgets(chaine, 4, p_File);
					nb = (int) strtol(chaine, NULL, 10);
					plateaux[i][j][k] = nb;
				}
			}
				nb = fgetc(p_File);		
		}
	}
	fclose(p_File);

	return(plateaux);
}








