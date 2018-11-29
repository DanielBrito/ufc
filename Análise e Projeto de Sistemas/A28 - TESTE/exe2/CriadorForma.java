package com.br.exe2;

public class CriadorForma {
	
	private Forma retangulo;
	private Forma triangulo;
	private Forma circulo;
	
	public CriadorForma() {
		
		circulo = new Circulo();
		triangulo = new Triangulo();
		retangulo = new Retangulo();		
	}
	
	public void desenharRetangulo() {
		
		retangulo.desenhar();
	}
	
	public void desenharTriangulo() {
		
		triangulo.desenhar();
	}
	
	public void desenharCirculo() {
		
		circulo.desenhar();
	}
}
