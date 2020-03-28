#include <stdio.h>
#include <stdlib.h>

int main(){
	//Declarations
	int ** Ma, ** Mb, ** Mc;
	int i, j, n;
	
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
			do{
				printf("Saisir la case Ma[%d, %d] : ", i, j);
				scanf("%d",&Ma[i][j]);
			}while(Ma[i][j] != 1 && Ma[i][j] != 0);
		}
	}
	
	//Lecture de Mb
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			do{
				printf("Saisir la case Mb[%d, %d] : ", i, j);
				scanf("%d",&Mb[i][j]);
			}while(Mb[i][j] != 1 && Mb[i][j] != 0);
		}
	}
	printf("\n");
	
	//Affichage de Ma
	printf("Ma : \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ", Ma[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	//Affichage de Mb
	printf("Mb : \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ", Mb[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	//Calcul du max de 2 img binaires
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(Ma[i][j] > Mb[i][j]){
				Mc[i][j] = Ma[i][j];
			}else{
				Mc[i][j] = Mb[i][j];
			}
		}
	}
	
	//Affichage de Mc
	printf("Resultat Mc : \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d ", Mc[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	//Nettoyage de la mémoire
	for(i=0;i<n;i++){
		free(Ma[i]);
		free(Mb[i]);
		free(Mc[i]);
	}
	free(Ma);
	free(Mb);
	free(Mc);

	exit(0);
}
