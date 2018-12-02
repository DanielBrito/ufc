package com.br.trabalhofinal;

import java.util.Scanner;

public class Entrada_Saida {
	
static Scanner scan = new Scanner(System.in);

	// ÁLGEBRA MATRICIAL
	
	public static void opSomar() {
		
		int linhas, colunas;
		float valor;
		
		System.out.print("\nDigite a quantidade de linhas: ");
		linhas = scan.nextInt();
		
		System.out.print("\nDigite a quantidade de colunas: ");
		colunas = scan.nextInt();
		
		Matriz termo1 = new Matriz(linhas, colunas);
		Matriz termo2 = new Matriz(linhas, colunas);
		Matriz resultado = new Matriz(linhas, colunas);
		
		System.out.println("\nInsira os valores da Matriz 1:");
		
		for(int i=0; i<linhas; i++) {
			
			for(int j=0; j<colunas; j++) {
				
				System.out.print("[" + (i+1) + "]" + "[" + (j+1) + "]" + " = ");
				valor = scan.nextFloat();
				
				termo1.setValor(i, j, valor);
			}
		}
		
		System.out.println("\nInsira os valores da Matriz 2:");
		
		for(int i=0; i<linhas; i++) {
			
			for(int j=0; j<colunas; j++) {
				
				System.out.print("[" + (i+1) + "]" + "[" + (j+1) + "]" + " = ");
				valor = scan.nextFloat();
				
				termo2.setValor(i, j, valor);
			}
		}
		
		resultado = AlgebraMatricial.somar(termo1, termo2);
		
		System.out.println("\nMatriz 1:");
		termo1.imprimir();
		
		System.out.println("\nMatriz 2:");
		termo2.imprimir();	
		
		System.out.println("\nMatriz 1 + Matriz 2:");
		resultado.imprimir();
	}
	
	public static void opSubtrair() {
		
		int linhas, colunas;
		float valor;
		
		System.out.print("\nDigite a quantidade de linhas: ");
		linhas = scan.nextInt();
		
		System.out.print("\nDigite a quantidade de colunas: ");
		colunas = scan.nextInt();
		
		Matriz minuendo = new Matriz(linhas, colunas);
		Matriz subtraendo = new Matriz(linhas, colunas);
		Matriz resultado = new Matriz(linhas, colunas);
		
		System.out.println("\nInsira os valores da Matriz 1:");
		
		for(int i=0; i<linhas; i++) {
			
			for(int j=0; j<colunas; j++) {
				
				System.out.print("[" + (i+1) + "]" + "[" + (j+1) + "]" + " = ");
				valor = scan.nextFloat();
				
				minuendo.setValor(i, j, valor);
			}
		}
		
		System.out.println("\nInsira os valores da Matriz 2:");
		
		for(int i=0; i<linhas; i++) {
			
			for(int j=0; j<colunas; j++) {
				
				System.out.print("[" + (i+1) + "]" + "[" + (j+1) + "]" + " = ");
				valor = scan.nextFloat();
				
				subtraendo.setValor(i, j, valor);
			}
		}
		
		resultado = AlgebraMatricial.subtrair(minuendo, subtraendo);
		
		System.out.println("\nMatriz 1:");
		minuendo.imprimir();
		
		System.out.println("\nMatriz 2:");
		subtraendo.imprimir();		
		
		System.out.println("\nMatriz 1 - Matriz 2:");
		resultado.imprimir();
	}

	public static void opMultiplicacaoPorEscalar() {
		
		float escalar;
		int linhas, colunas;
		float valor;
		
		System.out.print("\nDigite a quantidade de linhas: ");
		linhas = scan.nextInt();
		
		System.out.print("\nDigite a quantidade de colunas: ");
		colunas = scan.nextInt();
		
		System.out.print("\nDigite o valor do escalar: ");
		escalar = scan.nextFloat();
		
		Matriz matriz = new Matriz(linhas, colunas);
		Matriz resultado = new Matriz(linhas, colunas);
		
		System.out.println("\nInsira os valores da Matriz: ");
		
		for(int i=0; i<linhas; i++) {
			
			for(int j=0; j<colunas; j++) {
				
				System.out.print("[" + (i+1) + "]" + "[" + (j+1) + "]" + " = ");
				valor = scan.nextFloat();
				
				matriz.setValor(i, j, valor);
			}
		}
		
		resultado = AlgebraMatricial.multiplicacaoPorEscalar(matriz, escalar);
		
		System.out.println("\nMatriz:");
		matriz.imprimir();
		
		System.out.println("\n" + escalar + " * Matriz:");
		resultado.imprimir();
	}
	
	public static void opMultiplicacao() {
		
		int linhas1, colunas1, linhas2, colunas2;
		float valor;
		
		System.out.print("\nMatriz 1: " );
		
		System.out.print("\nDigite a quantidade de linhas: " );
		linhas1 = scan.nextInt();
		System.out.print("\nDigite a quantidade de colunas: " );
		colunas1 = scan.nextInt();
		
		System.out.print("\nMatriz 2: " );
		
		System.out.print("\nDigite a quantidade de linhas: " );
		linhas2 = scan.nextInt();
		System.out.print("\nDigite a quantidade de colunas: " );
		colunas2 = scan.nextInt();
		
		if(colunas1!=linhas2) {
			
			System.out.println("\nA multiplicação não está definida para as dimensões digitadas.");
			
			return;
		}
		
		Matriz fator1 = new Matriz(linhas1, colunas1);
		Matriz fator2 = new Matriz(linhas2, colunas2);
		Matriz resultado = new Matriz(linhas1, colunas2);
		
		System.out.println("\nInsira os valores da Matriz 1:");
		
		for(int i=0; i<linhas1; i++) {
			
			for(int j=0; j<colunas1; j++) {
				
				System.out.print("[" + (i+1) + "]" + "[" + (j+1) + "]" + " = ");
				valor = scan.nextFloat();
				
				fator1.setValor(i, j, valor);
			}
		}
		
		System.out.println("\nInsira os valores da Matriz 2:");
		
		for(int i=0; i<linhas2; i++) {
			
			for(int j=0; j<colunas2; j++) {
				
				System.out.print("[" + (i+1) + "]" + "[" + (j+1) + "]" + " = ");
				valor = scan.nextFloat();
				
				fator2.setValor(i, j, valor);
			}
		}
		
		resultado = AlgebraMatricial.multiplicacao(fator1, fator2);
		
		System.out.println("\nMatriz 1:");
		fator1.imprimir();
		
		System.out.println("\n Matriz 2:");
		fator2.imprimir();
		
		System.out.println("\nMatriz 1 * Matriz 2:");
		resultado.imprimir();
	}
	
	public static void opTransposicao() {
		
		int linhas, colunas;
		float valor;
		
		System.out.print("\nDigite a quantidade de linhas: " );
		linhas = scan.nextInt();
		
		System.out.print("\nDigite a quantidade de colunas: " );
		colunas = scan.nextInt();
		
		Matriz matriz = new Matriz(linhas, colunas);
		Matriz transposta = new Matriz(colunas, linhas);
		
		System.out.println("\nInsira os valores da Matriz:");
		
		for(int i=0; i<linhas; i++) {
			
			for(int j=0; j<colunas; j++) {
				
				System.out.print("[" + (i+1) + "]" + "[" + (j+1) + "]" + " = ");
				valor = scan.nextFloat();
				
				matriz.setValor(i, j, valor);
			}
		}
		
		transposta = AlgebraMatricial.transposicao(matriz);
		
		System.out.println("\nMatriz:");
		matriz.imprimir();
		
		System.out.println("\nTransposta:");
		transposta.imprimir();
	}
	
	public static void opPotenciacao() {
		
		int dimensao, expoente;
		float valor;
		
		System.out.print("\nDigite a dimensão da Matriz: ");
		dimensao = scan.nextInt();
		
		System.out.print("\nDigite o valor do expoente: ");
		expoente = scan.nextInt();
		
		Matriz matriz = new Matriz(dimensao, dimensao);
		Matriz resultado = new Matriz(dimensao, dimensao);
		
		System.out.println("\nInsira os valores da Matriz:");
		
		for(int i=0; i<dimensao; i++) {
			
			for(int j=0; j<dimensao; j++) {
				
				System.out.print("[" + (i+1) + "]" + "[" + (j+1) + "]" + " = ");
				valor = scan.nextFloat();
				
				matriz.setValor(i, j, valor);
			}
		}
		
		resultado = AlgebraMatricial.potenciacao(matriz, expoente);
		
		System.out.println("\nMatriz:");
		matriz.imprimir();
		
		System.out.println("\nMatriz ^ " + expoente + ":");
		resultado.imprimir();
	}
	
	public static void opInversa() {
		
		int dimensao;
		float valor;
		
		System.out.print("\nDigite a dimensão da Matriz: ");
		dimensao = scan.nextInt();
		
		Matriz matriz = new Matriz(dimensao, dimensao);
		Matriz inversa = new Matriz(dimensao, dimensao);
		
		System.out.println("\nInsira os valores da Matriz:");
		
		for(int i=0; i<dimensao; i++) {
			
			for(int j=0; j<dimensao; j++) {
				
				System.out.print("[" + (i+1) + "]" + "[" + (j+1) + "]" + " = ");
				valor = scan.nextFloat();
				
				matriz.setValor(i, j, valor);
			}
		}
		
		inversa = AlgebraMatricial.inversa(matriz);
		
		System.out.println("\nMatriz:");
		matriz.imprimir();
		
		if(inversa==null) {
			
			System.out.println("\nA matriz não admite inversa");
		}
		else {
			
			System.out.println("\nInversa:");
			inversa.imprimir();
		}		
	}
	
	public static void opCofatora() {
		
		int dimensao;
		float valor;
		
		System.out.print("\nDigite a dimensão da Matriz: ");
		dimensao = scan.nextInt();
		
		Matriz matriz = new Matriz(dimensao, dimensao);
		Matriz cofatora = new Matriz(dimensao, dimensao);
		
		System.out.println("\nInsira os valores da Matriz:");
		
		for(int i=0; i<dimensao; i++) {
			
			for(int j=0; j<dimensao; j++) {
				
				System.out.print("[" + (i+1) + "]" + "[" + (j+1) + "]" + " = ");
				valor = scan.nextFloat();
				
				matriz.setValor(i, j, valor);
			}
		}
		
		cofatora = AlgebraMatricial.cofatora(matriz);
		
		System.out.println("\nMatriz:");
		matriz.imprimir();
		
		System.out.println("\nCofatora:");
		cofatora.imprimir();
	}
	
	public static void opAdjunta() {
		
		int dimensao;
		float valor;
		
		System.out.print("\nDigite a dimensão da Matriz: ");
		dimensao = scan.nextInt();
		
		Matriz matriz = new Matriz(dimensao, dimensao);
		Matriz adjunta = new Matriz(dimensao, dimensao);
		
		System.out.println("\nInsira os valores da Matriz:");
		
		for(int i=0; i<dimensao; i++) {
			
			for(int j=0; j<dimensao; j++) {
				
				System.out.print("[" + (i+1) + "]" + "[" + (j+1) + "]" + " = ");
				valor = scan.nextFloat();
				
				matriz.setValor(i, j, valor);
			}
		}
		
		adjunta = AlgebraMatricial.adjunta(matriz);
		
		System.out.println("\nMatriz:");
		matriz.imprimir();
		
		System.out.println("\nAdjunta:");
		adjunta.imprimir();
	}
	
	public static void opDeterminante() {
		
		int dimensao;
		float valor, det=0;
		
		System.out.print("\nDigite a dimensão da Matriz: ");
		dimensao = scan.nextInt();
		
		Matriz matriz = new Matriz(dimensao, dimensao);
		
		System.out.println("\nInsira os valores da Matriz:");
		
		for(int i=0; i<dimensao; i++) {
			
			for(int j=0; j<dimensao; j++) {
				
				System.out.print("[" + (i+1) + "]" + "[" + (j+1) + "]" + " = ");
				valor = scan.nextFloat();
				
				matriz.setValor(i, j, valor);
			}
		}
		
		det = AlgebraMatricial.determinante(matriz);
		
		System.out.println("\nMatriz:");
		matriz.imprimir();
		
		System.out.println("\nDeterminante:");
		System.out.println(det);
	}
	
	// SISTEMAS
	
	public static void opGauss() {
		
		int linhas, colunas;
		float valor;
		
		System.out.print("\nDigite a quantidade de linhas da matriz dos coeficientes: ");
		linhas = scan.nextInt();
		
		System.out.print("\nDigite a quantidade de colunas da matriz dos coeficientes: ");
		colunas = scan.nextInt();
		
		Matriz matrizCoeficientes = new Matriz(linhas, colunas);
		float termosIndependentes[] = new float[linhas];
		float solucao[] = new float[linhas];
		
		System.out.println("\nInsira os valores da matriz dos coeficientes:");
		
		for(int i=0; i<linhas; i++) {
			
			for(int j=0; j<colunas; j++) {
				
				System.out.print("[" + (i+1) + "]" + "[" + (j+1) + "]" + " = ");
				valor = scan.nextFloat();
				
				matrizCoeficientes.setValor(i, j, valor);
			}
		}
		
		System.out.println("\nInsira os valores dos termos independentes:");
		
		for(int i=0; i<linhas; i++) {
			
			System.out.print("[" + (i+1) + "]" + " = ");
			valor = scan.nextFloat();
			
			termosIndependentes[i] = valor;
		}
		
		Matriz matAumentada = new Matriz(linhas, colunas+1);
		Matriz.matrizAumentada(matAumentada, matrizCoeficientes, termosIndependentes);
		
		solucao = Sistemas.gauss(matrizCoeficientes, termosIndependentes);
		
	/*
		// TESTE DE IMPRESSÃO
		
		System.out.println("\nMatriz aumentada:");
		matAumentada.imprimir();
		
		System.out.println("\nMatriz triangular superior:");
		
		for(int i=0; i<linhas; i++) {
			
			for(int j=0; j<colunas; j++) {
				
				System.out.printf("[%.2f] ", matrizCoeficientes.getValor(i, j));
				
				if(j==colunas-1) {
					
					System.out.printf("[%.2f]", solucao[i]);
				}
			}
			
			System.out.println();
		}
		
		// System.out.print("\nPosto da matriz ampliada: " + Sistemas.posto(matAumentada));
		
		// System.out.println("\nPosto da matriz dos coeficientes: " + Sistemas.posto(matrizCoeficientes));
		
		// FIM DO TESTE DE IMPRESSÃO
	*/
		
		Float v = solucao[solucao.length-1];
		
		if(Sistemas.posto(matrizCoeficientes)<linhas && v.isNaN()) {
			
			System.out.println("\nSistema possível e indeterminado");
		}
		else
		if(Sistemas.posto(matrizCoeficientes)<linhas && v!=0) {
			
			System.out.println("\nSistema impossível");
		}
		else {
			
			System.out.println("\nSistema possível e determinado");
			
			System.out.print("\nS = {( ");
			
			for(int i=0; i<linhas; i++) {
					
				System.out.printf("%.2f ", solucao[i]);
			}
			
			System.out.print(")}\n");
		}
	}
	
	public static void opGaussJordan() {
		
		int linhas, colunas;
		float valor;
		
		System.out.print("\nDigite a quantidade de linhas da matriz dos coeficientes: ");
		linhas = scan.nextInt();
		
		System.out.print("\nDigite a quantidade de colunas da matriz dos coeficientes: ");
		colunas = scan.nextInt();
		
		Matriz matrizCoeficientes = new Matriz(linhas, colunas);
		float termosIndependentes[] = new float[linhas];
		float solucao[] = new float[linhas];
		
		System.out.println("\nInsira os valores da matriz dos coeficientes:");
		
		for(int i=0; i<linhas; i++) {
			
			for(int j=0; j<colunas; j++) {
				
				System.out.print("[" + (i+1) + "]" + "[" + (j+1) + "]" + " = ");
				valor = scan.nextFloat();
				
				matrizCoeficientes.setValor(i, j, valor);
			}
		}
		
		System.out.println("\nInsira os valores dos termos independentes:");
		
		for(int i=0; i<linhas; i++) {
			
			System.out.print("[" + (i+1) + "]" + " = ");
			valor = scan.nextFloat();
			
			termosIndependentes[i] = valor;
		}
		
		Matriz matAumentada = new Matriz(linhas, colunas+1);
		Matriz.matrizAumentada(matAumentada, matrizCoeficientes, termosIndependentes);
		
		solucao = Sistemas.gaussJordan(matrizCoeficientes, termosIndependentes);
		
	/*
		// TESTE DE IMPRESSÂO
		
		System.out.println("\nMatriz aumentada:");
		matAumentada.imprimir();
		
		System.out.println("\nMatriz reduzida por linhas:");
		
		for(int i=0; i<linhas; i++) {
			
			for(int j=0; j<colunas; j++) {
				
				System.out.printf("[%.2f] ", matrizCoeficientes.getValor(i, j));
				
				if(j==colunas-1) {
					
					System.out.printf("[%.2f]", solucao[i]);
				}
			}
			
			System.out.println();
		}
		
		System.out.print("\nPosto da matriz ampliada: " + Sistemas.posto(matAumentada));
		
		System.out.println("\nPosto da matriz dos coeficientes: " + Sistemas.posto(matrizCoeficientes));
	
		// FIM DO TESTE DE IMPRESSÃO
		
	*/
		
		Float v = solucao[solucao.length-1];
		
		if(!v.isNaN() && !v.isInfinite()) {
			
			System.out.println("\nSistema possível e determinado");
						
			System.out.print("\nS = {( ");
			
			for(int i=0; i<linhas; i++) {
					
				System.out.printf("%.2f ", solucao[i]);
			}
			
			System.out.print(")}\n");

		}
		else
		if(v.isNaN()) {
			
			System.out.println("\nSistema possível e indeterminado");
		}
		else {
			
			System.out.println("\nSistema impossível");
		}
	}
	
	public static void opFatoracaoLU() {
		
		int linhas, colunas;
		float valor;
		
		System.out.print("\nDigite a quantidade de linhas da matriz dos coeficientes: ");
		linhas = scan.nextInt();
		
		System.out.print("\nDigite a quantidade de colunas da matriz dos coeficientes: ");
		colunas = scan.nextInt();
		
		Matriz matrizCoeficientes = new Matriz(linhas, colunas);
		float termosIndependentes[] = new float[linhas];
		
		System.out.println("\nInsira os valores da matriz dos coeficientes:");
		
		for(int i=0; i<linhas; i++) {
			
			for(int j=0; j<colunas; j++) {
				
				System.out.print("[" + (i+1) + "]" + "[" + (j+1) + "]" + " = ");
				valor = scan.nextFloat();
				
				matrizCoeficientes.setValor(i, j, valor);
			}
		}
		
		System.out.println("\nInsira os valores dos termos independentes:");
		
		for(int i=0; i<linhas; i++) {
			
			System.out.print("[" + (i+1) + "]" + " = ");
			valor = scan.nextFloat();
			
			termosIndependentes[i] = valor;
		}
		
		Matriz matrizL = new Matriz(linhas, colunas);
		Matriz matrizU = new Matriz(linhas, colunas);
		
		Sistemas.fatoracaoLU(matrizCoeficientes, matrizL, matrizU);
		
		System.out.println("\nMatriz L:");
		matrizL.imprimir();
		
		System.out.println("\nMatriz U:");
		matrizU.imprimir();
	}
	
	// ORTOGONALIZAÇÃO DE GRAM-SCHMIDT
	
	public static void opOrtogonalizacaoGramSchmidt() {
		
		int grauR, base;
		
		System.out.print("\nDigite o grau de R: ");
		grauR = scan.nextInt();
		
		System.out.print("\nDigite a dimensão da base B: ");
		base = scan.nextInt();
		
		scan.nextLine();
		
		// Implementação "estática", para grauR = 3 e base = 3:
		
		float vetor1[] = new float[grauR];
		float vetor2[] = new float[grauR];
		float vetor3[] = new float[grauR];
		
		System.out.println("\nDigite os valores dos vetores:");
		
		for(int i=1; i<=base; i++) {
			
			if(i==1) {
				
				System.out.println("\nValores de v1");
				
				for(int j=0; j<grauR; j++) {
					
					System.out.print("-> ");
					vetor1[j] = scan.nextFloat();
				}
			}
			
			if(i==2) {
				
				System.out.println("\nValores de v2");
				
				for(int j=0; j<grauR; j++) {
					
					System.out.print("-> ");
					vetor2[j] = scan.nextFloat();
				}
			}
			
			if(i==3) {
				
				System.out.println("\nValores de v3");
				
				for(int j=0; j<grauR; j++) {
					
					System.out.print("-> ");
					vetor3[j] = scan.nextFloat();
				}
			}
		}
		
		Ortogonalizacao.ortogonalizacaoGramSchmidt(vetor1, vetor2, vetor3);
	}
}
