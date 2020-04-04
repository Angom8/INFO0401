#include <stdio.h>
#include <stdlib.h>

int main(){
	//Declaration
	int n,i, j, tmp, min;
	n = 10;
	int t[10] = {1, 5, 7, 2, 3, 9, 8, 4, 10, 6};
	int stop = 0;


	
	for(i=0;i<n;i++){
		printf("%d ", t[i]);
	}

	printf("\n");

	for(i=0;i<n-1;i++){
		min = i;
		for(j=i+1;j<n;j++){
			if(t[j] < t[min]){
				min = j;
			}
		}
		if(min != i){
			tmp = t[min];
			t[min] = t[i];
			t[i] = tmp;
		}
	}

	for(i=0;i<n;i++){
		printf("%d ", t[i]);
	}
	printf("\n");
	
	exit(0);
}
