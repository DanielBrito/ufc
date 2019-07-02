/* Classe que verifica se o código está sintaticamente correto, ou seja, se as produções estão de acordo com a gramática. */

package analisador_sintatico;

import java.util.List;

import analisador_lexico.Classificacao;
import analisador_lexico.Elemento;
import analisador_lexico.TabelaDeSimbolos;
import analisador_lexico.Utilitarios;
import analisador_semantico.ErroSemanticoException;

public class Gramatica {
	
	static Elemento simboloAtual;
	static Elemento proximoSimbolo;
	static String tipoSimboloOperacao;
	
	public static void programa(List<Elemento> tabelaDeSimbolos) throws ErroSintaticoException, ErroSemanticoException {
		
		declClasse(tabelaDeSimbolos);
	}
	
	public static void declClasse(List<Elemento> tabelaDeSimbolos) throws ErroSintaticoException, ErroSemanticoException {
		
		simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
		
		if(!(simboloAtual.getLexema().equals("public"))) {
			
			throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Esperado: public");
		}
		else {
			
			Utilitarios.removerElementoAtual(tabelaDeSimbolos);
		}
		
		simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
		
		if(!(simboloAtual.getLexema().equals("class"))) {
			
			throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Esperado: class");
		}
		else {
			
			Utilitarios.removerElementoAtual(tabelaDeSimbolos);
		}
		
		ident(tabelaDeSimbolos);
		
		corpoClasse(tabelaDeSimbolos);		
	}
	
	public static void corpoClasse(List<Elemento> tabelaDeSimbolos) throws ErroSintaticoException, ErroSemanticoException {
		
		simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
		
		if(!simboloAtual.getLexema().equals("{")) {
			
			throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Esperado: {");
		}
		
		Utilitarios.removerElementoAtual(tabelaDeSimbolos);
		
		declMain(tabelaDeSimbolos);
		
		if(Utilitarios.verificaTabelaVazia(tabelaDeSimbolos)==true) {
			
			throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Esperado: }");
		}
		
		simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
		
		if(!simboloAtual.getLexema().equals("}")) {
			
			throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Esperado: }");
		}
		
		Utilitarios.removerElementoAtual(tabelaDeSimbolos);
		
		if(Utilitarios.verificaTabelaVazia(tabelaDeSimbolos)==false) {
			
			throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Existem símbolos após o término do programa");
		}
	}
	
	public static void declMain(List<Elemento> tabelaDeSimbolos) throws ErroSintaticoException, ErroSemanticoException {
		
		simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
		
		if(!simboloAtual.getLexema().equals("public")) {
			
			throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Esperado: public");
		}
		
		Utilitarios.removerElementoAtual(tabelaDeSimbolos);
		
		simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
		
		if(!simboloAtual.getLexema().equals("static")) {
			
			throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Esperado: static");
		}
		
		Utilitarios.removerElementoAtual(tabelaDeSimbolos);
		
		simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
		
		if(!simboloAtual.getLexema().equals("void")) {
			
			throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Esperado: void");
		}
		
		Utilitarios.removerElementoAtual(tabelaDeSimbolos);
		
		simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
		
		if(!simboloAtual.getLexema().equals("main")) {
			
			throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Esperado: main");
		}
		
		Utilitarios.removerElementoAtual(tabelaDeSimbolos);
		
		simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
		
		if(!simboloAtual.getLexema().equals("(")) {
			
			throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Esperado: (");
		}
		
		Utilitarios.removerElementoAtual(tabelaDeSimbolos);
		
		simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
		
		if(!simboloAtual.getLexema().equals(")")) {
			
			throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Esperado: )");
		}
		
		Utilitarios.removerElementoAtual(tabelaDeSimbolos);
		
		corpoMetodo(tabelaDeSimbolos);
	}
	
	public static void corpoMetodo(List<Elemento> tabelaDeSimbolos) throws ErroSintaticoException, ErroSemanticoException {
		
		simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
		
		if(!simboloAtual.getLexema().equals("{")) {
			
			throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Esperado: {");
		}
		
		Utilitarios.removerElementoAtual(tabelaDeSimbolos);
		
		if(!Utilitarios.getElementoAtual(tabelaDeSimbolos).getLexema().equals("}")) {
			
			declaracao(tabelaDeSimbolos);
		}
		
		simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
		
		if(!simboloAtual.getLexema().equals("}")) {
			
			throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Esperado: }");
		}
		
		Utilitarios.removerElementoAtual(tabelaDeSimbolos);
	}
	
	public static void declaracao(List<Elemento> tabelaDeSimbolos) throws ErroSintaticoException, ErroSemanticoException {
		
		simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
		
		if(tipoDeDado(simboloAtual.getLexema())==true) {
			
			declVar(tabelaDeSimbolos);
		}
		else
		if(verificarIdent(simboloAtual)==true) {
			
			declAtrib(tabelaDeSimbolos);
		}
		else
		if(simboloAtual.getLexema().equals("if")) {

			declIf(tabelaDeSimbolos);
			
			simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
			
			if(!simboloAtual.getLexema().equals("}")) {
				
				throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Esperado: }");
			}
			
			Utilitarios.removerElementoAtual(tabelaDeSimbolos);

			simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
			
			if(simboloAtual.getLexema().equals("else")) {
				
				Utilitarios.removerElementoAtual(tabelaDeSimbolos);
				
				simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
				
				if(!simboloAtual.getLexema().equals("{")) {
					
					throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Esperado: {");
				}
				
				Utilitarios.removerElementoAtual(tabelaDeSimbolos);
				
				declaracao(tabelaDeSimbolos);
				
				simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
				
				if(!simboloAtual.getLexema().equals("}")) {
					
					throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Esperado: }");
				}
				
				Utilitarios.removerElementoAtual(tabelaDeSimbolos);
				
				simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
				
				if(!simboloAtual.getLexema().equals("}")) {
					
					declaracao(tabelaDeSimbolos);
				}
				
			}
			else
			if(!simboloAtual.getLexema().equals("}")) {
				
				declaracao(tabelaDeSimbolos);
			}
		}
		else {
			
			throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Esperado: declaração de variável | declaração de atribuição | declaração de if");
		}
	}
	
	public static void declVar(List<Elemento> tabelaDeSimbolos) throws ErroSintaticoException, ErroSemanticoException {
		
		simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
		
		if(tipoDeDado(simboloAtual.getLexema())==false) {
			
			throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Esperado: tipo de dado");
		}
		
		Utilitarios.removerElementoAtual(tabelaDeSimbolos);
		
		ident(tabelaDeSimbolos);
		
		simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
		
		if(!simboloAtual.getLexema().equals(";")) {
			
			throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Esperado: ;");
		}
		
		Utilitarios.removerElementoAtual(tabelaDeSimbolos);
		
		simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
		
		if(tipoDeDado(simboloAtual.getLexema())==true || verificarIdent(simboloAtual)==true || simboloAtual.getLexema().equals("if")) {
			
			declaracao(tabelaDeSimbolos);
		}
	}
	
	public static void declAtrib(List<Elemento> tabelaDeSimbolos) throws ErroSintaticoException, ErroSemanticoException {
		
		simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
		
		tipoSimboloOperacao = verificarTipoId(simboloAtual);
		
		if(tipoSimboloOperacao==null) {
			
			throw new ErroSintaticoException("" + simboloAtual.getLinha(), "A variável " + simboloAtual.getLexema() + " não foi declarada");
		}
		
		if(validarEscopoIdentificador(simboloAtual)==false) {
			
			throw new ErroSemanticoException("" + simboloAtual.getLinha(), "A variável " + simboloAtual.getLexema() + " não foi declarada");
		}
		
		ident(tabelaDeSimbolos);
		
		simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
		
		if(!simboloAtual.getLexema().equals("=")) {
			
			throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Esperado: =");
		}
		
		Utilitarios.removerElementoAtual(tabelaDeSimbolos);
		
		simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
		proximoSimbolo = Utilitarios.getProximoElemento(tabelaDeSimbolos);
		
		if(verificarPalavraReservada(simboloAtual)==true) {
			
			throw new ErroSemanticoException("" + simboloAtual.getLinha(), "Esperado: identificador | " + tipoSimboloOperacao);
		}
		
		if(verificarIdent(simboloAtual)==true) {
			
			if(validarEscopoIdentificador(simboloAtual)==false) {
				
				throw new ErroSemanticoException("" + simboloAtual.getLinha(), "A variável " + simboloAtual.getLexema() + " não foi declarada");
			}
			
			if(verificarIdent(simboloAtual)==true && proximoSimbolo.getLexema().equals(";")) {
				
				if(!verificarTipoId(simboloAtual).equals(tipoSimboloOperacao)) {
					
					throw new ErroSemanticoException("" + simboloAtual.getLinha(), "Esperado: indentificador do tipo " + tipoSimboloOperacao);
				}

				Utilitarios.removerElementoAtual(tabelaDeSimbolos);
				
				simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
				
				if(!simboloAtual.getLexema().equals(";")) {
					
					throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Esperado: ;");
				}
					
				Utilitarios.removerElementoAtual(tabelaDeSimbolos);
			}
			else
			if(verificarIdent(simboloAtual)==true && verificarOperadorAritmetico(proximoSimbolo)) {
				
				expressaoAritmetica(tabelaDeSimbolos);
				
				simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
				
				if(!simboloAtual.getLexema().equals(";")) {
					
					throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Esperado: ;");
				}				
				
				Utilitarios.removerElementoAtual(tabelaDeSimbolos);
			}
			else
			if((verificarIdent(simboloAtual)==true) && (!proximoSimbolo.getLexema().equals(";"))){
				
				throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Esperado: ;");
			}
		}
		
		if(verificarDado(simboloAtual)==true) {
			
			if((verificarDado(simboloAtual)==true) && proximoSimbolo.getLexema().equals(";")) {
				
				if((!simboloAtual.getToken().getTipo().equals(tipoSimboloOperacao))) {
					
					throw new ErroSemanticoException("" + simboloAtual.getLinha(), "Esperado: valor do tipo " + tipoSimboloOperacao);
				}
			
				Utilitarios.removerElementoAtual(tabelaDeSimbolos);
				
				simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
				
				if(!simboloAtual.getLexema().equals(";")) {
					
					throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Esperado: ;");
				}
					
				Utilitarios.removerElementoAtual(tabelaDeSimbolos);
			}
			else
			if((verificarDado(simboloAtual)==true) && (verificarOperadorAritmetico(proximoSimbolo)==true)) {
				
				expressaoAritmetica(tabelaDeSimbolos);
				
				simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
				
				if(!simboloAtual.getLexema().equals(";")) {
					
					throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Esperado: ;");
				}				
	
				Utilitarios.removerElementoAtual(tabelaDeSimbolos);
			}
			else
			if((verificarDado(simboloAtual)==true) && (!proximoSimbolo.getLexema().equals(";"))){
				
				throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Esperado: ;");
			}
		}

		simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
		
		if(tipoDeDado(simboloAtual.getLexema())==true || verificarIdent(simboloAtual)==true || simboloAtual.getLexema().equals("if")) {
			
			declaracao(tabelaDeSimbolos);
		}
	}
	
	public static void expressaoAritmetica(List<Elemento> tabelaDeSimbolos) throws ErroSintaticoException, ErroSemanticoException {
		
		simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
		
		if(verificarPalavraReservada(simboloAtual)==true) {
			
			throw new ErroSemanticoException("" + simboloAtual.getLinha(), "Esperado: identificador | " + tipoSimboloOperacao);
		}
		
		if(verificarIdent(simboloAtual)==false && verificarDado(simboloAtual)==false) {
			
			throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Esperado: identificador | int | float | char | string | boolean");
		}
		
		if(verificarIdent(simboloAtual)==true) {
			
			if(validarEscopoIdentificador(simboloAtual)==false) {
				
				throw new ErroSemanticoException("" + simboloAtual.getLinha(), "A variável " + simboloAtual.getLexema() + " não foi declarada");
			}
			
			String tipoTermo = verificarTipoId(simboloAtual);
			
			if(tipoSimboloOperacao==null) {
				
				tipoSimboloOperacao = verificarTipoId(simboloAtual);
			}
			
			if(tipoTermo.equals(tipoSimboloOperacao)) {
				
				Utilitarios.removerElementoAtual(tabelaDeSimbolos);
				
				simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
				
				if(verificarOperadorAritmetico(simboloAtual)==false){
					
					throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Esperado: + | - | * | /");
				}
				
				Utilitarios.removerElementoAtual(tabelaDeSimbolos);
			}
			else {
				
				throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Esperado: identificador do tipo " + tipoSimboloOperacao);
			}
			
			simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
			
			if(verificarPalavraReservada(simboloAtual)==true) {
				
				throw new ErroSemanticoException("" + simboloAtual.getLinha(), "Esperado: identificador | " + tipoSimboloOperacao);
			}
			
			if(verificarIdent(simboloAtual)==true) {
				
				if(validarEscopoIdentificador(simboloAtual)==false) {
					
					throw new ErroSemanticoException("" + simboloAtual.getLinha(), "A variável " + simboloAtual.getLexema() + " não foi declarada");
				}
				
				tipoTermo = verificarTipoId(simboloAtual);
				
				if(verificarIdent(simboloAtual)==true && tipoTermo.equals(tipoSimboloOperacao)) {

					Utilitarios.removerElementoAtual(tabelaDeSimbolos);		
				}
				else {
					
					throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Esperado: identificador do tipo " + tipoSimboloOperacao);
				}				
			}
			else
			if(verificarDado(simboloAtual)==true) {
				
				if(verificarDado(simboloAtual)==true && simboloAtual.getToken().getTipo().equals(tipoSimboloOperacao)) {
					
					Utilitarios.removerElementoAtual(tabelaDeSimbolos);
				}
				else {
					
					throw new ErroSemanticoException("" + simboloAtual.getLinha(), "Esperado: valor do tipo " + tipoSimboloOperacao);
				}	
			}		
		}
		else
		if(verificarDado(simboloAtual)==true) {
			
			if(verificarDado(simboloAtual)==true && simboloAtual.getToken().getTipo().equals(tipoSimboloOperacao)) {

				Utilitarios.removerElementoAtual(tabelaDeSimbolos);
				
				simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
				
				if(verificarOperadorAritmetico(simboloAtual)==false){
					
					throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Esperado: + | - | * | /");
				}
				
				Utilitarios.removerElementoAtual(tabelaDeSimbolos);
			}
			else {
				
				throw new ErroSemanticoException("" + simboloAtual.getLinha(), "Esperado: valor do tipo " + tipoSimboloOperacao);
			}
			
			simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
			
			if(verificarPalavraReservada(simboloAtual)==true) {
				
				throw new ErroSemanticoException("" + simboloAtual.getLinha(), "Esperado: identificador | " + tipoSimboloOperacao);
			}		
			
			if(verificarIdent(simboloAtual)==true) {
				
				if(validarEscopoIdentificador(simboloAtual)==false) {
					
					throw new ErroSemanticoException("" + simboloAtual.getLinha(), "A variável " + simboloAtual.getLexema() + " não foi declarada");
				}
				
				String tipoTermo = verificarTipoId(simboloAtual);
				
				if(verificarIdent(simboloAtual)==true && tipoTermo.equals(tipoSimboloOperacao)) {
					
					Utilitarios.removerElementoAtual(tabelaDeSimbolos);
				}
				else {
					
					throw new ErroSemanticoException("" + simboloAtual.getLinha(), "Esperado: identificador do tipo " + tipoSimboloOperacao);
				}				
			}
			else
			if(verificarDado(simboloAtual)==true) {
				
				if(verificarDado(simboloAtual)==true && simboloAtual.getToken().getTipo().equals(tipoSimboloOperacao)) {
					
					Utilitarios.removerElementoAtual(tabelaDeSimbolos);
				}
				else {
					
					throw new ErroSemanticoException("" + simboloAtual.getLinha(), "Esperado: valor do tipo " + tipoSimboloOperacao);
				}	
			}
		}
	}
	
public static void expressaoRelacional(List<Elemento> tabelaDeSimbolos) throws ErroSintaticoException, ErroSemanticoException {
		
		simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
		
		if(verificarPalavraReservada(simboloAtual)==true) {
			
			throw new ErroSemanticoException("" + simboloAtual.getLinha(), "Esperado: identificador | " + tipoSimboloOperacao);
		}
		
		if(verificarIdent(simboloAtual)==false && verificarDado(simboloAtual)==false) {
			
			throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Esperado: identificador | int | float | char | string | boolean");
		}
		
		if(verificarIdent(simboloAtual)==true) {
			
			if(validarEscopoIdentificador(simboloAtual)==false) {
				
				throw new ErroSemanticoException("" + simboloAtual.getLinha(), "A variável " + simboloAtual.getLexema() + " não foi declarada");
			}
			
			String tipoTermo = verificarTipoId(simboloAtual);
			
			if(tipoSimboloOperacao==null) {
				
				tipoSimboloOperacao = verificarTipoId(simboloAtual);
			}
			
			if(tipoTermo.equals(tipoSimboloOperacao)) {
				
				Utilitarios.removerElementoAtual(tabelaDeSimbolos);
				
				simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
				
				if(verificarOperadorRelacional(simboloAtual)==false){
					
					throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Esperado: < | > | <= | >= | != | ==");
				}
				
				Utilitarios.removerElementoAtual(tabelaDeSimbolos);
			}
			else {
				
				throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Esperado: identificador do tipo " + tipoSimboloOperacao);
			}
			
			simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
			
			if(verificarPalavraReservada(simboloAtual)==true) {
				
				throw new ErroSemanticoException("" + simboloAtual.getLinha(), "Esperado: identificador | " + tipoSimboloOperacao);
			}
			
			if(verificarIdent(simboloAtual)==true) {
				
				if(validarEscopoIdentificador(simboloAtual)==false) {
					
					throw new ErroSemanticoException("" + simboloAtual.getLinha(), "A variável " + simboloAtual.getLexema() + " não foi declarada");
				}
				
				tipoTermo = verificarTipoId(simboloAtual);
				
				if(verificarIdent(simboloAtual)==true && tipoTermo.equals(tipoSimboloOperacao)) {

					Utilitarios.removerElementoAtual(tabelaDeSimbolos);		
				}
				else {
					
					throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Esperado: identificador do tipo " + tipoSimboloOperacao);
				}				
			}
			else
			if(verificarDado(simboloAtual)==true) {
				
				if(verificarDado(simboloAtual)==true && simboloAtual.getToken().getTipo().equals(tipoSimboloOperacao)) {
					
					Utilitarios.removerElementoAtual(tabelaDeSimbolos);
				}
				else {
					
					throw new ErroSemanticoException("" + simboloAtual.getLinha(), "Esperado: valor do tipo " + tipoSimboloOperacao);
				}	
			}		
		}
		else
		if(verificarDado(simboloAtual)==true) {
			
			tipoSimboloOperacao = simboloAtual.getToken().getTipo();
			
			if(verificarDado(simboloAtual)==true && simboloAtual.getToken().getTipo().equals(tipoSimboloOperacao)) {

				Utilitarios.removerElementoAtual(tabelaDeSimbolos);
				
				simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
				
				if(verificarOperadorRelacional(simboloAtual)==false){
					
					throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Esperado: < | > | <= | >= | != | ==");
				}
				
				Utilitarios.removerElementoAtual(tabelaDeSimbolos);
			}
			else {
				
				throw new ErroSemanticoException("" + simboloAtual.getLinha(), "Esperado: valor do tipo " + tipoSimboloOperacao);
			}
			
			simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
			
			if(verificarPalavraReservada(simboloAtual)==true) {
				
				throw new ErroSemanticoException("" + simboloAtual.getLinha(), "Esperado: identificador | " + tipoSimboloOperacao);
			}		
			
			if(verificarIdent(simboloAtual)==true) {
				
				if(validarEscopoIdentificador(simboloAtual)==false) {
					
					throw new ErroSemanticoException("" + simboloAtual.getLinha(), "A variável " + simboloAtual.getLexema() + " não foi declarada");
				}
				
				String tipoTermo = verificarTipoId(simboloAtual);
				
				if(verificarIdent(simboloAtual)==true && tipoTermo.equals(tipoSimboloOperacao)) {
					
					Utilitarios.removerElementoAtual(tabelaDeSimbolos);
				}
				else {
					
					throw new ErroSemanticoException("" + simboloAtual.getLinha(), "Esperado: identificador do tipo " + tipoSimboloOperacao);
				}				
			}
			else
			if(verificarDado(simboloAtual)==true) {
				
				if(verificarDado(simboloAtual)==true && simboloAtual.getToken().getTipo().equals(tipoSimboloOperacao)) {
					
					Utilitarios.removerElementoAtual(tabelaDeSimbolos);
				}
				else {
					
					throw new ErroSemanticoException("" + simboloAtual.getLinha(), "Esperado: valor do tipo " + tipoSimboloOperacao);
				}	
			}
		}
	}
	
	public static void declIf(List<Elemento> tabelaDeSimbolos) throws ErroSintaticoException, ErroSemanticoException {
		
		simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
		
		if(!simboloAtual.getLexema().equals("if")) {
			
			throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Esperado: if");
		}
		
		Utilitarios.removerElementoAtual(tabelaDeSimbolos);
		
		simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
		
		if(!simboloAtual.getLexema().equals("(")) {
			
			throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Esperado: (");
		}
		
		Utilitarios.removerElementoAtual(tabelaDeSimbolos);
		
		expressaoRelacional(tabelaDeSimbolos);
		
		simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
		
		if(!simboloAtual.getLexema().equals(")")) {
			
			throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Esperado: )");
		}
		
		Utilitarios.removerElementoAtual(tabelaDeSimbolos);
		
		simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
		
		if(!simboloAtual.getLexema().equals("{")) {
			
			throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Esperado: {");
		}
		
		Utilitarios.removerElementoAtual(tabelaDeSimbolos);
		
		declaracao(tabelaDeSimbolos);
	}
	
	public static boolean validarEscopoIdentificador(Elemento atual) {
		
		for(int i=0; i<TabelaDeSimbolos.getIdentificadores().size(); i++) {
			
			if(atual.getLexema().equals(TabelaDeSimbolos.getIdentificadores().get(i).getId())) {
				
				if(TabelaDeSimbolos.getIdentificadores().get(i).getLinha()<atual.getLinha()) {
					
					return true;
				}
			}
		}
		
		return false;
	}
	
	public static boolean verificarDado(Elemento atual) {
		
		if(caractere(atual.getLexema())==true) {
			
			return true;
		}
		
		if(inteiro(atual.getLexema())==true) {
			
			return true;
		}
		
		if(real(atual.getLexema())==true) {
			
			return true;
		}
		
		if(string(atual.getLexema())==true) {
			
			return true;
		}
		
		if(bool(atual.getLexema())==true) {
			
			return true;
		}		
		
		return false;
	}
	
	public static boolean tipoDeDado(String lexema) {

		String[] tipoDeDado = {"int", "char", "float", "string", "boolean"};
		
		for(int i=0; i<tipoDeDado.length; i++) {
			
			if(lexema.equals(tipoDeDado[i])) {
				
				return true;
			}
		}
		
		return false;		
	}
	
	public static boolean caractere(String lexema) {
		
		if(lexema.length()==3 && lexema.charAt(0)=='\'' && lexema.charAt(2)=='\'') {
			
			return true;
		}
		
		return false;
	}
	
	public static boolean string(String lexema) {
		
		if(lexema.charAt(0)=='"' && lexema.charAt(lexema.length()-1)=='"') {
			
			return true;
		}
		
		return false;
	}
	
	public static boolean bool(String lexema) {
		
		if(lexema.equals("true") || lexema.equals("false")) {
			
			return true;
		}
		
		return false;
	}
	
	public static boolean inteiro(String lexema) {
		
		for(int i=0; i<lexema.length(); i++) {
			
			if(!Character.isDigit(lexema.charAt(i))) {
				
				return false;
			}
		}
		
		return true;
	}
	
	public static boolean real(String lexema) {
		
		int contPonto=0;
		
		for(int i=0; i<lexema.length(); i++) {
			
			if(lexema.charAt(i)=='.') {
				
				contPonto++;
			}
		}
		
		if(contPonto>1) {
			
			return false;
		}
		else {
			
			for(int i=0; i<lexema.length(); i++) {
				
				if(lexema.charAt(i)=='.') {
					
					continue;
				}
				
				if(!Character.isDigit(lexema.charAt(i))) {
					
					return false;
				}
			}
		}
		
		return true;
	}
	
	public static void identIni(Elemento atual) throws ErroSintaticoException {
		
		if(atual.getLexema().length()==1) {
			
			if((atual.getLexema().indexOf(0)=='$') || (atual.getLexema().indexOf(0)=='_') || letra(atual.getLexema())==false) {
				
				throw new ErroSintaticoException("" + atual.getLinha(), "Esperado: identificador");
			}
			
			return;
		}
		else {
			
			if((atual.getLexema().indexOf(0)=='$') || (atual.getLexema().indexOf(0)=='_') || letra(atual.getLexema())==false) {
				
				throw new ErroSintaticoException("" + atual.getLinha(), "Esperado: identificador");
			}
		}
	}
	
	public static void ident(List<Elemento> tabelaDeSimbolos) throws ErroSintaticoException {
		
		simboloAtual = Utilitarios.getElementoAtual(tabelaDeSimbolos);
		
		if(verificarPalavraReservada(simboloAtual)==true) {
			
			throw new ErroSintaticoException("" + simboloAtual.getLinha(), "Esperado: identificador");
		}
		
		identIni(simboloAtual);
		
		literalCorpo(simboloAtual.getLexema());
		
		Utilitarios.removerElementoAtual(tabelaDeSimbolos);
	}
	
	public static boolean verificarPalavraReservada(Elemento atual) {
		
		for(int i=0; i<Classificacao.palavrasReservadas.size(); i++) {
			
			if(atual.getLexema().equals(Classificacao.palavrasReservadas.get(i).getLexema())) {
				
				return true;
			}
		}
		
		for(int i=0; i<Classificacao.tipoDeDado.size(); i++) {
			
			if(atual.getLexema().equals(Classificacao.tipoDeDado.get(i).getLexema())) {
				
				return true;
			}
		}

		return false;
	}
	
	public static boolean verificarIdent(Elemento atual) throws ErroSintaticoException {
		
		if(verificarPalavraReservada(atual)==true) {
			
			return false;
		}
		
		if(atual.getLexema().length()==1) {
			
			if((atual.getLexema().indexOf(0)=='$') || (atual.getLexema().indexOf(0)=='_') || letra(atual.getLexema())==false) {
				
				return false;
			}
		}
		else {
			
			if((atual.getLexema().indexOf(0)=='$') || (atual.getLexema().indexOf(0)=='_') || letra(atual.getLexema())==false) {
				
				return false;
			}
		}
		
		String alfaNum = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
		boolean subChar=false;
		
		for(int i=1; i<atual.getLexema().length(); i++) {
			
			for(int j=0; j<alfaNum.length(); j++) {
				
				if(atual.getLexema().charAt(i)==alfaNum.charAt(j)) {
										
					subChar=true;
				}
			}
			
			if(subChar==false) {
				
				return false;
			}
		}
		
		return true;		
	}
		
	public static boolean letra(String lexema) {
		
		String letra = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
		char ch = lexema.charAt(0);
			
		for(int i=0; i<letra.length(); i++) {
			
			if(ch==letra.charAt(i)) {
				
				return true;
			}
		}		
		
		return false;
	}
	
	public static void literalCorpo(String lexema) throws ErroSintaticoException {
		
		String alfaNum = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
		boolean subChar=false;
		
		for(int i=1; i<lexema.length(); i++) {
			
			for(int j=0; j<alfaNum.length(); j++) {
				
				if(lexema.charAt(i)==alfaNum.charAt(j)) {
										
					subChar=true;
				}
			}
			
			if(subChar==false) {
				
				throw new ErroSintaticoException("" + simboloAtual.getLinha(), "identificador");
			}
		}
	}
	
	public static String verificarTipoId(Elemento atual) {
		
		for(int i=0; i<TabelaDeSimbolos.getIdentificadores().size(); i++) {
			
			if(atual.getLexema().equals(TabelaDeSimbolos.getIdentificadores().get(i).getId())) {
				
				return TabelaDeSimbolos.getIdentificadores().get(i).getTipoId();
			}
		}
		
		return null;
	}
	
	public static boolean verificarOperadorRelacional(Elemento atual) {
		
		if(atual.getLexema().equals("<") || atual.getLexema().equals(">") || atual.getLexema().equals("!=") || atual.getLexema().equals("==") ||
		   atual.getLexema().equals("<=") || atual.getLexema().equals(">=")) {
			
			return true;
		}
		
		return false;
	}
	
	public static boolean verificarOperadorAritmetico(Elemento atual) {
		
		if(atual.getLexema().equals("+") || atual.getLexema().equals("-") || atual.getLexema().equals("*") || atual.getLexema().equals("/")) {
			
			return true;
		}
		
		return false;
	}
}