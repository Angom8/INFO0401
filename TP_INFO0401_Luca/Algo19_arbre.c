#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int value;
	Node *lft, *rgt, *top;
} Node;

typedef struct arbre{
	int size;
	Node *root;
} Arbre;


Arbre* creerArbre(){
	Arbre * a = malloc(sizeof(Arbre));
	a->root = NULL;
	a->size = 0;
	
	return a;
}

void afficherPrefixe(Node * n){
	if(n != NULL){
		printf("%d \n"n->value);
		afficherPrefixe(n->lft);
		afficherPrefixe(n->rgt);
	}
}

void afficherInfixe(Node * n){
	if(n != NULL){
		afficherInfixe(n->lft);
		printf("%d \n"n->value);
		afficherInfixe(n->rgt);
	}
}

void afficherPosfixe(Node * n){
	if(n != NULL){
		afficherInfixe(n->lft);
		afficherInfixe(n->rgt);
		printf("%d \n"n->value);
	}
}

void Initilizer(Arbre * a){

}

void ajouterValeur(Arbre * a, Node * n, int val){
	Node * node;
	node->value = val;
	node->lft
	if(n != NULL){
		if(n->lft == NULL){
			n->lft = node;
		}else if(n->rgt == NULL){
			n->rgt = node;
		}else{
			
		}
	}
}



