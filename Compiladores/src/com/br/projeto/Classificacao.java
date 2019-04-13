/* Classe responsável por verificar e classificar os dados mapeados do arquivo. */

package com.br.projeto;

import java.util.ArrayList;
import java.util.List;

public class Classificacao {
	
	String nome;
	String valor;
	String lexema;
	
	static int contTipo = 1;
	static int contId = 1;
	
	Classificacao(String nome, String valor, String lexema) {
		
		this.nome = nome;
		this.valor = valor;
		this.lexema = lexema;
	}
	
	static List<Classificacao> palavrasReservadas = new ArrayList<Classificacao>();
	static List<Classificacao> operadoresLogicos = new ArrayList<Classificacao>();
	static List<Classificacao> operadoresRelacionais = new ArrayList<Classificacao>();
	static List<Classificacao> operadoresAritmeticos = new ArrayList<Classificacao>();
	static List<Classificacao> operadoresUnarios = new ArrayList<Classificacao>();
	static List<Classificacao> operadorAtribuicao = new ArrayList<Classificacao>();
	static List<Classificacao> delimitadores = new ArrayList<Classificacao>();
	static List<Classificacao> tipoDeDado = new ArrayList<Classificacao>();
	
	public static void carregarInformacoes() {
		
		palavrasReservadas.add(new Classificacao("Palavra reservada", "<IF>", "if"));
		palavrasReservadas.add(new Classificacao("Palavra reservada", "<CLASS>", "class"));
		palavrasReservadas.add(new Classificacao("Palavra reservada", "<ELSE>", "else"));
		palavrasReservadas.add(new Classificacao("Palavra reservada", "<FINAL>", "final"));
		palavrasReservadas.add(new Classificacao("Palavra reservada", "<FOR>", "for"));
		palavrasReservadas.add(new Classificacao("Palavra reservada", "<NEW>", "new"));
		palavrasReservadas.add(new Classificacao("Palavra reservada", "<BREAK>", "break"));
		palavrasReservadas.add(new Classificacao("Palavra reservada", "<CONTINUE>", "continue"));
		palavrasReservadas.add(new Classificacao("Palavra reservada", "<PRIVATE>", "private"));
		palavrasReservadas.add(new Classificacao("Palavra reservada", "<PROTECTED>", "protected"));
		palavrasReservadas.add(new Classificacao("Palavra reservada", "<PUBLIC>", "public"));
		palavrasReservadas.add(new Classificacao("Palavra reservada", "<RETURN>", "return"));
		palavrasReservadas.add(new Classificacao("Palavra reservada", "<STATIC>", "static"));
		palavrasReservadas.add(new Classificacao("Palavra reservada", "<VOID>", "void"));
		palavrasReservadas.add(new Classificacao("Palavra reservada", "<DO>", "do"));
		palavrasReservadas.add(new Classificacao("Palavra reservada", "<WHILE>", "while"));
		palavrasReservadas.add(new Classificacao("Palavra reservada", "<SYSTEM>", "System"));
		palavrasReservadas.add(new Classificacao("Palavra reservada", "<OUT>", "out"));
		palavrasReservadas.add(new Classificacao("Palavra reservada", "<PRINTLN>", "println"));
		
		operadoresLogicos.add(new Classificacao("Operador Lógico", "<E>", "&&"));
		operadoresLogicos.add(new Classificacao("Operador Lógico", "<OU>", "||"));
		operadoresLogicos.add(new Classificacao("Operador Lógico", "<NÃO>", "!"));
		
		operadoresRelacionais.add(new Classificacao("Operador Relacional", "<MENORQUE>", "<"));
		operadoresRelacionais.add(new Classificacao("Operador Relacional", "<MAIORQUE>", ">"));
		operadoresRelacionais.add(new Classificacao("Operador Relacional", "<MENORIGUAL>", "<="));
		operadoresRelacionais.add(new Classificacao("Operador Relacional", "<MAIORIGUAL>", ">="));
		operadoresRelacionais.add(new Classificacao("Operador Relacional", "<DIFERENTE>", "!="));
		operadoresRelacionais.add(new Classificacao("Operador Relacional", "<IGUAL>", "=="));
		
		operadoresAritmeticos.add(new Classificacao("Operador Aritmético", "<SOMA>", "+"));
		operadoresAritmeticos.add(new Classificacao("Operador Aritmético", "<SUBTRACAO>", "-"));
		operadoresAritmeticos.add(new Classificacao("Operador Aritmético", "<MULTIPLICACAO>", "*"));
		operadoresAritmeticos.add(new Classificacao("Operador Aritmético", "<DIVISAO>", "/"));
		
		operadoresUnarios.add(new Classificacao("Operador Unário", "<INCREMENTO>", "++"));
		operadoresUnarios.add(new Classificacao("Operador Unário", "<DECREMENTO>", "--"));
		
		delimitadores.add(new Classificacao("Delimitador", "<PONTOVIRGULA>", ";"));
		delimitadores.add(new Classificacao("Delimitador", "<PONTO>", "."));
		delimitadores.add(new Classificacao("Delimitador", "<DOISPONTOS>", ":"));
		delimitadores.add(new Classificacao("Delimitador", "<ABREPARENTESES>", "("));
		delimitadores.add(new Classificacao("Delimitador", "<FECHAPARENTESES>", ")"));
		delimitadores.add(new Classificacao("Delimitador", "<ABRECOLCHETES>", "["));
		delimitadores.add(new Classificacao("Delimitador", "<FECHACOLCHETES>", "]"));
		delimitadores.add(new Classificacao("Delimitador", "<ABRECHAVES>", "{"));
		delimitadores.add(new Classificacao("Delimitador", "<FECHACHAVES>", "}"));
		delimitadores.add(new Classificacao("Delimitador", "<ABREASPASSIMPLES>", "'"));
		delimitadores.add(new Classificacao("Delimitador", "<FECHAASPASSIMPLES>", "'"));
		delimitadores.add(new Classificacao("Delimitador", "<ABREASPASDUPLAS>", "\""));
		delimitadores.add(new Classificacao("Delimitador", "<FECHAASPASDUPLAS>", "\""));
		
		tipoDeDado.add(new Classificacao("Tipo de Dado", "<TIPOINT>", "int"));
		tipoDeDado.add(new Classificacao("Tipo de Dado", "<TIPOCHAR>", "char"));
		tipoDeDado.add(new Classificacao("Tipo de Dado", "<TIPOFLOAT>", "float"));
		tipoDeDado.add(new Classificacao("Tipo de Dado", "<TIPOSTRING>", "String"));
		tipoDeDado.add(new Classificacao("Tipo de Dado", "<TIPOBOOLEAN>", "boolean"));
		tipoDeDado.add(new Classificacao("Tipo de Dado", "<TIPONULL>", "null"));
	}
	
	public static Elemento atribuirInformacoes(Mapeamento m) {
		
		for(Classificacao p : palavrasReservadas) {
			
			if(p.lexema.compareTo(m.simbolo)==0) {
				
				Token t = new Token(p.nome, p.valor);
				Elemento e = new Elemento(t, p.lexema, m.numLinha);
				
				return e;
			}
		}
		
		for(Classificacao ol : operadoresLogicos) {
			
			if(ol.lexema.compareTo(m.simbolo)==0) {
				
				Token t = new Token(ol.nome, ol.valor);
				Elemento e = new Elemento(t, ol.lexema, m.numLinha);
				
				return e;
			}
		}
		
		for(Classificacao or : operadoresRelacionais) {
			
			if(or.lexema.compareTo(m.simbolo)==0) {
				
				Token t = new Token(or.nome, or.valor);
				Elemento e = new Elemento(t, or.lexema, m.numLinha);
				
				return e;
			}
		}
		
		for(Classificacao oa : operadoresAritmeticos) {
			
			if(oa.lexema.compareTo(m.simbolo)==0) {
				
				Token t = new Token(oa.nome, oa.valor);
				Elemento e = new Elemento(t, oa.lexema, m.numLinha);
				
				return e;
			}
		}
		
		for(Classificacao ou : operadoresUnarios) {
			
			if(ou.lexema.compareTo(m.simbolo)==0) {
				
				Token t = new Token(ou.nome, ou.valor);
				Elemento e = new Elemento(t, ou.lexema, m.numLinha);
				
				return e;
			}
		}
		
		if(m.simbolo.compareTo("=")==0) {
			
			Token t = new Token("Operador de Atribuição", "<ATRIBUICAO>");
			Elemento e = new Elemento(t, "=", m.numLinha);
			
			return e;
		}
		
		for(Classificacao del : delimitadores) {
			
			if(del.lexema.compareTo(m.simbolo)==0) {
				
				Token t = new Token(del.nome, del.valor);
				Elemento e = new Elemento(t, del.lexema, m.numLinha);
				
				return e;
			}
		}
		
		for(Classificacao td : tipoDeDado) {
			
			if(td.lexema.compareTo(m.simbolo)==0) {
				
				Token t = new Token(td.nome + " " + contTipo, td.valor);
				Elemento e = new Elemento(t, td.lexema, m.numLinha);
				
				++contTipo;
				
				return e;
			}
		}
		
		if(verificaIdentificador(m.simbolo)) {
			
			Token t = new Token("Identificador", "<ID" + contId + ">");
			Elemento e = new Elemento(t, m.simbolo, m.numLinha);
			
			++contId;
			
			return e;
		}
		
		if(verificaBoolean(m.simbolo)) {
			
			Token t = new Token("Palavra reservada", "<" + m.simbolo.toUpperCase() + ">");
			Elemento e = new Elemento(t, m.simbolo, m.numLinha);
			
			return e;
		}
		
		if(verificaChar(m.simbolo)) {
			
			Token t = new Token("Caractere", "<CHAR>");
			Elemento e = new Elemento(t, m.simbolo, m.numLinha);
			
			return e;
		}
		
		if(verificarInt(m.simbolo)) {
			
			Token t = new Token("Número inteiro", "<INT>");
			Elemento e = new Elemento(t, m.simbolo, m.numLinha);
			
			return e;
		}
		
		if(verificarFloat(m.simbolo)) {
			
			Token t = new Token("Número real", "<FLOAT>");
			Elemento e = new Elemento(t, m.simbolo, m.numLinha);
			
			return e;
		}
		
		if(verificarString(m.simbolo)) {
			
			Token t = new Token("Literal", "<STRING>");
			Elemento e = new Elemento(t, m.simbolo, m.numLinha);
			
			return e;
		}
		
		return null;
	}
	
	public static boolean verificaIdentificador(String s) {
		
		if(Character.isAlphabetic(s.charAt(0)) || s.charAt(0)=='$' || s.charAt(0)=='_') {
			
			return true;
		}
		else {
			
			return false;
		}
	}
	
	public static boolean verificaBoolean(String s) {
		
		if(s.compareTo("true")==0 || s.compareTo("false")==0) {
			
			return true;
		}
		
		return false;
	}
	
	public static boolean verificaChar(String s) {
		
		if((s.charAt(0)=='\'' && s.charAt(2)=='\'')) {
			
			return true;
		}
		
		return false;
	}
	
	public static boolean verificarFloat(String s) {
		
		for(int i=0; i<s.length(); i++) {
			
			if(!Character.isDigit(s.charAt(i)) && s.charAt(i)!='.'){
				
				return false;
			}
		}
		
		return true;
	}
	
	public static boolean verificarInt(String s) {
		
		for(int i=0; i<s.length(); i++) {
			
			if(!Character.isDigit(s.charAt(i))){
				
				return false;
			}
		}
		
		return true;
	}
	
	public static boolean verificarString(String s) {
		
		if(s.charAt(0)=='\"' && s.charAt(s.length()-1)=='\"') {
			
			return true;
		}
		
		return false;
	}
}