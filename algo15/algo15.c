#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//main
int main(void){

	srand(time(NULL));

	int n, i;
	short int sortie= 0;
	char c[255];
	char * a, * b;


	//remplissage 
	printf("Saisissez une chaine de caractères (Taille max : 255)\n");
	scanf("%s", c);

	i = 0;
	n = 1;
	while(*(c+i) != '\0'){
		n++;
		i++;
	}
	
	a = c;
	b = a+n;
	
	//Affichage
	for(i=0;i<n;i++){
		printf("%c", *(a+i));
	}
	printf("\n");

	//Parcours et décalage à l'aide du double parcours de pointeur

	i = 0;
	while (sortie == 0 & i<n/2){
		if(*(a+i) == *b || *(a+i) == *b+32 || *(a+i) == *b-32){//Majuscules ET minuscules
			i ++;
			*b--;
		}
		else{
			sortie = 1;
		}

	}


	if(sortie != 0){
		printf("Est un palindrome\n");
	}
	else{
		printf("N'est pas un palindrome\n");
	}


	exit(0);
}
