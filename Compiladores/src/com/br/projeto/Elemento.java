/* Classe que define os campos que constituem uma linha da tabela de símbolos. */

package com.br.projeto;

public class Elemento {
	
	Token token;
	String lexema;
	int linha;
	
	Elemento(Token token, String lexema, int linha){
		
		this.token = token;
		this.lexema = lexema;
		this.linha = linha;
	}
	
	@Override
	public String toString() {
		
		return token.toString() + "Lexema: " + lexema + " | Linha: " + linha;
	}
}
