package com.br.exe2;

/*

Neste exercício é criada uma classe Forma e algumas classes concretas (Circulo, Retangulo, Triangulo) 
implementando a interface Forma.

Com base na motivação e nas características do padrão de projeto Façade, a classe criadorForma utiliza 
as classes concretas para delegar chamadas de usuário a estas classes.

No final, a classe criadorForma é utilizada para mostrar os resultados da execução para cada uma das
formas referentes às classes concretas.

*/

public class Teste {

	public static void main(String[] args) {

		CriadorForma criadorForma = new CriadorForma();
		
		criadorForma.desenharCirculo();
		criadorForma.desenharRetangulo();
		criadorForma.desenharTriangulo();
	}
}