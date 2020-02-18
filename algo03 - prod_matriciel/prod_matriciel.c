#include <stdio.h>
#include <stdlib.h>

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
	int max, i, j, k, taille, a, b, tmp;
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

	printf("Insérez les valeurs de votre premiere matrice\n");
	
	for(i=0;i<taille;i++){
		for(j=0;j<taille;j++){
			scanf("%d", &m1[i][j]);//On verifie la saisie via la variable tmp
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
	printf("Insérez les valeurs de votre deuxième matrice\n");
	
	for(i=0;i<taille;i++){
		for(j=0;j<taille;j++){
			scanf("%d", &m2[i][j]);
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

	//Remplissage troisième matrice
	for(i=0;i<taille;i++){
		for(j=0;j<taille;j++){
			m3[i][j] = 0;
		}
	}

	
	//Remplissage troisième matrice par calcul
	for(i=0;i<taille;i++){
		for(j=0;j<taille;j++){
			for(k=0;k<taille;k++){
				m3[i][j] += m1[i][k] + m2[k][j];
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
	free(m1);
	free(m2);
	free(m3);

	exit(0);
}
