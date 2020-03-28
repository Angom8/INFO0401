#include <stdio.h>
#include <stdlib.h>

void ackerman_pile(){
	int m,n;
	do{
		printf("Saisir n : ");
		scanf("%d",&n);
	}while(n<0);
	do{
		printf("Saisir m : ");
		scanf("%d",&m);
	}while(n<0);
	
	printf("Ackerman(%d, %d) \n",n , m);
	
	Pile * p = creerPile();
	empilerPile(p,m);
	empilerPile(p,n);
	
	while(!pileEstVide(p)){
		n = sommet(p);
		depilerPile(p);
		
		if(!pileEstVide(p)){
			m = sommet(p);
			depilerPile(p);
		}else{
			break;
		}
		
		if(m == 0){
			empilerPile(p, n+1);
		}else if(n == 0){
			empilerPile(p, m-1);
			empilerPile(p, 1);
		}else{
			empilerPile(p, m-1);
			empilerPile(p, m);
			empilerPile(p, n-1);
		}
		
	}
	printf("Resultat : %d \n", n);
}
