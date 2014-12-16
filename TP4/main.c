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
	NoeudABR * temp = (NoeudABR*)(malloc(sizeof(NoeudABR)))
	temp = arbre -> racine;
	if (temp == NULL){
		temp = noeud;
	}else{

		

	}
	return 1;

}
























void main(){
	ListePosition * poulet = creer_liste_position();
	ajouter_position(poulet, 5,25,62);

	ArbreBR * arbreMini = creer_ARB();

}