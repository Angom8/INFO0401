#include <stdio.h>
#include <stdlib.h>

int main(){
	//Declaration
	int * t1; 
	float * t2;
	int i, n, a, b;
	float max;
	
	//Lecture de la taille
	do{
		printf("Saisir une taille : ");
		scanf("%d",&n);
	}while(n<1);
	
	//Lecture de l'intervalle [a, b]
	printf("Saisir l'intervalle a : ");
	scanf("%d",&a);
	printf("Saisir l'intervalle b : ");
	scanf("%d",&b);
	
	//Permute a et b si besoins
	if(a>b){
		a += b;
		b = a-b;
		a = a-b;
	}	
	
	//Lecture de t1
	t1 = (int *)calloc(n, sizeof(int));
	
	for(i=0;i<n;i++){
		printf("Saisir la case t1[%d] : ", i);
		scanf("%d",t1+i);
	}
	
	//Affichage de t1
	for(i=0;i<n;i++){
		printf("%d ", t1[i]);
	}
	printf("\n");
	
	//Normalisation
	max = t1[0];
	for(i=0;i<n;i++){
		if(t1[i]>max){
			max = t1[i];
		}
	}
	printf("Max = %.0f \n", max);
	
	t2 = (float *)calloc(n, sizeof(float));
	
	printf("Resultat : \n");
	for(i=0;i<n;i++){
		if(a < 0){
			t2[i] = (t1[i]/max)*(b+abs(a)) + a;
		}else{
			t2[i] = (t1[i]/max)*(b-a) + a;
		}
		printf("%.2f ", t2[i]);
	}
	printf("\n");
}
