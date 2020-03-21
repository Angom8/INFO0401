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

//main
int main(void){
	
	//declarations
	int max, i, taille, a, b;
	int* t1;
	float* t2;

	//Entrée de valeurs par l'utilisateur
	do{
		printf("Rentrez la taille des tableaux\n");
		scanf("%d", &taille);
	}while(taille<1);

	//allocation dynamique des tableaux
	t1 = malloc(taille*sizeof(int));
	t2 = malloc(taille*sizeof(float));

	printf("Insérez les valeurs de votre tableau\n");
	
	for(i=0;i<taille;i++){
		scanf("%d", &t1[i]);
	}

	//affichage des valeurs
	printf("Votre tableau :\n");
	
	for(i=0;i<taille;i++){
		printf("%d ", t1[i]);
	}	
	printf("\n");

	//Entrée des valeurs normalisantes
	printf("Rentrez vos valeurs normalisantes\n");
	scanf("%d %d", &a, &b);

	if(b<a){//On inverse les valeurs si elles ne sont pas rentrées dans l'ordre
		a += b;
		b = a - b;
		a = a - b;
	}


	//Recherche de la valeur maximale du tableau
	max = t1[0];
	for(i=0;i<taille;i++){
		if(maximum(max, t1[i])>max){
			max = t1[i];
		}
	}	

	//Deplacement et normalisation vers le deuxième tableau
	for(i=0;i<taille;i++){
		if(a<0){
			t2[i] = (t1[i]*1.0/max)*(abs(a)+abs(b))+a;//On multiplie par la valeur maximale, on agrandie l'intervalle et on le décale avec a
		}
		else{
			t2[i] = (t1[i]*1.0/max)*(abs(b)-abs(a))+a;//On multiplie par la valeur maximale, on agrandie l'intervalle et on le décale avec a
		}
	}

	//affichage du deuxième tableau
	printf("Votre tableau normalisé :\n");
	
	for(i=0;i<taille;i++){
		printf("%.2f ", t2[i]);
	}	
	printf("\n");

	//Nettoyage de la mémoire
	free(t1);
	free(t2);

	exit(0);
}
