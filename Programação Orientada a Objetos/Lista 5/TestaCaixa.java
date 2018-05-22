package com.daniel.lista5;

public class TestaCaixa {

	public static void main(String[] args) {
			
		SimuladorDeCaixa caixa1 = new SimuladorDeCaixa(1);
		SimuladorDeCaixa caixa2 = new SimuladorDeCaixa(2);
		SimuladorDeCaixa caixa3 = new SimuladorDeCaixa(3);
		SimuladorDeCaixa caixa4 = new SimuladorDeCaixa(4);
		SimuladorDeCaixa caixa5 = new SimuladorDeCaixa(5);
		
		System.out.println();
		
		caixa1.iniciaAtendimento();
		caixa2.iniciaAtendimento();
		caixa3.iniciaAtendimento();
		caixa4.iniciaAtendimento();
		caixa5.iniciaAtendimento();
		
		caixa1.iniciaAtendimento();
		caixa2.iniciaAtendimento();
		caixa3.iniciaAtendimento();
		caixa4.iniciaAtendimento();
		caixa5.iniciaAtendimento();
	}
}
