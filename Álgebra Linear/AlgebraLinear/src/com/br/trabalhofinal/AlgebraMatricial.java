package com.br.trabalhofinal;

public class AlgebraMatricial {
	
	public static Matriz somar(Matriz termo1, Matriz termo2) {
		
		Matriz resultado = new Matriz(termo1.getLinhas(), termo1.getColunas());
		
		for(int i=0; i<termo1.getLinhas(); i++) {
			
			for (int j=0; j<termo1.getColunas(); j++) {
				
				resultado.setValor(i, j, termo1.getValor(i, j) + termo2.getValor(i, j));
			}
		}
		
		return resultado;
	}
	
	public static Matriz subtrair(Matriz minuendo, Matriz subtraendo) {
		
		Matriz resultado = new Matriz(minuendo.getLinhas(), minuendo.getColunas());
		
		for(int i=0; i<minuendo.getLinhas(); i++) {
			
			for (int j=0; j<minuendo.getColunas(); j++) {
				
				resultado.setValor(i, j, minuendo.getValor(i, j) - subtraendo.getValor(i, j));
			}
		}
		
		return resultado;
	}
	
	public static Matriz multiplicacaoPorEscalar(Matriz matriz, float escalar) {
		
		Matriz resultado = new Matriz(matriz.getLinhas(), matriz.getColunas());
		
		for(int i=0; i<matriz.getLinhas(); i++) {
			
			for(int j=0; j<matriz.getColunas(); j++) {
				
				resultado.setValor(i, j, matriz.getValor(i, j) * escalar);
			}
		}
		
		return resultado;
	}
	
	public static Matriz multiplicacao(Matriz fator1, Matriz fator2) {
		
		Matriz resultado = new Matriz(fator1.getLinhas(), fator2.getColunas());
		int somatorio = 0;
		
		for(int i=0; i<fator1.getLinhas(); i++) {
			
			for(int j=0; j<fator2.getColunas(); j++) {
				
				for(int k=0; k<fator1.getColunas(); k++) {
					
					somatorio += fator1.getValor(i, k) * fator2.getValor(k, j);
				}
				
				resultado.setValor(i, j, somatorio);
				
				somatorio = 0;
			}
		}
		
		return resultado;
	}
	
	public static Matriz transposicao(Matriz matriz) {
		
		Matriz transposta = new Matriz(matriz.getColunas(), matriz.getLinhas());
		
		for(int i=0; i<matriz.getLinhas(); i++) {
			
			for(int j=0; j<matriz.getColunas(); j++) {
				
				transposta.setValor(j, i, matriz.getValor(i, j));
			}
		}
		
		return transposta;
	}
	
	public static Matriz potenciacao(Matriz matriz, int expoente) {
		
		Matriz resultado = new Matriz(matriz.getLinhas(), matriz.getColunas());
		
		resultado = identidade(matriz.getLinhas());
		
		if(expoente==0) {
			
			return resultado;
		}
		else {
			
			for(int i=0; i<expoente; i++) {
				
				resultado = multiplicacao(resultado, matriz);
			}
		}
		
		return resultado;
	}
	
	public static Matriz inversa(Matriz matriz) {
		
		if(determinante(matriz)==0) {
			
			return null;
		}
		
		return multiplicacaoPorEscalar(adjunta(matriz), (float)(1.0/determinante(matriz)));
	}
	
	public static Matriz cofatora(Matriz matriz) {
		
		Matriz cofatora = new Matriz(matriz.getLinhas(), matriz.getColunas());
		
		for(int i=0; i<matriz.getLinhas(); i++) {
			
			for(int j=0; j<matriz.getColunas(); j++) {
				
				cofatora.setValor(i, j, oposto(i) * oposto(j) * determinante(menorComplementar(matriz, i, j)));
			}
		}
		
		return cofatora;
	}
	
	public static Matriz adjunta(Matriz matriz) {
		
		Matriz adjunta = new Matriz(matriz.getLinhas(), matriz.getColunas());
		
		adjunta = transposicao(cofatora(matriz));
		
		return adjunta;
	}
	
	public static float determinante(Matriz matriz) {
		
		if(matriz.getLinhas()==1) {
			
			return matriz.getValor(0, 0);
		}
		
		if(matriz.getLinhas()==2) {
			
			return matriz.getValor(0, 0) * matriz.getValor(1, 1) - matriz.getValor(0, 1) * matriz.getValor(1, 0);
		}
		
		float det=0;
		
		for(int i=0; i<matriz.getLinhas(); i++) {
			
			det += Math.pow(-1, i) * matriz.getValor(0, i) * determinante(menorComplementar(matriz, 0, i));
		}
		
		return det;
	}
	
	// FUNÇÕES AUXILIARES
	
	public static Matriz identidade(int dimensao) {
		
		Matriz identidade = new Matriz(dimensao, dimensao);
		
		for(int i=0; i<dimensao; i++) {
			
			for(int j=0; j<dimensao; j++) {
				
				if(i==j) {
					
					identidade.setValor(i, j, 1);
				}
				else {
					
					identidade.setValor(i, j, 0);
				}
			}
		}
		
		return identidade;
	}
	
	public static Matriz menorComplementar(Matriz matriz, int linhaX, int colunaX) {
		
		Matriz menor = new Matriz(matriz.getLinhas()-1, matriz.getColunas()-1);
		int linha = -1;
		
		for(int i=0; i<matriz.getLinhas(); i++) {
			
			if(i==linhaX) {
				
				continue;
			}
			
			linha++;
			int coluna = -1;
			
			for(int j=0; j<matriz.getColunas(); j++) {
				
				if(j==colunaX) {
					
					continue;
				}
				
				menor.setValor(linha, ++coluna, matriz.getValor(i, j));
			}
		}

		return menor;
	}
	
	private static int oposto(int i) {
		
		if (i%2==0) {
			
			return 1;
		}
		else {
			
			return -1;
		}
	}
}