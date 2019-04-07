/* Classe que define as informações iniciais dos dados lidos do arquivo. */

package com.br.projeto;

public class Mapeamento {
	
	String simbolo;
	int numLinha;
	
	Mapeamento(String simbolo, int numLinha){
		
		this.simbolo = simbolo;
		this.numLinha = numLinha;
	}
	
	@Override
	public String toString() {
		
		return "Linha: " + numLinha + " | Simbolo: " + simbolo;
	}
}
