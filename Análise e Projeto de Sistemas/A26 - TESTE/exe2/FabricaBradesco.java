package com.br.exe2;

public class FabricaBradesco extends FabricaAbstrata{

	@Override
	public MensagemLogon gerarMensagemLogon() {
		
		return new MensagemLogonBradesco("BRADESCO", "Seja bem vindo!");
	}

	@Override
	public MensagemLogout gerarMensagemLogout() {
		
		return new MensagemLogoutBradesco("BRADESCO", "Volte sempre!");
	}
}
