//1.1
void main(){
	float a, b;
	printf("Entrez deux numeros: ");
	scanf("%f%f", &a, &b);
	printf("\nNumeros entres: %f , %f\n", a, b);
	a+=b;
	printf("Somme: ", a);
}

//1.2
void main(){
	float a, b;
	printf("Entrez deux numeros: ");
	scanf("%f%f", &a, &b);
	printf("\nNumeros entres: %f , %f\n", a, b);
	float c= a;
	a=b; b=c;
	printf("\nNumeros entres: %f , %f\n", a, b);

}

//1.3
void main(){
	float pourc, y;
	printf("Entrez le nombre et ensuite le pourcentage a calculer: ");
	scanf("%f%f",&y , &pourc);
	pourc /= 100;
	pourc *= y;
	printf("Resultat: %f", pourc);

}

//1.4
void main(){
	float farenh;
	printf("Entrez la temp en F: ");
	scanf("%f", &farenh);
	farenh = (5/9) * (farenh - 32);
	printf("T en C: %f", farenh);
}

//1.5
void main(){
	int entier;
	float decimal;

	printf("Entrez un nombre: ");
	scanf("%d", &entier);
	decimal = (float) entier;
	printf("Decimal: %f\n", decimal);
	printf("Octal :%o\n", entier);
	printf("Hexa %x\n", entier); 


}

//1.6
void main(){
	int a;
	printf("Entrez entier: ");
	scanf("%d", &a);

	if(a==0){
		printf("Valeur Nulle\n");
	}

	if(a%2 == 0){
		printf("Nombre pair!\n");
	}else{
		printf("Nombre impair!\n");
	}

}

//1.7
void main(){
	char c = '5';
	int i = (int) c;
	

}

//EXERCICE 2
//2.1
void main(){
	char c;
	printf("Entrez un caractere: ");
	scanf("%c", &c);

	if(c>=48 || c<= 57){
		printf("Nombre");
	}elseif(c>=48 || c<= 57){
		printf("Majuscule");
	}elseif(c>=97 || c<= 122){
		printf("Minuscule");
	}else{

	}

}

//2.2
void main(){

	int plep[1000];
	int i=0;
	scanf("%d", &plep[i]);
	
	while(plep[i] != -1){
		i++;
		scanf("%d", &plep[i]);
	}


}


//2.3
void main(){
	int table, i;
	printf("Quelle table de multiplication voulez-vous, tapez 0 (zéro) pour sortir ? ");
	scanf("%d", &table);


	while(table != 0){
		if (table>0 && table<10){

			for(i=0; i<10; i++){
				printf("%d\n", (i+1)*table);
			}

			printf("Quelle table de multiplication voulez-vous, tapez 0 (zéro) pour sortir ?");
			scanf("%d", &table);
			
		}else{
			printf("ce n'est pas dans les possibilités du programme, recommencez !\n");
			printf("Quelle table de multiplication voulez-vous, tapez 0 (zéro) pour sortir ?");
			scanf("%d", &table);
		}


	}

	printf("Vous etes sorti! :(");


}

//2.4
void main(){
	int c =	getchar();
	switch(c){
		case '1':
			printf("Un\n");
			break;
		case '2':
			printf("Deux\n");
			break;
		case '3':
			printf("Trois\n");
			break;
		default:
			printf("autre caractere");
	}		

}

// EXERCICE 3

// 3.1
void main(){
	
	int tab[10];
	int i;
	for(i=0; i<10; i++){
		tab[i]=0;
	}

}

//3.2
void main(){
	int tab[5];
	int i;
	for(i=0; i<5; i++){
		tab[i]=5-i;
	}	
}

//3.3
void main(){
	int tab[3][4];
	int i, j=0;

	for (j=0; j<3; j++){

		for(i=0; i<4; i++){
			if(j==0){
				tab[j][i]=i+12;
			}else if(j==1){
				tab[j][i]=i+16;
			}else if(j==2){
				tab[j][i]=i+20;
			}
		}	
	}

	for (j=0; j<4; j++){

		for(i=0; i<3; i++){
			printf("%d ",tab[i][j]);
		}	
		printf("\n");
	}	
}

//4.5
#include <stdio.h>

int main(){
	int tab[3][4];

	int *p;

	
	int i;
	int j;
	p=&tab[0][0];
	

	for (i=0; i<12; i++){
		*(p+i) = i+12;
		if (!i%4 && i!=0){
			p++;
			printf("\n");
		}
		printf("%d\n", *(p+i));
	}

	i=0;
	j=0;
	for (i=0; i<3; i++ ){
		for (j=0; j<4; j++ ){
			printf("tab[%d][%d]: %d",i, j, tab[i][j]);
		}	
		printf("\n");
	}	

	return 0;
}