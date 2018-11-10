package com.br.exe4;

public class Circulo extends Forma {
	
	private int raio, x, y;
	
	public Circulo(int raio, int x, int y, Desenhar desenhar) {
		
		super(desenhar);
		this.x = x;
		this.y = y;
		this.raio = raio;
	}	

	@Override
	public void criar() {

		desenhar.desenharCirculo(raio, x, y);
	}
}
