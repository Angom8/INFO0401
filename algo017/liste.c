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
    Cell *last;
    int size;

};

/*Initialisation d'une list
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
		if(j>l->size){
			return l->last;
		}
		else {
			if(j<0){
				j = (l->size-n)%l->size;
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
		if(l->first != NULL){/*Ajout d'un élément de la pile standard*/

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
		if(l->first != NULL){/*Ajout d'un élément de la liste standard*/

			if(n<l->size && n>0){
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
				if(n>=l->size){
					ajouterDernierElementListe(l, val);
				}
				else{
					j = (l->size-n)%l->size;
					ajouterElementListe(l,val, j);
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
			elem = chercherElementListe(l, l->size-2); //Retourne l'avant-dernière case
			printf("--%d\n", l->last->value);

			elem->nxt = NULL;//Suppression du dernier élément
			free(l->last);

			l->size--;//Réduction de la taille

			l->last = elem;//Redéfinition de la dernière case
		}
		else{//La liste ne contient qu'une seule case
			elem = l->first; //Retourne la seule et unique case
			printf("--%d\n", elem->value);
			l->first = NULL;
			l->last = NULL;
			l->size = 0;
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
			if(n<l->size & n > 0){
				elem1 = chercherElementListe(l, n); //Retourne l'élément n
				elem2 = chercherElementListe(l, n-1); //Retourne l'élément n-1
				elem3 = elem1->nxt; //Retourne l'élément n+1
				printf("--%d\n", elem1->value);

				elem2->nxt = elem3; //On saute l'élement n à supprimer

				l->size--;//Réduction de la taille

				free(elem1);
			}
			else{
				if(n>=l->size){
					supprimerDernierElementListe(l);
				}
				else{
					if(n == 0){
						elem1 = chercherElementListe(l, 0); //Retourne l'élément n
						elem2 = elem1->nxt; //Retourne l'élément n+1
						printf("--%d\n", elem1->value);
						l->first= elem2;
						l->size--;//Réduction de la taille

						free(elem1);
					}
					else{
						j = (l->size-n)%l->size;
						supprimerElementListe(l, j);
					}
				}
			}
		}
		else{//La liste ne contient qu'une seule case : on la supprime donc
			elem1 = l->first; //Retourne la seule et unique case
			printf("--%d\n", elem1->value);
			l->first = NULL;
			l->last = NULL;
			l->size = 0;
			free(elem1);
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
	
	if(i<l->size){
		supprimerElementListe(l, i);
		retour = 1;
	}
	return retour;
}


/*Affiche le contenu de la liste*/
void afficherListe(Liste *l){

	printf("La liste : ");

	Cell* elem = l->first;

	while(elem != NULL){
		printf("%d ", elem->value);
		elem = elem->nxt;
	}
	
	printf("Taille : %d - FIN\n", l->size);
	
}

/*Retour 0 ou 1 selon si la liste est vide ou non*/
int listeEstVide(Liste *l){
	int i = 1;
	if(l != NULL && l->first != NULL){
		i = 0;
	}
	return i;
}

/*Vide complétement la liste*/
void viderListe(Liste *l){

	while(l->first != NULL){
		supprimerDernierElementListe(l);
	}

}

/*On compare deux listes l1 et l2
**Retour 1 en cas d'égalité, 0 sinon
*/
int estEgaleListe(Liste* l1, Liste* l2){

	Cell* elem1 = l1->first;
	Cell* elem2 = l2->first;
	short int stop = 1;

	/*On verifie si la taille est différente*/
	if(l1->size != l2 ->size){
		stop = 0;
	}

	while (elem1 != NULL && elem2 != NULL && stop == 1){
		if(elem1->value != elem2->value){
			stop = 0;
		}
		else{
			elem1 = elem1->nxt;
			elem2 = elem2->nxt;
		}
	}
	
	return stop;
	
}

/*Tri dans l'ordre croissant les valeurs d'une liste*/
void trierListe(Liste *l){

	int valtmp;
	int stop = 0;
	Cell * elem;

	while(stop == 0){
		elem = l->first;
		stop = 1;
		while(elem->nxt != NULL){
			if(elem->nxt->value < elem->value){
				valtmp = elem->nxt->value;
				elem->nxt->value = elem->value;
				elem->value = valtmp;
				stop = 0;
			}
			elem = elem->nxt;
		}
	}
}

Liste* fusionnerListes(Liste *l1, Liste *l2){

	Liste* l3 = creerListe();
	Cell elem1 = l1->first;
	Cell elem2 = l2->first;

	while(elem1 != NULL || elem2 != NULL){
		
		if(elem1 != NULL){
			if(elem2!=NULL){
				if(elem1->value < elem2->value){
					ajouterDernierElementListe(l3, elem1->value);
					elem1 = elem1->nxt;
				}
				else{
					ajouterDernierElementListe(l3, elem2->value);
					elem2 = elem2->nxt;
				}
			}
			else{
				ajouterDernierElementListe(l3, elem1->value);
				elem1 = elem1->nxt;
			}
		}
		else{
			ajouterDernierElementListe(l3, elem2->value);
			elem2 = elem2->nxt;
		}

	}
}

void extraireChaine(Liste *l, int a, int b){

	Cell elem = l->first;
	int c = 0;

	while(elem != NULL){
		if(c >= a && c <= b){
			printf("%d", elem->value);
		}
		elem = elem->nxt;
		c ++;
	}


}


/*Test des fonctions ci-dessus*/
int main(){

	Liste *l = creerListe();
	Cell *e;	

	ajouterDernierElementListe(l, 5);
	afficherListe(l);
	ajouterDernierElementListe(l, 10);
	afficherListe(l);
	ajouterElementListe(l, 20, 3);

	e = chercherElementListe(l, 10);
	if(e != NULL){printf("Trouvé !\n");}
	e = chercherElementListe(l, 15);
	if(e != NULL){printf("Non Trouvé !\n");}
	
	afficherListe(l);
	printf("%d\n", listeEstVide(l));

	ajouterDernierElementListe(l, 7);
	afficherListe(l);

	supprimerValeurListe(l, 5);
	afficherListe(l);

	trierListe(l);
	afficherListe(l);
	
	supprimerElementListe(l, 1);
	afficherListe(l);

	supprimerDernierElementListe(l);
	afficherListe(l);

	viderListe(l);
	afficherListe(l);

	return 0;

}
