package com.br.exe2;

public class Cliente {

	public static void main(String[] args) {
		
		int userKey = UtilConstantes.CODIGO_BRADESCO;
		
		FabricaAbstrata fbs = FabricaAbstrata.configurarInstancia(userKey);
		MensagemLogon telaLogon = fbs.gerarMensagemLogon();
		//MensagemLogout telaLogout = fbs.gerarMensagemLogout();
		
		telaLogon.mostrarTelaGrafica();
		//telaLogout.mostrarTelaGrafica();
	}
}
