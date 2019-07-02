/* Classe para controlar cada uma dos identificadores declarados no decorrer do programa. */

package analisador_lexico;

public class Identificador {
	
	String tipoId;
	String id;
	int escopo;
	int linha;

	Identificador(String tipoId, String id, int escopo, int linha) {
		
		this.tipoId = tipoId;
		this.id = id;
		this.escopo = escopo;
		this.linha = linha;
	}
	
	public String toString() {
		
		return "tipoId: " + tipoId + " | id: " + id + " | escopo: " + escopo + " | linha: " + linha;
	}
	
	public String getTipoId() {
		
		return tipoId;
	}
	
	public String getId() {
		
		return id;
	}
	
	public int getEscopo() {
		
		return escopo;
	}
	
	public int getLinha() {
		
		return linha;
	}
}
