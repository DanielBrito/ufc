package com.br.exe1;

public abstract class SmartphonePrototype {
	
	protected double preco;
	protected String modelo;
	
	public abstract String exibirInfo();
	
	public abstract SmartphonePrototype clonar();
	
	public double getPreco() {
		
		return preco;
	}
	
	public String getModelo() {
		
		return modelo;
	}
	
	public void setPreco(double preco) {
		
		this.preco = preco;
	}
	
	public void setModelo(String modelo) {
		
		this.modelo = modelo;
	}
}
