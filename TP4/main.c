struct position{
	int numero_ligne;
	int ordre;
	int numero_phrase;
	Position * suivant;
};

typedef struct position Position;

struct listePosition{
	Position* debut;
	int nb_elements;
};

typedef struct listePosition ListePosition;

struct noeudABR{
	char * mot;
	ListePosition positions;
	NoeudABR * filsGauche;
	NoeudABR * filsDroit;		
};

typedef struct noeudABR NoeudABR;

struct arbreBR {
	NoeudABR * racine;
	int nb_mots_differents;
	int nb_mots_total;
};

typedef struct arbreBR ArbreBR;

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


ArbreBR * creer_ARB(){
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

int ajouter_noeud(ArbreBR *arbre, NoeudABR *noeud){
	NoeudABR * temp = (NoeudABR*)(malloc(sizeof(NoeudABR)));
	temp = arbre -> racine;
	int nbMots = arbre->nb_mots_total , i;

	if (temp == NULL){
		temp = noeud;
	}else{
		//TODO
			// Check nullite des enfants
			//
		ArbreBR * nouvelArbre = (ArbreBR*)(malloc(sizeof(ArbreBR)));

		if (temp->filsGauche == NULL && temp->filsDroit == NULL){
				temp->filsDroit = noeud; //on met le premier a droite
				// /PLEP
		}else if (temp->filsGauche == NULL && temp->filsDroit != NULL && strcmp(noeud->mot, temp->filsDroit->mot) <= 0 ){
				temp->filsGauche = noeud;

		}else if (temp->filsGauche == NULL && temp->filsDroit != NULL && strcmp(noeud->mot, temp->filsDroit->mot) > 0 ){
				nouvelArbre->racine = temp->filsDroit;
				ajouter_noeud(nouvelArbre, noeud);

		}else if(temp->filsGauche != NULL && temp->filsDroit == NULL && strcmp(noeud->mot, temp->filsGauche->mot) <= 0 ){
				nouvelArbre->racine = temp->filsGauche;
				ajouter_noeud(nouvelArbre, noeud);

		}else if(temp->filsGauche != NULL && temp->filsDroit == NULL && strcmp(noeud->mot, temp->filsGauche->mot) > 0 ){
				temp -> filsDroit = noeud;
		
		}else if(temp->filsGauche != NULL && temp-> filsDroit != NULL){

				if (strcmp(noeud->mot, temp->filsGauche->mot) <= 0 ){
					nouvelArbre->racine = temp -> filsGauche;
					ajouter_noeud(nouvelArbre, noeud);
				}else{
					nouvelArbre->racine = temp -> filsDroit;
					ajouter_noeud(nouvelArbre, noeud);
				}
		}
					

	}
	return 1;

}



int * compterProfondeur (NoeudABR *noeud){
	//Passer la racine de l'arbre
	int profGauche, profDroite;
	NoeudABR * temp = (NoeudABR*)(malloc(sizeof(NoeudABR)));
	temp = noeud.

}








int charger_fichier(ArbreBR * arbre, char *filename){
	int nombre_mots;
    printf("pouet");
    FILE* fichier = NULL;
	char chaine[TAILLE_MAX] = ""; //TAILLEMAX = 1000
    fichier = fopen(filename, "r");
	if (fichier != NULL){
   	 printf("pouet2");
    	while (fgets(chaine, TAILLE_MAX, fichier) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
    	{
        	printf("%s", chaine); // On affiche la chaîne qu'on vient de lire
    	}

    	fclose(fichier);
	}

	return 0;
}




int motExiste (char* mot, NoeudABR * noeud){
	NoeudABR * temp = (NoeudABR*)malloc(sizeof(NoeudABR));
	temp=noeud;
	if (strcmp(temp->mot, mot) == 0){
		return 1; //mot existe deja
	}
	//test a gauche
	if (temp-> filsGauche != NULL){
		if(strcmp(temp->filsGauche->mot, mot) == 0){
			return 1;
		}else{
			if(motExiste (mot, temp->filsGauche) == 1)
				return 1;			
		}
	}

	//test a droite
	if (temp-> filsDroit != NULL){
		if(strcmp(temp->filsDroit->mot, mot) == 0){
			return 1;
		}else{
			if(motExiste (mot, temp->filsDroit) == 1)
				return 1;			
		}
	}
	return 0;
}

NoeudABR* rechercheNoeud (char* mot, ArbreBR * arbre){
	NoeudABR * temp = (NoeudABR*)malloc(sizeof(NoeudABR));
	ArbreBR * tempABR = (ArbreBR*)malloc(sizeof(ArbreBR));
	temp=arbre->racine;

	if (strcmp(temp->mot, mot) == 0){
		return temp; //mot existe deja
	}
	//test a gauche
	if (temp-> filsGauche != NULL){
		if(strcmp(temp->filsGauche->mot, mot) == 0){
			return temp->filsGauche;
		}else{
			tempABR->racine = temp->filsGauche;
			if(rechercheNoeud (mot, tempABR) != NULL)
				return rechercheNoeud (mot, tempABR);			
		}
	}

	//test a droite
	if (temp-> filsDroit != NULL){
		if(strcmp(temp->filsDroit->mot, mot) == 0){
			return temp->filsDroit;
		}else{
			tempABR->racine = temp->filsDroit;
			if(rechercheNoeud (mot, tempABR) != NULL)
				return rechercheNoeud (mot, tempABR);			
		}
	}
	return NULL;
}



void afficherArbre (ArbreBR * arbre){
	NoeudABR* temp = (NoeudABR*)malloc(sizeof(NoeudABR));
	ArbreBR * tempABR = (ArbreBR*)malloc(sizeof(ArbreBR));
	temp = arbre->racine;
	if (temp->filsGauche != NULL){
		tempABR->racine = temp->filsGauche;
		afficherArbre(tempABR);
	}
	//Entre gauche et droite pour l'ordre alphabetique
	printf(" -*- $s", temp->mot);

	if (temp->filsDroit != NULL){
		tempABR->racine = temp->filsDroit;
		afficherArbre(tempABR);
	}
}

void main(){
	ListePosition * poulet = creer_liste_position();
	ajouter_position(poulet, 5,25,62);

	ArbreBR * arbreMini = creer_ARB();

}