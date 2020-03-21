#include <stdio.h>
#include <stdlib.h>

/*Element de l'arbre de type char*/
typedef struct Node Node;
struct Node
{
    char value;
    Node *lft, *rgt, *top;
};

/*Liste de taille n, de premier element root*/
typedef struct Arbre Arbre;
struct Arbre
{
    Node *root;
    int size;

};

/*Un element pour définir une priorité dans l'arbre d'Huffman*/
typedef struct Donnee Donnee;
struct Donnee
{
	char symbol;
	int poids;
};

/*Fonctions d'affichage d'un arbre (utilisée pour vérifier l'arbre durant le développement)*/
void afficherPrefixe(Node *e){
	if(e != NULL){
		printf("%c", e->value);
		afficherPrefixe(e->lft);
		afficherPrefixe(e->rgt);
	}
}

void afficherInfine(Node *e){
	if(e != NULL){
		afficherInfine(e->lft);
		printf("%c", e->value);
		afficherInfine(e->rgt);
	}
}

void afficherPostfixe(Node *e){
	if(e != NULL){
		afficherPostfixe(e->lft);
		afficherPostfixe(e->rgt);
		printf("%c", e->value);
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
	printf("\n");

}

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
void decodage(Donnee * p, char * s, int n, int nn){
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
void encodage(Donnee * p, char * s, int n, int nn){
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


int main(){

	int t, ts;
	Donnee *p;
	char * s,* s2;

	t = 5;
	p = malloc(sizeof(Donnee) * t);
	p[0].symbol = 'C';
	p[0].poids = 1;
	p[1].symbol = 'A';
	p[1].poids = 2;
	p[2].symbol = 'Z';
	p[2].poids = 3;
	p[3].symbol = 'E';
	p[3].poids = 4;
	p[4].symbol = 'T';
	p[4].poids = 5;

	s = "0010110001011";

	//ts correspond à la taille de la chaine de caractère
	ts = 13;
	decodage(p, s, ts, t);

	//Il est important de réinitialiser le tableau, celui-ci étant modifié

	p[0].symbol = 'C';
	p[0].poids = 1;
	p[1].symbol = 'A';
	p[1].poids = 2;
	p[2].symbol = 'Z';
	p[2].poids = 3;
	p[3].symbol = 'E';
	p[3].poids = 4;
	p[4].symbol = 'T';
	p[4].poids = 5;

	s2 = "ZETAEC";

	//ts correspond à la taille de la chaine de caractère
	ts = 6;
	encodage(p, s2, ts, t);
	
}
