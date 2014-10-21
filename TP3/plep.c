#include <stdio.h>

typedef enum {PLATEAU, RPG, COOPERATIF, AMBIANCE, HASARD} GENRE;

typedef struct{
	char nom[30];
	GENRE genre;
	int nbJoueursMax;
	int nbJoueursMin;
	int dureeMoy_min;
} t_jeu;

int plep(int*, void, char[]);

void main(){

}

int ajouter_jeu(t_ludotheque* ludo, t_jeu* jeu){
	int i;

	if(ludo->debut == NULL){
		ludo->debut = jeu;	
	}else{

		t_jeu *debutLudo = ludo->debut;
		printf("DEBUG: debutLudo1 %s\n", debutLudo->nom);
		for(i=0; i<(ludo->nb_jeu); i++){
			if(ludo->debut->suivant != NULL){
				ludo->debut = ludo->debut->suivant;
			}
		}
		printf("DEBUG: debutLudo2 %s\n", debutLudo->nom);

		ludo->debut->suivant = jeu;
		ludo->debut = debutLudo; 
		printf("DEBUG: test arrive apres affectation de nouveau jeu\n");
	}
	//verif
	int wasAdded = 0; //0 false 1 true
	for(i = 0; i<(ludo->nb_jeu)+1; i++){
		if(ludo->debut->nom == jeu->nom){
			wasAdded = 1;
		}else{
			wasAdded = 0;
		}
	}
	printf("DEBUG: test arrive apres wasAdded\n");

	if(wasAdded==1){

		ludo->nb_jeu++;
		return 1;
	}else{
		return 0;
	}
	printf("DEBUG: test arrive fin de fct\n");
}