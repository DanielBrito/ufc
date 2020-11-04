package com.br.ufc.topico4;

public class Matriz {
	
	// Atributos da Matriz:
	private int linhas;
	private int colunas;
	private double[][] matriz;
	
	// Construtor para instanciar uma Matriz:
	Matriz(int linhas, int colunas){

		this.linhas = linhas;
		this.colunas = colunas;
		
		matriz = new double[linhas][colunas];
	}
	
	// Construtor para inicializar uma Matriz:
	Matriz(double[][] valores){
		
		linhas = valores.length;
		colunas = valores[0].length;
		
		this.matriz = new double[linhas][colunas];

		for(int i=0; i<linhas; i++) {
			
			for(int j=0; j<colunas; j++) {

				this.matriz[i][j] = valores[i][j];
			}
		}
	}
	
	// Funcoes para manipulacao dos elementos da matriz:
	
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

	public void setValor(int linha, int coluna, double valor) {
		
		matriz[linha][coluna] = valor;
	}
	
	public double getValor(int linha, int coluna) {
		
		return matriz[linha][coluna];
	}
	
	public double[] getLinha(int posicao) {
		
		double[] linha = new double[this.colunas];
		
		for(int i=0; i<this.colunas; i++) {
			
			linha[i] = this.getValor(posicao, i);
		}
		
		return linha;
	}
	
	public void setLinha(double[] linha, int posicao) {
		
		for(int i=0; i<this.getColunas(); i++) {
			
			this.setValor(posicao, i, linha[i]);
		}
	}
	
	public void trocaLinhas(int linha1, int linha2) {
		
		double[] temp = this.getLinha(linha1);
		this.setLinha(this.getLinha(linha2), linha1);
		this.setLinha(temp, linha2);
	}
	
	// Funcao para gerar uma Matriz identidade com uma dada dimensao:
	public void gerarIdentidade(int dimensao) {
		
		for(int i=0; i<dimensao; i++) {
			
			for(int j=0; j<dimensao; j++) {
				
				if(i==j) {
					
					this.setValor(i, j, 1);
				}
				else {
					
					this.setValor(i, j, 0);
				}
			}
		}
	}
	
	// Funcao para imprimir elementos da Matriz:
	public void imprimir() {
		
		for(int i=0; i<linhas; i++) {
			
			for(int j=0; j<colunas; j++) {
				
				System.out.printf("[%8.4f] ", matriz[i][j]);
			}
			
			System.out.println("");
		}
		
		System.out.println();
	}
	
	// Funcao para calcular determinante e auxiliar na solucao do sistema:
	public static double determinante(Matriz matriz) {
		
		if(matriz.getLinhas()==1) {
			
			return matriz.getValor(0, 0);
		}
		
		if(matriz.getLinhas()==2) {
			
			return matriz.getValor(0, 0) * matriz.getValor(1, 1) - matriz.getValor(0, 1) * matriz.getValor(1, 0);
		}
		
		double determinante=0;
		
		for(int i=0; i<matriz.getLinhas(); i++) {
			
			determinante += Math.pow(-1, i) * matriz.getValor(0, i) * determinante(menorComplementar(matriz, 0, i));
		}
		
		return determinante;
	}
	
	// Funcao auxiliar para calculo do determinante:
	private static Matriz menorComplementar(Matriz matriz, int linhaX, int colunaX) {
		
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
}