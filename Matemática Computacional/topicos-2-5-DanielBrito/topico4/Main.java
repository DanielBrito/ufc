package com.br.ufc.topico4;

public class Main {

	public static void main(String[] args) {
		
		// Definicao da matriz para teste:
		double[][] a = {{3, 2, 4}, {1, 1, 2}, {4, 3, 2}};
		
		// Instanciando Matriz:
		Matriz A = new Matriz(a);
		
		// Realizando fatoração e retornando as matrizes L, U e P:
		Matriz aL = Sistemas.fatoracaoLU(A)[0];
		Matriz aU = Sistemas.fatoracaoLU(A)[1];
		Matriz aP = Sistemas.fatoracaoLU(A)[2];
		
		// Imprimindo resultados:
		aL.imprimir();
		aU.imprimir();
		aP.imprimir();
	}	
}