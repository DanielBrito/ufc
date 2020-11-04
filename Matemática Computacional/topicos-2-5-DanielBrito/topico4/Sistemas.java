package com.br.ufc.topico4;

import static java.util.stream.IntStream.range;

public class Sistemas {
	
	private static double somatorio(double[] a, double[] b) {
		
        return range(0, a.length).mapToDouble(i -> a[i] * b[i]).sum();
    }

	private static Matriz matrizMultiplicacao(Matriz a, Matriz b) {
		
		Matriz resultado = new Matriz(a.getLinhas(), b.getColunas());
		double[] aux = new double[b.getLinhas()];
		
		for(int i=0; i<b.getColunas(); i++) {
			
			for(int j=0; j<b.getLinhas(); j++) {
				
				aux[j] = b.getValor(j, i);
			}
			
			for(int k=0; k<a.getLinhas(); k++) {
				
				resultado.setValor(k, i, somatorio(a.getLinha(k), aux));
			}
		}
		
		return resultado;
	}
    
    private static Matriz pivoteamento(Matriz m) {
    	
    	int n = m.getLinhas();
    	
    	Matriz identidade = new Matriz(n, n);
    	identidade.gerarIdentidade(n);
    	
    	for(int i=0; i<n; i++) {
    		
    		double maxM = m.getValor(i, i);
    		int linha = i;
    		
    		for(int j=i; j<n; j++) {
    			
    			if(m.getValor(j, i)>maxM) {
    				
    				maxM = m.getValor(j, i);
    				linha = j;
    			}
    		}
    		
    		if(i!=linha) {
    			
    			m.trocaLinhas(i, linha);
    		}
    	}
    	
    	return identidade;
    }
    
    public static Matriz[] fatoracaoLU(Matriz m) {
    	
    	int n = m.getLinhas();
    	
    	Matriz L = new Matriz(n, n);
    	Matriz U = new Matriz(n, n);
    	Matriz P = pivoteamento(m);
    	Matriz mAux = matrizMultiplicacao(P, m);
    	
    	for(int i=0; i<n; i++) {
    		
    		L.setValor(i, i, 1);
    		
    		for(int j=0; j<i+1; j++) {
    			
    			double soma1 = 0;
    			
    			for(int k=0; k<j; k++) {
    				
    				soma1 += U.getValor(k, i) * L.getValor(j, k);
    			}
    			
    			U.setValor(j, i, mAux.getValor(j, i)-soma1);
    		}
    		
    		for(int j=i; j<n; j++) {
    			
    			double soma2 = 0;
    			
    			for(int k=0; k<i; k++) {
    				
    				soma2 += U.getValor(k, i) * L.getValor(j, k);
    			}
    			
    			L.setValor(j, i, (mAux.getValor(j, i)-soma2) / U.getValor(i, i));
    		}
    	}
    	
    	return new Matriz[] {L, U, P};
    }
}
