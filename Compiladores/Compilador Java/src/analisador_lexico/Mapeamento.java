/* Classe que define as informações iniciais dos dados lidos do arquivo. */

package analisador_lexico;

public class Mapeamento {
	
	String simbolo;
	int numLinha;
	int escopo;
	
	public Mapeamento(String simbolo, int numLinha, int escopo){
		
		this.simbolo = simbolo;
		this.numLinha = numLinha;
		this.escopo = escopo;
	}
	
	@Override
	public String toString() {
		
		return "Linha: " + numLinha + " | Simbolo: " + simbolo + " | Escopo: " + escopo;
	}
}
