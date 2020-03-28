#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*Demande à l'utilisateur de sasir*/
int saisirNb(){
	int nb;
	
	do{
		printf("Saisir un nombre en base 10 :");
		scanf("%d", &nb);
	}while(nb < 0);
	
	return nb;
}

/*Convertie un nombre base 10 en base 2*/
int * conversion(int nb){
	//Declarations
	int i, tmp, n;
	int * v;
	
	//Calcul de la taille du tableau
	tmp = nb;
	for(i=0;tmp > 0;i++){
		tmp -= pow(2,i);
	}
	n = i;
	
	//Initialisation du tableau v
	v = (int *)malloc(sizeof(int)*n);
	
	//Calcul du nombre binaire
	for(i=n-1;i>=0;i--){
		if(nb%2 == 0){
			v[i] = 0;
		}else{
			v[i] = 1;
		}
		
		nb /= 2;
	}
	
	//Affichage du tableau v
	printf("nombre binaire : \n");
	for(i=0;i<n;i++){
		printf("%d ", v[i]);
	}
	printf("\n");
	
	return v;
}


void conversion_binaire(){
	int n, nb, tmp, i;
	int * T;
	
	nb = saisirNb();
	
	tmp = nb;
	for(i=0;tmp > 0;i++){
		tmp -= pow(2,i);
	}
	n = i;
	
	T = conversion(nb);
	
	free(T);
}
