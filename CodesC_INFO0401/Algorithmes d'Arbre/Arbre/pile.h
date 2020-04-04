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
typedef struct CellNode CellNode;
struct CellNode
{
    Node* value;
    CellNode *nxt;
};

/*Pile de premier element first*/
typedef struct PileNode PileNode;
struct PileNode
{
    CellNode *first;
};

/*Initialisation d'une pile */
PileNode* creerPileNode(){	
	PileNode *p = malloc(sizeof(PileNode));
	p->first = NULL;
	return p;
}

/*On ajoute la valeur val dans notre pile*/
void empilerPileNode(PileNode *p, Node* val){	

	CellNode *new_c = malloc(sizeof(CellNode));
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
Node* depilerPileNode(PileNode *p){

	CellNode *elem = p->first;
	Node* r;

	if (p != NULL && p->first != NULL){
		p->first = elem->nxt;
		r = elem->value;
		free(elem);
	}

	return r;
	
}

/*Retourne la valeur du sommet de la pile*/
CellNode* sommetNode(PileNode *p){

	CellNode *elem = p->first;

	return elem;
	
}

/*Retour 0 ou 1 selon si la pile est vide ou non*/
int pileNodeEstVide(PileNode *p){
	int i = 1;
	if(p != NULL && p->first != NULL){
		i = 0;
	}
	return i;
}

/*Vide complétement la pile*/
void viderPileNode(PileNode *p){

	while(p->first != NULL){
		depilerPileNode(p);
	}

}

void DeplacementPileNode(PileNode *p1, PileNode *p2){
	if(p1 != NULL){
		viderPileNode(p1);
		free(p1);
	}
	p1=creerPileNode();
	
	while(p2 != NULL && sommetNode(p2) != NULL){
		empilerPileNode(p1, sommetNode(p2)->value);
		depilerPileNode(p2);
	}
}

