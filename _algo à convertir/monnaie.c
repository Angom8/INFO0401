#include <stdio.h>

int main(){
	int a;
	
	printf("Merci de saisir votre montant en € (sans les centimes svp) : ");
	scanf("%d", &a);
	
	printf("%d billet(s) de 100, ",a/100) ;
	a = a%100;
	
	printf("%d billet(s) de 50, ",a/50) ;
	a = a%50;
	
	printf("%d billet(s) de 20, ",a/20) ;
	a = a%20;
	
	printf("%d billet(s) de 10, ",a/10) ;
	a = a%10;

	printf("%d billet(s) de 5, ",a/5) ;
	a = a%5;

	printf("%d pièce(s) de 2 ",a/2) ;
	a = a%2;
	
	printf("et %d pièce(s) de 1.\n",a/2) ;
	a = a%2;
	
	return 0;

}
