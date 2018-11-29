package com.br.exe3;

/*

Neste exercício é criada uma interface Personagem e algumas classes concretas (Guerreiro, Mago)
implementando a interface Personagem. 

A partir daí, com base na motivação e nas características do padrão de projeto Decorator, é 
criada uma a classe abstrata PersonagemDecorator implementando a interface Personagem, que 
tem um objeto Personagem como sua variável de instância. As classes concretas EspadaDecorator
e PocaoDecorator implementam PersonagemDecorator.

No final, são utilizadas EspadaDecorator e PocaoDecorator para decorar alguns objetos instanciados.

*/

public class Teste {

	public static void main(String[] args) {

		Personagem orc = new Guerreiro();
		Personagem reiArthur = new EspadaDecorator(new Guerreiro());
		Personagem severusSnape = new PocaoDecorator(new Mago());
		
		System.out.println();
		orc.criar();
		
		System.out.println();
		reiArthur.criar();
		
		System.out.println();
		severusSnape.criar();		
	}
}
