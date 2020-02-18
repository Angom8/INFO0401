#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//main
int main(void){

	char t[255];
	char *d;

	printf("Saisissez une chaine de caractères (Taille max : 255)\n");
	scanf("%s", t);

	d = t;
	
	while (*d != '\0') {
		d ++;
	}

	printf("Taille : %ld\n", ((d-t)/sizeof(char)));
}

