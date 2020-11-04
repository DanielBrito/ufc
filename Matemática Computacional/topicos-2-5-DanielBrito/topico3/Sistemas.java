package com.br.ufc.topico3;

public class Sistemas {
	
	// Tolerancia de precisao:
	private static final double EPSILON = 1e-10;
	
	public static double[] eliminacaoGaussianaPivoteamento(Matriz coeficientes, double[] termos) {
		
		int n = termos.length;
		
		for(int i=0; i<n; i++) {
			
			// Variaveis auxiliares:
			int max = i;
			double t;
			
			coeficientes.imprimir();
			imprimirSolucao(termos);
			
			// Encontrando linha pivô:
			for(int j=i+1; j<n; j++) {
				
				if(Math.abs(coeficientes.getValor(j, i)) > Math.abs(coeficientes.getValor(max, i))){
					
					max = j;
				}
			}
			
			// Realizando 'swap' das linhas:
			coeficientes.trocaLinhas(i, max);
			        
		    // Realizando 'swap' dos termos independentes:
		    t = termos[i];
			termos[i] = termos[max];
			termos[max] = t;
			      
			// Verificando restricao da precisao:
			if(Math.abs(coeficientes.getValor(i, i)) <= EPSILON) {
				
				return null;
			}
			
			// Realizando pivoteamento:
			for(int k=i+1; k<n; k++) {
				
				double m = coeficientes.getValor(k, i) / coeficientes.getValor(i, i);
				termos[k] -= m * termos[i];
				
				for(int j=i; j<n; j++) {
					
					coeficientes.setValor(k, j, (coeficientes.getValor(k, j)) - (m*coeficientes.getValor(i, j)));
				}
			}
		}
		
		double[] solucao = new double[n];
		
		// Realizando substituicao para tras:
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
