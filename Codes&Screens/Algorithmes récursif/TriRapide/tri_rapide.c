#include <stdio.h>
#include <stdlib.h>

void TriRapide(int * T, int inf, int sup){
	int G, D, i, j, P, K;
	
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
		
		while((T[j] > P) && (i != j)){
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
	
	if(G < i){
		TriRapide(T,G,i);
	}
	
	if(D > i+1){
		TriRapide(T,i+1,D);
	}
}

int main(){
	int inf, n, i;
	int * T;
	
	do{
		printf("Saisir taille de T :");
		scanf("%d", &n);
	}while(n <= 1);
	
	T = (int *)malloc(n*sizeof(int));
	
	for(i=0;i<n;i++){
		printf("Saisir T[%d] :", i);
		scanf("%d", &T[i]);
	}
	
	TriRapide(T, 0, n-1);
	
	printf("Affichage du tableau trie ");
	for(i=0;i<n;i++){
		printf("%d ", T[i]);
	}
	printf("\n");
	
	exit(0);
}
