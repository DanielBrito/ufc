package com.br.exe3;

public class BancoFactory {
	
	private BancoFactory() {};
	
	public static Logon factoryMethod(int codigo) {
		
		if(codigo==UtilConstantes.CODIGO_BRADESCO) {
			
			return new LogonBradesco();
		}
		else
		if(codigo==UtilConstantes.CODIGO_ITAU) {
			
			return new LogonItau();
		}
		else {
			
			return null;
		}
	}

}
