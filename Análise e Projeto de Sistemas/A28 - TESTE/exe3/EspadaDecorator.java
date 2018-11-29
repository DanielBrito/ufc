package com.br.exe3;

public class EspadaDecorator extends PersonagemDecorator {

	public EspadaDecorator(Personagem avatar) {
		
		super(avatar);
	}
	
	@Override
	public void criar() {
		
		avatar.criar();
		setArma(avatar);
	}
	
	private void setArma(Personagem avatar) {
		
		System.out.println("Equipamento: Espada");
	}
}
