package patricia.binario;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class Main {
	
	private static BufferedReader br;
	static long inicio, fim;

	public static void main(String[] args) throws FileNotFoundException, IOException {
		
		inicio = System.currentTimeMillis();
		
		PatriciaTrieBinario arvore = new PatriciaTrieBinario();
		
		FileReader arquivo = new FileReader("arquivo2_ASCII.txt");
	    
		br = new BufferedReader(arquivo);

		String linha;
        ArrayList<String> binarios = new ArrayList<String>();
        
        while ((linha = br.readLine()) != null) {
        	
        	String[] str = new String[4];

        	str = linha.split(" ");
        	String binario = charParaBinario(str[0].charAt(0));

        	arvore.inserir(binario);
        	binarios.add(binario);
        }
        
        binarios.add("00110011"); // Teste - Não presente no arquivo
		
		System.out.println("Pesquisando...\n");
		
		for(int i=0; i<binarios.size(); i++) {
			
			if(arvore.procurar(binarios.get(i))) {
				
				System.out.println(binarios.get(i) + ": encontrado");
			}
			else {
				
				System.out.println(binarios.get(i) + ": nao encontrado");
			}
		}
		
		fim = System.currentTimeMillis();
		
		System.out.println("\nTempo de execução: " + (fim-inicio) + "ms");
    }
	
	static String charParaBinario(char c) {
		
		String binario = Integer.toBinaryString(c);
		
		while (binario.length()!=8) {
        	
        	binario = "0" + binario;        	
        }
			
		return binario;
	}
}
