package com.daniel.lista6;

public class TestaBanco {

	public static void main(String[] args) {

		Banco bradesco = new Banco();
		
		bradesco.criarConta(1111, 1000.00, true, 500);
		bradesco.criarConta(2222, 2000.00, false, 700);
		bradesco.criarConta(3333, 900.00, true, 300);
		bradesco.criarConta(4444, 700.00, false, 250);
		bradesco.criarConta(5555, 6000.00, true, 1000);
		
		bradesco.sacar(1111, 500);
		bradesco.excluirConta(2222);
		bradesco.transferir(1111, 2222, 200);

		bradesco.gerarExtrato(1111);
		bradesco.gerarExtrato(2222);
		bradesco.gerarExtrato(1111);
	}

}