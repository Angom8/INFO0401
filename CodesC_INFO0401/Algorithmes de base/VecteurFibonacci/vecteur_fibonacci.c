#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	//Declarations
	int n, i;
	long int * tab;
	
	//Lecture du nombre d'opération
	do{
		printf("Saisir le nombre d'opération (supp à 2): ");
		scanf("%d",&n);
	}while(n < 2);
	printf("\n");
	
	//Initialisation
	tab = (long int *)calloc(n, sizeof(long int));
	tab[0] = 0;
	tab[1] = 1;
	
	//Calcul de la suite de Fibonacci
	for(i=2;i<n;i++){
		tab[i] = tab[i-1]+tab[i-2];
	}
	
	
	//Affiche la suite de Fibonacci
	printf("Suite de Fibonacci : \n");
	for(i=0;i<n;i++){
		printf("%ld ", tab[i]);
	}
	printf("\n");
	
	free(tab);
	
	return 0;
}
