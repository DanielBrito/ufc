package com.daniel.lista6;

import java.util.ArrayList;

public class Conta{
	
	private int numero;
	private double saldo;
	private boolean status;
	private boolean especial;
	private double limite;
	private ArrayList <Movimentacao> movimentacoes = new ArrayList <Movimentacao>();

	public Conta(int numero, double saldo, boolean especial, double limite){

		this.numero = numero;

		if(saldo>=0){

			this.saldo = saldo;
		}

		this.especial = especial;
		this.status = true;

		if(limite>=0){

			this.limite = limite;
		}
	}

	public double getSaldo(){

		return this.saldo;
	}

	public void setSaldo(double valor){

		this.saldo = valor;
	}
	
	public void setStatus(boolean status) {
		
		this.status = status;
	}

	public double getLimite(){

		return this.limite;
	}
	
	public int getNumero() {
		
		return this.numero;
	}
	
	public boolean getStatus() {
		
		return this.status;
	}

	public void setMovimentacao(Movimentacao m){

		movimentacoes.add(m);
	}

	public String imprimirMovimentacoes(){
		
		String resultado = "";

		for(int i=0; i<movimentacoes.size(); i++) {
			
			resultado += movimentacoes.get(i).toString();
		}
		
		return resultado;
	}

	public String toString(){

		String resultado = "";

		resultado = "Número: " + this.numero +
		            "\nSaldo: " + this.saldo +
		            "\nAtiva: " + this.status +
		            "\nEspecial: " + this.especial +
		            "\nLimite: " + this.limite;

		return resultado;
	}
}
