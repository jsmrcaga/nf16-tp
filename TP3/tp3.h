#ifndef TP3_H_   /* Include guard */
#define TP3_H_




t_ludotheque* creer_ludotheque();
t_jeu* creer_jeu(char *nom, genre_jeu genre, int nbJoueurMin, int nbJoueurMax, int duree);
int ajouter_jeu(t_ludotheque* ludo,t_jeu* j);
int retirer_jeu(t_ludotheque* ludo, char* nom);
void affiche_ludotheque(t_ludotheque*ludo);
int ajouter_jeu(t_ludotheque* ludo, t_jeu* jeu);

typedef enum
{
	Plateau, RPG, Cooperatif, Ambiance, Hasard
}genre_jeu;


struct jeu{
	genre_jeu genre;
	char* nom;
	int nbJoueurMin;
	int nbJoueurMax;
	int duree;
	struct jeu* suivant; //pointeur sur le jeu suivant
};

typedef struct jeu t_jeu;


struct ludotheque{
	int nb_jeu; //nombre de jeux dans une ludothèque
	t_jeu* debut;
};

typedef struct ludotheque t_ludotheque;


#endif