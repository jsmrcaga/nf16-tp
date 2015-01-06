#ifndef ARBRE_H
#define ARBRE_H

struct noeudABR{
	char * mot;
	struct listePosition* positions;
	struct noeudABR * filsGauche;
	struct noeudABR * filsDroit;
};

typedef struct noeudABR NoeudABR;

struct arbreBR {
	struct noeudABR * racine;
	int nb_mots_differents;
	int nb_mots_total;
};

typedef struct arbreBR ArbreBR;


int ajouter_noeud(ArbreBR *arbre, NoeudABR *noeud);
	//ajouter_noeud - ajoute un noeud dans l'arbre
		//@param ArbreBR - arbre auquel ajouter le noeud
		//@param NoeudABR - noeud a ajouter
NoeudABR* creer_Noeud(char* mot);
	//creer_Noeud - initialise une variable pour quelle contienne un neoud
ArbreBR * creer_ABR();
	//creer_ABR - comme creer_Noeud

void caracteristiquesABR(ArbreBR * arbre);
	//caracteristiquesABR - affiche profondeur, equilibre et nombre de noeuds

#endif

