#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void variables_fibonacci(){
	//Declarations
	int n, i;
	long int a, b, c;
	
	//Lecture du nombre d'opération
	do{
		printf("Saisir le nombre d'opération supp à 2: ");
		scanf("%d",&n);
	}while(n < 2);
	printf("\n");
	
	//Initialisation
	printf("Suite de Fibonacci : \n");
	a = 0;
	printf("%ld ", a);
	b = 1;
	printf("%ld ", b);
	
	//Calcul de la suite de Fibonacci et affichage
	for(i=2;i<n;i++){
		c = a+b;
		printf("%ld ", c);
		a = b;
		b = c;
	}
	printf("\n");
}
