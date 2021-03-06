/* Classe que far� a leitura de um arquivo e armazenar� os dados em uma lista que ser� utilizada pela classe TabelaDeSimbolos. */

package executar;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import analisador_lexico.Mapeamento;

public class Arquivo {

	static List<Mapeamento> simbolos = new ArrayList<Mapeamento>();
	static int escopo=0;

	public static List<Mapeamento> lerArquivo(String enderecoArquivo){
		
		String linha="";
		int numLn=0;

		System.out.println("Arquivo = " + enderecoArquivo);
		
		try {
			
			FileReader arquivo = new FileReader(enderecoArquivo);
			BufferedReader lerArquivo = new BufferedReader(arquivo);
			
			while (linha!=null) {
				
				
				listarElementos(linha, numLn++);
				linha = lerArquivo.readLine();
				
			}

			arquivo.close();
		} 
		catch (IOException e) {
			
			System.err.println("Erro na abertura do arquivo: " + e.getMessage());
		}
		
		return simbolos;
	}
	
	private static void listarElementos(String linha, int ln) {
		
		String[] str = linha.split(" ");
		
		for(int i=0; i<str.length; i++) {
			
			if(str[i].length()>0) {
				
				if(str[i].equals("{")) {
					
					++escopo;
				}
				else
				if(str[i].equals("}")) {
					
					--escopo;
				}
				
				Mapeamento m = new Mapeamento(str[i], ln, escopo);
				
				simbolos.add(m);
			}
		}
	}
}
