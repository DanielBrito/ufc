/* Classe referente ao tratamento de exceções de erros semânticos. */

package analisador_semantico;

public class ErroSemanticoException extends Exception {
	
	private static final long serialVersionUID = 1L;
	private static String linha;
	private static String simbolo;
	
	@Override
	public String getMessage(){
		
		return "\nErro semântico na linha: " + linha + ". " + simbolo;
	}
	
	public ErroSemanticoException(String msgLinha, String msgSimbolo) {
		
		linha = msgLinha;
		simbolo = msgSimbolo;
		getMessage();
	}
}
