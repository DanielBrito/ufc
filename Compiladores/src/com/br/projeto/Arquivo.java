package com.br.projeto;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Arquivo {

	static List<String> elementos = new ArrayList<String>();

	public static List<String> lerArquivo(String enderecoArquivo){
		
		String linha="";

		System.out.println("Arquivo = " + enderecoArquivo);
		
		try {
			
			FileReader arquivo = new FileReader(enderecoArquivo);
			BufferedReader lerArquivo = new BufferedReader(arquivo);
			
			while (linha!=null) {
				
				listarElementos(linha);

				linha = lerArquivo.readLine();
			}

			arquivo.close();
			
		} catch (IOException e) {
			
			System.err.printf("Erro na abertura do arquivo: %s.\n", e.getMessage());
		}
		
		return elementos;
	}
	
	private static void listarElementos(String linha) {
		
		String[] str = linha.split(" ");
		
		for(int i=0; i<str.length; i++) {
			
			if(str[i].length()>0) {
				
				elementos.add(str[i]);
			}
		}
	}
}
