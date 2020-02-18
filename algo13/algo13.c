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
	b = a+n-1;


	//remplissage avec des valeurs aléatoires de A
	for(i=0;i<n;i++){
		*(a+i) = rand()%101;
	}
	

	//Affichage
	for(i=0;i<n;i++){
		printf("%d ", *(a+i));
	}
	printf("\n");

	//Parcours et décalage à l'aide du double parcours de pointeur
	for(i=0;i<n/2;i++){
		x = *(a+i);
		*(a+i) = *b;
		*b = x;

		*b--;
	}

	
	//Affichage
	for(i=0;i<n;i++){
		printf("%d ", *(a+i));
	}
	printf("\n");


	exit(0);
}
