/* Classe para representar cada uma das linha da tabela do código de 3 endereços. */

package iii_enderecos;

public class Quadrupla {
	
	String termo;
    Quadrupla operando1;
    Quadrupla operando2;
    Character operador;
    
    Quadrupla(Character operando){
    	
        this.termo = operando + "";
        this.operador = operando;
    }

    Quadrupla(Character operador, Quadrupla e1, Quadrupla e2, String termo){
    	
        this.operando1 = e1;
        this.operando2 = e2;
        this.operador = operador;
        this.termo = termo;
    }
}
