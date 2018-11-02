package com.br.trabalho2;

public class Goldbach {
	
	private Primos p;
	private int limiteSuperior;
	
	public Goldbach(int n) {
		
		this.limiteSuperior = n;
	}
	
	public void verificarIntervalo() {
		
		for(int i=6; i<=limiteSuperior; i+=2) {
			
			teorema(i);
		}
	}
	
	public void teorema(int x) {
		
		if(this.p == null) {
			
			this.p = new Primos();
			
			p.primosAteN(x);
		}
		else {
			
			p.primosAteN(x);
		}
		
		for(int a = 0; a < p.getTamanho(); a++) {
			
			for(int b = 0; b < p.getTamanho(); b++) {
				
				if((p.getIndice(a) + p.getIndice(b)) == x) {
					
					System.out.println("Goldbach " + x + " = " + p.getIndice(a) + " + " + p.getIndice(b) + " (Ok)");
					
					return;
				}
			}
		}
	}
}
