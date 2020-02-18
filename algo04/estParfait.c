#include <stdio.h>
#include <stdlib.h>

//main
int main(void){
	int i, n, somme;
	
	//initialisations
	printf("Saisir un entier\n");
	scanf("%d", &n);
	somme = 0;

	printf("Valeur saisie : %d\n", n);

	//calcul: On regarde jusqu'à la valeur n/2 (inutile au-delà) et on additionne à la somme
	for(i=1;i<=(n/2);i++){
		if(n%i == 0){
			somme += i;
		}
	}

	if(somme == n){
		printf("Votre nombre est parfait !\n");
	}
	else{
		printf("Votre nombre n'est pas parfait !\n");
	}

	exit(0);
}
