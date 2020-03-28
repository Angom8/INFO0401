#include <stdio.h>
#include <stdlib.h>

//Fonction Ackerman récursif
int Ackerman(int m, int n){
	if(m == 0){
		return (n+1);
	}else if(n==0){
		return (Ackerman(m-1,1));
	}else{
		return (Ackerman(m-1, Ackerman(m, n-1)));
	}
}

void ackerman_recursif(){
	//Déclarations
	int m,n;
	
	//Initialisation
	do{
		printf("Saisir n : ");
		scanf("%d",&n);
	}while(n<0);
	do{
		printf("Saisir m : ");
		scanf("%d",&m);
	}while(n<0);
	
	//Affichage du résultat
	printf("Ackerman(%d, %d) : \n",n,m);
	printf("Resultat = %d \n", Ackerman(m,n));
}
