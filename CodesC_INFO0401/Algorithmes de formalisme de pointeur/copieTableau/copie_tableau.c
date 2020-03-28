#include <stdio.h>
#include <stdlib.h>

int main(){
	//Declaration
	int n;
	int * p1, * p2;
	int * tab;
	int * tab_copy;
	
	//Lecture de la chaine de caractère
	printf("Saisir la taille n : ");
	do{
		scanf("%d",&n);
	}while(n < 1);
	
	//Initialisation
	tab = (int *)calloc(n, sizeof(int));
	tab_copy = (int *)calloc(n, sizeof(int));
	
	//Lecture du tableau
	for(p1=tab;p1 < &tab[n];p1++){
		printf("Saisir tab[%ld] :", p1-tab);
		scanf("%d", p1);
	}
	printf("\n");
	
	//Affichage du résultat
	printf("tab : ");
	for(p1=tab;p1 < &tab[n];p1++){
		printf("%d ", *p1);
	}
	printf("\n");
	
	//Copie
	for(p1=tab, p2=tab_copy;p1 < &tab[n];p1++, p2++){
		*p2 = *p1;
	}
	
	//Affichage du résultat
	printf("résultat tab_copy : ");
	for(p1=tab_copy;p1 < &tab_copy[n];p1++){
		printf("%d ", *p1);
	}
	printf("\n");
	
	free(tab);
	free(tab_copy);
	exit(0);
}
