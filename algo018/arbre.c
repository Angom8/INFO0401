#include <stdlib.h>
#include <stdio.h>
#include "pile.h"

/*Element de l'arbre de type int*/
typedef struct Node Node;
struct Node
{
    int value;
    Node *lft, *rgt, *top;
};

/*Liste de taille n, de premier element root*/
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


int parcoursHauteur(Node *e, int h){
	int htmp1 = h;
	int htmp2 = h;
	if(e != NULL){
		htmp1 = parcoursHauteur(e->lft, h+1);
		htmp2 = parcoursHauteur(e->rgt, h+1);
		if(htmp1 < htmp2){
			htmp1 = thmp2;
		}
	}
	return htmp1;
}

int calculHauteur(Arbre *a){
	int h;
	Node *e = a->root;
	if(e != NULL){
		h = parcoursHauteur(e, 0);
	}
	return h;

}

int calculHauteurEtage(Node *e){
	int h;
	if(e != NULL){
		h = parcoursHauteur(e, 0);
	}
	return h;
}

int estEquilibre(Arbre *a){
	int hl = 0;
	int hr = 0;

	if(a->root->lft != NULL){
		hl = calculHauteurEtage(a->root->lft);
	}
	if(a->root->rgt != NULL){
		hr = calculHauteurEtage(a->root->rgt);
	}
	return (hr+1==hl|hl+1==hr|hr == hr);
}

int parcoursEgal(Node *e1, Node*e2, int n){
	int n_tmp = n;
	if(e1 != NULL &  e1 != NULL){
		if(e1->value != e2->value){
			n_tmp = 0;
		}
		else{
			n_tmp = parcoursEgal(e1->lft, e2->lft, n_tmp);
			n_tmp = parcoursEgal(e1->rgt, e2->rgt, n_tmp);
		}
	}
	else{
		if(e1 != e2){
			n_tmp = 0;
		}
	}
	return n_tmp;

}

int estEgal(Arbre *a1, Arbre *a2){
	return parcoursEgal(a1->root, a2->root, 1);
}

int estvideArbre(Arbre *a){
	return (a->root == NULL);
}

int viderArbre(){
//parcourspostfixe 
}

int equilibrageArbre(Arbre *a){
//parcours case par case de l'arbre de base en ajoutant dans un nouveau qui remplacera l'autre
}

int ajoutArbre(){
//calcul hauteur et nombre de case si arbre equilibre, sinon ajout ajout logique
}

int ajoutLogiqueArbre(){
//calcul en comparant les valeurs des noeufs fils
}

int retirerElementArbre(){
//supprimer le noeud n en ramifiant l'arbre (fd du top devient l'ancien fd du noeud, idem pour gauche)
}

void decodageArbreHuffman(){
//voir cours
}

void encodageHuffman(){
//voir cours
}

void afficherConfigurationsArbre(){
//parcorus de l'arbre en largeur
//inverser fd et fg pour chaque noeud recursivement
//faire un algorithme "afficher arbre jusqu'au noeud x"
//
}


int main(){

}

