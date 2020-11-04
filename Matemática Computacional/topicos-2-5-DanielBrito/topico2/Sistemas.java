package com.br.ufc.topico2;

public class Sistemas {
	
	public static double[] eliminacaoGaussiana(Matriz coeficientes, double[] termos) {
		
		int n = termos.length;
		
		// Realizando a eliminação:
		for(int k=0; k<n; k++) {
			
			// Impressao da matriz e dos termos independentes:
			coeficientes.imprimir();
			imprimirSolucao(termos);
			      
			for(int i=k+1; i<n; i++) {
				
				double m = coeficientes.getValor(i, k) / coeficientes.getValor(k, k);
				coeficientes.setValor(i, k, 0);
				
				for(int j=k; j<n; j++) {
					
					coeficientes.setValor(i, j, (coeficientes.getValor(i, j)) - (m*coeficientes.getValor(k, j)));
				}
				
				termos[i] -= m * termos[k];
			}
		}
		
		double[] solucao = new double[n];
		
		solucao[n-1] = termos[n-1] / coeficientes.getValor(n-1, n-1);
		
		// Realizando a substituicao para tras:
		for(int k=n-1; k>=0; k--) {
			
			double soma = 0;
			
			for(int j=k+1; j<n; j++) {
				
				soma += coeficientes.getValor(k, j) * solucao[j];
			}
			
			solucao[k] = (termos[k]-soma) / coeficientes.getValor(k, k);
		}
		
		return solucao;
	}
	
	// Funcao auxiliar para imprimir o vetor solucao:
	public static void imprimirSolucao(double[] b) {
		
		for(int i=0; i<b.length; i++) {
			
			System.out.printf("[%8.4f] ", b[i]);
		}
		
		System.out.println("\n");
	}
}
