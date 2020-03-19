#include <stdio.h>
#include <stdlib.h>

int Ackerman(int m, int n){
	if(m == 0){
		return (n+1);
	}else if(n==0){
		return (Ackerman(m-1,1));
	}else{
		return (Ackerman(m-1, Ackerman(m, n-1)));
	}
}

int main(){
	int m,n;
	do{
		printf("saisir n: ");
		scanf("%d",&n);
	}while(n<0);
	do{
		printf("saisir m : ");
		scanf("%d",&m);
	}while(n<0);
	printf("%d %d \n",n,m);
	printf("%d \n", Ackerman(m,n));
	return 0;
}
