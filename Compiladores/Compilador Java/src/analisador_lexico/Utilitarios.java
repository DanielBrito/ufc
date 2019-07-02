package analisador_lexico;

import java.util.List;

public class Utilitarios {
	
	public static Elemento getElementoAtual(List<Elemento> tabelaDeSimbolos) {
		
		return tabelaDeSimbolos.get(0);
	}
	
	public static Elemento getProximoElemento(List<Elemento> tabelaDeSimbolos) {
		
		return tabelaDeSimbolos.get(1);
	}
	
	public static void removerElementoAtual(List<Elemento> tabelaDeSimbolos) {
		
		tabelaDeSimbolos.remove(0);
	}
	
	public static boolean verificaTabelaVazia(List<Elemento> tabelaDeSimbolos) {
		
		return tabelaDeSimbolos.isEmpty();
	}
}
