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
		//printf("--%d\n", elem->value);
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
**On suit le principe d'une pile (on ne peut accéder qu'à la première valeur au sommet), 
**mais avec le formalisme pointeur, on pourrait très bien remonter la pile telle une chaine
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
	
	/*Nettoyage de la mémoire*/
	free(ptmp1);
	free(ptmp2);
	
	return stop;
	
}

/*Affiche le contenu de la pile
**On suit le principe d'une pile (on ne peut accéder qu'à la première valeur au sommet),
**mais avec le formalisme pointeur, on pourrait très bien remonter la pile telle une chaine
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
	printf("- FIN\n");
	
	/*Nettoyage de la mémoire*/
	free(ptmp);
}

/*Tri dans l'ordre croissant les valeurs d'une pile*/
void trierPile(Pile * p){
	/*Declarations*/
	int min;
	Pile * tmp1 = creerPile();
	Pile * tmp2 = creerPile();
	
	while(p->first != NULL){
		min = sommet(p);
		while(p->first != NULL){
			if(sommet(p) < min){
				min = sommet(p);
			}
			empilerPile(tmp1, sommet(p));
			depilerPile(p);
		}
		
		while(tmp1->first != NULL){
			if(sommet(tmp1) != min){
				empilerPile(p, sommet(tmp1));
			}
			depilerPile(tmp1);
		}
		
		empilerPile(tmp2, min);
	}
	
	while(tmp2->first != NULL){
		empilerPile(p, sommet(tmp2));
		depilerPile(tmp2);
	}
	
	/*Nettoyage de la mémoire*/
	free(tmp1);
	free(tmp2);
}

int compterOccurence(Pile *p, int x){} //Pile p intacte !
