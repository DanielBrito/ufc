package com.br.lista1;

public class Bota{
	
	private int tamanho;
	private char lado;
	private boolean contada;

	Bota(int tamanho, char lado){

		this.tamanho = tamanho;
		this.lado = lado;
		this.contada = false;
	}
	
	public char getLado() {
		
		return lado;
	}
	
	public int getTamanho() {
		
		return tamanho;
	}
	
	public boolean getStatus() {
		
		return contada;
	}
	
	public void setContada(Bota bota) {
		
		bota.contada = true;
	}
}
