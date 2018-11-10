package com.br.exe2;

public abstract class FabricaAbstrata {
	
	public abstract MensagemLogon gerarMensagemLogon();
	public abstract MensagemLogout gerarMensagemLogout();
	
	public static FabricaAbstrata configurarInstancia(int codigoBanco) {
		
		if(codigoBanco==UtilConstantes.CODIGO_ITAU) {
			
			return new FabricaItau();
		}
		else
		if(codigoBanco==UtilConstantes.CODIGO_BRADESCO) {
			
			return new FabricaBradesco();
		}
		
		return null;
	}

}
