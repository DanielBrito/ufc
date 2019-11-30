package patricia.alfabeto;

import java.util.Arrays;

public class PatriciaTrieAlfabeto {
       
    private static abstract class PatriciaNo { }
    
    public static class PatriciaNoInterno extends PatriciaNo {
    	
        int index; 
        PatriciaNo esq, dir;
    }  
    
    public static class PatriciaNoExterno extends PatriciaNo {
    	
        byte[] chave;
    }
  
    private PatriciaNo raiz;
    private int nbitsChave;
    
    public PatriciaTrieAlfabeto(int nbitsChave) {
    	
        this.raiz = null; 
        this.nbitsChave = nbitsChave; 
    }

    private boolean verificarNoExterno(PatriciaNo p) {   
        
        return p.getClass().getName().equals(PatriciaNoExterno.class.getName());
    }

    private PatriciaNo criaNoInterno(int i, PatriciaNo esq, PatriciaNo dir) {
    	
        PatriciaNoInterno p = new PatriciaNoInterno();
        
        p.index = i; 
        p.esq = esq; 
        p.dir = dir;
        
        return p;
    }

    private PatriciaNo criaNoExterno(byte[] b) {
    	
        PatriciaNoExterno p = new PatriciaNoExterno();
        
        p.chave = b;
        
        return p;
    }
  
    private PatriciaNo inserirEntre(byte[] b, PatriciaNo no, int i) {
    	
        PatriciaNoInterno aux = null; 
        
        if (!verificarNoExterno(no)) {
        	
        	aux = (PatriciaNoInterno)no;
        }
        
        if (verificarNoExterno (no) || (i < aux.index)) {
	        
        	PatriciaNo p = criaNoExterno (b);
        	
        	return (b[i]==1) ? criaNoInterno(i, no, p) : criaNoInterno(i, p, no);
        }
        else {
        	
            if (b[aux.index]==1) {
            	
            	aux.dir = inserirEntre(b, aux.dir, i);
            }
            else {
            	
            	aux.esq = inserirEntre(b, aux.esq, i);
            }
            
            return aux;        	
        }
    }
  
    private PatriciaNo inserir(byte[] b, PatriciaNo no) {
    	
        if (no == null) {
        	
        	return criaNoExterno(b);
        }
        else {
        	
            PatriciaNo p = no;
            
            while (!verificarNoExterno (p)) {
            	
                PatriciaNoInterno aux = (PatriciaNoInterno)p;
                
                p = (b[aux.index]==1) ? aux.dir : aux.esq;
            }
            
            PatriciaNoExterno aux = (PatriciaNoExterno)p;
            
            int i = 0;
            
            while ((i < nbitsChave)&&(b[i] == aux.chave[i])) {
            	
            	i++;
            }
            
            if (i >= nbitsChave) {
                
                return no;
            }
            else {
            	
                return inserirEntre (b, no, i);
            }
        }
    }
 
    private void pesquisar(byte[] b, PatriciaNo no) {
    	
        if (verificarNoExterno (no)) {
        	
            PatriciaNoExterno aux = (PatriciaNoExterno)no;
            
            if (Arrays.equals(aux.chave, b)){
            	
                System.out.println(": encontrada");
            }
            else {
            	
            	System.out.println(": nao encontrada");
            }
        }
        else { 
        	
            PatriciaNoInterno aux = (PatriciaNoInterno)no;
            
            if (b[aux.index]== 0) {
            	
            	pesquisar (b, aux.esq);
            }
            else {
            	
            	pesquisar (b, aux.dir);
            }
        }
    }
    
    public void procurar(String palavra){

        byte[] aux;
        aux = transforma(palavra);
        
        pesquisar(aux, this.raiz);
    }
    
    private void inserir(byte[] b) {
    	
        this.raiz = inserir(b, this.raiz); 
    } 

    public void inserir(String palavra){

        byte[] aux;

        aux = transforma(palavra);
        
        inserir(aux);
    }  
    
    byte[] transforma(String palavra){
    	
 	   byte[] bits = new byte[128];
 	
 	   int intAux, i;
 	   char charAux;
 	   String stringAux = null;
 	   StringBuilder strBuilder = new StringBuilder(128);
 	
 	   for (i=0; i<16; i++){
 		   
 	        if(i>=palavra.length()){
 	
 	            strBuilder.append("00000000");
 	        }
 	        else{
 	
 	            charAux = palavra.charAt(i);
 	            
 	            stringAux = Integer.toBinaryString(charAux);
 	            
 	            intAux = Integer.toBinaryString(charAux).length();
 	            
 	            while(intAux!=8){
 	
 	                stringAux = "0"+stringAux;
 	                intAux++;
 	            }
 	            
 	            strBuilder.append(stringAux);  
 	        }     
 	    }
 	   
 	    stringAux = strBuilder.toString();
 	    
 	    for(i=0; i<128; i++){
 	    	
 	        charAux = stringAux.charAt(i);
 	        byte byteAux = (byte)charAux;
 	        byteAux -= 48;
 	        bits[i] = byteAux;
 	    }
 	   
 	    return bits;
 	}
}