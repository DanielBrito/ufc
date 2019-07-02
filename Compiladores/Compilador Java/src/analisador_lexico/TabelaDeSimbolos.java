/* Classe que define os elementos da Tabela de Símbolos e que verifica a existência de erros léxicos. */

package analisador_lexico;

import java.util.ArrayList;
import java.util.List;

import analisador_semantico.ErroSemanticoException;
import analisador_sintatico.ErroSintaticoException;
import analisador_sintatico.Gramatica;
import executar.Arquivo;

public class TabelaDeSimbolos {
	
	static Elemento aux;
	static List<Mapeamento> simbolos = new ArrayList<Mapeamento>();
	static List<Elemento> elementos = new ArrayList<Elemento>();
	static List<Identificador> identificadores = new ArrayList<Identificador>();

	public static void gerarTabela(String enderecoArquivo) throws ComentarioInvalidoException, SimboloInvalidoException, ErroSintaticoException, ErroSemanticoException {
		
		Classificacao.carregarInformacoes();
		
		boolean lendoComentarioInline = false;
		boolean lendoComentarioBloco = false;
		int linhaComentarioInline=0;
		int linhaComentarioBloco=0;

		simbolos = Arquivo.lerArquivo(enderecoArquivo);		
		
		for(Mapeamento m : simbolos) {
			
			if(m.simbolo.compareTo("//")==0) {
				
				lendoComentarioInline = true;
				linhaComentarioInline = m.numLinha;
			}

			if(m.simbolo.compareTo("/*")==0) {
				
				lendoComentarioBloco = true;
				linhaComentarioBloco = m.numLinha;
			} 

			if(m.simbolo.compareTo("*/")==0) {
			
				lendoComentarioBloco = false;
			}
			
			if((lendoComentarioInline==true) && (m.numLinha==linhaComentarioInline)) { // Comentário inline
				
				continue;
			}
			else
			if(lendoComentarioBloco==true) { // Comentário bloco
				
				continue;
			}
			
			if(m.simbolo.equals("*/")) {
				
				lendoComentarioBloco = false;
				continue;
			}
			
			if((lendoComentarioBloco==false || lendoComentarioInline==false) && m.numLinha!=linhaComentarioInline) {
				
				aux = Classificacao.atribuirInformacoes(m);
				
				if(aux==null) {
					
					throw new SimboloInvalidoException("" + m.numLinha, m.simbolo);
					
				}
				else {
					
					elementos.add(aux);
				}
			}
		}
		
		if(lendoComentarioBloco==true) {
			
			throw new ComentarioInvalidoException("" + linhaComentarioBloco);
		}
		
		
		System.out.println("\nTABELA DE SÍMBOLOS:\n");
		
		for(Elemento e : elementos) {
			
			System.out.println(e);
		}
		
		
		listarIdentificadores(elementos);
		
		
		System.out.println("\nLISTA DE IDENTIFICADORES:\n");
		
		for(Identificador id : identificadores) {
			
			System.out.println(id);
		}
		
		
		System.out.println();
		
		Gramatica.programa(elementos);
	}
	
	public static void listarIdentificadores(List<Elemento> elementos) throws ErroSintaticoException {
		
		for(int i=0; i<elementos.size(); i++) {
			
			if(Classificacao.verificarTipo(elementos.get(i).lexema)==true) {
				
				Identificador id = new Identificador(elementos.get(i).lexema, elementos.get(i+1).lexema, elementos.get(i).getEscopo(), elementos.get(i).getLinha());
				
				for(int j=0; j<identificadores.size(); j++) {
					
					if(id.getId().equals(identificadores.get(j).id) && id.getEscopo()==identificadores.get(j).escopo) {
						
						throw new ErroSintaticoException("" + elementos.get(i).getLinha(), "O identificador " + id.getId() + " já foi declarado neste escopo");
					}
				}
					
				identificadores.add(id);
			}
		}
	}
	
	public static List<Identificador> getIdentificadores(){
		
		return identificadores;
	}
}