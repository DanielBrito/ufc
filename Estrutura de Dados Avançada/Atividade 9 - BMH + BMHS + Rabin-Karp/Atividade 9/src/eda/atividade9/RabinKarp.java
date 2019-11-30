package eda.atividade9;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.PriorityQueue;

public class RabinKarp {
	
	static long inicio, fim;
	static final int NUM_CARACTERES = 256;
	static final long PRIMO = 27;

	public static void main(String[] args) throws IOException {
		
		inicio = System.currentTimeMillis();
		 
		String texto = Arquivo.lerArquivo("Texto3.txt");
		String delimitadores = "[\\s|,|.]";
		
		ArrayList<String> palavras = new ArrayList<String>();
		
		PriorityQueue<Palavra> ocorrencias = new PriorityQueue<Palavra>(Collections.reverseOrder());		
		
		String tokens[] = texto.split(delimitadores);
		
		for(int i=0; i<tokens.length; i++) {
			
			if(tokens[i].length()!=0) {
				
				if(!palavras.contains(tokens[i])) {
					
					palavras.add(tokens[i]);
				}
			}
		}
		
		for(String palavra : palavras) {
			
			ocorrencias.add(new Palavra(palavra, rabinKarp(texto, palavra)));
		}
		
		System.out.println("Dez palavras mais frequentes no texto:\n");
		
		for(int i=0; i<10; i++) {
			
			System.out.println((i+1) + "a -> " + ocorrencias.peek());
			ocorrencias.poll();
		}
		
		fim = System.currentTimeMillis();
		
		System.out.println("\nTempo de execução: " + (fim-inicio) + "ms");
	}
	
	static int rabinKarp(String texto, String padrao){ 
		
		
		int tamanhoPadrao = padrao.length(); 
		int tamanhoTexto = texto.length(); 
		int i, j, contOcorrencias=0;
		long padraoHash=0, textoHash = 0, h=1;

		for(i=0; i<tamanhoPadrao-1; i++) { 

			h = (h*NUM_CARACTERES)%PRIMO; 
		}

		for(i=0; i<tamanhoPadrao; i++) { 

			padraoHash = (NUM_CARACTERES*padraoHash + padrao.charAt(i))%PRIMO; 
			textoHash = (NUM_CARACTERES*textoHash + texto.charAt(i))%PRIMO; 
		} 

		for(i=0; i<=tamanhoTexto-tamanhoPadrao; i++){ 

			if(padraoHash==textoHash) { 

				for(j=0; j<tamanhoPadrao; j++) { 

					if(texto.charAt(i+j)!=padrao.charAt(j)) break;
				} 

				if(j==tamanhoPadrao) ++contOcorrencias;
			} 

			if(i<tamanhoTexto-tamanhoPadrao){ 

				textoHash = (NUM_CARACTERES*(textoHash-texto.charAt(i)*h) + texto.charAt(i+tamanhoPadrao))%PRIMO; 

				if(textoHash<0) {

					textoHash = (textoHash+PRIMO); 
				}
			} 
		}

		return contOcorrencias;
	}
}
