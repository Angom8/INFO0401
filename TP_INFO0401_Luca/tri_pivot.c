#include <stdio.h>
#include <stdlib.h>

void TriRapide(int * T, int inf, int sup){
	int G, D, i, j, P, K, z;
	
	
	printf(" entree TriRapide \n");
	printf("tableau entree TriRapide \n");
	for(z=0;z<10;z++){
		printf("%d ", T[z]);
	}
	printf("\n");
	
	G = inf;
	D = sup;
	i = G;
	j = sup-1;
	P = T[sup];
	printf(" p = %d \n", P);
	
	while(i != j){
		while((T[i] < P) && (i != j)){
			i++;
		}
		
		while((T[i] > P) && (i != j)){
			j--;
		}
		
		K = T[i];
		T[i] = T[j];
		T[j] = K;
	}
	
	if(T[i] > P){
		K = T[i];
		T[i] = T[sup];
		T[sup] = K;
	}
	
	
	printf("\nTableau avant sortie TriRapide\n");
	for(z=0;z<10;z++){
		printf("%d ", T[z]);
	}
	printf("\n");
	
	printf("\nsortie TriRapide\n");
	
	if(G < i){
		printf("%d G\n", i);
		TriRapide(T,G,i);
	}
	
	if(D > i+1){
		printf("%d D\n", i);
		TriRapide(T,i+1,D);
	}
}

int main(){
	int inf, n, i;
	int * T;
	
	inf=0;
	
	do{
		printf("Saisir taille de T :");
		scanf("%d", &n);
	}while(sup < 1);
	
	T = (int *)malloc(n*sizeof(int));
	
	for(i=0;i<sup;i++){
		printf("Saisir T[%d] :", i);
		scanf("%d", &T[i]);
	}
	
	TriRapide(T, inf, sup-1);
	
	printf("Affichage du tableau trie ");
	for(i=0;i<n;i++){
		printf("%d ", T[i]);
	}
	printf("\n");
	
	return 0;
}
