package com.br.trabalhofinal;

public class Ortogonalizacao {
	
	public static void ortogonalizacaoGramSchmidt(float[] v1, float[] v2, float[] v3) {
		
		float[] w1 = new float[v1.length];
		w1 = v1;
		
		float[] w2 = new float[v2.length];
		w2 = subtrairVetores(v2, multiplicacaoPorEscalar(produtoInterno(v2, w1)/produtoInterno(w1, w1), w1));
	
		float[] w3 = new float[v3.length];
		w3 = subtrairVetores(subtrairVetores(v3, multiplicacaoPorEscalar(produtoInterno(v3, w1)/produtoInterno(w1,w1), w1)), multiplicacaoPorEscalar(produtoInterno(v3, w2)/produtoInterno(w2, w2), w2));
	
		System.out.print("\nBase: B = ");
		imprimirVetores(v1, v2, v3);
		
		System.out.print("\nBase Ortogonal:  C = ");
		imprimirVetores(w1, w2, w3);
		
		System.out.print("\nBase C ortonormalizada: ");
		ortonormalizacao(w1, w2, w3);
	}
	
	public static float[] somarVetores(float[] v1, float[] v2) {
		
		float[] resultado = new float[v1.length];
		
		for(int i=0; i<v1.length; i++) {
			
			resultado[i] = v1[i] + v2[i];
		}
		
		return resultado;
	}
	
	public static float[] subtrairVetores(float[] v1, float[] v2) {
		
		float[] resultado = new float[v1.length];
		
		for(int i=0; i<v1.length; i++) {
			
			resultado[i] = v1[i] - v2[i];
		}
		
		return resultado;
	}
	
	public static float[] multiplicacaoPorEscalar(float escalar, float[] vetor) {
		
		float[] resultado = new float[vetor.length];
		
		for(int i=0; i<vetor.length; i++) {
			
			resultado[i] = vetor[i]*escalar;
		}
		
		return resultado;
	}
	
	public static float produtoInterno(float[] v1, float[] v2) {
		
		float soma = 0;
		
		for(int i=0; i<v1.length; i++) {
			
			soma += v1[i] * v2[i];
		}
		
		return soma;
	}
	
	public static void imprimirVetores(float[] v1, float[] v2, float[] v3) {
		
		System.out.print("{( ");
		
		for(int i=0; i<v1.length; i++) {
			
			System.out.printf("%.2f ", v1[i]);
		}
		
		System.out.print("), ");
		
		System.out.print("( ");
		
		for(int i=0; i<v2.length; i++) {
			
			System.out.printf("%.2f ", v2[i]);
		}
		
		System.out.print("), ");
		
		System.out.print("( ");
		
		for(int i=0; i<v3.length; i++) {
			
			System.out.printf("%.2f ", v3[i]);
		}
		
		System.out.println(")}"); 
	}
	
	public static void ortonormalizacao(float[] w1, float[] w2, float[] w3) {
		
		float[] u1 = new float[w1.length];
		float[] u2 = new float[w2.length];
		float[] u3 = new float[w3.length];
		
		for(int i=0; i<w1.length; i++) {
			
			u1[i] = (float)(w1[i]/(Math.sqrt(produtoInterno(w1, w1))));
		}
		
		for(int i=0; i<w2.length; i++) {
			
			u2[i] = (float)(w2[i]/(Math.sqrt(produtoInterno(w2, w2))));
		}
		
		for(int i=0; i<w3.length; i++) {
			
			u3[i] = (float)(w3[i]/(Math.sqrt(produtoInterno(w3, w3))));
		}
		
		imprimirVetores(u1, u2, u3);
	}
}