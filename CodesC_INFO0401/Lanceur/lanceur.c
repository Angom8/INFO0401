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
#include "Algo/tri_bulle.c"
#include "Algo/tri_selec.c"

//Algorithmes de Probabilité
#include "Algo/simulation_tennis.c"

//Algorithmes Récursif
#include "Algo/ackerman_recursif.c"
#include "Algo/tri_rapide.c"

//Algorithmes Pile
#include "Algo/pile.c"
#include "Algo/ackerman_pile.c"

//Algorithmes Liste
#include "Algo/liste.c"
#include "Algo/list_binaire.c"

//Algorithmes Arbre
#include "Algo/arbre.c"
#include "Algo/huffman.c"

int main(){
	int typeAlgo;
	int numeroAlgo;
	int numeroAction, numeroEgal;
	int val, tmp, n, i;
	int * tab;
	Pile * p, * p_tmp;
	Liste * l, * l_tmp;
	Arbre * a;
	Cell * c;
	Donnee * d;
	char c_tab[100];
	
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
			printf("6.Tri à bulle \n");
			printf("7.Tri par sélection \n");
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
									
				case 6:
					tri_bulle();
					break;
					
				case 7:
					tri_selec();
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
						printf("6.Afficher \n");
						printf("7.Trier \n");
						printf("8.Egal à une autre pile \n");
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
								printf("La pile a été vidé ! \n");
								break;
							
							case 6:
								afficherPile(p);
								break;
							
							case 7:
								trierPile(p);
								printf("La pile a été trié ! \n");
								afficherPile(p);
								break;
								
							case 8:
								p_tmp = creerPile();
								do{
									printf("\nChoisir une action sur la pile temporaire : \n");
									printf("1.Empiler \n");
									printf("2.Depiler \n");
									printf("3.Afficher \n");
									printf("4.Vérifier si les piles sont égales");
									printf("Autre.Sortir \n");
						
									scanf("%d", &numeroEgal);
									switch(numeroEgal){
										case 1:
											printf("Choisir la valeur à empiler : \n");
											scanf("%d", &val);
											empilerPile(p_tmp, val);
											break;
							
										case 2:
											depilerPile(p_tmp);
											break;
											
										case 3:
											afficherPile(p_tmp);
											break;
											
										case 4:
											if(estegalePile(p, p_tmp)){
												printf("Les piles sont égales ! \n");
											}else{
												printf("Les piles ne sont pas égales ! \n");
											}
											
											viderPile(p_tmp);
											free(p_tmp);
											
											break;
								
										default:
											viderPile(p_tmp);
											free(p_tmp);
											break;
									}
								}while(numeroEgal >= 1 && numeroEgal <=3);
								break;
				
							default:
								break;
						}
					}while(numeroAction >= 1 && numeroAction <= 8);
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
			printf("1.Liste Binaire \n");
			printf("2.Liste \n");
			
			printf("Autre.Sortir \n");
			scanf("%d", &numeroAlgo);
			switch(numeroAlgo){
				case 1:
					printf("Saisir le nombre à convertir : \n");
					scanf("%d", &val);
					tab = conversion(val);
					tmp = val;
					for(i=0;tmp > 0;i++){
						tmp -= pow(2,i);
					}
					n = i;
					l = constructionListB(tab, n);
					do{
						printf("\nChoisir une action sur la liste binaire : \n");
						printf("1.Incrementer de 1 \n");
						printf("2.Incrementer de n \n");
						printf("3.Afficher la liste\n");
						printf("Autre.Sortir \n");
						
						scanf("%d", &numeroAction);
						switch(numeroAction){
							case 1:
								incrementationListeB(l);
								break;
								
							case 2:
								printf("Saisir n :\n");
								scanf("%d", &n);
								for(i=0;i<n;i++){
									incrementationListeB(l);
								}
								break;
							
							case 3:
								afficherListe(l);
								break;
								
							default:
								break;
						}
					}while(numeroAction >= 1 && numeroAction <=3);
					
					break;
					
				case 2:
					l = creerListe();
					do{
						printf("\nChoisir une action sur la liste : \n");
						printf("1.Ajouter un element en fin de liste \n");
						printf("2.Chercher le nième element \n");
						printf("3.Ajouter un element à la place n \n");
						printf("4.Supprimer le dernier element \n");
						printf("5.Supprimer l'element nième \n");
						printf("6.Supprimer la valeur v \n");
						printf("7.Afficher \n");
						printf("8.La liste est vide ? \n");
						printf("9.Vider \n");
						printf("10.Trier \n");
						printf("11.Extraire une partie \n");
						printf("12.Egale à une autre liste \n");
						printf("Autre.Sortir \n");
						
						scanf("%d", &numeroAction);
						switch(numeroAction){
							case 1:
								printf("Saisir la valeur : \n");
								scanf("%d", &val);
								ajouterDernierElementListe(l, val);
								break;
							
							case 2:
								printf("Saisir l'element nième à rechercher : \n");
								scanf("%d", &n);
								c = chercherElementListe(l, n);
								printf("element numero %d = %d", n, c->value);
								break;
								
							case 3:
								printf("Saisir la valeur : \n");
								scanf("%d", &val);
								printf("Saisir la place n : \n");
								scanf("%d", &n);
								ajouterElementListe(l, val, n);
								break;
								
							case 4:
								supprimerDernierElementListe(l);
								break;
								
							case 5:
								printf("Saisir l'element nième à supprimer : \n");
								scanf("%d", &n);
								supprimerElementListe(l, n);
								break;
								
							case 6:
								printf("Saisir la valeur v : \n");
								scanf("%d", &n);
								supprimerValeurListe(l, n);
								break;
								
							case 7:
								afficherListe(l);
								break;
								
							case 8:
								if(listeEstVide(l)){
									printf("La liste est vide ! \n");
								}else{
									printf("La liste n'est pas vide ! \n");
								}
								break;
								
							case 9:
								viderListe(l);
								printf("La liste a été vié ! \n");
								break;
								
							case 10:
								trierListe(l);
								printf("La liste a été trié ! \n");
								afficherListe(l);
								break;
								
							case 11:
								printf("Saisir a : \n");
								scanf("%d", &val);
								printf("Saisir b : \n");
								scanf("%d", &n);
								extraireChaine(l, val, n);
								break;
								
							case 12:
								l_tmp = creerListe();
								do{
									printf("\nChoisir une action sur la liste temporaire : \n");
									printf("1.Ajouter un element en fin de liste \n");
									printf("2.Supprimer le dernier element \n");
									printf("3.Afficher \n");
									printf("4.Vérifier si les listes sont égales");
									printf("Autre.Sortir \n");
						
									scanf("%d", &numeroEgal);
									switch(numeroEgal){
										case 1:
											printf("Saisir la valeur : \n");
											scanf("%d", &val);
											ajouterDernierElementListe(l_tmp, val);
											break;
							
										case 2:
											supprimerDernierElementListe(l_tmp);
											break;
											
										case 3:
											afficherListe(l_tmp);
											break;
											
										case 4:
											if(estEgaleListe(l, l_tmp)){
												printf("Les listes sont égales ! \n");
											}else{
												printf("Les listes ne sont pas égales ! \n");
											}
											
											viderListe(l_tmp);
											free(l_tmp);
											
											break;
								
										default:
											viderListe(l_tmp);
											free(l_tmp);
											break;
									}
								}while(numeroEgal >= 1 && numeroEgal <=3);
								break;
								
							default:
								break;
						}
					}while(numeroAction >= 1 && numeroAction <=12);
					
					break;
				
				default:
					break;
			}
			
			break;
		
		case 7:
			printf("Choisir un algorithme d'Arbre : \n");
			printf("1.Huffman \n");
			printf("2.Arbre \n");
			printf("Autre.Sortir \n");
			
			scanf("%d", &numeroAlgo);
			printf("\n");
			switch(numeroAlgo){
				case 1:
					d = malloc(sizeof(Donnee) * 5);
					do{
						d[0].symbol = 'C';
						d[0].poids = 1;
						d[1].symbol = 'A';
						d[1].poids = 2;
						d[2].symbol = 'Z';
						d[2].poids = 3;
						d[3].symbol = 'E';
						d[3].poids = 4;
						d[4].symbol = 'T';
						d[4].poids = 5;
						
						printf("\nChoisir une action huffman : \n");
						printf("1.Decoder \n");
						printf("2.Encoder \n");
						printf("Autre.Sortir \n");
						
						scanf("%d", &numeroAction);
						switch(numeroAction){
							case 1:
								printf("Saisir une chaine de '1' et '0' à decoder (max 100) : \n");
								scanf("%s", c_tab);
								for(i=0;c_tab[i] != '\0';i++){}
								n=i;
								decodage(d, c_tab, n, 5);
								break;
								
							case 2:
								printf("Saisir une chaine de 'C','A','Z','E' et 'T' à encoder (max 100) : \n");
								scanf("%s", c_tab);
								for(i=0;c_tab[i] != '\0';i++){}
								n=i;
								encodage(d, c_tab, n, 5);
								break;
								
							default:
								break;
						}
					}while(numeroAction >= 1 && numeroAction <=2);
					break;
					
				case 2:
					a = creerArbre();
					do{
						printf("\nChoisir une action sur l'arbre : \n");
						printf("1.Ajouter un element en largeur \n");
						printf("2.Afficher en largeur \n");
						printf("3.Afficher Prefixe \n");
						printf("4.Afficher Infine \n");
						printf("5.Afficher Postfixe \n");
						printf("6.Calculer la hauteur \n");
						printf("7.Est équilibré ? \n");
						printf("8.Est Vide ? \n");
						printf("9.Vider \n");
						printf("10.Ajouter un element logiquement \n");
						printf("11.Ajouter un element trier \n");
						printf("12.Equilibrer l'arbre \n");
						printf("Autre.Sortir \n");
						
						scanf("%d", &numeroAction);
						switch(numeroAction){
							case 1:
								printf("Saisir la valeur : \n");
								scanf("%d", &val);
								ajoutLargeur(a, val);
								break;
								
							case 2:
								printf("Affichage en largeur : \n");
								affichageLargeur(a);
								break;
								
							case 3:
								printf("Affichage Prefixe : \n");
								afficherPrefixe(a->root);
								printf("\n");
								break;
								
							case 4:
								printf("Affichage Infine : \n");
								afficherInfine(a->root);
								printf("\n");
								break;
							
							case 5:
								printf("Affichage Postfixe : \n");
								afficherPostfixe(a->root);
								printf("\n");
								break;
								
							case 6:
								printf("La hauteur : %d \n",calculHauteur(a->root));
								break;
								
							case 7:
								if(estEquilibre(a)){
									printf("L'arbre est équilibré ! \n");
								}else{
									printf("L'arbre n'est pas équilibré ! \n");
								}
								break;
								
							case 8:
								if(estvideArbre(a)){
									printf("L'arbre est vide ! \n");
								}else{
									printf("L'arbre n'est pas vide ! \n");
								}
								break;
								
							case 9:
								viderArbre(a);
								printf("L'arbre à été vidé ! \n");
								break;
								
							case 10:
								affichageLargeur(a);
								break;
								
							case 11:
								printf("Saisir la valeur : \n");
								scanf("%d", &val);
								ajouterTriElement(val, a->root);
								break;
								
							case 12:
								equilibrageArbre(a);
								break;
								
							default:
								break;
						}
					}while(numeroAction >= 1 && numeroAction <=13);
					
					break;
				
				default:
					break;
			}
			
			break;
		
		default:
			printf("Au revoir ! \n");
			break;
	}
	
	exit(0);
}
