/* Classe que define os campos que constituem um token. */

package com.br.projeto;

public class Token {
	
	String tipo;
	String valor;
	
	Token(String tipo, String valor){
		
		this.tipo = tipo;
		this.valor = valor;
	}
	
	@Override
	public String toString() {
		
		return "Tipo: " + tipo + " | Valor: " + valor + " | ";
	}
}
