/* Classe referente ao tratamento de exceções de erros sintáticos. */

package analisador_sintatico;

public class ErroSintaticoException extends Exception {
	
	private static final long serialVersionUID = 1L;
	private static String linha;
	private static String simbolo;
	
	@Override
	public String getMessage(){
		
		return "\nErro sintático na linha: " + linha + ". " + simbolo;
	}
	
	public ErroSintaticoException(String msgLinha, String msgSimbolo) {
		
		linha = msgLinha;
		simbolo = msgSimbolo;
		getMessage();
	}
}
