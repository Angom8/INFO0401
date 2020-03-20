#include <stdio.h>
#include <stdlib.h>

int main(){
	//Declarations
	int n, nb;
	int *p1, *p2;
	int * tab;
	
	//Lecture de la taille du tableau
	do{
		printf("Saisir la taille du tableau : ");
		scanf("%d",&n);
	}while(n < 1);
	
	//Lecture de l'occurence
	printf("Saisir l'occurance à supprimer : ");
	scanf("%d",&nb);
	
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
	
	//Supprimer toutes les occurences
	for(p1=p2=tab;p1<tab+n;p1++){
		*p2 = *p1;
		if(*p2 != nb){
			p2++;
		}
	}
	n = p2-tab;
	
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
