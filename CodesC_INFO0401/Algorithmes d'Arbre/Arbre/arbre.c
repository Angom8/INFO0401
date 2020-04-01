#include <stdlib.h>
#include <stdio.h>
#include "pile.h"

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
			htmp1 = htmp2;
		}
	}
	return htmp1;
}

int calculHauteur(Node * e){
	int h = 0;
	if(e != NULL){
		h = parcoursHauteur(e, 0);
	}
	return h;

}

int estEquilibre(Arbre *a){
	int hl = 0;
	int hr = 0;

	if(a->root->lft != NULL){
		hl = calculHauteur(a->root->lft);
	}
	if(a->root->rgt != NULL){
		hr = calculHauteur(a->root->rgt);
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

int parcoursLargeur(Arbre *a){

	int done = 0;
	Pile *p1 = creerPile();
	Pile *p2 = creerPile();
	Node * tmp;

	//prendre racine
	empilerPile(p1, a->root);

	while(done != 1){
		done = 1;
		//depiler et stocker nouveaux fils dans une pile
		while(p1->first != NULL){

			empilerPile(p2, sommet(p1)->value->lft);
			tmp = sommet(p1)->value->lft;

			if(tmp != NULL){
				done =0;
				printf("%d", sommet(p2)->value->value);
			}
			else{
				printf("[]");
			}

			empilerPile(p2, sommet(p1)->value->rgt);
			tmp = sommet(p1)->value->rgt;

			if(tmp != NULL){
				done = 0;
				printf("%d", sommet(p2)->value->value);
			}
			else{
				printf("[]");
			}
			depilerPile(p1);
		}	
		//répéter tant que pile pas vide au départ (= pas de fils). Stockage des null, donc arret quand un parcours de pile = que des null
		p1 = p2;
		viderPile(p2);
	}
}

int estvideArbre(Arbre *a){
	return (a->root == NULL);
}


void vidage(Node *e){
	if(e != NULL){
		vidage(e->lft);
		vidage(e->rgt);
		e->lft = NULL;
		e->rgt = NULL;
		e->top = NULL;
		free(e);
	}
}
void viderArbre(Arbre *a){
	if(a != NULL){
		vidage(a->root);
	}
	a->root = NULL;
	a->size = 0;
}

int ajoutLogiqueArbre(Node *elem, int v){

	if(elem->lft == NULL){
		Node *new_elem = malloc(sizeof(Node));
		new_elem->value = v;
		new_elem->top = elem;
		elem->lft = new_elem;
	}
	else{
		if(elem->rgt == NULL){
			Node *new_elem = malloc(sizeof(Node));
			new_elem->value = v;
			new_elem->top = elem;
			elem->lft = new_elem;
		}	
		else{
			if(elem->lft-> value >= elem->rgt->value){
				 ajoutLogiqueArbre(elem->lft, v);
			}
			else{
				 ajoutLogiqueArbre(elem->rgt, v);
			}

		}
	}
}


int ajoutLargeur(Arbre *a, int v){

	Pile *p1 = creerPile();
	Pile *p2 = creerPile();
	Node * tmp;
	Node * b = malloc(sizeof(Node));
	b->lft = NULL;
	b->rgt = NULL;
	b->top = NULL;
	b->value = v;
	
	int done = 0;
	if(a->root != NULL){
		//prendre racine
		empilerPile(p1, a->root);

		while(done != 1){
			done = 1;
			//depiler et stocker nouveaux fils dans une pile
			while(p1->first != NULL){

				empilerPile(p2, sommet(p1)->value->lft);
				tmp = sommet(p1)->value->lft;

				if(tmp !=  NULL){
					done = 0;
				}
				else{
					sommet(p1)->value->lft = b;
					b->top = sommet(p1)->value;
					done=1;
					break;
				}

				empilerPile(p2, sommet(p1)->value->rgt);
				tmp = sommet(p1)->value->rgt;

				if(tmp != NULL){
					done = 0;
				}
				else{
					
					sommet(p1)->value->rgt = b;
					b->top = sommet(p1)->value;
					done=1;
					break;
				}
				depilerPile(p1);
			}	
			//répéter tant que pile pas vide au départ (= pas de fils). Stockage des null, donc arret quand un parcours de pile = que des null
			DeplacementPile(p1,p2);
			p2->first = NULL;
		}

		viderPile(p1);
		viderPile(p2);
		free(p1);
		free(p2);
	}
	else{
		a->root = b;
	}
}


int affichageLargeur(Arbre *a){

	Pile *p1 = creerPile();
	Pile *p2 = creerPile();
	Node * tmp;
	int i, h = calculHauteur(a->root);
	h++;

	//prendre racine
	if(a != NULL && a->root != NULL){
		empilerPile(p1, a->root);
		for(i=0;i<(3*h+4);i++){printf("_");}
		printf("%d", a->root->value);
		printf("\n");
		while(p1->first != NULL){
			h--;
			for(i=0;i<(h);i++){printf("___");}
			//depiler et stocker nouveaux fils dans une pile
			while(p1->first != NULL){

				tmp = sommet(p1)->value->lft;

				if(tmp != NULL){
					empilerPile(p2, sommet(p1)->value->lft);
					for(i=0;i<h;i++){printf("_");}
					printf("%d", sommet(p2)->value->value);
				}
				else{
					printf("_[]");
				}

				tmp = sommet(p1)->value->rgt;

				if(tmp != NULL){
					empilerPile(p2, sommet(p1)->value->rgt);
					for(i=0;i<(h);i++){printf("_");}
					printf("%d", sommet(p2)->value->value);
				}
				else{
					printf("_[]");
				}

				depilerPile(p1);
			}
			printf("\n");
			//répéter tant que pile pas vide au départ (= pas de fils). Stockage des null, donc arret quand un parcours de pile = que des null
			DeplacementPile(p1,p2);
			p2->first = NULL;
		}
	}
	printf("\n");

	viderPile(p1);
	viderPile(p2);
	free(p1);
	free(p2);
}



void ajouterTriElement(int n, Node* c){

	int ecart1, ecart2, tmp;
	Node* b = malloc(sizeof(Node));
	b->value = n;
	if(c->lft == NULL){
		c->lft = b;
		b->top = c;
	}
	else if(c->rgt == NULL){
		c->rgt = b;
		b->top = c;//puis inversion si valeur plus petit qu'à gauche

		if(c->rgt->value < c->lft->value){
			tmp = c->rgt->value;
			c->rgt->value = c->lft->value;
			c->lft->value = tmp;
		}
	}
	else {
		if(c->lft->value < n){
			ajouterTriElement(n, c->lft);//ajout recursif à gauche
		}

		else if(c->rgt->value < n){
			ajouterTriElement(n, c->rgt);//ajout recursif à droite, 

		}
		else{
			ecart1 = n-c->lft->value;
			ecart2 = n-c->rgt->value;
			
			if(ecart1>ecart2){//ajout récursif à droite avec inversion de la valeur à insérer
				tmp = c->rgt->value;
				c->rgt->value = n;
				ajouterTriElement(tmp, c->rgt);
				
			}
			else{
				//ajout récursif à gauche avec inversion de la valeur à insérer
				tmp = c->lft->value;
				c->lft->value = n;
				ajouterTriElement(tmp, c->lft);
			}
		}
	}

}

int triTableauViaArbre(int *T, int n){
	Arbre *a = malloc(sizeof(Arbre));
	for(int i=0;i<n;i++){
		if(a->root == NULL){
			Node* b = malloc(sizeof(Node));
			a->root = b;
		}
		else{
			ajouterTriElement(T[i], a->root);
		}
	}
	afficher(a, 'f');
}


int equilibrageArbre(Arbre *a){
//parcours case par case de l'arbre de base en ajoutant dans un nouveau qui remplacera l'autre
	Pile *p1 = creerPile();
	Pile *p2 = creerPile();
	Pile *p3 = creerPile();
	Node * tmp;
	int done = 0;
	empilerPile(p3, a->root);

	//prendre racine
	empilerPile(p1, a->root);

	while(done != 1){
		done = 1;
		//depiler et stocker nouveaux fils dans une pile
		while(p1->first != NULL){
			empilerPile(p2, sommet(p1)->value->lft);
			tmp = sommet(p1)->value->lft;

			if(tmp != NULL){
				done = 0;
				empilerPile(p3, sommet(p1)->value->lft);
			}

			empilerPile(p2, sommet(p1)->value->rgt);
			tmp = sommet(p1)->value->rgt;

			if(tmp != NULL){
				done = 0;
				empilerPile(p3, sommet(p1)->value->rgt);
			}
			depilerPile(p1);
		}	
		//répéter tant que pile pas vide au départ (= pas de fils). Stockage des null, donc arret quand un parcours de pile = que des null
		p1 = p2;
		viderPile(p2);
	}
	vidage(a->root);
	a->root = depilerPile(p3);
	
	while(sommet(p3) != NULL){
		ajoutLargeur(a, depilerPile(p3)->value);
	}

	viderPile(p1);
	viderPile(p2);
	viderPile(p3);
	free(p1);
	free(p2);
	free(p3);
}


void couperBrancheArbre(Arbre *a, Node *c){
//supprimer le noeud n en ramifiant l'arbre (coupage de branche)
	Node * b = c->top;
	if(c == b->lft){
		b->lft = NULL;	
	}
	else{
		b->rgt = NULL;
	}
	vidage(c);
}

void afficherConfigurationsArbre(){
//parcorus de l'arbre en largeur
//inverser fd et fg pour chaque noeud recursivement
//faire un algorithme "afficher arbre jusqu'au noeud x"
//
}


int main(){
	int val, i;
	Arbre * a = creerArbre();
	
	for(i=1;i<15;i++){
		ajoutLargeur(a, i);
	}
	
	afficherPrefixe(a->root);
	printf("\n");
	
	printf("%d\n", a->root->value);
	printf("%d\n", a->root->lft->value);
	printf("%d\n", a->root->rgt->value);
	printf("%d\n", a->root->lft->lft->value);
	printf("%d\n", a->root->lft->rgt->value);
	
	affichageLargeur(a);
	
	printf("Hauteur = %d\n",calculHauteur(a->root));
}



