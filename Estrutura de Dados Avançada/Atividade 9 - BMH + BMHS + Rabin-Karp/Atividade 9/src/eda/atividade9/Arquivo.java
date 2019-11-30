package eda.atividade9;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Arquivo {
	
	private static String texto = "";
	private static BufferedReader br;
	
	public static String lerArquivo(String enderecoArquivo) throws IOException {
		
		FileReader arquivo = new FileReader(enderecoArquivo);
	    
		br = new BufferedReader(arquivo);
		
		String textoArquivo;
		
        while ((textoArquivo = br.readLine()) != null) {
        	
        	texto += textoArquivo;
        }
		
		return texto.toLowerCase();
	}

}
