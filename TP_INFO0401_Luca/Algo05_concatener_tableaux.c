#include <stdio.h>
#include <stdlib.h>

int main(){
	//Declaration
	int i, j, n1, n2;
	int * a, * b, * c;
	
	//Lecture de la taille
	do{
		printf("Saisir la taille du premier tableau : ");
		scanf("%d",&n1);
	}while(n1 < 1);
	
	do{
		printf("Saisir la taille du deuxieme tableau : ");
		scanf("%d",&n2);
	}while(n2 < 1);
	
	//Initialisation
	a = (int *)calloc(n1, sizeof(int));
	b = (int *)calloc(n2, sizeof(int));
	c = (int *)calloc(n1+n2, sizeof(int));
	
	//Lecture du tableau A
	printf("Saisir a[0] : ");
	scanf("%d",&a[0]);
	for(i=1;i<n1;i++){
		do{
		printf("Saisir a[%d] : ",i);
		scanf("%d",&a[i]);
		}while(a[i-1] > a[i]);
	}
	printf("\n");
	
	//Lecture du tableau B
	printf("Saisir b[0] : ");
	scanf("%d",&b[0]);
	for(i=1;i<n2;i++){
		do{
		printf("Saisir b[%d] : ", i);
		scanf("%d",&b[i]);
		}while(b[i-1] > b[i]);
	}
	printf("\n");
	
	//Affichage du tableau A
	for(i=0;i<n1;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	
	//Affichage du tableau B
	for(i=0;i<n2;i++){
		printf("%d ",b[i]);
	}
	printf("\n");
	
	//Concatener
	i=0;
	j=0;
	while(i<n1 || j<n2){
		if(i>=n1){
			c[i+j] = b[j];
			j++;
		}else if(j>=n2){
			c[i+j] = a[i];
			i++;
		}else if(a[i] < b[j]){
			c[i+j] = a[i];
			i++;
		}else{
			c[i+j] = b[j];
			j++;
		}
	}
	
	//Affichage du tableau C
	for(i=0;i<(n1+n2);i++){
		printf("%d ",c[i]);
	}
	printf("\n");
}
