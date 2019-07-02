/* Classe responsável por verificar e classificar os dados mapeados do arquivo. */

package analisador_lexico;

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

	public static List<Classificacao> palavrasReservadas = new ArrayList<Classificacao>();
	public static List<Classificacao> operadoresLogicos = new ArrayList<Classificacao>();
	public static List<Classificacao> operadoresRelacionais = new ArrayList<Classificacao>();
	public static List<Classificacao> operadoresAritmeticos = new ArrayList<Classificacao>();
	public static List<Classificacao> operadoresUnarios = new ArrayList<Classificacao>();
	public static List<Classificacao> operadorAtribuicao = new ArrayList<Classificacao>();
	public static List<Classificacao> delimitadores = new ArrayList<Classificacao>();
	public static List<Classificacao> tipoDeDado = new ArrayList<Classificacao>();

	public static void carregarInformacoes() {

		palavrasReservadas.add(new Classificacao("palavra reservada", "<IF>", "if"));
		palavrasReservadas.add(new Classificacao("palavra reservada", "<CLASS>", "class"));
		palavrasReservadas.add(new Classificacao("palavra reservada", "<ELSE>", "else"));
		palavrasReservadas.add(new Classificacao("palavra reservada", "<FINAL>", "final"));
		palavrasReservadas.add(new Classificacao("palavra reservada", "<FOR>", "for"));
		palavrasReservadas.add(new Classificacao("palavra reservada", "<NEW>", "new"));
		palavrasReservadas.add(new Classificacao("palavra reservada", "<BREAK>", "break"));
		palavrasReservadas.add(new Classificacao("palavra reservada", "<CONTINUE>", "continue"));
		palavrasReservadas.add(new Classificacao("palavra reservada", "<PRIVATE>", "private"));
		palavrasReservadas.add(new Classificacao("palavra reservada", "<PROTECTED>", "protected"));
		palavrasReservadas.add(new Classificacao("palavra reservada", "<PUBLIC>", "public"));
		palavrasReservadas.add(new Classificacao("palavra reservada", "<RETURN>", "return"));
		palavrasReservadas.add(new Classificacao("palavra reservada", "<STATIC>", "static"));
		palavrasReservadas.add(new Classificacao("palavra reservada", "<VOID>", "void"));
		palavrasReservadas.add(new Classificacao("palavra reservada", "<DO>", "do"));
		palavrasReservadas.add(new Classificacao("palavra reservada", "<WHILE>", "while"));
		palavrasReservadas.add(new Classificacao("palavra reservada", "<TRUE>", "true"));
		palavrasReservadas.add(new Classificacao("palavra reservada", "<FALSE>", "false"));
		palavrasReservadas.add(new Classificacao("palavra reservada", "<MAIN>", "main"));

		operadoresLogicos.add(new Classificacao("operador lógico", "<E>", "&&"));
		operadoresLogicos.add(new Classificacao("operador lógico", "<OU>", "||"));
		operadoresLogicos.add(new Classificacao("operador lógico", "<NÃO>", "!"));

		operadoresRelacionais.add(new Classificacao("operador relacional", "<MENORQUE>", "<"));
		operadoresRelacionais.add(new Classificacao("operador relacional", "<MAIORQUE>", ">"));
		operadoresRelacionais.add(new Classificacao("operador relacional", "<MENORIGUAL>", "<="));
		operadoresRelacionais.add(new Classificacao("operador relacional", "<MAIORIGUAL>", ">="));
		operadoresRelacionais.add(new Classificacao("operador relacional", "<DIFERENTE>", "!="));
		operadoresRelacionais.add(new Classificacao("operador relacional", "<IGUAL>", "=="));

		operadoresAritmeticos.add(new Classificacao("operador aritmético", "<SOMA>", "+"));
		operadoresAritmeticos.add(new Classificacao("operador aritmético", "<SUBTRACAO>", "-"));
		operadoresAritmeticos.add(new Classificacao("operador aritmético", "<MULTIPLICACAO>", "*"));
		operadoresAritmeticos.add(new Classificacao("operador aritmético", "<DIVISAO>", "/"));

		operadoresUnarios.add(new Classificacao("operador unário", "<INCREMENTO>", "++"));
		operadoresUnarios.add(new Classificacao("operador unário", "<DECREMENTO>", "--"));

		delimitadores.add(new Classificacao("delimitador", "<PONTOVIRGULA>", ";"));
		delimitadores.add(new Classificacao("delimitador", "<PONTO>", "."));
		delimitadores.add(new Classificacao("delimitador", "<DOISPONTOS>", ":"));
		delimitadores.add(new Classificacao("delimitador", "<ABREPARENTESES>", "("));
		delimitadores.add(new Classificacao("delimitador", "<FECHAPARENTESES>", ")"));
		delimitadores.add(new Classificacao("delimitador", "<ABRECOLCHETES>", "["));
		delimitadores.add(new Classificacao("delimitador", "<FECHACOLCHETES>", "]"));
		delimitadores.add(new Classificacao("delimitador", "<ABRECHAVES>", "{"));
		delimitadores.add(new Classificacao("delimitador", "<FECHACHAVES>", "}"));
		delimitadores.add(new Classificacao("delimitador", "<ABREASPASSIMPLES>", "'"));
		delimitadores.add(new Classificacao("delimitador", "<FECHAASPASSIMPLES>", "'"));
		delimitadores.add(new Classificacao("delimitador", "<ABREASPASDUPLAS>", "\""));
		delimitadores.add(new Classificacao("delimitador", "<FECHAASPASDUPLAS>", "\""));

		tipoDeDado.add(new Classificacao("tipo de dado", "<TIPOINT>", "int"));
		tipoDeDado.add(new Classificacao("tipo de dado", "<TIPOCHAR>", "char"));
		tipoDeDado.add(new Classificacao("tipo de dado", "<TIPOFLOAT>", "float"));
		tipoDeDado.add(new Classificacao("tipo de dado", "<TIPOSTRING>", "String"));
		tipoDeDado.add(new Classificacao("tipo de dado", "<TIPOBOOLEAN>", "boolean"));
		tipoDeDado.add(new Classificacao("tipo de dado", "<TIPONULL>", "null"));
	}

	public static Elemento atribuirInformacoes(Mapeamento m) {

		for (Classificacao p : palavrasReservadas) {

			if (p.lexema.compareTo(m.simbolo) == 0) {

				Token t = new Token(p.nome, p.valor);
				Elemento e = new Elemento(t, p.lexema, m.numLinha, m.escopo);

				return e;
			}
		}

		for (Classificacao ol : operadoresLogicos) {

			if (ol.lexema.compareTo(m.simbolo) == 0) {

				Token t = new Token(ol.nome, ol.valor);
				Elemento e = new Elemento(t, ol.lexema, m.numLinha, m.escopo);

				return e;
			}
		}

		for (Classificacao or : operadoresRelacionais) {

			if (or.lexema.compareTo(m.simbolo) == 0) {

				Token t = new Token(or.nome, or.valor);
				Elemento e = new Elemento(t, or.lexema, m.numLinha, m.escopo);

				return e;
			}
		}

		for (Classificacao oa : operadoresAritmeticos) {

			if (oa.lexema.compareTo(m.simbolo) == 0) {

				Token t = new Token(oa.nome, oa.valor);
				Elemento e = new Elemento(t, oa.lexema, m.numLinha, m.escopo);

				return e;
			}
		}

		for (Classificacao ou : operadoresUnarios) {

			if (ou.lexema.compareTo(m.simbolo) == 0) {

				Token t = new Token(ou.nome, ou.valor);
				Elemento e = new Elemento(t, ou.lexema, m.numLinha, m.escopo);

				return e;
			}
		}

		if (m.simbolo.compareTo("=") == 0) {

			Token t = new Token("operador de atribuição", "<ATRIBUICAO>");
			Elemento e = new Elemento(t, "=", m.numLinha, m.escopo);

			return e;
		}

		for (Classificacao del : delimitadores) {

			if (del.lexema.compareTo(m.simbolo) == 0) {

				Token t = new Token(del.nome, del.valor);
				Elemento e = new Elemento(t, del.lexema, m.numLinha, m.escopo);

				return e;
			}
		}

		for (Classificacao td : tipoDeDado) {

			if (td.lexema.compareTo(m.simbolo) == 0) {

				Token t = new Token(td.nome + " " + contTipo, td.valor);
				Elemento e = new Elemento(t, td.lexema, m.numLinha, m.escopo);

				++contTipo;

				return e;
			}
		}

		if (verificaIdentificador(m.simbolo)) {

			Token t = new Token("identificador", "<ID" + contId + ">");
			Elemento e = new Elemento(t, m.simbolo, m.numLinha, m.escopo);

			++contId;

			return e;
		}

		if (verificaBoolean(m.simbolo)) {

			Token t = new Token("palavra reservada", "<" + m.simbolo.toUpperCase() + ">");
			Elemento e = new Elemento(t, m.simbolo, m.numLinha, m.escopo);

			return e;
		}

		if (verificaChar(m.simbolo)) {

			Token t = new Token("char", "<CHAR>");
			Elemento e = new Elemento(t, m.simbolo, m.numLinha, m.escopo);

			return e;
		}

		if (verificarInt(m.simbolo)) {

			Token t = new Token("int", "<INT>");
			Elemento e = new Elemento(t, m.simbolo, m.numLinha, m.escopo);

			return e;
		}

		if (verificarFloat(m.simbolo)) {

			Token t = new Token("float", "<FLOAT>");
			Elemento e = new Elemento(t, m.simbolo, m.numLinha, m.escopo);

			return e;
		}

		if (verificarString(m.simbolo)) {

			Token t = new Token("String", "<STRING>");
			Elemento e = new Elemento(t, m.simbolo, m.numLinha, m.escopo);

			return e;
		}

		return null;
	}

	public static boolean verificaIdentificador(String s) {

		if (Character.isAlphabetic(s.charAt(0)) || s.charAt(0) == '$' || s.charAt(0) == '_') {

			return true;
			
		} else {

			return false;
		}
	}

	public static boolean verificaBoolean(String s) {

		if (s.compareTo("true") == 0 || s.compareTo("false") == 0) {

			return true;
		}

		return false;
	}

	public static boolean verificaChar(String s) {

		if ((s.charAt(0) == '\'' && s.charAt(2) == '\'')) {

			return true;
		}

		return false;
	}

	public static boolean verificarFloat(String s) {
		
		return  s.matches("[0-9]*\\.[0-9]+");
	}

	public static boolean verificarInt(String s) {

		return s.matches("\\d+");

	}

	public static boolean verificarString(String s) {

		if (s.charAt(0) == '\"' && s.charAt(s.length()-1) == '\"') {

			return true;
		}

		return false;
	}

	public String getLexema() {

		return lexema;
	}
	
	public static boolean verificarTipo(String lexema) {
		
		if(lexema.equals("int") || lexema.equals("char") || lexema.equals("String") || lexema.equals("float") || lexema.equals("boolean")) {
			
			return true;
		}
		
		return false;
	}
}