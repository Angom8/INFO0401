#include <stdio.h>
#include <stdlib.h>

void copie_chaine(){
	//Declarations
	int n;
	char * p1, * p2;
	char tab[100], * tab_copy;
	
	//Lecture de la chaine de caractère
	printf("Saisir une chaine de caractere max(100) : ");
	scanf("%s",tab);
	
	//Calcul de la taille de la chaine
	for(p1=tab;*p1 != '\0';p1++){
	}
	n = p1-tab;
	
	//Initialisation
	tab_copy = (char *)calloc(n, sizeof(char));
	
	//Copie
	for(p1=tab, p2 = tab_copy;*p1 != '\0';p1++, p2++){
		*p2 = *p1;
	}
	
	//Affichage du résultat
	printf("résultat : %s de taille %d \n", tab_copy, n);
	
	//Nettoyage de la mémoire
	free(tab_copy);
}
