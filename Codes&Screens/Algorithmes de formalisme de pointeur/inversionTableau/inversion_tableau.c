#include <stdio.h>
#include <stdlib.h>

int main(){
	//Declarations
	int n, tmp;
	int *p1, *p2;
	int * tab;
	
	//Lecture de la taille du tableau
	do{
		printf("Saisir la taille du tableau : ");
		scanf("%d",&n);
	}while(n < 1);
	
	//Initialisation
	tab = (int *)calloc(n, sizeof(int));
	
	//Lecture du tableau
	for(p1=tab;p1<tab+n;p1++){
		printf("Saisir tab[%ld] = : ", p1-tab);
		scanf("%d",p1);
	}
	
	//Affichage du tableau
	for(p1=tab;p1<tab+n;p1++){
		printf("%d ", *p1);
	}
	printf("\n");
	
	//Inverse les éléments du tableau
	for(p1=tab, p2=tab+n-1;p1<tab+(n/2);p1++, p2--){
		tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
	}
	
	//Affichage du résultat
	printf("Résultat : \n");
	for(p1=tab;p1<tab+n;p1++){
		printf("%d ", *p1);
	}
	printf("\n");
	
	//Nettoyage de la mémoire
	free(tab);
	
	exit(0);
}
