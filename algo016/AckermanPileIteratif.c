#include <stdlib.h>
#include <stdio.h>

/*Element de la pile de type int*/
typedef struct Cell Cell;
struct Cell
{
    int value;
    Cell *nxt;
};

/*Pile de premier element first*/
typedef struct Pile Pile;
struct Pile
{
    Cell *first;
};

/*Initialisation d'une pile */
Pile* creerPile(){	
	Pile *p = malloc(sizeof(Pile));
	p->first = NULL;
	return p;
}

/*On ajoute la valeur val dans notre pile*/
void empilerPile(int val, Pile *p){	

	Cell *new_c = malloc(sizeof(*new_c));
    	if (p == NULL || new_c == NULL){
  	}
	else{
		if(p->first != NULL){/*Ajout d'un élément de la pile*/
		    	new_c->value = val;
		    	new_c->nxt = p->first;
		   	p->first = new_c;
		}
		else{/*Ajout du premier élément de la pile*/
		    	new_c->value = val;
		    	new_c->nxt = NULL;
		   	p->first = new_c;
		}
	}
	
}

/*On retire le sommet*/
void depilerPile(Pile *p){

	Cell *elem = p->first;

	if (p != NULL && p->first != NULL){
		
		p->first = elem->nxt;
		free(elem);
	}
	
}

/*Retourne la valeur du sommet de la pile*/
int sommet(Pile *p){

	Cell *elem = p->first;

	return elem->value;
	
}

/*Retour 0 ou 1 selon si la pile est vide ou non*/
int pileEstVide(Pile *p){
	int i = 1;
	if(p != NULL && p->first != NULL){
		i = 0;
	}
	return i;
}

/*Vide complétement la pile*/
void viderPile(Pile *p){

	while(p->first != NULL){
		depilerPile(p);
	}

}

/*Ackerman itératif via une pile*/
int Ackerman(Pile *p){
	int m, n;

	printf("Rentrez m et n\n");

	scanf("%d", &n);
	scanf("%d", &m);

	empilerPile(m, p);
	empilerPile(n, p);

	while(pileEstVide(p) == 0){
		n = sommet(p);
		depilerPile(p);
		if(pileEstVide(p) == 0){
			
			m = sommet(p);
			depilerPile(p);
			
		}
		else{
			return(n);
		}
		if(m==0){
			empilerPile(n+1, p);
		}
		else if(n==0){
				empilerPile(m-1, p);
				empilerPile(1, p);
			}
		else{
			empilerPile(m-1, p);
			empilerPile(m,p);
			empilerPile(n-1, p);
		}
	}

}

int main(){
	
	printf("%d\n", Ackerman(creerPile()));	

	return 0;

}
