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

NoeudABR* creerNoeud(char* mot){
	NoeudABR* temp = (NoeudABR*)malloc(sizeof(NoeudABR));
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

		//if (rechercheNoeud(noeud->mot, arbre) != NULL){
			//ajouter position
		//}else{

				//TODO
				// Check nullite des enfants
				//
			ArbreBR * nouvelArbre = (ArbreBR*)(malloc(sizeof(ArbreBR)));

			if (temp->filsGauche == NULL && temp->filsDroit == NULL){
				if (strcmp(noeud->mot, temp->mot) < 0){
					temp->filsGauche = noeud;
				}else if(strcmp(noeud->mot, temp->mot) > 0){
					temp->filsDroit = noeud;
				}//apres les mots sont les memes ils seront traites avant

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
			arbre->nb_mots_differents++;
		//}		
					

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


/************************************************************************************/


char * mot = (char *)malloc(30*sizeof(char));
                    fgets(mot, 30, stdin);
                    strtok(mot, "\n");
                    fflush(stdin);

int charger_fichier(ArbreBR *arbre, char *filename){
    int test=-1,  ordre=0, no_ligne=0, no_phrase=1;
    const char s1[2] = " ";
    //const char s2[2] = ".";
    char ligne [100];
    char * token1;
    //char * token2;
    NoeudABR* n;
    FILE* mon_fichier;

    mon_fichier = fopen(filename, "r");
    if (mon_fichier != NULL){
        while(fgets(ligne, 100, mon_fichier) != NULL){
        token1 = strtok(ligne, s1);
        //token2= strtok(ligne, s2);
            no_ligne++;
            while(token1 != NULL){
            //printf("mot -%s- \n ordre : %d \n no_ligne : %d \n \n", token1, ordre, no_ligne);
            ordre++;
            n=rechercher_noeud(arbre, token1);
            if (n!=NULL){
                    n->positions=creer_liste_positions();
                    test=ajouter_position(n->positions, no_ligne, ordre, no_phrase);
                    if (test==0){
                        printf("erreur \n");
                        test=-1;
                    }
                }
            else{
                n=creer_noeud(token1);
                test=ajouter_position(n->positions, no_ligne, ordre, no_phrase);
                test=ajouter_noeud(arbre,n);

                if (test==0){
                        printf("erreur \n");
                        test=-1;
                    }
            }
            token1 = strtok(NULL, s1);
        	}
    	}
	}
}