#include <stdio.h>
#include <stdlib.h>

int main(){
	//Declaration
	int n,i, j, tmp;
	n = 10;
	int t[10] = {1, 5, 7, 2, 3, 9, 8, 4, 10, 6};
	int stop = 0;


	
	for(i=0;i<n;i++){
		printf("%d ", t[i]);
	}
	printf("\n");
	while(stop == 0){
		i = 0;
		stop = 1;
		while(i < n-1){
			if(t[i] > t[i+1]){
				tmp = t[i+1];
				t[i+1] = t[i];
				t[i] = tmp;
				stop = 0;
			}
			i++;
		}
		
	}

	for(i=0;i<n;i++){
		printf("%d ", t[i]);
	}
	printf("\n");
	
	exit(0);
}
