#include <stdio.h>
#include <stdlib.h>

int main(){
	//Declarations
 	short int test = 1;
	int n;
	char *p1, *p2;
	char tab[30];
	
	//Lecture de la chaine de caractère
	printf("Saisir une chaine de caractere (max 30): ");
	scanf("%s", tab);
	
	//Affichage du tableau
	for(p1=tab;*p1 != '\0';p1++){
		printf("%c", *p1);
	}
	printf("\n");	
	//Calculer la taille de la chaine de caractère
	n = p1-tab;
	
	//Test si c'est un Palindrome
	for(p1=tab, p2=tab+n-1;p1<tab+(n/2);p1++, p2--){
		if(*p1 != *p2){
			test = 0;
		}
	}
	
	//Affichage du résultat
	printf("Résultat : \n");
	for(p1=tab;p1<tab+n;p1++){
		printf("%c", *p1);
	}
	if(test == 0){
		printf(" n'est pas un palindrome \n");
	}else{
		printf(" est un palindrome \n");
	}
	
	exit(0);
}
