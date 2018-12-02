package com.br.trabalhofinal;

import java.util.Scanner;

public class Menus {
	
	public static Scanner scan = new Scanner(System.in);
	
	public static void menuPrincipal() {
		
		int op;
		
		System.out.println("\nEscolha a categoria:\n");
		
		System.out.println(" 1 - Álgebra Matricial");
		System.out.println(" 2 - Sistemas");
		System.out.println(" 3 - Ortogonalização de Gram-Schmidt");		
		System.out.println(" 0 - Sair");
		
		System.out.print("\n => ");
		
		op = scan.nextInt();
		
		switch(op) {
		
			case 1: menuAlgebraMatricial(); break;
			
			case 2: menuSistemas(); break;
			
			case 3: Entrada_Saida.opOrtogonalizacaoGramSchmidt(); Menus.Opcao(); break;
			
			case 0: System.exit(0);
		}	
	}
	
	public static void menuAlgebraMatricial() {
		
		int op;
		
		System.out.println("\nEscolha a operação:\n");
		
		System.out.println(" 1 - Adição");
		System.out.println(" 2 - Subtração");
		System.out.println(" 3 - Multiplicação por escalar");
		System.out.println(" 4 - Multiplição");
		System.out.println(" 5 - Transposição");
		System.out.println(" 6 - Potenciação");
		System.out.println(" 7 - Inversa");
		System.out.println(" 8 - Cofatora");
		System.out.println(" 9 - Adjunta");
		System.out.println("10 - Determinante");
		
		System.out.print("\n => ");
		
		op = scan.nextInt();
		
		switch(op) {
		
			case 1: Entrada_Saida.opSomar(); break;
			
			case 2: Entrada_Saida.opSubtrair(); break;
			
			case 3: Entrada_Saida.opMultiplicacaoPorEscalar(); break;
			
			case 4: Entrada_Saida.opMultiplicacao(); break;

			case 5: Entrada_Saida.opTransposicao(); break;
			
			case 6: Entrada_Saida.opPotenciacao(); break;
			
			case 7: Entrada_Saida.opInversa(); break;
			
			case 8: Entrada_Saida.opCofatora(); break;
			
			case 9: Entrada_Saida.opAdjunta(); break;
			
			case 10: Entrada_Saida.opDeterminante(); break;
		}
		
		Menus.Opcao();
	}
	
	public static void menuSistemas() {
		
		int op;
		
		System.out.println("\nEscolha o método:\n");
		
		System.out.println(" 1 - Gauss");
		System.out.println(" 2 - Gauss-Jordan");
		System.out.println(" 3 - Fatoração LU");
		
		System.out.print("\n => ");
		
		op = scan.nextInt();
		
		switch(op) {
		
			case 1: Entrada_Saida.opGauss(); break;
			
			case 2: Entrada_Saida.opGaussJordan(); break;
			
			case 3: Entrada_Saida.opFatoracaoLU(); break;
		}
		
		Menus.Opcao();
	}
	
	public static void Opcao() {
		
		int op;
		
		System.out.println("\n 1 - Menu");
		System.out.println(" 0 - Sair");
		
		System.out.print("\n => ");
		
		op = scan.nextInt();
		
		if(op==1) {
			
			Menus.menuPrincipal();
		}
		
		if(op==0) {
			
			System.exit(0);
		}
	}
}