#include 


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



void charger_fichier(ArbreBR *arbre, char *filename){
	int test=-1,  ordre=0, no_ligne=0, no_phrase=1;
	char ligne[TAILLE_MAX] = "";

	char * token1;

	NoeudABR* n = NULL;
	FILE* mon_fichier;

	mon_fichier = fopen(filename, "r");
	if (mon_fichier != NULL){
    	while(fgets(ligne, TAILLE_MAX, mon_fichier) != NULL){

        	ordre=0;

        	token1 = strtok(ligne, " ,.");

        	no_ligne++;


        	while(token1 != NULL){

            	ordre++;

            	if (arbre->racine != NULL) {
                	n=rechercheNoeud(token1, arbre);
            	}


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
                	n=creer_Noeud(token1);

                	n->positions = creer_liste_position();

                	test=ajouter_position(n->positions, no_ligne, ordre, no_phrase);

                	test=ajouter_noeud(arbre, n);

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





void afficherArbre (ArbreBR * arbre){
	NoeudABR* temp = (NoeudABR*)malloc(sizeof(NoeudABR));
	ArbreBR * tempABR = (ArbreBR*)malloc(sizeof(ArbreBR));
	temp = arbre->racine;
	if (temp->filsGauche != NULL){
    	tempABR->racine = temp->filsGauche;
    	afficherArbre(tempABR);
	}
	//Entre gauche et droite pour l'ordre alphabetique
	printf(" -*- %s", temp->mot);

	if (temp->filsDroit != NULL){
    	tempABR->racine = temp->filsDroit;
    	afficherArbre(tempABR);
	}
}


int compterProfondeur (NoeudABR * noeud, int profondeurPrec){
	//Passer la racine de l'arbre
	int profGauche = 0;
	int profDroite = 0;
	int profondeur = 0;
	profondeurPrec++; //on incremente la profondeur de l'arbre puisqu'on rentre dans le noeud suivant

	NoeudABR * temp = (NoeudABR*)(malloc(sizeof(NoeudABR)));
	temp = noeud;

	if(temp->filsGauche != NULL){
    	profGauche = compterProfondeur(temp->filsGauche, profondeurPrec);
	}
	if(temp->filsDroit != NULL){
    	profDroite = compterProfondeur(temp->filsDroit, profondeurPrec);
	}
	if(profGauche > 0 && profDroite > 0){
    	profondeur = (profGauche > profDroite) ? profGauche : profDroite;
	}
	else if (profGauche == 0 && profDroite > 0){
        	profondeur=profDroite;
	}
	else if (profGauche > 0 && profDroite == 0){
        	profondeur=profGauche;
	}else if (profGauche == 0 && profDroite == 0){
    	profondeur = profondeurPrec;
    	}

	return profondeur;
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
    	noeudsTot = noeudsGauche + noeudsDroite -nbNoeuds;
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
	int profGauche = compterProfondeur(arbre->racine->filsGauche,0);
	int profDroit = compterProfondeur(arbre->racine->filsDroit,0);
	if(profGauche == profDroit){
    	return 1;
	}else{
    	return 0;
	}
}



void printMenu (){
	printf("|-----------------------------------------------|");
	printf("\n|                  	MENU                 	|");
	printf("\n|-----------------------------------------------|");
	printf("\n|  1 .- Creer un ABR");
	printf("\n|  2 .- Charger un fichier dans l'ABR");
	printf("\n|  3 .- Caracteristiques de l'ABR");
	printf("\n|  4 .- Afficher les mots par ordre alphabetique");
	printf("\n|  5 .- Chercher un mot dans le texte");
	printf("\n|  6 .- Chercher une phrase contenant deux mots");
	printf("\n|  7 .- Quitter");
	printf("\n|-----------------------------------------------|\n");

	selectMenu();
}

void selectMenu(){
	int selection;
	char path[1000];
	char mot2[50];


	printf("Entrez l'action a realiser (8 affiche le menu): ");
	scanf("%d", &selection);

	while (selection < 1 || selection > 7){
    	printf("Entrez un nombre entre 1 et 7 svp");
    	scanf("%d", &selection);
	}
	switch(selection){
    	case 1:
        	arbre = creer_ABR();
        	printf("\n");
        	break;
    	case 2:
        	printf("\nEntrez le nom du fichier (chemin complet: ex C:/Windows/plep.txt)\n");
        	scanf("%s", &path);
        	charger_fichier(arbre, path);
        	break;
    	case 3:
        	caracteristiquesABR(arbre);
        	printf("\n\n");
        	break;
    	case 4:
        	afficherArbre(arbre);
        	printf("\n\n");
        	break;
    	case 5:
        	printf("\nEntrez le mot a chercher dans le texte: ");
        	scanf("%s", &path);
        	struct noeudABR * n1 = (NoeudABR*) malloc(sizeof(NoeudABR));
        	n1=rechercheNoeud (path, arbre);
        	if(n1 != NULL){
            	printf("%s\n\n", n1->mot);
        	}
        	else
        	{
            	printf("\n");
            	printf("mot pas trouve");
            	printf("\n");
        	}
        	break;
    	case 6:
        	printf("\nEntrez le premier mot que vous desirez chercher: ");
        	scanf("%s", &path);
        	printf("\nEntrez le deuxieme: ");
        	scanf("%s", &mot2);
        	break;
    	case 7:
        	exit(0);
        	break;
    	case 8:
        	printMenu();
        	break;
	}
	selectMenu();
}
