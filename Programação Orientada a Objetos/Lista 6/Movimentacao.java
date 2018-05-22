package com.daniel.lista6;

public class Movimentacao{
	
	private String descricao;
	private double valor;
	private char tipo; // (c)rédito || (d)ébito

	public Movimentacao(String descricao, double valor, char tipo){

		this.descricao = descricao;
		this.valor = valor;
		this. tipo = tipo;
	}

	public String toString(){

		String resultado = "";

		resultado = "Descrição: " + this.descricao +
		            "\nValor: " + this.valor +
		            "\nTipo: " + this.tipo + "\n";

		return resultado;
	}
}