package com.br.trabalho2;

import java.util.Scanner;

public class Teste {
	
	private static Scanner scan;

	public static void main(String[] args) {
		
		scan = new Scanner(System.in);
		int n;
		
		System.out.println("Qual conjectura deseja testar?\n");
		System.out.println(" G - Goldbach");
		System.out.println(" C - Collatz");
		System.out.println(" 0 - Sair");
		
		System.out.print("\n -> ");
		char op = scan.next().charAt(0);
		
		switch(op) {
		
			case 'G': System.out.print("\nDigite o valor de n: ");
					  n = scan.nextInt();
					  
					  System.out.println("");
					
					  Goldbach testeGoldbach = new Goldbach(n);
					  testeGoldbach.verificarIntervalo();
					  
					  break;
					
			case 'C': System.out.print("\nDigite o valor de n: ");
					  n = scan.nextInt();
					  
					  System.out.println("");
					
					  Collatz.testeCollatz(n);
					  
					  break;
				
			case '0': System.exit(0);
			
			default: System.out.println("\nOpção inválida.");
			         System.exit(0);
		}		
	}
}
