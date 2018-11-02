package com.br.teste;

public interface Colecao {
	
	public boolean inserir(Pessoa p);
	public boolean remover();
	public boolean remover(int i);
	public void atualizar(int i, Pessoa p);
	public boolean pesquisar(Pessoa p);
	public boolean colecaoEstaVazia();
	public void imprimirDadosColecao();
	public Pessoa retornarObjeto(int i);
}