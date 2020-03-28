//Algorithmes de Base
#include "Algo/calcul_max_matrices_binaires.c"
#include "Algo/concatenation_tableau.c"
#include "Algo/conversion_binaire.c"
#include "Algo/est_parfait.c"
#include "Algo/majorite_tableau.c"
#include "Algo/normalisation.c"
#include "Algo/produit_matriciel.c"
#include "Algo/variables_fibonacci.c"
#include "Algo/vecteur_fibonacci.c"

//Algorithmes Pointeur
#include "Algo/chaine_est_palindrome.c"
#include "Algo/copie_chaine.c"
#include "Algo/copie_tableau.c"
#include "Algo/inversion_tableau.c"
#include "Algo/supprimer_occurence.c"

//Algorithmes de Probabilité
#include "Algo/simulation_tennis.c"

//Algorithmes Récursif
#include "Algo/ackerman_recursif.c"
#include "Algo/tri_rapide.c"

//Algorithmes Pile
#include "Algo/pile.c"
#include "Algo/ackerman_pile.c"

//Algorithmes Liste

//Algorithmes Arbre

int main(){
	int typeAlgo;
	int numeroAlgo;
	int numeroAction;
	int val;
	Pile * p;
	
	printf("Choisir un type d'algorithme : \n");
	printf("1.Base \n");
	printf("2.Pointeur \n");
	printf("3.Probabilité \n");
	printf("4.Récursif \n");
	printf("5.Pile \n");
	printf("6.Liste \n");
	printf("7.Arbre \n");
	printf("Autre.Quitter \n");
	scanf("%d", &typeAlgo);
	printf("\n");
	
	switch(typeAlgo){
		case 1:
			printf("Choisir un algorithme de Base : \n");
			printf("1.Normalisation \n");
			printf("2.Maximun de 2 matrices binaires \n");
			printf("3.Produit de 2 matrices \n");
			printf("4.Nombre est Parfait \n");
			printf("5.Concaténer 2 tableaux \n");
			printf("6.Fibonacci avec un Vecteur \n");
			printf("7.Fibonacci avec des Variables \n");
			printf("8.Majorité d'un tableau \n");
			printf("9.Conversion nombre base 10 en Binaire \n");
			printf("Autre.Sortir \n");
			
			scanf("%d", &numeroAlgo);
			printf("\n");
			switch(numeroAlgo){
				case 1:
					normalisation();
					break;
					
				case 2:
					calcul_max_matrices_binaires();
					break;
					
				case 3:
					produit_matriciel();
					break;
					
				case 4:
					est_parfait();
					break;
					
				case 5:
					concatenation_tableau();
					break;
					
				case 6:
					vecteur_fibonacci();
					break;
					
				case 7:
					variables_fibonacci();
					break;
					
				case 8:
					majorite_tableau();
					break;
					
				case 9:
					conversion_binaire();
					break;
				
				default:
					break;
			}
			break;
		
		case 2:
			printf("Choisir un algorithme de Pointeur : \n");
			printf("1.Copier une chaine de caractère \n");
			printf("2.Supprimer une occurence \n");
			printf("3.Inverser les éléments d'un tableau \n");
			printf("4.Vérifier un palindrome \n");
			printf("5.Copier un tableau d'entier \n");
			printf("Autre.Sortir \n");
			
			scanf("%d", &numeroAlgo);
			printf("\n");
			switch(numeroAlgo){
				case 1:
					copie_chaine();
					break;
					
				case 2:
					supprimer_occurence();
					break;
					
				case 3:
					inversion_tableau();
					break;
					
				case 4:
					chaine_est_palindrome();
					break;
					
				case 5:
					copie_tableau();
					break;
				
				default:
					break;
			}
			break;
		
		case 3:
			printf("Choisir un algorithme de Probabilité : \n");
			printf("1.Simulation d'un jeu de tennis \n");
			printf("Autre.Sortir \n");
			
			scanf("%d", &numeroAlgo);
			printf("\n");
			switch(numeroAlgo){
				case 1:
					simulation_tennis();
					break;
				
				default:
					break;
			}
			
			break;
		
		case 4:
			printf("Choisir un algorithme de Récursif : \n");
			printf("1.Ackerman \n");
			printf("2.Tri rapide d'un tableau \n");
			printf("Autre.Sortir \n");
			
			scanf("%d", &numeroAlgo);
			printf("\n");
			switch(numeroAlgo){
				case 1:
					ackerman_recursif();
					break;
					
				case 2:
					tri_rapide();
					break;
				
				default:
					break;
			}
			
			break;
		
		case 5:
			printf("Choisir un algorithme Pile : \n");
			printf("1.Pile \n");
			printf("2.Ackerman \n");
			printf("Autre.Sortir \n");
			
			scanf("%d", &numeroAlgo);
			printf("\n");
			switch(numeroAlgo){
				case 1:
					p = creerPile();
					do{
						printf("\nChoisir une action sur la Pile : \n");
						printf("1.Empiler \n");
						printf("2.Depiler \n");
						printf("3.Sommet \n");
						printf("4.La pile est vide ? \n");
						printf("5.Vider \n");
						printf("6.Afficher la pile \n");
						printf("7.Trier la pile \n");
						printf("Autre.Sortir \n");
					
						scanf("%d", &numeroAction);
						printf("\n");
						switch(numeroAction){
							case 1:
								printf("Choisir la valeur à empiler : \n");
								scanf("%d", &val);
								empilerPile(p, val);
								break;
					
							case 2:
								depilerPile(p);
								break;
						
							case 3:
								printf("Le sommet est : %d \n", sommet(p));
								break;
							
							case 4:
								if(pileEstVide(p)){
									printf("La pile est vide \n");
								}else{
									printf("La pile n'est pas vide \n");
								}
								break;
							
							case 5:
								viderPile(p);
								break;
							
							case 6:
								afficherPile(p);
								break;
							
							case 7:
								trierPile(p);
								break;
				
							default:
								break;
						}
					}while(numeroAction >= 1 && numeroAction <= 7);
					break;
					
				case 2:
					ackerman_pile();
					break;
				
				default:
					break;
			}
			
			break;
		
		case 6:
			printf("Choisir un algorithme de Liste : \n");
			
			printf("Autre.Sortir \n");
			
			break;
		
		case 7:
			printf("Choisir un algorithme d'Arbre : \n");
			
			printf("Autre.Sortir \n");
			
			break;
		
		default:
			printf("Au revoir ! \n");
			break;
	}
	
	exit(0);
}
