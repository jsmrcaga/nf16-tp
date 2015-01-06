#ifndef LISTE_H
#define LISTE_H


struct position{
	int numero_ligne;
	int ordre;
	int numero_phrase;
	struct position * suivant;
};


typedef struct position Position;

struct listePosition{
	Position* debut;
	int nb_elements;
};

typedef struct listePosition ListePosition;


ListePosition *creer_liste_position();
int ajouter_position(ListePosition *listeP, int ligne, int ordre, int num_phrase);

#endif