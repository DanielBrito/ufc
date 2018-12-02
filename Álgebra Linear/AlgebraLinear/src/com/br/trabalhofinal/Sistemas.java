package com.br.trabalhofinal;

public class Sistemas {
	
	public static float[] gauss(Matriz matCoef, float[] termInd) {
		
		int n = termInd.length;
		
		for(int p=0; p<n; p++) {
			
			int max = p;
			
			for(int i=p+1; i<n; i++) {
				
				if(Math.abs(matCoef.getValor(i, p)) > Math.abs(matCoef.getValor(max, p))){
					
					max = i;
				}
			}
			
			float[] temp = matCoef.getLinha(matCoef, p);
			        matCoef.setLinha(matCoef, matCoef.getLinha(matCoef, max) , p);
			        matCoef.setLinha(matCoef, temp, max);
			        
			float t = termInd[p];
			      termInd[p] = termInd[max];
			      termInd[max] = t;
			      
			for(int i=p+1; i<n; i++) {
				
				float a = matCoef.getValor(i, p)/matCoef.getValor(p, p);
				termInd[i] -= a*termInd[p];
				
				for(int j=p; j<n; j++) {
					
					matCoef.setValor(i, j, (matCoef.getValor(i, j))-(a*matCoef.getValor(p, j)));
				}
			}
		}
		
		float[] solucao = new float[n];
		
		for(int i=n-1; i>=0; i--) {
			
			float soma = 0;
			
			for(int j=i+1; j<n; j++) {
				
				soma += matCoef.getValor(i, j)*solucao[j];
			}
			
			solucao[i] = (termInd[i]-soma)/matCoef.getValor(i, i);
		}
		
		return solucao;
	}
	
	public static float[] gaussJordan(Matriz matCoef, float[] termInd) {
		
		int i, j, k, m;
		float temp;
		
		int indice[][] = new int[matCoef.getLinhas()][2];
		
		float tempPivo;
		float tempLinha[];
		int r, s=0, t;
		
		t = s;
		
		for(r=s+1; r<matCoef.getLinhas(); r++) {
			
			if((Math.abs(matCoef.getValor(r, s)) > (Math.abs(matCoef.getValor(t, s))))) {
				
				t = r;
			}
		}
		
		if(t!=s) {
			
			tempLinha = matCoef.getLinha(matCoef, s);
			matCoef.setLinha(matCoef, matCoef.getLinha(matCoef, t), s);
			matCoef.setLinha(matCoef, tempLinha, t);
			
			tempPivo = termInd[s];
			termInd[s] = termInd[t];
			termInd[t] = tempPivo;
		}
		
		for(i=0; i<matCoef.getLinhas(); ++i) {
			
			temp = matCoef.getValor(i, i);
			
			for(j=0; j<matCoef.getColunas(); ++j) {
				
				matCoef.setValor(i, j, matCoef.getValor(i, j)/temp);
			}
			
			termInd[i] /= temp;
			matCoef.setValor(i, i, 1/temp);
			
			for(k=0; k<matCoef.getLinhas(); ++k) {
				
				if(k!=i) {
					
					temp = matCoef.getValor(k, i);
					
					for(j=0; j<matCoef.getColunas(); ++j) {
						
						matCoef.setValor(k, j, matCoef.getValor(k, j)-temp*matCoef.getValor(i, j));
					}
					
					termInd[k] -= temp*termInd[i];
					matCoef.setValor(k, i, matCoef.getValor(k, i)-temp*matCoef.getValor(i, i));
				}
			}
		}
		
		for(j=matCoef.getColunas()-1; j>=0; --j) {
			
			k = indice[j][0];
			m = indice[j][1];
			
			if(k!=m) {
				
				for(i=0; i<matCoef.getLinhas(); ++i) {
					
					temp = matCoef.getValor(i, m);
					matCoef.setValor(i, m, matCoef.getValor(i, k));
					matCoef.setValor(i, k, temp);
				}
			}
		}
		
		return termInd;
	}
	
	public static void fatoracaoLU(Matriz matriz, Matriz matrizL, Matriz matrizU) {
		
		float soma = 0;
		
		for(int i=0; i<matriz.getLinhas(); i++) {
			
			for(int k=i; k<matriz.getLinhas(); k++) {
				
				soma = 0;
				
				for(int j=0; j<i; j++) {
					
					soma += (matrizL.getValor(i, j)*matrizU.getValor(j, k));
				}
				
				matrizU.setValor(i, k, matriz.getValor(i, k)-soma);
			}
			
			for(int k=i; k<matriz.getLinhas(); k++) {
				
				if(i==k) {
					
					matrizL.setValor(i, i, 1);
				}
				else {
					
					soma = 0;
					
					for(int j=0; j<i; j++) {
						
						soma += (matrizL.getValor(k, j)*matrizU.getValor(j, i));
					}
					
					matrizL.setValor(k, i, (matriz.getValor(k, i)-soma)/matrizU.getValor(i, i));
				}
			}
		}
	}
	
	public static int posto(Matriz matriz) {
		
		int linhaNula=0, elementoNulo=0;
		
		for(int i=0; i<matriz.getLinhas(); i++) {
			
			for(int j=0; j<matriz.getColunas(); j++) {
				
				if(matriz.getValor(i, j)==0) {
					
					elementoNulo++;
				}
			}
			
			if(elementoNulo==matriz.getColunas()) {
				
				linhaNula++;
			}
			
			elementoNulo = 0;
		}
		
		return matriz.getLinhas()-linhaNula;
	}
}
