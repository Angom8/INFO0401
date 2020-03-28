#include <stdio.h>
#include <stdlib.h>

int main(){
	//Declarations
	int i, nb, tmp;
	
	//Lecture de la taille
	printf("Saisir un nombre : ");
	scanf("%d",&nb);
	
	//Initialisation
	tmp = 0;	
	
	//Calcul d'un nombre parfait
	for(i=1;i<=(nb/2);i++){
		if((nb%i) == 0){
			tmp += i;
		}
	}
	printf("\n");
	
	//Vérification si le nombre est parfait
	if(nb == tmp){
		printf("Le nombre %d est parfait \n", nb);
	}else{
		printf("Le nombre %d n'est pas parfait \n", nb);
	}
}
