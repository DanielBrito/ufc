/* Classe principal que enviará o endereço do código-fonte para o método gerador da tabela de símbolos. */

package com.br.projeto;

import java.io.File;

public class Main {

	public static void main(String[] args) throws ComentarioException {
		
		String enderecoArquivo = new File("src/Hello.txt").getAbsolutePath();
		
		TabelaDeSimbolos.gerarTabela(enderecoArquivo);
	}
}
