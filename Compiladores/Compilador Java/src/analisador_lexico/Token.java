/* Classe que define os campos que constituem um token. */

package analisador_lexico;

public class Token {
	
	String tipo;
	String valor;
	
	Token(String tipo, String valor){
		
		this.tipo = tipo;
		this.valor = valor;
	}
	
	public String getTipo() {
		
		return tipo;
	}
	
	public String getValor() {
		
		return valor;
	}
	
	@Override
	public String toString() {
		
		return "Tipo: " + tipo + " | Valor: " + valor + " | ";
	}
}
