package com.br.exe3;

public class PocaoDecorator extends PersonagemDecorator {

	public PocaoDecorator(Personagem avatar) {
		
		super(avatar);
	}
	
	@Override
	public void criar() {
		
		avatar.criar();
		setEquipamento(avatar);
	}
	
	private void setEquipamento(Personagem avatar) {
		
		System.out.println("Equipamento: Poção venenosa");
	}
}
