#include <stdlib.h>
#include <stdio.h>
#include <math.h>

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

/*Demande à l'utilisateur de sasir*/
int saisirNb(){
	int nb;
	
	do{
		printf("Sasir un nombre en base 10 :");
		scanf("%d", &nb);
	}while(nb < 0);
	
	return nb;
}

/*Convertie un nombre base 10 en base 2*/
int * conversion(int nb){
	//Declarations
	int i, tmp;
	int * v;
	
	//Calcul de la taille du tableau
	tmp = nb;
	for(i=0;tmp > 0;i++){
		tmp -= pow(2,i);
	}
	n = i;
	
	//Initialisation du tableau v
	v = (int *)malloc(sizeof(int)*n);
	
	//Calcul du nombre binaire
	for(i=n-1;i>=0;i--){
		if(nb%2 == 0){
			v[i] = 0;
		}else{
			v[i] = 1;
		}
		
		nb /= 2;
	}
	
	//Affichage du tableau v
	printf("v : ");
	for(i=0;i<n;i++){
		printf("%d ", v[i]);
	}
	printf("\n");
	
	return v;
}

/*Contruit une liste à partir d'un tableau d'entiers*/
Liste * constructionListB(int * v, int n){
	int i;
	Liste * l = creerListe();
	
	for(i=0;i<n;i++){
		ajouterDernierElementListe(l, v[i]);
	}
	
	afficherListe(l);
	
	return l;
}

/*Incremente de 1 une liste binaire*/
void incrementationListeB(Liste * l){
	int counter; 
	Cell * c;
	if(l != NULL && l->first != NULL){
		counter = l->size-2;
		c = l->last;
		while(c != NULL && counter >= 0 && c->value != 0){
			c->value = 0;
			c = chercherElementListe(l,counter);
			counter--;
		}
	
		if(c != NULL && counter >= 0){
			c->value = 1;
		}else{
			ajouterDernierElementListe(l, 0);
		}
	}
	afficherListe(l);
}

int main(){
	int n, nb, tmp, i;
	int * T;
	Liste * L;
	
	nb = saisirNb();
	
	tmp = nb;
	for(i=0;tmp > 0;i++){
		tmp -= pow(2,i);
	}
	n = i;
	
	T = conversion(nb);
	L = constructionListB(T,n);
	
	
	incrementationListeB(L);
	
	afficherListe(L);
	
	incrementationListeB(L);
	
	afficherListe(L);
	
	return 0;
}
