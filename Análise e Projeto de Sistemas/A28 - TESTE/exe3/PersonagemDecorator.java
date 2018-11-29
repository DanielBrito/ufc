package com.br.exe3;

public abstract class PersonagemDecorator implements Personagem {
	
	protected Personagem avatar;
	
	public PersonagemDecorator(Personagem avatar) {
		
		this.avatar = avatar;
	}
	
	public void criar() {
		
		avatar.criar();
	}	
}
