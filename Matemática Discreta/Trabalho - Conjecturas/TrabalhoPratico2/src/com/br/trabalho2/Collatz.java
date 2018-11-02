package com.br.trabalho2;

public class Collatz {
	
	public static void testeCollatz(int n) {
		
		System.out.print("Collatz ");
		
		while(true) {
			
			if(n==1) {
				
				System.out.print(n + " (Ok)");
				
				return;
			}
			
			if(n%2==0) {
				
				System.out.print(n + " -> ");
				n = n/2;
			}
			else {
				
				System.out.print(n + " -> ");
				n = 3*n+1;
			}
		}
	}
}