/* Classe que fará a leitura de um arquivo e armazenará os dados em uma lista que será utilizada pela classe TabelaDeSimbolos. */

package com.br.projeto;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Arquivo {

	static List<Mapeamento> simbolos = new ArrayList<Mapeamento>();

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
				
				Mapeamento m = new Mapeamento(str[i], ln);
				
				simbolos.add(m);
			}
		}
	}
}
