/*To print numbers from 1 to 10 using goto statement*/

#include<stdio.h>

int main(){
	
    int number;
    number=1;
 
	repeat:
		
	    printf("%d\n",number);
	    number++;
	 
	    if(number<=10){
	    	
	    	goto repeat;
		}
		
    return 0;
}
