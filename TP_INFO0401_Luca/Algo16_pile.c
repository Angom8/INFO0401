#include <stdio.h>
#include <stdlib.h>

typedef struct Cell{
	int value;
	struct Cell * next;	
}Cell;

typedef struct Pile{
	struct Cell * first;	
}Pile;

Pile * creerPile(){
	Pile * p = malloc(sizeof(Pile));
	p->first = NULL;
	return p;
}

void empiler(Pile * p, int val){
	Cell * new_cell = malloc(sizeof(Cell));
	new_cell->value = val;
	new_cell->next = NULL;
	if(p != NULL || new_cell != NULL){
		if(p->first != NULL){
			new_cell->next = p->first;
			p->first = new_cell;
		}else{
			new_cell->next = NULL;
			p->first = new_cell;
		}
	}
}

void depiler(Pile *p){
	Cell *elem = p->first;
	if(p != NULL && p->first != NULL){
		p->first = elem->next;
		free(elem);
	}
}

int sommet(Pile * p){
	return p->first->value;
}

int pileEstVide(Pile * p){
	int test=0;
	if(p->first == NULL){
		test=1;
	}
	return test;
}

void viderPile(Pile * p){
	while(p->first != NULL){
		depiler(p);
	}
}

void afficherPile(Pile * p){
	Pile * tmp = creerPile();
	
	while(p->first != NULL){
		empiler(tmp, sommet(p));
		printf("%d ", sommet(p));
		depiler(p);
	}
	printf("\n");
	
	while(tmp->first != NULL){
		empiler(p, sommet(tmp));
		depiler(tmp);
	}
}

int egalPile(Pile * p1, Pile * p2){
	int test = 1;
	
	Pile * tmp1 = creerPile();
	Pile * tmp2 = creerPile();
	
	while(p1->first != NULL && p2->first != NULL){
		empiler(tmp1, sommet(p1));
		empiler(tmp2, sommet(p2));
		
		if(sommet(p1) != sommet(p2)){
			test = 0;
		}
		
		depiler(p1);
		depiler(p2);
	}
	
	if(p1->first != NULL || p2->first != NULL){ test = 0; }
	
	while(tmp1->first != NULL && tmp2->first != NULL){
		empiler(p1, sommet(tmp1));
		empiler(p1, sommet(tmp1));
		
		depiler(tmp1);
		depiler(tmp2);
	}
	
	return test;
}

void trierPile(Pile * p){

	Pile * tmp1 = creerPile();
	Pile * tmp2 = creerPile();
	int min;
	
	while(p->first != NULL){
		min = sommet(p);
		while(p->first != NULL){
			if(sommet(p) < min){
				min = sommet(p);
			}
			empiler(tmp1, sommet(p));
			depiler(p);
		}
		
		while(tmp1->first != NULL){
			if(sommet(tmp1) != min){
				empiler(p, sommet(tmp1));
			}
			depiler(tmp1);
		}
		
		empiler(tmp2, min);
	}
	
	while(tmp2->first != NULL){
		empiler(p, sommet(tmp2));
		depiler(tmp2);
	}
}

int main(){
	int i;
	Pile * p = creerPile();
	Pile * p2 = creerPile();
	for(i=0; i<10;i++){
		empiler(p, i);
		empiler(p2, i);
	}
	afficherPile(p2);
	
	trierPile(p);
	afficherPile(p);
	
	printf("\n%d \n",egalPile(p,p2));
	empiler(p, 10);
	printf("\n%d \n",egalPile(p,p2));
	
	printf("\n%d \n",p->first->value);
	depiler(p);
	printf("%d \n",p->first->value);
	viderPile(p);
	printf("%d \n",pileEstVide(p));
	empiler(p, 10);
	printf("%d \n",pileEstVide(p));
	printf("%d \n",p->first->value);
	return 0;
}
