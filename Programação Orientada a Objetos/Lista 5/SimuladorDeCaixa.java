package com.daniel.lista5;

public class SimuladorDeCaixa {
	
	private static int numeroDoCliente;
	private int numeroDoCaixa;
	
	public SimuladorDeCaixa(int numeroDoCaixa) {
		
		this.numeroDoCaixa = numeroDoCaixa;
		this.numeroDoCliente = 0;
		
		System.out.println("O caixa " + numeroDoCaixa + " entrou em operação.");
	}
	
	public void iniciaAtendimento() {
		
		System.out.println("Cliente " + numeroDoCliente + " dirija-se ao caixa " + numeroDoCaixa);
		numeroDoCliente++;
	}
}
