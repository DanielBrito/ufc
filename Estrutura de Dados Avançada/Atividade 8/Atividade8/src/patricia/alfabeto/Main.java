package patricia.alfabeto;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.text.Normalizer;
import java.util.ArrayList;

public class Main {

	private static BufferedReader br;
	static long inicio, fim;

	public static void main(String[] args) throws FileNotFoundException, IOException {
		
		inicio = System.currentTimeMillis();
		
		PatriciaTrieAlfabeto arvore = new PatriciaTrieAlfabeto(128);
		
		FileReader arquivo = new FileReader("arquivo1_cadeias.txt");
	    
		br = new BufferedReader(arquivo);

        String linha;
        ArrayList<String> palavras = new ArrayList<String>();
        
        while ((linha = br.readLine()) != null) {
        	
        	linha = normalizar(linha);
        	
        	arvore.inserir(linha);
        	palavras.add(linha);
        }
		
		palavras.add("amo"); // Teste - Não presente no arquivo
		
		System.out.println("Pesquisando...\n");
		
		for(int i=0; i<palavras.size(); i++) {
			
			System.out.print(palavras.get(i));
			
			arvore.procurar(palavras.get(i));
		}
		
		fim = System.currentTimeMillis();
		
		System.out.println("\nTempo de execução: " + (fim-inicio) + "ms");
    }
	
	public static String normalizar(String palavra){
		
	    palavra = Normalizer.normalize(palavra, Normalizer.Form.NFD);
	    palavra = palavra.replaceAll("[\\p{InCombiningDiacriticalMarks}+-]", "");
	    
	    return palavra.toLowerCase();
	}
}