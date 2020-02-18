#include <stdio.h>
#include <stdlib.h>

//Fonction max : Retourne un int, prend deux int a et b
int maximum(int a, int b){
	int max;
	if(a>b){
		max = a;
	}
	else{
		max = b;
	}
}

//Fonction de saisie de la taille d'un tableau : Retourne un int
int saisieTaille(){

	int taille;

	do{
		printf("Rentrez la taille des tableaux\n");
		scanf("%d", &taille);
	}while(taille<1);

	return taille;
}

//main
int main(void){
	
	//declarations
	int max, i, j, taille, a, b, tmp;
	int** m1;
	int** m2;
	int** m3;

	//Entrée de valeurs par l'utilisateur
	taille = saisieTaille();

	//allocation dynamique des matrices

	m1 = (int**)malloc(taille*sizeof(int*));
	m2 = (int**)malloc(taille*sizeof(int*));
	m3 = (int**)malloc(taille*sizeof(int*));

	for(i=0;i<taille;i++){
		m1[i] = malloc(taille*sizeof(int));
		m2[i] = malloc(taille*sizeof(int));
		m3[i] = malloc(taille*sizeof(int));
	}

	//Remplissage première matrice

	printf("Insérez les valeurs de votre premiere matrice (0 ou 1)\n");
	
	for(i=0;i<taille;i++){
		for(j=0;j<taille;j++){
			scanf("%d", &tmp);//On verifie la saisie via la variable tmp
			if(tmp >= 1){
				m1[i][j] = 1;
			}
			else{		
				m1[i][j] = 0;
			}
		}
	}

	//affichage des valeurs première matrice

	printf("Votre matrice m1 :\n");
	
	for(i=0;i<taille;i++){
		for(j=0;j<taille;j++){
			printf("%d ", m1[i][j]);
		}
		printf("\n");
	}	

	//Remplissage deuxième matrice
	printf("Insérez les valeurs de votre deuxième matrice (0 ou 1)\n");
	
	for(i=0;i<taille;i++){
		for(j=0;j<taille;j++){
			scanf("%d", &tmp);//On verifie la saisie via la variable tmp
			if(tmp >= 1){
				m2[i][j] = 1;
			}
			else{		
				m2[i][j] = 0;
			}
		}
	}

	//affichage des valeurs deuxième matrice

	printf("Votre matrice m2 :\n");
	
	for(i=0;i<taille;i++){
		for(j=0;j<taille;j++){
			printf("%d ", m2[i][j]);
		}
		printf("\n");
	}	


	//calcul matrice 3
	for(i=0;i<taille;i++){
		for(j=0;j<taille;j++){
			if(maximum(m1[i][j], m2[i][j])>=1){
				m3[i][j] = 1;
			}
			else{		
				m3[i][j] = 0;
			}
		}
	}

	printf("Votre matrice m3 :\n");
	
	for(i=0;i<taille;i++){
		for(j=0;j<taille;j++){
			printf("%d ", m3[i][j]);
		}
		printf("\n");
	}	

	//Nettoyage de la mémoire
	for(i=0;i<taille;i++){
		free(m1[i]);
		free(m2[i]);
		free(m3[i]);
	}
	free(m1);
	free(m2);
	free(m3);

	exit(0);
}
