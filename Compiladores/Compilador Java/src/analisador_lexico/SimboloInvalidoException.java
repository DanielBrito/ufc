/* Classe referente ao tratamento de exceções de símbolos inválidos. */

package analisador_lexico;

public class SimboloInvalidoException extends Exception{
	
	private static final long serialVersionUID = 1L;
	private static String linha;
	private static String simbolo;
	
	@Override
	public String getMessage(){
		
		return "\nErro léxico na linha " + linha + ". Símbolo inválido: " + simbolo;
	}
	
	public SimboloInvalidoException(String msgLinha, String msgSimbolo) {
		
		linha = msgLinha;
		simbolo = msgSimbolo;
		getMessage();
	}
}
