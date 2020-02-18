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
	long int a, b, c;

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
		a = 0;
		b = 1;
		
		for(i=2;i<n;i++){
			c = a;
			a = a + b;
			b = c;
			printf("%ld ", c);
		}	
	}

	printf("\n");

	exit(0);
}
