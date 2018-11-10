package com.br.exe3;

public class Cliente {

	public static void main(String[] args) {

		Logon b = BancoFactory.factoryMethod(UtilConstantes.CODIGO_BRADESCO);
		
		b.mostrarTelaLogin();
	}
}