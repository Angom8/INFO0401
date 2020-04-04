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

	PileNode *p1 = creerPileNode();
	PileNode *p2 = creerPileNode();
	Node * tmp;
	Node * b = malloc(sizeof(Node));
	b->lft = NULL;
	b->rgt = NULL;
	b->top = NULL;
	b->value = v;
	
	int done = 0;
	if(a->root != NULL){
		//prendre racine
		empilerPileNode(p1, a->root);

		while(done != 1){
			done = 1;
			//depiler et stocker nouveaux fils dans une pile
			while(p1->first != NULL){

				empilerPileNode(p2, sommetNode(p1)->value->lft);
				tmp = sommetNode(p1)->value->lft;

				if(tmp !=  NULL){
					done = 0;
				}
				else{
					sommetNode(p1)->value->lft = b;
					b->top = sommetNode(p1)->value;
					done=1;
					break;
				}

				empilerPileNode(p2, sommetNode(p1)->value->rgt);
				tmp = sommetNode(p1)->value->rgt;

				if(tmp != NULL){
					done = 0;
				}
				else{
					
					sommetNode(p1)->value->rgt = b;
					b->top = sommetNode(p1)->value;
					done=1;
					break;
				}
				depilerPileNode(p1);
			}	
			//répéter tant que pile pas vide au départ (= pas de fils). Stockage des null, donc arret quand un parcours de pile = que des null
			DeplacementPileNode(p1,p2);
			p2->first = NULL;
		}

		viderPileNode(p1);
		viderPileNode(p2);
		free(p1);
		free(p2);
	}
	else{
		a->root = b;
	}
}


int affichageLargeur(Arbre *a){

	PileNode *p1 = creerPileNode();
	PileNode *p2 = creerPileNode();
	Node * tmp;
	int i, sep, H, w, h_tmp, h = calculHauteur(a->root);
	w=0;
	H=h;
	h_tmp=h;
	h++;
	sep = 2*h-1;
	h =h*h;
	//prendre racine
	if(a != NULL && a->root != NULL){
		empilerPileNode(p1, a->root);
		for(i=0;i<(h);i++){printf(" ");}
		printf("%d", a->root->value);
		printf("\n");
		while(p1->first != NULL){
			h_tmp--;
			if(h_tmp < 1){
				w+=1;
			}else{
				w+=H;
			}
			sep-=2;
			for(i=0;i<(h-sep-w);i++){printf(" ");}
			//depiler et stocker nouveaux fils dans une pile
			while(p1->first != NULL){

				tmp = sommetNode(p1)->value->lft;
				for(i=0;i<sep;i++){printf(" ");}
				if(tmp != NULL){
					empilerPileNode(p2, sommetNode(p1)->value->lft);
					printf("%d", sommetNode(p2)->value->value);
				}
				else{
					printf("N");
				}

				tmp = sommetNode(p1)->value->rgt;
				for(i=0;i<sep;i++){printf(" ");}
				if(tmp != NULL){
					empilerPileNode(p2, sommetNode(p1)->value->rgt);
					printf("%d", sommetNode(p2)->value->value);
				}
				else{
					printf("N");
				}

				depilerPileNode(p1);
			}
			printf("\n");
			//répéter tant que pile pas vide au départ (= pas de fils). Stockage des null, donc arret quand un parcours de pile = que des null
			DeplacementPileNode(p1,p2);
			p2->first = NULL;
		}
	}
	printf("\n");

	viderPileNode(p1);
	viderPileNode(p2);
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
	PileNode *p1 = creerPileNode();
	PileNode *p2 = creerPileNode();
	PileNode *p3 = creerPileNode();
	Node * tmp;
	int done = 0;
	empilerPileNode(p3, a->root);

	//prendre racine
	empilerPileNode(p1, a->root);

	while(done != 1){
		done = 1;
		//depiler et stocker nouveaux fils dans une pile
		while(p1->first != NULL){
			empilerPileNode(p2, sommetNode(p1)->value->lft);
			tmp = sommetNode(p1)->value->lft;

			if(tmp != NULL){
				done = 0;
				empilerPileNode(p3, sommetNode(p1)->value->lft);
			}

			empilerPileNode(p2, sommetNode(p1)->value->rgt);
			tmp = sommetNode(p1)->value->rgt;

			if(tmp != NULL){
				done = 0;
				empilerPileNode(p3, sommetNode(p1)->value->rgt);
			}
			depilerPileNode(p1);
		}	
		//répéter tant que pile pas vide au départ (= pas de fils). Stockage des null, donc arret quand un parcours de pile = que des null
		DeplacementPileNode(p1,p2);
		p2->first = NULL;
	}
	vidage(a->root);
	a->root = depilerPileNode(p3);
	
	while(sommetNode(p3) != NULL){
		ajoutLargeur(a, depilerPileNode(p3)->value);
	}

	viderPileNode(p1);
	viderPileNode(p2);
	viderPileNode(p3);
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


int main(){
	int n, i;
	Arbre * a = creerArbre();
	printf("Saisir n : ");
	scanf("%d",&n);
	
	for(i=1;i<n;i++){
		printf("Ajout en largeur v=%d \n",i);
		ajoutLargeur(a, i);
	}
	
	//printf("Ajout logique v=%d \n",i);
	//ajoutLogiqueArbre(a->root,70);
	
	printf("Affichage Prefixe :\n");
	afficherPrefixe(a->root);
	printf("\n");
	
	printf("Affichage Infine :\n");
	afficherInfine(a->root);
	printf("\n");
	
	printf("Affichage Posfixe :\n");
	afficherPostfixe(a->root);
	printf("\n");
	
	printf("Affichage en largeur :\n");
	affichageLargeur(a);
	
	printf("Hauteur = %d\n",calculHauteur(a->root));
}



