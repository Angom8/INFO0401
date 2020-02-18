#include <stdlib.h>
#include <stdio.h>

/*Element de la pile de type int*/
typedef struct Cell Cell;
struct Cell
{
    int value;
    Cell *nxt;
};

/*Liste de taille n, de premier element first et de dernier element last*/
typedef struct Liste Liste;
struct Liste
{
    Cell *first;
    Cell *last
    int size;

};

/*Initialisation d'une pile 
**La liste ne contient aucune case
**La taille est de 0
*/
Liste* creerListe(){	
	Liste * l= malloc(sizeof(Liste));
	l->first = NULL;
	l->last = NULL;
	l->size = 0;
	return l;
}


/*Retourne la n-ième valeur d'une liste. Retourne la dernière valeur si OutOfBounds à la taille. Si inférieur à 0, retourne la taille - la valeur*/
Cell* chercherElementListe(Liste *l, int n){

	int i = 0;
	int j = n;
	Cell* c = l->first;

	if(c != NULL){
		if(j>size){
			return l->last;
		}
		else {
			if(j<0){
				j = (size-n)%size;
			}
			while(i < j){
				c = c->nxt;
				i++;
			}
			return c;
		}
	}
	else{
		return NULL;
	}

}

/*On ajoute la valeur val à la fin de notre liste*/
void ajouterDernierElementListe(Liste *l, int val){	

	Cell *new_c = malloc(sizeof(*new_c));
	Cell *tmp;

    	if (l == NULL || new_c == NULL){
  	}
	else{
		if(p->first != NULL){/*Ajout d'un élément de la pile standard*/

			//On définit la nouvelle case
		    	new_c->value = val;
		    	new_c->nxt = NULL;

			//On redéfinit la dernière case
			tmp = l->last;
			tmp->nxt = new_c;

			//On définit la nouvelle case comme dernière case
		   	l->last = new_c;

			//On augmente la taille
			l->size++;
			
		}
		else{/*Ajout du premier élément de la pile*/
		    	new_c->value = val;
		    	new_c->nxt = NULL;
		   	l->first = new_c;
			l->last = new_c;
			l->size = 1;

		}
	}
	
}

/*On ajoute la valeur val à la place n de notre liste*/
void ajouterElementListe(Liste *l, int val, int n){	

	Cell *new_c = malloc(sizeof(*new_c));
	Cell *tmp;
	int j;

    	if (l == NULL || new_c == NULL){
  	}
	else{
		if(p->first != NULL){/*Ajout d'un élément de la liste standard*/

			if(n<size && n>0){
				//On définit la nouvelle case
			    	new_c->value = val;
			    	new_c->nxt = chercherElementListe(l, n+1);

				//On redéfinit la case n-1
				tmp = chercherElementListe(l, n-1);
				tmp->nxt = new_c;

				//On augmente la taille
				l->size++;
			}
			else{
				if(n>=size){
					ajouterDernierElementListe(l, val);
				}
				else{
					j = (size-n)%size;
					ajouterElementListe(j);
				}
			}
			
		}
		else{/*Ajout du premier élément de la pile*/
		    	new_c->value = val;
		    	new_c->nxt = NULL;
		   	l->first = new_c;
			l->last = new_c;
			l->size = 1;

		}
	}
	
}

/*On retire la dernière cell de notre liste*/
void supprimerDernierElementListe(Liste *l){

	Cell *elem; 

	if (l != NULL){
		if(l->size > 1){
			elem = chercherElementListe(l, size-1); //Retourne l'avant-dernière case
			printf("--%d\n", l->last->value);

			elem->nxt = NULL;//Suppression du dernier élément
			free(l->last);

			size--;//Réduction de la taille

			l->last = elem;//Redéfinition de la dernière case
		}
		else{//La liste ne contient qu'une seule case
			elem = l->first; //Retourne la seule et unique case
			printf("--%d\n", elem->value);
			l->first = NULL;
			l->last = NULL;
			l->size = 0
			free(elem);
		}
	}
	
}

/*On retire la cell n de notre liste*/
void supprimerElementListe(Liste *l, int n){

	Cell *elem1;
	Cell *elem2;
	Cell *elem3;
	int j;

	if (l != NULL){
		if(l->size > 1){
			if(n<size & n > 0){
				elem1 = chercherElementListe(l, n); //Retourne l'élément n
				elem2 = chercherElementListe(l, n-1); //Retourne l'élément n-1
				elem2 = chercherElementListe(l, n+1); //Retourne l'élément n-1
				printf("--%d\n", elem1->value);

				elem2->nxt = elem3; //On saut l'élement n à supprimer

				size--;//Réduction de la taille

				free(elem1);
			}
			else{
				if(n>=size){
					supprimerDernierElementListe(l);
				}
				else{
					j = (size-n)%size;
					supprimerElementListe(j);
				}
			}
		}
		else{//La liste ne contient qu'une seule case : on la supprime donc
			elem = l->first; //Retourne la seule et unique case
			printf("--%d\n", elem->value);
			l->first = NULL;
			l->last = NULL;
			l->size = 0
			free(elem);
		}
	}
	
}

/*On retire la cell contenant la valeur v de notre liste. Retourne 1 si réussite. Retourne 0 si échec*/
int supprimerValeurListe(Liste *l, int v){

	Cell *elem = l->first; 
	int i = 0;
	int retour = 0;

	while(elem != NULL && elem->value != v){
		elem = elem->nxt;
		i++;
	}
	
	if(i<=size){
		supprimerElementListe(l, i);
		retour = 1;
	}
	return retour;
}


/*Affiche le contenu de la liste
*/
void afficherListe(Liste *l){

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
