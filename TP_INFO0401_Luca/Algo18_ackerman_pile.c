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
			new_cell->value = val;
			new_cell->next = p->first;
			p->first = new_cell;
		}else{
			new_cell->value = val;
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
	Cell *elem = p->first;
	return elem->value;
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

int main(){
	int m,n;
	do{
		printf("saisir n: ");
		scanf("%d",&n);
	}while(n<0);
	do{
		printf("saisir m : ");
		scanf("%d",&m);
	}while(n<0);
	
	Pile * p = creerPile();
	empiler(p,m);
	empiler(p,n);
	
	while(!pileEstVide(p)){
		n = sommet(p);
		depiler(p);
		
		if(!pileEstVide(p)){
			m = sommet(p);
			depiler(p);
		}else{
			break;
		}
		
		if(m == 0){
			empiler(p, n+1);
		}else if(n == 0){
			empiler(p, m-1);
			empiler(p, 1);
		}else{
			empiler(p, m-1);
			empiler(p, m);
			empiler(p, n-1);
		}
		
	}
	printf("résultat : %d \n", n);
	
	return 0;
}
