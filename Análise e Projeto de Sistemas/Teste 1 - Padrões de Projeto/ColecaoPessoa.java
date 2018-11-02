package com.br.teste;

public final class ColecaoPessoa implements Colecao{
	
	private Pessoa[] dados = new Pessoa[100];
	private int posicaoCorrente=0;
	
	private static final ColecaoPessoa colecao = new ColecaoPessoa();
	
	private ColecaoPessoa() {
		
	}
	
	public static ColecaoPessoa getInstance() {
		
		return colecao;
	}

	@Override
	public boolean inserir(Pessoa p) {

		if(posicaoCorrente==100) {
			
			return false;
		}
		else		
		if(p==null) {
			
			return false;
		}
		else {
			
			dados[posicaoCorrente++] = p;
		}

		return true;
	}

	@Override
	public boolean remover(int i) {

		if(posicaoCorrente==0 || i>=posicaoCorrente) {
			
			return false;
		}
		else {
			
			for(int j=i; j<posicaoCorrente-1; j++) {
				
				dados[j] = dados[j+1];
			}
			
			--posicaoCorrente;
		}
		
		return true;
	}
	
	@Override
	public boolean remover() {

		if(posicaoCorrente==0) {
			
			return false;
		}
		
		--posicaoCorrente;
		
		return true;
	}

	@Override
	public void atualizar(int i, Pessoa p) {
		
		if(i<0 || i>=posicaoCorrente || p==null) {
			
			System.out.println("\nNão foi possível atualizar registro.");
		}
		else {
			
			dados[i] = p;
			
			System.out.println("\nRegistro atualizado com sucesso.");
		}
	}

	@Override
	public boolean pesquisar(Pessoa p) {
		
		for(int i=0; i<posicaoCorrente; i++) {
			
			if(dados[i].equals(p)) {
				
				return true;
			}
		}
		
		return false;
	}

	@Override
	public boolean colecaoEstaVazia() {

		return posicaoCorrente==0;
	}

	@Override
	public void imprimirDadosColecao() {

		if(posicaoCorrente==0) {
			
			System.out.println("\nA coleção está vazia.");
		}
		
		for(int i=0; i<posicaoCorrente; i++) {
			
			System.out.println("\n" + dados[i].toString());			
		}		
	}

	@Override
	public Pessoa retornarObjeto(int i) {
		
		if(i<0 || i>=posicaoCorrente) {
			
			return null;
		}
		
		return dados[i];
	}
}