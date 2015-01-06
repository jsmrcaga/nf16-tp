#include "liste.h"

ListePosition *creer_liste_position(){
	ListePosition * temp = (ListePosition*)malloc(sizeof(ListePosition));
	temp->debut = NULL;
	temp->nb_elements = 0;
	return temp;
}

int ajouter_position(ListePosition *listeP, int ligne, int ordre, int num_phrase){
	Position * temp = (Position*)malloc(sizeof(Position));
	Position * tempAjout = (Position*)malloc(sizeof(Position));
	temp -> numero_ligne = ligne;
	temp -> numero_phrase = num_phrase;
	temp -> ordre = ordre;

	if(listeP->debut == NULL){
    	listeP->debut = temp;
    	return 1;
	}else{

    	tempAjout = listeP -> debut;

    	while(tempAjout->suivant != NULL){
        	tempAjout = tempAjout->suivant;
    	}
    	tempAjout->suivant = temp;

    	if (tempAjout != NULL && temp!=NULL){
        	return 1;
    	}else{
        	return 0;
    	}
	}
}