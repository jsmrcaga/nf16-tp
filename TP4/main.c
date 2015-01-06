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

NoeudABR* creer_Noeud(char* mot){
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
	

	if (temp == NULL){
		arbre->racine = noeud;
	}else{

			ArbreBR * nouvelArbre = (ArbreBR*)(malloc(sizeof(ArbreBR)));

			if (temp->filsGauche == NULL && temp->filsDroit == NULL){
				if (strcmpi(noeud->mot, temp->mot) < 0){
					temp->filsGauche = noeud;
				}else if(strcmpi(noeud->mot, temp->mot) > 0){
					temp->filsDroit = noeud;
				}//apres les mots sont les memes ils seront traites avant

					// /PLEP
			}else if (temp->filsGauche == NULL && temp->filsDroit != NULL && strcmpi(noeud->mot, temp->filsDroit->mot) <= 0 ){
				if(strcmpi(noeud->mot, temp->mot) > 0){
					nouvelArbre->racine = temp->filsDroit;
					ajouter_noeud(nouvelArbre, noeud);
				}else{
					temp->filsGauche = noeud;	
				}

			}else if (temp->filsGauche == NULL && temp->filsDroit != NULL && strcmpi(noeud->mot, temp->filsDroit->mot) > 0 ){
					nouvelArbre->racine = temp->filsDroit;
					ajouter_noeud(nouvelArbre, noeud);

			}else if(temp->filsGauche != NULL && temp->filsDroit == NULL && strcmpi(noeud->mot, temp->filsGauche->mot) <= 0 ){
					nouvelArbre->racine = temp->filsGauche;
					ajouter_noeud(nouvelArbre, noeud);

			}else if(temp->filsGauche != NULL && temp->filsDroit == NULL && strcmpi(noeud->mot, temp->filsGauche->mot) > 0 ){

				if(strcmpi(noeud->mot, temp->mot) > 0){
					temp -> filsDroit = noeud;
				}else{
					nouvelArbre->racine = temp->filsGauche;
					ajouter_noeud(nouvelArbre, noeud);
				}
			
			}else if(temp->filsGauche != NULL && temp-> filsDroit != NULL){

					if (strcmpi(noeud->mot, temp->filsGauche->mot) <= 0 ){
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


//appeler cette fonction comme compterProfondeur(arbre->racine, 0);

int compterProfondeur (NoeudABR * noeud, int profondeurPrec){
	//Passer la racine de l'arbre
	int profGauche = 0, profDroite = 0, profondeur;
	profondeurPrec++; //on incremente la profondeur de l'arbre puisqu'on rentre dans le noeud suivant

	NoeudABR * temp = (NoeudABR*)(malloc(sizeof(NoeudABR)));
	temp = noeud;

	if(temp->filsGauche != NULL){
		profGauche = compterProfondeur(temp->filsGauche, profondeurPrec);
	}

	if(temp->filsDroit != NULL){
		profDroite = compterProfondeur(temp->filsDroit, profondeurPrec);
	}

	if (profGauche > 0 && profDroite > 0 ){
		profondeur = (profGauche > profDroite) ? profGauche : profDroite;
	}else if(profGauche == 0 && profDroite > 0 ){
		profondeur = profDroite;
	}else if(profGauche > 0 && profDroite == 0 ){
		profondeur = profGauche;
	}else if (profGauche == 0 && profDroite == 0){
		profondeur = profondeurPrec;
	}

	return profondeur;
}




int motExiste (char* mot, NoeudABR * noeud){
	NoeudABR * temp = (NoeudABR*)malloc(sizeof(NoeudABR));
	temp=noeud;
	if (strcmpi(temp->mot, mot) == 0){
		return 1; //mot existe deja
	}
	//test a gauche
	if (temp-> filsGauche != NULL){
		if(strcmpi(temp->filsGauche->mot, mot) == 0){
			return 1;
		}else{
			if(motExiste (mot, temp->filsGauche) == 1)
				return 1;			
		}
	}

	//test a droite
	if (temp-> filsDroit != NULL){
		if(strcmpi(temp->filsDroit->mot, mot) == 0){
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

	if (strcmpi(temp->mot, mot) == 0){
		return temp; //mot existe deja
	}
	//test a gauche
	if (temp-> filsGauche != NULL){
		if(strcmpi(temp->filsGauche->mot, mot) == 0){
			return temp->filsGauche;
		}else{
			tempABR->racine = temp->filsGauche;
			if(rechercheNoeud (mot, tempABR) != NULL)
				return rechercheNoeud (mot, tempABR);			
		}
	}

	//test a droite
	if (temp-> filsDroit != NULL){
		if(strcmpi(temp->filsDroit->mot, mot) == 0){
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
	if(arbre->racine == NULL){
		return;
	}
	
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

void printMenu (){
	printf("|-----------------------------------------------|");
	printf("\n|                      MENU                     |");
	printf("\n|-----------------------------------------------|");
	printf("\n|  1 .- Creer un ABR");
	printf("\n|  2 .- Charger un fichier dans l'ABR");
	printf("\n|  3 .- Caracteristiques de l'ABR");
	printf("\n|  4 .- Afficher les mots par ordre alphabetique");
	printf("\n|  5 .- Chercher un mot dans le texte");
	printf("\n|  6 .- Chercher une phrase contenant deux mots");
	printf("\n|  7 .- Quitter");
	printf("\n|-----------------------------------------------|");

	selectMenu();
}

void selectMenu(){
	int selection;
	char path[1000];
	char mot2[50];
	ArbreBR * arbre;

	printf("\nEntrez l'action a realiser (8 affiche le menu): ");
	scanf("%d", &selection);

	while (selection < 1 || selection > 7){
		printf("Entrez un nombre entre 1 et 7 svp");
		scanf("%d", &selection);		
	}

	switch(selection){
		case 1:
			arbre = creer_ARB();
			break;
		case 2:
			printf("\nEntrez le nom du fichier (chemin complet: ex C:/Windows/plep.txt)\n");
			scanf("%s", &path);
			charger_fichier(arbre, path);
			break;
		case 3:
			caracteristiquesABR(arbre);
			break;
		case 4:
			afficherArbre(arbre);
			break;
		case 5:
			printf("\nEntrez le mot a chercher dans le texte: ");
			scanf("%s", &path);
			break;
		case 6:
			printf("\nEntrez le premier mot que vous desirez chercher: ");
			scanf("%s", &path);
			printf("\nEntrez le deuxieme: ");
			scanf("%s", &mot2);
			break;
		case 7:
			exit();
			break;
		case 8:
			printMenu();
			break;
	}

	selectMenu();
}

void caracteristiquesABR(ArbreBR * arbre){
	int profondeur = compterProfondeur(arbre,0);
	int nombreNoeuds = compterNoeuds(arbre);
	int equilibre = isEquilibre(arbre);

	printf("L'arbre est de profondeur: %d, contient %d noeuds ", profondeur, nombreNoeuds);

	if(equilibre == 1){
		printf("et est equilibre.");
	}else{
		printf("et n'est pas equilibre.");
	}


}

int compterNoeuds(NoeudABR * noeud, int nbNoeuds){
	NoeudABR * temp = (NoeudABR*)malloc (sizeof(NoeudABR));
	temp = noeud;

	int noeudsGauche = 0, noeudsDroite = 0, noeudsTot= 0;
	nbNoeuds++;

	if(temp->filsGauche != NULL){
		noeudsGauche = compterNoeuds(temp->filsGauche, nbNoeuds);
	}

	if(temp->filsDroit != NULL){
		noeudsDroite = compterNoeuds(temp->filsDroit, nbNoeuds);
	}

	if (noeudsGauche > 0 && noeudsDroite > 0 ){
		noeudsTot = noeudsGauche + noeudsDroite - nbNoeuds;
	}else if(noeudsGauche == 0 && noeudsDroite > 0 ){
		noeudsTot = noeudsDroite;
	}else if(noeudsGauche > 0 && noeudsDroite == 0 ){
		noeudsTot = noeudsGauche;
	}else if (noeudsGauche == 0 && noeudsDroite == 0){
		noeudsTot = nbNoeuds;
	}

	return noeudsTot;

}

int isEquilibre(ArbreBR * arbre){
	int profGauche = compterProfondeur(arbre->racine->filsGauche);
	int profDroit = compterProfondeur(arbre->racine->filsDroit);
	if(profGauche == profDroit){
		return 1; 
	}else{
		return 0;
	}
}
/************************************************************************************/


char * mot = (char *)malloc(30*sizeof(char));
                    fgets(mot, 30, stdin);
                    strtok(mot, "\n");
                    fflush(stdin);

int charger_fichier(ArbreBR *arbre, char *filename){
    int test=-1,  ordre=0, no_ligne=0, no_phrase=1;
    char ligne [100];
    char * token1;
  
    NoeudABR* n = NULL;
    FILE* mon_fichier;
    fseek(mon_fichier, 0, SEEK_END);

    long fichierTaille = ftell(mon_fichier);
    fseek(mon_fichier, 0, SEEK_SET);


    mon_fichier = fopen(filename, "r");
    if (mon_fichier != NULL){
        while(fgets(ligne, fichierTaille, mon_fichier) != NULL){
        	ordre=0;

        	token1 = strtok(ligne, " ,.");
        
            no_ligne++;


            while(token1 != NULL){
            
	            ordre++;

	            n=rechercher_noeud(token1, arbre);

	            if (n!=NULL){
	            		if(n->positions == NULL){

	                    	n->positions=creer_liste_position();
	            		}
	                    test=ajouter_position(n->positions, no_ligne, ordre, no_phrase);
	                    if (test==0){
	                        printf("erreur \n");
	                        test=-1;
	                    }
	                }
	            else{
	                n=creer_noeud(token1);
	                n->positions = creer_liste_position();
	                test=ajouter_position(n->positions, no_ligne, ordre, no_phrase);
	                test=ajouter_noeud(arbre,n);

	                if (test==0){
	                        printf("erreur \n");
	                        test=-1;
	                    }
	            }
	            token1 = strtok(NULL, " ,.");
        	}


    	}
	}
}