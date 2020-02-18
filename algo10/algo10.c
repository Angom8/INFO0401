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

	int n, m, i;
	int * a, * b;

	n = saisieTaille();
	m = saisieTaille();

	a = (int*)malloc((n+m)*sizeof(int));//Taille de A = taille de B + taille de A prévue par l'utilisateur
	b = (int*)malloc(m*sizeof(int));

	//remplissage avec des valeurs aléatoires de A
	for(i=0;i<n;i++){
		*(a+i) = random()%101;
	}
	//remplissage avec des valeurs aléatoires de B
	for(i=0;i<m;i++){
		*(b+i) = random()%101;
	}

	//affichage de a puis b
	printf("A :\n");
	for(i=0;i<n;i++){
		printf("%d ", *(a+i));
	}
	printf("\nB :\n");
	for(i=0;i<m;i++){
		printf("%d ", *(b+i));
	}

	//fusion
	printf("\nFusion...\n");

	for(i=0;i<m;i++){
		*(a+i+n) = *(b + i);
	}

	//affichage de la fusion

	//fusion
	printf("A+B :\n");
	for(i=0;i<(m+n);i++){
		printf("%d ", *(a+i));
	}
	printf("\n");

	exit(0);
}
