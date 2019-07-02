/* Classe para tratar a expressão digitada e criar o código de três endereços */

package iii_enderecos;

import java.util.Stack;

public class CodigoTresEnderecos {
	
	static int index=1;
	
	public static void imprimirProcesso(String variavel, String expressao) {
		
		Quadrupla raiz = tratarExpressao(expressao);
		
		System.out.print("\nPos-ordem: ");
	    ImprimirPosOrdem(raiz);
	    
	    System.out.println("\n\nCodigo de 3 enderecos:");
	    imprimirCodigo(raiz);
	    System.out.println(variavel + " = " + raiz.termo);
	}
	
	public static Quadrupla tratarExpressao(String expressao) {
		
		Stack<Character> pilhaElemento = new Stack<Character>();
	    Stack<Quadrupla> pilhaTermo = new Stack<Quadrupla>();
	
	    Character c;
	    
	    for (int i=0;i<expressao.length();i++){
	
	        c = expressao.charAt(i);
	
	        if (c=='('){
	        	
	            pilhaElemento.push(c);
	        }
	        else 
	        if (Character.isDigit(c) || Character.isAlphabetic(c)){
	        	
	            pilhaTermo.push(new Quadrupla(c));
	        }
	        else 
	        if (verificarOperador(c)){
	
	            while (Operador.getOperatorPrecedence(Pilha.getTopOfOperator(pilhaElemento)) >= Operador.getOperatorPrecedence(c)) {
	            	
	                Character operador = pilhaElemento.pop();
	                Quadrupla e2 = pilhaTermo.pop();
	                Quadrupla e1 = pilhaTermo.pop();
	
	                pilhaTermo.push(new Quadrupla(operador, e1, e2, "E"+index++));
	            }
	
	            pilhaElemento.push(c);
	        }
	        else 
	        if (c==')'){
	
	                while (Pilha.getTopOfOperator(pilhaElemento) != '(') {
	
	                    Character operador = pilhaElemento.pop();
	                    Quadrupla e2 = pilhaTermo.pop();
	                    Quadrupla e1 = pilhaTermo.pop();
	
	                    pilhaTermo.push(new Quadrupla(operador, e1, e2, "E"+index++));
	                }
	
	            pilhaElemento.pop();
	        }
	    }
	
	    while(!pilhaElemento.empty()){
	    	
	        Character operator=pilhaElemento.pop();
	        Quadrupla e2=pilhaTermo.pop();
	        Quadrupla e1=pilhaTermo.pop();
	        
	        pilhaTermo.push(new Quadrupla(operator,e1,e2,"E"+index++));
	    }
	   
	    return pilhaTermo.pop();
	}
	
	public static void imprimirCodigo(Quadrupla raiz){
	    	
	    if (verificarOperador(raiz.operador)){
	        	
        	imprimirCodigo(raiz.operando1);
        	imprimirCodigo(raiz.operando2);
        	
            System.out.println(raiz.termo + " = " + raiz.operando1.termo + " " + raiz.operador  + " " + raiz.operando2.termo);
	    }
	}
	
	public static void ImprimirPosOrdem(Quadrupla raiz){
		
	    if (raiz.operando1!=null){
	    	
	    	ImprimirPosOrdem(raiz.operando1);
	    }
	
	    if (raiz.operando2!=null){
	    	
	    	ImprimirPosOrdem(raiz.operando2);
	    }
	    
	    System.out.print(raiz.operador);
	}
	
	public static boolean verificarOperador(Character c){
		
		return c=='+' || c=='-' || c=='*' || c=='/';
	}
}
