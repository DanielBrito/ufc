#include <stdio.h>

int multRec(int k, int n){

    if (n==0) {
    	
        return 0;
	}

    return k + multRec(k, n-1);
}

int main(){
	
	int k=2, n=20;

	printf("%d * %d = %d", k, n, multRec(k, n));

	printf("\n");

	return 0;
}
