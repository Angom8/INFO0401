#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int saisieTaille(){
	int taille;
	do{
		printf("Taille de la matrice\n");
		scanf("%d", &taille);
	}while(taille<1);

	return taille;
}

//main
int main(void){

	srand(time(NULL));

	int  i, j, x;
	int n, m;
	int ** tab;
	int indices[] = {-1, -1};

	n = saisieTaille();
	m = saisieTaille();

	tab = (int**)malloc(n*sizeof(int*));

	for(i=0;i<m;i++){
		tab[i] = malloc(m*sizeof(int));
	}

	//remplissage

	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			tab[i][j] = random()%101;
		}
	}

	printf("Valeur à chercher : \n");
	scanf("%d", &x);

	i = 0;
	j = 0;

	while(indices[0] == -1 && i < n){
		while(indices[0] == -1 && j < m){
			if(tab[i][j] == x){
				indices[0] = i;
				indices[1] = j;
			}
			j++;

		} 	
		i++;

	} 

	if(indices[0] == -1){
		printf("Valeur trouvée, indices i=%d, j=%d\n", indices[0], indices[1]);
	}
	else{
		printf("Valeur non trouvée\n");
	}

	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%d ", tab[i][j]);
		}
	}

	printf("\n");
	exit(0);
}
