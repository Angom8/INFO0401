//Fonction de saisie de la taille d'un tableau : Retourne un int
int saisieTaille(){
	int taille;
	do{
		printf("Rentrez la taille des tableaux\n");
		scanf("%d", &taille);
	}while(taille<1);

	return taille;
}

