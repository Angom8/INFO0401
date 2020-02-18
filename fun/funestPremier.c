#include <stdio.h>
#include <stdlib.h>

//Fonction déterminant si un nombre 
int estPremier(int n){
	int i, somme;
	short short int isPerfect = 0;//En C, le type booléen n'est pas primitif.
	
	//initialisations
	somme = 0;

	//calcul
	for(i=1;i<=(n/2);i++){
		if(n%i == 0){
			somme += i;
		}
	}

	if(somme == n){
		isPerfect = 1;
	}

	return isPerfect;
}
