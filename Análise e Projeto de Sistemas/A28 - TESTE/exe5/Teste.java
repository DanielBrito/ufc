package com.br.exe5;

/*

Neste exercício é criada uma interface Imagem e algumas classes concretas (ImagemReal, ImagemProxy)
que implementam a interface Imagem.

Com base na motivação e nas características do padrão de projeto Proxy, ImagemProxy é uma classe de 
proxy para reduzir o consumo de memória do carregamento em relação aos objetos ImagemReal.

No final, ProxyImage é utilizado para obter um objeto Imagem para carregar e exibir sempre que
for necessário.

*/

public class Teste {

	public static void main(String[] args) {

		Imagem img = new ImagemProxy("profile.jpg");
		
		// Carregada do disco
		img.exibir();
		System.out.println("");
		
		// Não carregada do disco
		img.exibir();
	}
}
