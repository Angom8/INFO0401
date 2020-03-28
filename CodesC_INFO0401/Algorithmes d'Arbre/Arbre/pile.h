#include <stdlib.h>
#include <stdio.h>

/*Element de l'arbre de type int*/
typedef struct Node Node;
struct Node
{
    int value;
    Node *lft, *rgt, *top;
};

/*Element de la pile de type int*/
typedef struct Cell Cell;
struct Cell
{
    Node* value;
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
void empilerPile(Pile *p, Node* val){	

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
		printf("--%d\n", elem->value);
		p->first = elem->nxt;
		free(elem);
	}
	
}

/*Retourne la valeur du sommet de la pile*/
Node* sommet(Pile *p){

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
