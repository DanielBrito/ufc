package rway.alfabeto;

public class TrieAlfabeto { 
	
    static final int ALFABETO = 26; 
      
    public static class TrieNoAlfabeto{ 
    	
        TrieNoAlfabeto[] filhos = new TrieNoAlfabeto[ALFABETO]; 
        boolean fimPalavra; 
          
        TrieNoAlfabeto(){
        	
            fimPalavra = false; 
            
            for (int i=0; i<ALFABETO; i++) {
            	
            	filhos[i] = null;            	
            } 
        } 
        
        void inserir(TrieNoAlfabeto raiz, String chave) { 
        	
            int index; 
           
            TrieNoAlfabeto aux = raiz; 
           
            for (int i = 0; i<chave.length(); i++) { 
            	
                index = caractereParaDecimal(chave.charAt(i)); 
                
                if (aux.filhos[index]==null) {
                	
                	aux.filhos[index] = new TrieNoAlfabeto(); 
                }
           
                aux = aux.filhos[index]; 
            } 
           
            aux.fimPalavra = true; 
        }
        
        boolean procurar(TrieNoAlfabeto raiz, String chave) {
        	
            int index; 
            
            TrieNoAlfabeto aux = raiz; 
           
            for (int i=0; i<chave.length(); i++) { 
            	
                index = caractereParaDecimal(chave.charAt(i)); 
           
                if (aux.filhos[index] == null) {
                	
                    return false; 
                }
           
                aux = aux.filhos[index]; 
            } 
           
            return (aux != null && aux.fimPalavra); 
        }
        
        static int caractereParaDecimal(char letra) {
        	
        	return letra-'a';
        }
        
    	static char decimalParaCaractere(int numero){
    		
    		numero = numero+'a';
    		char letra = (char)numero;
    		
    		return letra;
    	}
    }
}
