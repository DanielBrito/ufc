/* Classe que define os campos que constituem uma linha da tabela de símbolos. */

package analisador_lexico;

public class Elemento {
	
	Token token;
	String lexema;
	int linha;
	int escopo;
	
	Elemento(Token token, String lexema, int linha, int escopo){
		
		this.token = token;
		this.lexema = lexema;
		this.linha = linha;
		this.escopo = escopo;
	}
	
	public Token getToken() {
		
		return token;
	}
	
	public String getLexema() {
		
		return lexema;
	}
	
	public int getLinha() {
		
		return linha;
	}
	
	public int getEscopo() {
		
		return escopo;
	}
	
	@Override
	public String toString() {
		
		return token.toString() + "Lexema: " + lexema + " | Linha: " + linha + " | Escopo: " + escopo;
	}
}
