#include <stdio.h>
#include <stdlib.h>

int main(){
	//Declaration
	int ** Ma, ** Mb, ** Mc;
	int i, j, k, n;
	
	//Lecture de la taille
	do{
		printf("Saisir une taille : ");
		scanf("%d",&n);
	}while(n<1);
	
	//Allocation dynamique
	Ma = (int **)calloc(n, sizeof(int *));
	Mb = (int **)calloc(n, sizeof(int *));
	Mc = (int **)calloc(n, sizeof(int *));
	
	for(i=0;i<n;i++){
		Ma[i] = (int *)calloc(n, sizeof(int));
		Mb[i] = (int *)calloc(n, sizeof(int));
		Mc[i] = (int *)calloc(n, sizeof(int));
	}	
	
	//Lecture de Ma
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("Saisir la case Ma[%d, %d] : ", i, j);
			scanf("%d",&Ma[i][j]);
		}
	}
	
	//Lecture de Mb
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("Saisir la case Mb[%d, %d] : ", i, j);
			scanf("%d",&Mb[i][j]);
		}
	}
	
	//Affichage de Ma
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ", Ma[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	//Affichage de Mb
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ", Mb[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	//Initialisation de la matrice C en 0
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			Mc[i][j] = 0;
		}
	}
	
	//Multiplication de la matrice A et B
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			for(k=0;k<n;k++){
				Mc[i][j] += Ma[i][k]*Mb[i][k];
			}
		}
	}
	
	//Affichage de Mc
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ", Mc[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
