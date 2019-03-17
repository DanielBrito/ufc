package com.br.projeto;

import java.util.List;

public class Main {

	public static void main(String[] args) {
		
		List<String> tokens;
		
		String enderecoArquivo = "C:\\Users\\Daniel\\Codes\\Photon-Entreprise-Workspace\\Compiladores\\src\\Hello.txt";
		
		tokens = Arquivo.lerArquivo(enderecoArquivo);
		
		System.out.println("\nTOKENS DO ARQUIVO:\n");
		
		for(String t : tokens) {
			
				System.out.println(t);
		}
	}
}
