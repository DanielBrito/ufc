#include<stdio.h>

int main(){
	
	int P, Q, R;
	
	printf("P  Q  R  (P && R)  (Q || R)  (P && R) || (Q || R)\n\n");
	
	for(P=0; P<=1; P++){
		
		for(Q=0; Q<=1; Q++){
			
			for(R=0; R<=1; R++){
				
				printf("%d  %d  %d     %d         %d               %d\n", P, Q, R, P&&R, Q||R, (P&&Q)||(Q||R));
			}
		}
	}
	
	return 0;
}
