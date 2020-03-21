#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	//Declarations
	int n, i, nb, compteur, tmp1, tmp2;
	int * tab;
	
	//Lecture de la taille du tableau
	do{
		printf("Saisir la taille du tableau : ");
		scanf("%d",&n);
	}while(n < 1);
	
	//Initialisation
	tab = (int *)calloc(n, sizeof(int));
	
	//Lecture du tableau
	printf("Saisir tab[0] : ");
	scanf("%d",&tab[0]);
	for(i=1;i<n;i++){
		do{
		printf("Saisir tab[%d] : ",i);
		scanf("%d",&tab[i]);
		}while(tab[i-1] > tab[i]);
	}
	printf("\n");
	
	//Affiche le tableau
	for(i=0;i<n;i++){
		printf("%d ", tab[i]);
	}
	printf("\n");
	
	//Calcul du majoré
	tmp2 = tab[0];
	compteur = 0;
	tmp1 = 1;
	for(i=1;i<n;i++){
		if(tmp2 != tab[i]){
			if(tmp1 > compteur){
				compteur = tmp1;
				nb = tmp2;
			}
			tmp1 = 1;
			tmp2 = tab[i];
		}else{
			tmp1++;
		}
	}
	
	//Affichage du résultat
	printf("Le majoté est %d qui est compté %d fois \n", nb, compteur);
	
	//Nettoyage de la mémoire
	free(tab);
	
	exit(0);
}
