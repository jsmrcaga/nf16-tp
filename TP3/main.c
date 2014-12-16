// NF16-TP3.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "stdlib.h" //pour le malloc

typedef enum
{
	Plateau, RPG, Cooperatif, Ambiance, Hasard
}genre_jeu;


struct jeu{
	genre_jeu genre;
	char* nom;
	int nbJoueurMin;
	int nbJoueurMax;
	int duree;
	struct jeu* suivant; //pointeur sur le jeu suivant
};

typedef struct jeu t_jeu;


struct ludotheque{
	int nb_jeu; //nombre de jeux dans une ludothèque
	t_jeu* debut;
};

typedef struct ludotheque t_ludotheque;


//Prototypes fonctions
t_ludotheque* creer_ludotheque();
t_jeu* creer_jeu(char *nom, genre_jeu genre, int nbJoueurMin, int nbJoueurMax, int duree);
int ajouter_jeu(t_ludotheque* ludo,t_jeu* j);
int retirer_jeu(t_ludotheque* ludo, char* nom);
void affiche_ludotheque(t_ludotheque*ludo);
int ajouter_jeu(t_ludotheque* ludo, t_jeu* jeu);
t_ludotheque * tri_alpha(t_ludotheque * ludo_Trier);


//main
void main()
{
	t_ludotheque *l;
	t_jeu *t1, *t2, *t3;
	l = creer_ludotheque();
	t1 = creer_jeu("Times up", Ambiance, 4, 8, 35);
	t2 = creer_jeu("Endors", RPG, 3, 8, 90);
	t3 = creer_jeu("pouet", RPG, 6, 9, 900);
	printf("PLEP: %d",ajouter_jeu(l, t1));
	printf("PLEP: %d",ajouter_jeu(l, t2));
	printf("PLEP: %d",ajouter_jeu(l, t3));
	affiche_ludotheque(l);
	printf("---------------------------------------------\n");
	l= tri_alpha(l);
	affiche_ludotheque(l);
}


//fonction menu
/*
void MENU ()
{
int rep;
printf ("\n\n\n\t========	MENU	======== : \n\n\n    1 : Créer une ludotheque\n    2 : Ajouter un jeu dans la ludotheque en saisissant ses caractéristiques\n    3 : Effectuer une recherche de jeu à partir de critères\n    4 : Tableau recapitulatif des equipes\n    6 : Quitter \n");
printf ("%d" ,&rep);
system ("cls");
return rep;
}
*/




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
	t_jeu * prec;
	for(int i=0; i< (ludo->nb_jeu) ; i++){ //ou  ou while ?
		if(ludo_tmp->debut->nom==n){
			 //strcmp pour des chaines ??
			prec->suivant = ludo_tmp->debut->suivant;
			ludo_tmp->debut->suivant=NULL;
			free(ludo_tmp->debut);
			return 1;
		}else{
			prec= ludo_tmp->debut;
			ludo_tmp->debut=ludo_tmp->debut->suivant;
		}

	}
	return 0;
}

//fonction pour supprimer ludotheque
void supprimer_ludotheque(t_ludotheque* ludo){
	t_ludotheque* ludo_tmp=ludo;
	t_jeu suivant;
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
		
	}

}

t_ludotheque * requete_jeu(t_ludotheque * ludo, genre_jeu genre, int nbJoueurs, int duree){
	t_ludotheque *temp;

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
		// for(i=0; i<(ludo->nb_jeu); i++){
		// 	if(ludo->debut->suivant != NULL){
		// 		ludo->debut = ludo->debut->suivant;
		// 	}
		// }
		while (debutLudo->suivant != NULL){
			debutLudo = debutLudo -> suivant;
		}

		debutLudo -> suivant = jeu;

		printf("DEBUG: debutLudo2 %s\n", debutLudo->nom);
		// ludo->debut->suivant = jeu;
		// ludo->debut = debutLudo;
		printf("DEBUG: test arrive apres affectation de nouveau jeu\n");
	}
	//verif
	ludo = tri_alpha(ludo);

	int wasAdded = 0; //0 false 1 true
	debutLudo = ludo ->debut;
	while(debutLudo -> suivant != NULL ){

		if (debutLudo -> nom == jeu -> nom){
			wasAdded = 1;
			break;
		}
	}

	// for(i = 0; i<(ludo->nb_jeu)+1; i++){
	// 	if(ludo->debut->nom == jeu->nom){
	// 		wasAdded = 1;
	// 	}else{
	// 		wasAdded = 0;
	// 	}
	// }
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
	t_ludotheque *temp= creer_ludotheque();
	t_jeu * tempJeu, *tempJeuAutre;

	temp->debut = ludo1->debut;
	tempJeu = ludo1 -> debut; //=ludo1->debut
	//tempJeuAutre = ludo1->debut->suivant;
	int i;

	for (i=0; i< ludo1->nb_jeu; i++){

		ajouter_jeu(temp, creer_jeu(tempJeu->nom, tempJeu->genre, tempJeu->nbMin, tempJeu->nbMax, tempJeu->duree));
		

			tempJeu = tempJeu -> suivant;
		
	}
	tempJeu = ludo2->debut;
	
	for (i=0; i < ludo2->nb_jeu; i++){
		ajouter_jeu(temp, creer_jeu(tempJeu->nom, tempJeu->genre, tempJeu->nbMin, tempJeu->nbMax, tempJeu->duree))
		

		tempJeu = tempJeu ->suivant;
		

	}

	return tri_alpha(temp);

}

t_ludotheque * tri_alpha(t_ludotheque * ludo_Trier){
	t_ludotheque *temp = creer_ludotheque();

	t_jeu *tempJeu = ludo_Trier->debut->suivant; //2eme element de la ludo a trier

	temp->debut = ludo_Trier->debut;

	t_jeu *tempJeuTemp = temp ->debut; //premier element de la ludo a trier

	t_jeu *tempListe; //un jeu au cas ou pour intervertir les variables

	int i;

	for(i = 1; i < (ludo_Trier->nb_jeu); i++){

		while((strcmp(tempJeu->nom, tempJeuTemp ->nom ) < 0) && (tempJeuTemp->suivant != NULL)) {
			tempJeuTemp = tempJeuTemp ->suivant;
		}

		if (tempJeuTemp = temp -> debut){

			temp -> debut = tempJeu;
			temp -> debut -> suivant = tempJeuTemp; 
			// tempJeuTemp = temp -> debut -> suivant;

		}else{

			tempListe = tempJeuTemp -> suivant;
			tempJeuTemp -> suivant = tempJeu;
			tempJeuTemp-> suivant -> suivant = tempListe;
			
		}

	}
	
	return temp;

}



