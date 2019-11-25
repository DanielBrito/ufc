package rway.binario;

public class TrieBinario { 
	
    static final int BINARIO = 2; 
      
    public static class TrieNoBinario{ 
    	
        TrieNoBinario[] filhos = new TrieNoBinario[BINARIO]; 
        boolean fimPalavra; 
          
        TrieNoBinario(){
        	
            fimPalavra = false; 
            
            for (int i = 0; i < BINARIO; i++) {
            	
            	filhos[i] = null;            	
            } 
        } 
        
        void inserir(TrieNoBinario raiz, String chave) { 
        	
            int index; 
           
            TrieNoBinario aux = raiz; 
           
            for (int i=0; i<chave.length(); i++) { 
            	
                index = Character.getNumericValue(chave.charAt(i)); 
                
                if (aux.filhos[index]==null) {
                	
                    aux.filhos[index] = new TrieNoBinario(); 
                }
           
                aux = aux.filhos[index]; 
            } 
           
            aux.fimPalavra = true; 
        }

        boolean procurar(TrieNoBinario raiz, String chave) {
        	
            int index; 
            TrieNoBinario aux = raiz; 
           
            for (int i=0; i<chave.length(); i++) { 
            	          	
                index = Character.getNumericValue(chave.charAt(i));
           
                if (aux.filhos[index] == null) {
                	
                    return false; 
                }
           
                aux = aux.filhos[index]; 
            } 
           
            return (aux != null && aux.fimPalavra); 
        }
    }
}
