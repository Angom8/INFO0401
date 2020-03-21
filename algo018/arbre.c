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

int estEquilibre(Arbre *a){
	int hl = 0;
	int hr = 0;

	if(a->root->lft != NULL){
		hl = calculHauteur(a->root->lft, 0);
	}
	if(a->root->rgt != NULL){
		hr = calculHauteur(a->root->rgt, 0);
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

	int done = 1;
	Pile *p1 = creerPile();
	Pile *p2 = creerPile();
	Node * tmp;

	//prendre racine
	empilerPile(p1, a->root);

	while(done != 0){
		//depiler et stocker nouveaux fils dans une pile
		while(p1->first != NULL){

			if((tmp = empiler(p2, sommet(p1)->value->lft) != NULL){
				done =0;
				printf("%d", sommet(p2)->value->value);
			}
			else{
				printf("[]");
			}
			if((tmp = empiler(p2, sommet(p1)->value->rgt) != NULL){
				done = 0;
				printf("%d", sommet(p2)->value->value);
			}
			else{
				printf("[]");
			}
			depilerPiler(p1);
		}	
		//répéter tant que pile pas vide au départ (= pas de fils). Stockage des null, donc arret quand un parcours de pile = que des null
		p1 = p2;
		viderPile(p2);
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
	Node * b;
	b->value = v;
	
	done = 0;

	//prendre racine
	empilerPile(p1, a->root);

	while(done != 1){
		done = 1;
		//depiler et stocker nouveaux fils dans une pile
		while(p1->first != NULL){

			if((tmp= empilerPile(p2, sommet(p1)->value->lft) != NULL){
				done = 0;
			}
			else{
				sommet(p1)->value->lft = b;
				b->top = sommet(p1)->value;
			}
			if(empilerPile(p2, sommet(p1)->value->rgt != NULL){
				done = 0;
			}
			else{
				if((sommet(p1)->value->lft) != NULL){
					sommet(p1)->value->rgt = b;
					b->top = sommet(p1)->value;
				}
			}
			depilerPiler(p1);
		}	
		//répéter tant que pile pas vide au départ (= pas de fils). Stockage des null, donc arret quand un parcours de pile = que des null
		p1 = p2;
		viderPile(p2);
	}

	viderPile(p1);
	viderPile(p2);
	free(p1);
	free(p2);
}


int affichageLargeur(Arbre *a){

	Pile *p1 = creerPile();
	Pile *p2 = creerPile();
	Node * tmp;
	done = 0;

	//prendre racine
	empilerPile(p1, a->root);

	while(done != 1){
		done = 1;
		//depiler et stocker nouveaux fils dans une pile
		while(p1->first != NULL){

			if(empilerPile(p2, sommet(p1)->value->lft != NULL){
				done = 0;
				printf("%d", sommet(p2)->value->value);
			}
			else{
				printf("[]");
			}
			if(empilerPile(p2, sommet(p1)->value->rgt != NULL){
				done = 0;
				printf("%d", sommet(p2)->value->value);
			}
			else{
				printf("[]");
			}
			depilerPiler(p1);
		}	
		//répéter tant que pile pas vide au départ (= pas de fils). Stockage des null, donc arret quand un parcours de pile = que des null
		p1 = p2;
		viderPile(p2);
	}

	viderPile(p1);
	viderPile(p2);
	free(p1);
	free(p2);
}

int ajoutArbre(Arbre *a, int v, int a){
//calcul hauteur et nombre de case si arbre equilibre, sinon ajout ajout logique
	int h = calculHauteur(a);
	int z = 2;

	
	if(estEquilibre(a) != 1){
		if(a->size > 0){
			while(h>1){
				z*=2;
				h-=1; 
			}
			ajoutLargeur(*a, v);
		}
		else{
			Node* elem = malloc(sizeof(Node));
			elem->value = v;
			a->root = elem;
		}
		
	}
	else{
		ajoutLogiqueArbre(a->root, int v);
	}

}

/*----------------------------------------- HUFFMAN ---------------------------------------*/

/*Recherche la priorité maximale dans la table de priorité. 
**Retourne le symbole correspondant et place le symbole à la fin. 
**Il ne sera plus visité (n est diminué de 1 au prochain appel*/
char rechercherMax(Donnee *p, int n){

	int i = 0;
	int imax = 0;
	Donnee tmp;

	//n est réduit n à chaque appel
	while(i < n){
		//On stocke l'indice où la valeur est maximale.
		if(p[i].poids >= p[imax].poids){
			imax = i;
		}
		i++;
	}
	
	//On échange les valeurs entre la case où la priorité est maximale et la dernière case.
	tmp = p[imax];
	p[imax] = p[n];
	p[n] = tmp;

	return tmp.symbol;//On retourne le symbole
}

/*Transforme un tableau de priorité en un arbre d'Huffman
**On crée l'arbre à partir du haut, donc on recherche la priorité maximale, on place son symbole sur le fils droit, puis on place notre pointeur de parcours sur le fils gauche
**Si on est à la fin de la table, on place directement sur le dernier fils gauche*/
Arbre * transformerPrio(Donnee *p, int n){

	Arbre *a = malloc(sizeof(Arbre));
	Node* b, *d;
	int nn = n;//On ne peut pas modifier directement des paramètres de fonction
	char c;

	a->root = malloc(sizeof(Node));
	d = a->root;//On commence au sommet de l'arbre

	while(nn != 0){

		c = rechercherMax(p, nn);
		nn = nn - 1;//A chaque parcours du tableau, on réduit de 1 (la valeur à la case n a été traitée)

		b = malloc(sizeof(Node));

		b->value = c;
		d->rgt = b;

		if(nn != 0){//On est à la fin de la création de l'arbre, on place donc le dernier symbole dans le dernier fils gauche.
			d->lft = malloc(sizeof(Node));
			d = d->lft;
		}
		else{
			d->value = c;
		}
	}
	
	return a;//On retourne l'Arbre d'Huffman

}

/*Decode une chaine de caractères de longueur n*/
void decodageHuffman(Donnee * p, char * s, int n, int nn){
	int i = 0;

	/*Transformer prio retourne l'arbre d'Huffman à partir de la table de priorités*/
	Arbre* a = transformerPrio(p, nn);

	Node *b = a->root;

	

	/*On parcourt la chaine de caractère en caractère.*/
	for(i=0;i<n;i++){
		if(s[i] == '1'){
			printf("%c", b->rgt->value);
			b = a->root;
		}
		else{//Si on n'a pas 1, on passe au caractère suivant dans l'arbre de priorité d'Huffman
			if(b->lft == NULL){
				printf("%c", b->value);
				b = a->root;			
			}
			else{
				b = b->lft;
			}
		}
	}
	printf("\n");

}


/*Decode une chaine de caractères de longueur n*/
void encodageHuffman(Donnee * p, char * s, int n, int nn){
	int i;

	/*Transformer prio retourner l'arbre d'Huffman à partir de la table de priorités*/
	Arbre* a = transformerPrio(p, nn);

	Node *b = a->root;
	int j = 0;

	for(i=0;i<n;i++){
		//On regarde le fis de gauche. S'il est nul, on est arrivé tout en bas à gauche de l'arbre, donc au dernier symbole. Si on a la valeur sur le fils droit, on est arrivé au bon caractère
		//j permet de compter le nombre de zéros à insérer
		while(b->lft != NULL && b->rgt->value != s[i]){
			b = b->lft;
			j++;
			
		}
		if(b->lft == NULL){//On n'affiche que des 0
			while(j != 0){
				printf("0");	
				j--;
			}
			
		}
		else{//On affiche 1 zéro par j et le 1 une fois tous les 0 insérés
			while(j != 0){
				printf("0");	
				j--;
			}
			printf("1");
		}
		b = a->root;
		j = 0;
	}
	printf("\n");
}
/*----------------------------------------- FIN HUFFMAN ---------------------------------------*/

void ajouterElementTri(int n, Node* c){

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

		else if(rgt < n){
			ajouterTriElement(n, c->rgt);//ajout recursif à droite, 

		}
		else{
			ecart1 = n-c->lft->value;
			ecart2 = n-c->rgt->value;
			
			if(ecart1>ecart2){//ajout récursif à droite avec inversion de la valeur à insérer
				tmp = c->rgt->value;
				c->rgt->value = n;
				ajouterTriElement(tmp, c->rgt)
				
			}
			else{
				//ajout récursif à gauche avec inversion de la valeur à insérer
				tmp = c->lft->value;
				c->lft->value = n;
				ajouterTriElement(tmp, c->lft)
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
			ajouterElementTri(T[i], a->root);
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
	done = 0;
	empilerPile(p3, a->root);

	//prendre racine
	empilerPile(p1, a->root);

	while(done != 1){
		done = 1;
		//depiler et stocker nouveaux fils dans une pile
		while(p1->first != NULL){
			if(empilerPile(p2, sommet(p1)->value->lft != NULL){
				done = 0;
				empilerPile(p3, sommet(p1)->value->lft);
			}
			if(empilerPile(p2, sommet(p1)->value->rgt != NULL){
				done = 0;
				empilerPile(p3, sommet(p1)->value->rgt);
			}
			depilerPiler(p1);
		}	
		//répéter tant que pile pas vide au départ (= pas de fils). Stockage des null, donc arret quand un parcours de pile = que des null
		p1 = p2;
		viderPile(p2);
	}
	vidage(a->root);
	a->root = depilerPile(p3);
	
	while(sommet(p3) != NULL){
		ajoutLargeur(a, depilerPile(p3)->value->value);
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

}

