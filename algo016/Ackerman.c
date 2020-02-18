#include <stdlib.h>
#include <stdio.h>

int Ackerman(int m, int n){
	if(m == 0){
		return (n+1);
	}
	else{
		if(n==0){
			return Ackerman(m-1, 1);
		}
		else{
			return Ackerman(m-1, Ackerman(m, n-1));
		}
	}
}

int main(){

	int n, m;
	
	printf("Rentrez m et n\n");

	scanf("%d", &n);
	scanf("%d", &m);

	printf("%d\n", Ackerman(m, n));
	return(0);

}
