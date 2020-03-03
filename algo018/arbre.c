#include <stdlib.h>
#include <stdio.h>

/*Element de la pile de type int*/
typedef struct Node Node;
struct Node
{
    int value;
    Node *lft, *rgt, *top;
};

/*Liste de taille n, de premier element first et de dernier element last*/
typedef struct Arbre Arbre;
struct Arbre
{
    Node *root;
    int size;

};

/*Initialisation d'un arbre 
**L'arbre ne contient aucune case
**La taille est de 0
*/
Arbre* creerArbre(){	
	Arbre * a = malloc(sizeof(Arbre));
	a->root = NULL;
	a->size = 0;
	return a;
}

void afficher(Arbre *a, char c){
	
	switch(c){
		case('p'):
			afficherPostfixe(a->root);
			break;
		case('i'):
			afficherInfine(a->root);
			break;
		default:
			afficherPrefixe(a->root);
			break;
	}

}

void afficherPrefixe(Node *e){
	if(e != NULL){
		printf("%d", e->value);
		afficherPrefixe(e->lft);
		afficherPrefixe(e->rgt);
	}
}

void afficherInfine(Node *e){
	if(e != NULL){
		afficherInfine(e->lft);
		printf("%d", e->value);
		afficherInfine(e->rgt);
	}
}

void afficherPostfixe(Node *e){
	if(e != NULL){
		afficherPostfixe(e->lft);
		afficherPostfixe(e->rgt);
		printf("%d", e->value);
	}
}

void calculHauteur(Arbre *a){
	int h;
	Node *e = a->root;
	if(e != NULL){
		h = parcoursHauteur(e, 1);
	}
	return h;

}

int calculHauteurEtage(Node *e){
	int h;
	if(e != NULL){
		h = parcoursHauteur(e, 1);
	}
	return h;

}

int parcoursHauteur(Node *e, h){
	if(e != NULL){
		parcoursHauteur(e->lft, h+1);
		parcoursHauteur(e->rgt, h+1);
	}
	return h;
}

int estEquilibre(Arbre *a){
	int hl = 0;
	int hr = 0;

	if(a->root->lft != NULL){
		hl = calculHauteurEtage(a->root->lft)
	}
	if(a->root->rgt != NULL){
		hr = calculHauteurEtage(a->root->rgt)
	}
	return (hr+1==hl | hl+1==hr | hr == hr);
}

int estEgal(Arbre *a1, Arbre *a2){
	return parcoursEgal(a1->root, a2->root, 1);
}

void parcoursEgal(Node *e1, Node*e2, int n){
	int n_tmp = n;
	if(e1 != NULL &  e1 != NULL){
		if(e1->value != e2->value){
			n_tmp = 0;
		}
		else{
			n_tmp = afficherPrefixe(e1->lft, e2->lft, n_tmp);
			n_tmp = afficherPrefixe(e1->rgt, e2->rgt, n_tmp);
		}
	}
	else{
		if(e1 != e2){
			n_tmp = 0;
		}
	}
	return n_tmp;
}

