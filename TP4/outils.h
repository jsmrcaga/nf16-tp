#ifndef OUTILS_H
#define OUTILS_H
	
NoeudABR* rechercheNoeud (char* mot, ArbreBR * arbre);
void charger_fichier(ArbreBR *arbre, char *filename);
int motExiste (char* mot, NoeudABR * noeud);
void afficherArbre (ArbreBR * arbre);
int compterProfondeur (NoeudABR * noeud, int profondeurPrec);
int compterNoeuds(NoeudABR * noeud, int nbNoeuds);
int isEquilibre(ArbreBR * arbre);
void printMenu ();
void selectMenu();

#endif