#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	//Declarations
	int n, i;
	long int a, b, c;
	
	//Lecture du nombre d'opération
	do{
		printf("Saisir le nombre d'opération supp à 2: ");
		scanf("%d",&n);
	}while(n < 2);
	
	//Initialisation
	a = 0;
	printf("%d ", a);
	b = 1;
	printf("%d ", b);
	
	//Calcul de la suite de Fibonacci et affichage
	for(i=2;i<n;i++){
		c = a+b;
		printf("%d ", c);
		a = b;
		b = c;
	}
	printf("\n");
	
	return 0;
}
