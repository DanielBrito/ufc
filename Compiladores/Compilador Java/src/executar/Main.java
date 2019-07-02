/* Classe principal que enviará o endereço do código-fonte para o método gerador da tabela de símbolos. */

package executar;

import java.io.File;

import analisador_lexico.ComentarioInvalidoException;
import analisador_lexico.SimboloInvalidoException;
import analisador_lexico.TabelaDeSimbolos;
import analisador_semantico.ErroSemanticoException;
import analisador_sintatico.ErroSintaticoException;

public class Main {

	public static void main(String[] args) throws ComentarioInvalidoException, SimboloInvalidoException, ErroSintaticoException, ErroSemanticoException {
		
		String enderecoArquivo = new File("src/TesteSintaticoSemantico.txt").getAbsolutePath();
		
		TabelaDeSimbolos.gerarTabela(enderecoArquivo);
		
		System.out.println("Código compilado!");		
	}
}
