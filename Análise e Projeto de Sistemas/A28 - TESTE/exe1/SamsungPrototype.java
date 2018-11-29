package com.br.exe1;

public class SamsungPrototype extends SmartphonePrototype {
	
	protected SamsungPrototype(SamsungPrototype samsung) {
		
		this.preco = samsung.getPreco();
		this.modelo = samsung.getModelo();
	}
	
	public SamsungPrototype(double preco, String modelo) {
		
		this.preco = preco;
		this.modelo = modelo;
	}

	@Override
	public String exibirInfo() {

		return "Marca: Samsung\nModelo: " + getModelo() + "\nPreço: R$ " + getPreco();
	}

	@Override
	public SmartphonePrototype clonar() {

		return new SamsungPrototype(this);
	}
}
