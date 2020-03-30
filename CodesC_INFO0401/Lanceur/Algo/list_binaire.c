#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/*Contruit une liste à partir d'un tableau d'entiers*/
Liste * constructionListB(int * v, int n){
	int i;
	Liste * l = creerListe();
	
	for(i=0;i<n;i++){
		ajouterDernierElementListe(l, v[i]);
	}
	
	printf("Construction de la liste :\n");
	afficherListe(l);
	
	return l;
}

/*Incremente de 1 une liste binaire*/
void incrementationListeB(Liste * l){
	int counter; 
	Cell * c;
	if(l != NULL && l->first != NULL){
		counter = l->size-2;
		c = l->last;
		while(c != NULL && counter >= 0 && c->value != 0){
			c->value = 0;
			c = chercherElementListe(l,counter);
			counter--;
		}
	
		if(c != NULL && counter >= 0){
			c->value = 1;
		}else{
			ajouterDernierElementListe(l, 0);
		}
	}
	printf("Incrementation de 1 : \n");
	afficherListe(l);
}
