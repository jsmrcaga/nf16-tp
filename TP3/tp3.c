#include <stdio.h>
#include "TP3.h"

//fonction creer_ludotheque()
t_ludotheque* creer_ludotheque(){
	t_ludotheque* ludo=(t_ludotheque*)malloc(sizeof(t_ludotheque));
	ludo->nb_jeu=0;
	ludo->debut=NULL;
	if(ludo!=NULL){
		return ludo;
	}
	else
	{
		return NULL;
	}
}



//fonction creer_jeu();
t_jeu* creer_jeu(char *n, genre_jeu g, int nbMin, int nbMax, int d){
	t_jeu* jeu=(t_jeu*)malloc(sizeof(t_jeu));
	jeu->nom=n;
	jeu->genre=g;
	jeu->nbJoueurMin=nbMin;
	jeu->nbJoueurMax=nbMax;
	jeu->duree=d;
	jeu->suivant=NULL;
	return jeu;
}


//fonction pour retirer un jeu d'une ludotheque
int retirer_jeu(t_ludotheque* ludo, char* n){
	t_ludotheque* ludo_tmp=ludo;
	for(int i=0; i< (ludo->nb_jeu) ; ++i){ //ou  ou while ?
		if(ludo_tmp->debut->nom==n){ //strcmp pour des chaines ??
			free(ludo_tmp->debut);
		}
		ludo_tmp->debut=ludo_tmp->debut->suivant;

	}

	//verif
	int exists = 1;
	for (int i =0; i<(ludo->nb_jeu); i++){
		if (ludo_tmp->debut->nom ==n){
			exists = 1;
		}else{
			exists=0;
		}
		ludo_tmp->debut=ludo_tmp->debut->suivant;
	}

	return  exists;


}

//fonction pour supprimer ludotheque
void supprimer_ludotheque(t_ludotheque* ludo){
	t_ludotheque* ludo_tmp=ludo;
	for(int i=0; i< (ludo->nb_jeu) ; ++i){ //ou  ou while ?\
		free(ludo_tmp->debut);
		ludo_tmp->debut=ludo_tmp->debut->suivant;

	}

	free(ludo);
}

//fonction d'affichage de la ludotheque
void affiche_ludotheque(t_ludotheque* ludo){
	t_ludotheque* ludo_tmp=ludo;
	printf("Nom       ||Type      ||Nombre de joueurs||Durée moyenne|\n");
	for(int i=0; i<(ludo_tmp->nb_jeu); ++i){
		printf("%s          ", ludo_tmp->debut->nom);
		printf("%d            ", ludo_tmp->debut->genre);
		printf("%d-%d       ", ludo_tmp->debut->nbJoueurMin, ludo->debut->nbJoueurMax);
		printf("%d'         ", ludo_tmp->debut->duree);
		ludo_tmp->debut=ludo_tmp->debut->suivant;
		printf("\n");
	}
}

t_ludotheque * requete_jeu(t_ludotheque * ludo, genre_jeu genre, int nbJoueurs, int duree){
	t_ludotheque temp;
	t_jeu tempJeu = ludo->debut;
	double minDur = duree * 0.9;
	double maxDur = duree * 1.1; 
	int i;

	for (i=0; i<(ludo->nb_jeu); i++){
		
		if ((((nbJoueurs!=-1)&&((tempJeu->nbJoueurMax => nbJoueurs) && (tempJeu->nbJoueurMin <= nbJoueurs))) || (nbJoueurs == -1))&& 
			(((genre!=-1) && (tempJeu->genre == genre)) || (genre==-1)) && 
			(((tempJeu->duree < maxDur)||(tempJeu->duree > minDur)) || (duree == -1)) ){

			ajouter_jeu(temp, tempJeu);
		}

		tempJeu= tempJeu->suivant;

	}

	return temp;
}


//fonction ajouter un jeu à la ludothèque
int ajouter_jeu(t_ludotheque* ludo, t_jeu* jeu){
	int i;
	printf("DEBUG : INIT AJOUT\n");
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
		printf("DEBUG: nombre jeus: %d\n", ludo->nb_jeu);
		return 1;
	}else{
		ludo->nb_jeu++;
		return 0;
	}
	printf("DEBUG: test arrive fin de fct\n");
}

t_ludotheque * fusion(t_ludotheque * ludo1, t_ludotheque * ludo2){
	t_ludotheque temp;
	t_jeu tempJeu, tempJeuAutre;

	temp->debut = ludo1->debut;
	tempJeu = temp->debut;
	tempJeuAutre = ludo1->debut->suivant;
	int i;
	for (i=0; i< ludo1->nb_jeu; i++){
		tempJeu->suivant = tempJeuAutre;
		tempJeuAutre= tempJeuAutre->suivant;
		tempJeu=tempJeu->suivant;

	}
	tempJeuAutre = ludo2->debut;
	
	for (i=0; i< ludo2->nb_jeu; i++){
		tempJeu->suivant = tempJeuAutre;
		tempJeuAutre= tempJeuAutre->suivant;
		tempJeu=tempJeu->suivant;

	}

}

