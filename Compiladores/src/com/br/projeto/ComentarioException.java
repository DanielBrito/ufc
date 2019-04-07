/* Classe referente ao tratamento de exceções de comentários incorretos. */

package com.br.projeto;

public class ComentarioException extends Exception {

	private static final long serialVersionUID = 1L;
	private static String linha;
	
	@Override
	public String getMessage(){
		
		return "Erro: Comentário aberto e não fechado na linha " + linha;
	}
	
	public ComentarioException(String mensagem) {
		
		linha = mensagem;
		getMessage();
	}
}