package com.br.trabalhofinal;

public class Matriz {
	
	private int linhas;
	private int colunas;
	private float[][] matriz;
	
	Matriz(int linhas, int colunas){

		matriz = new float[linhas][colunas];

		this.linhas = linhas;
		this.colunas = colunas;
	}
	
	public int getLinhas() {
		
		return linhas;
	}

	public void setLinhas(int linhas) {
		
		this.linhas = linhas;
	}

	public int getColunas() {
		
		return colunas;
	}

	public void setColunas(int colunas) {
		
		this.colunas = colunas;
	}

	public void setValor(int linha, int coluna, float valor) {
		
		matriz[linha][coluna] = valor;
	}
	
	public float getValor(int linha, int coluna) {
		
		return matriz[linha][coluna];
	}
	
	public void imprimir() {
		
		for(int i=0; i<linhas; i++) {
			
			for(int j=0; j<colunas; j++) {
				
				System.out.printf("[%.2f] ", matriz[i][j]);
			}
			
			System.out.println();
		}
	}
	
	public float[] getLinha(Matriz m, int ln) {
		
		float[] linha = new float[m.colunas];
		
		for(int i=0; i<m.colunas; i++) {
			
			linha[i] = m.getValor(ln, i);
		}
		
		return linha;
	}
	
	public void setLinha(Matriz m, float[] linha, int ln) {
		
		for(int i=0; i<m.getColunas(); i++) {
			
			m.setValor(ln, i, linha[i]);
		}
	}
	
	public static Matriz matrizAumentada(Matriz matAumentada, Matriz matCoef, float[] termInd) {
		
		for(int i=0; i<matCoef.getLinhas(); i++) {
			
			for(int j=0; j<matCoef.getColunas(); j++) {
				
				matAumentada.setValor(i, j, matCoef.getValor(i, j));
				
				if(j+1==matCoef.getColunas()) {
					
					matAumentada.setValor(i, j+1, termInd[i]);
				}
			}
		}
		
		return matAumentada;
	}
	
	@Override
	public String toString(){

		int i, j;
		String m="";

		for(i=0; i<linhas; i++){

			for(j=0; j<colunas; j++){

				m = m + "[" + matriz[i][j] + "] "; 
			}

			m = m + "\n";
		}

		return m;
	}
}