#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Saisie
int saisieTaille(){
	int taille;
	do{
		printf("Taille du tableau\n");
		scanf("%d", &taille);
	}while(taille<1);

	return taille;
}

//main
int main(void){

	srand(time(NULL));

	int n, i, x;
	int compteur = 0;
	int * a, * b;

	n = saisieTaille();

	a = (int*)malloc(n*sizeof(int));
	b=a;

	//On demande X
	printf("Renseignez X le nombre à rechercher (entier supérieur à 0 et inférieur à 100)\n");
	do{
		scanf("%d", &x);
	}while(x>100&x<0);

	//remplissage avec des valeurs aléatoires de A
	for(i=0;i<n;i++){
		*(a+i) = rand()%101;
	}
	
	//Parcours et décalage à l'aide du double parcours de pointeur
	for(i=0;i<n;i++){
		*(a+i) = *b;
		if(*b != x){
			*b++;
		}
		else{
			compteur++;
		}
	}

	
	//Affichage
	for(i=0;i<n;i++){
		printf("%d ", *(a+i));
	}
	printf("\nNombre d'occurences : %d\n", compteur);


	exit(0);
}
