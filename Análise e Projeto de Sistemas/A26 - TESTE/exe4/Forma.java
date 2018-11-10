package com.br.exe4;

public abstract class Forma {
	
	protected Desenhar desenhar;
	
	public Forma(Desenhar desenhar) {
		
		this.desenhar = desenhar;
	}
	
	public abstract void criar();

}
