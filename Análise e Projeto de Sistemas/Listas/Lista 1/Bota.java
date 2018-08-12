package com.br.lista1;

public class Bota{
	
	private int tamanho;
	private char lado;
	private boolean verificada;

	Bota(int tamanho, char lado){

		this.tamanho = tamanho;
		this.lado = lado;
		this.verificada = false;
	}
	
	public char getLado() {
		
		return lado;
	}
	
	public int getTamanho() {
		
		return tamanho;
	}
	
	public boolean getStatus() {
		
		return verificada;
	}
	
	public void setStatus(Bota bota) {
		
		bota.verificada = true;
	}
	
	public String ToString(){

		return tamanho + " " + lado;
	}
}
