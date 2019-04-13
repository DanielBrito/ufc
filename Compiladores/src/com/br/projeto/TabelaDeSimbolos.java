/* Classe que define os elementos da Tabela de Símbolos e que verifica a existência de erros léxicos. */

package com.br.projeto;

import java.util.ArrayList;
import java.util.List;

public class TabelaDeSimbolos {

	
	public static void gerarTabela(String enderecoArquivo) throws ComentarioException {
		
		Classificacao.carregarInformacoes();
		
		List<Mapeamento> simbolos = new ArrayList<Mapeamento>();
		List<Mapeamento> invalidos = new ArrayList<Mapeamento>();
		List<Elemento> elementos = new ArrayList<Elemento>();
		
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
			
			if(((lendoComentarioInline==true) && (m.numLinha==linhaComentarioInline)) || lendoComentarioBloco==true || m.simbolo.compareTo("*/")==0) {
				
				continue;
			}
			else {
				
				lendoComentarioInline = false;
				
				Elemento aux = Classificacao.atribuirInformacoes(m);
				
				if(aux==null) {
					
					invalidos.add(m);
				}
				else {
					
					elementos.add(aux);
				}
			}
		}
		
		System.out.println("\n\nTABELA DE SÍMBOLOS:\n");
		
		for(Elemento e : elementos) {
			
			System.out.println(e);
		}
		
		System.out.println("\n\nSÍMBOLOS INVÁLIDOS:\n");
		
		for(Mapeamento e : invalidos) {
			
			//if(!(e.simbolo.compareTo("/*")==0 || e.simbolo.compareTo("*/")==0)) {
				
				System.out.println(e);
			//}
		}
		
		if(lendoComentarioBloco==true){
			
			throw new ComentarioException("" + linhaComentarioBloco);
		}	
	}
	
	/* O método verificarComentarios ainda não está totalmente funcional
	
	public static void verificarComentarios(List<Mapeamento> simbolos) throws ComentarioException{
		
		boolean contComent= false;
		int contLine=0;
		
		for(Mapeamento m : simbolos) {
			
			if(m.simbolo.compareTo("")==0) {
				
				contComent = true;
				
				if(contLine==0) {
					
					contLine = m.numLinha;
				}	
			}
			
			if(m.simbolo.compareTo("")==0) {
					
				contComent = false;
				contLine = 0;
			}
		}
		
		
		
		
	}
	 */
}