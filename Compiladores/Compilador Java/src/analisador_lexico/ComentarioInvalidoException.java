/* Classe referente ao tratamento de exceções de comentários incorretos. */

package analisador_lexico;

public class ComentarioInvalidoException extends Exception {

	private static final long serialVersionUID = 1L;
	private static String linha;
	
	@Override
	public String getMessage(){
		
		return "\nErro léxico na linha " + linha + ": Comentário aberto e não fechado.";
	}
	
	public ComentarioInvalidoException(String msgLinha) {
		
		linha = msgLinha;
		getMessage();
	}
}