#include "arbre.h"



int ajouter_noeud(ArbreBR *arbre, NoeudABR *noeud){
	NoeudABR * temp = (NoeudABR*)malloc(sizeof(NoeudABR));
	temp = arbre->racine;


	if (temp == NULL){
    	arbre->racine = noeud;
	}else{

    	ArbreBR * nouvelArbre = (ArbreBR*)malloc(sizeof(ArbreBR));

    	if (temp->filsGauche == NULL && temp->filsDroit == NULL){
        	if (strcmp(noeud->mot, temp->mot) < 0){
            	temp->filsGauche = noeud;
        	}else if(strcmp(noeud->mot, temp->mot) > 0){
            	temp->filsDroit = noeud;
        	}

            	// /PLEP
    	}else if (temp->filsGauche == NULL && temp->filsDroit != NULL && strcmp(noeud->mot, temp->filsDroit->mot) <= 0 ){
            	if(strcmp(noeud->mot, temp->mot) > 0){
                	nouvelArbre->racine = temp->filsDroit;
                	ajouter_noeud(nouvelArbre, noeud);
            	}else{
                	temp->filsGauche = noeud;
            	}

    	}else if (temp->filsGauche == NULL && temp->filsDroit != NULL && strcmp(noeud->mot, temp->filsDroit->mot) > 0 ){
            	nouvelArbre->racine = temp->filsDroit;
            	ajouter_noeud(nouvelArbre, noeud);

    	}else if(temp->filsGauche != NULL && temp->filsDroit == NULL && strcmp(noeud->mot, temp->filsGauche->mot) <= 0 ){
            	nouvelArbre->racine = temp->filsGauche;
            	ajouter_noeud(nouvelArbre, noeud);

    	}else if(temp->filsGauche != NULL && temp->filsDroit == NULL && strcmp(noeud->mot, temp->filsGauche->mot) > 0 ){
           	if(strcmp(noeud->mot, temp->mot) > 0){
                	temp -> filsDroit = noeud;
            	}else{
                	nouvelArbre->racine = temp->filsGauche;
                	ajouter_noeud(nouvelArbre, noeud);
            	}

    	}else if(temp->filsGauche != NULL && temp-> filsDroit != NULL){

            	if (strcmp(noeud->mot, temp->filsGauche->mot) <= 0 ){
                	nouvelArbre->racine = temp -> filsGauche;
                	ajouter_noeud(nouvelArbre, noeud);
            	}else{
                	nouvelArbre->racine = temp -> filsDroit;
                	ajouter_noeud(nouvelArbre, noeud);
            	}
    	}

	arbre->nb_mots_differents++;
	}
	return 1;

}

NoeudABR* creer_Noeud(char* mot){
	NoeudABR* temp = (NoeudABR*)malloc(sizeof(NoeudABR));
	temp->mot = malloc(strlen(mot) + 1*sizeof(char));
	temp->mot = mot;
	temp->positions= NULL;
	temp->filsGauche = NULL;
	temp->filsDroit = NULL;

	if(temp != NULL){

    	return temp;
	}else{
    	return 0;
	}
}


ArbreBR * creer_ABR(){
	ArbreBR * temp =(ArbreBR*)malloc(sizeof(ArbreBR));
	temp -> racine = NULL;
	temp -> nb_mots_differents = 0;
	temp -> nb_mots_total = 0;

	if (temp != NULL){

    	return temp;
	}else{
    	return NULL;
	}

}

void caracteristiquesABR(ArbreBR * arbre){
	int profondeur = compterProfondeur(arbre->racine,0);
	int nombreNoeuds = compterNoeuds(arbre->racine, 0);
	int equilibre = isEquilibre(arbre);

	printf("L'arbre est de profondeur: %d, contient %d noeuds ", profondeur, nombreNoeuds);

	if(equilibre == 1){
    	printf("et est equilibre.");
	}else{
    	printf("et n'est pas equilibre.");
	}


}
