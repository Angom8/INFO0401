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
void empilerPile(Pile *p, int val){	

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

/*On compare deux piles p1 et p2
**Retour 1 en cas d'égalité, 0 sinon
**On suit le principe d'une pile (on ne peut accéder qu'à la première valeur au sommet), mais avec le formalisme pointeur, on pourrait très bien remonter la pile telle une chaine
*/
int estegalePile(Pile *p1, Pile *p2){

	Pile *ptmp1 = creerPile();
	Pile *ptmp2 = creerPile();
	short int stop = 1;

	while (p1 != NULL && p1->first != NULL && p2 != NULL && p2->first != NULL && stop == 1){
		if(sommet(p1) != sommet(p2)){
			stop = 0;
		}
		else{
			empilerPile(ptmp1, sommet(p1));
			empilerPile(ptmp2, sommet(p2));
			depilerPile(p1);
			depilerPile(p2);
		}
	}

	/*On verifie si la taille est différente*/
	if( (p2->first != NULL)|(p1->first != NULL)){
		stop = 0;
	}

	/*On reempile les piles*/
	while (ptmp1 != NULL && ptmp1->first != NULL && ptmp2 != NULL && ptmp2->first != NULL){
		empilerPile(p1, sommet(ptmp1));
		empilerPile(p2, sommet(ptmp2));
		depilerPile(ptmp1);
		depilerPile(ptmp2);
	}

	free(ptmp1);
	free(ptmp2);
	
	return stop;
	
}

/*Affiche le contenu de la pile
**On suit le principe d'une pile (on ne peut accéder qu'à la première valeur au sommet), mais avec le formalisme pointeur, on pourrait très bien remonter la pile telle une chaine
*/
void afficherPile(Pile *p){

	Pile *ptmp = creerPile();

	printf("La pile : ");

	while (p != NULL && p->first != NULL){
		printf("%d ", sommet(p));
		empilerPile(ptmp, sommet(p));
		depilerPile(p);
	}


	/*On repile la pile*/
	while (ptmp != NULL && ptmp->first != NULL){
		empilerPile(p, sommet(ptmp));
		depilerPile(ptmp);
	}
	printf(" - FIN\n");

	free(ptmp);
	
}

/*Tri dans l'ordre croissant les valeurs d'une pile*/
Pile* trierPile(Pile *p1){

	int min = sommet(p1);

	Pile *p2= creerPile();
	Pile *p3 = creerPile();

	while (p1->first != NULL){

		while(p1 != NULL){
			empilerPile(p2, sommet(p1));
			if(min>sommet(p1)){
				min = sommet(p1);
			}
			depilerPile(p1);
		}

		while(p2 != NULL){
			if(min!=sommet(p2)){
				empilerPile(p1, sommet(p2));
				depilerPile(p2);
			}
			else{
				empilerPile(p3, min);
				depilerPile(p2);
			}	
		}
		min = sommet(p1);		
	}

	while(p3->first != NULL){
		empilerPile(p1, sommet(p3));
		depilerPile(p3);
	}

	free(p2);
	free(p3);
	return p1;
}

/*Test des fonctions ci-dessus*/
int main(){

	Pile *p = creerPile();	

	empilerPile(p, 5);
	empilerPile(p, 10);
	empilerPile(p, 15);
	empilerPile(p, 20);
	
	printf("%d\n", sommet(p));
	
	depilerPile(p);

	printf("%d\n", sommet(p));
	
	printf("Est vide : %d\n", pileEstVide(p));

	viderPile(p);

	printf("Est vide : %d\n", pileEstVide(p));

	return 0;

}