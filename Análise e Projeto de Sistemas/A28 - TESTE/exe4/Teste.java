package com.br.exe4;

/*

Neste exercício, com base na motivação e nas características do padrão de projeto 
Iterator, é criada uma interface Iterator, que é utilizado como um método de navegação, 
e uma interface Colecao, que retorna o iterador.

Classes concretas que implementam a interface Colecao ficarão responsáveis por
implementar e utilizar o Iterator.

No final, o RepositorioDisciplinas - uma implementação de uma classe concreta 
para exibir disciplinas armazenadas como uma coleção em um RepositorioDisciplinas -
é utilizado para exibir as informações.

*/

public class Teste {

	public static void main(String[] args) {
		
		RepositorioDisciplinas disciplinas = new RepositorioDisciplinas();
		
		for(Iterator i = disciplinas.getIterator(); i.hasNext();) {
			
			String nome = (String)i.next();
			System.out.println("Disciplina: " + nome);
		}
	}
}
