#include <stdio.h>
#include <stdlib.h>

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
	int i, n, m, j = 0;
	int* tab1, * tab2, * tab3;
	
	//initialisations
	n = saisieTaille();
	m = saisieTaille();

	//allocation dynamique des tableaux

	tab1 = (int*)malloc(n*sizeof(int));
	tab2 = (int*)malloc(m*sizeof(int));
	tab3 = (int*)malloc((n+m)*sizeof(int));

	//Remplissage premier tableau et vérification
	do{
		printf("Insérez les valeurs de votre premier tableau. Celui-ci doit être trié !\n");
		for(i=0;i<n;i++){
			scanf("%d", &tab1[i]);
		}

		i = 0;
		while(i<n-1){
			if(tab1[i] > tab1[i+1]){
				i = 2*n;
			}
			i ++;
				
		}
	}while(i==2*n);

	//affichage premier tableau
	for(i=0;i<n;i++){
			printf("%d ", tab1[i]);
	}
	

	//Remplissage deuxième tableau et vérification
	do{
		printf("\nInsérez les valeurs de votre deuxième tableau. Celui-ci doit être trié !\n");
		for(i=0;i<m;i++){
			scanf("%d", &tab2[i]);
		}

		i = 0;
		while(i<m-1){
			if(tab2[i] > tab2[i+1]){
				i = 2*m;
			}
			i++;
				
		}
	}while(i==2*m);

	//affichage deuxième tableau
	for(i=0;i<m;i++){
			printf("%d ", tab2[i]);
	}
	
	printf("\n");
	//reattribution
	i = 0;
	j = 0;

	while(i<n || j<m){
		if(i>=n){
			tab3[i+j] = tab2[j];
			j++;
		}
		else if(j>=m){
			tab3[i+j] = tab1[i];
			i++;
		}
		else if(tab1[i] < tab2[j]){
			tab3[i+j] = tab1[i];
			i++;
		}	
		else{
			tab3[i+j] = tab2[j];
			j++;
		}	
	}

	//affichage trosième tableau
	for(i=0;i<(n+m);i++){
			printf("%d ", tab3[i]);
	}

	free(tab1);
	free(tab2);
	free(tab3);

	exit(0);
}
