#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	//Declaration
	int score1, score2, avantage;
	float p;
	
	//Lecture de la probabilité de gagnée
	do{
		printf("Saisir votre probabilité de gagner entre 0 et 100 : ");
		scanf("%f",&p);
	}while(p > 100 && p < 0);
	
	//Initialisation
	score1 = 0;
	score2 = 0;
	avantage = 0;
	srand(time(NULL));
	
	//Simulation du jeu
	while((score1 != 4 && score2 != 4 && avantage == 0) || (score1 != 5 && score2 != 5 && avantage == 1)){
		if(score1 < 3 || score2 < 3){
			if(rand()%100 < p){
				score1++;
			}else{
				score2++;
			}
		}else{
			avantage = 1;
			if(rand()%100 < p){
				if(score2 == 4){
					score2 = 3;
				}else{
					score1++;
				}
			}else{
				if(score1 == 4){
					score1 = 3;
				}else{
					score2++;
				}
			}
		}
	}
	
	//Affiche si on a gagné ou perdu
	if((score1 == 4 && avantage == 0) || score1 == 5){
		printf("Vous avez gagné le jeu ! \n");
	}else{
		printf("Vous avez perdu le jeu ! \n");
	}
}
