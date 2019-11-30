package eda.atividade9;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.PriorityQueue;

public class BMH {
	
	static long inicio, fim;
	static final int NUM_CARACTERES = 256;

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
			
			ocorrencias.add(new Palavra(palavra, bmh(texto, palavra)));
		}
		
		System.out.println("Dez palavras mais frequentes no texto:\n");
		
		for(int i=0; i<10; i++) {
			
			System.out.println((i+1) + "a -> " + ocorrencias.peek());
			ocorrencias.poll();
		}
		
		fim = System.currentTimeMillis();
		
		System.out.println("\nTempo de execução: " + (fim-inicio) + "ms");
	}
	
	public static int bmh(String texto, String padrao) {
		
		int tamanhoPadrao = padrao.length();
		int tamanhoTexto = texto.length();
		int contOcorrencia = 0;
		
		int[] tabela = new int[NUM_CARACTERES];
		
		int i, j, k;
		
		for(j=0; j<NUM_CARACTERES; j++) {
			
			tabela[j] = tamanhoPadrao;			
		}
		
		for(j=0; j<tamanhoPadrao-1; j++) {
			
			tabela[(int)padrao.charAt(j)] = tamanhoPadrao-j-1;
		}
		
		i = tamanhoPadrao-1;
		
		while(i<tamanhoTexto-1) {
			
			k = i;
			j = tamanhoPadrao-1;
			
			while((j>=0) && (texto.charAt(k)==padrao.charAt(j))) {
				
				k--;
				j--;
			}
			
			if(j<0) {
				
				++contOcorrencia;
			}
			
			i = i+tabela[(int)texto.charAt(i)];
		}
		
		
	
		return contOcorrencia;
	}
}
