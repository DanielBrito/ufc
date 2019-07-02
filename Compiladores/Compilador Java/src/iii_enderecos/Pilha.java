/* Classe para representar a pilha na geração do código de 3 endereços. */

package iii_enderecos;
import java.util.Stack;

public class Pilha {

    public static Character getTopOfOperator(Stack<Character> pilha){
    	
        if (pilha.isEmpty()){
        	
            return 'e';
        }
        
        return pilha.peek();
    }
}
