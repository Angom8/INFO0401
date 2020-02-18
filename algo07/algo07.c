#include <stdio.h>
#include <stdlib.h>

int saisieTaille(){
	int taille;
	do{
		printf("Calculez le nième terme\n");
		scanf("%d", &taille);
	}while(taille<1);

	return taille;
}

//main
int main(void){
	int  i, n;
	long int* tab;
	
	//initialisations
	n = saisieTaille();

	if(n<0){
		printf("Erreur : n < 0\n");
	}
	else if (n == 0){
		printf("= 0\n");
	}
	else if (n == 1){
		printf("= 1\n");
	}
	else{
		//allocation dynamique du tableau
		tab = (long int*)malloc(n*sizeof(long int));
		tab[0] = 0;
		tab[1] = 1;
		
		for(i = 2;i<n;i++){
			tab[i] = tab[i-1] + tab[i-2];
		}
		
		
		for(i = 0;i<n;i++){
			printf("%ld ", tab[i]);
		}

		printf("\n");
		free(tab);
	}

	exit(0);
}
