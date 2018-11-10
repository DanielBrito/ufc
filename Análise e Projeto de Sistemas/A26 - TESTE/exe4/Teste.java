package com.br.exe4;

public class Teste {

	public static void main(String[] args) {
		
		Forma circuloVermelho = new Circulo(50, 30, 30, new CirculoVermelho()); // raio, x, y
		Forma circuloVerde = new Circulo(10, 100, 100, new CirculoVerde()); // raio, x, y
		
		circuloVermelho.criar();
		circuloVerde.criar();
	}
}
