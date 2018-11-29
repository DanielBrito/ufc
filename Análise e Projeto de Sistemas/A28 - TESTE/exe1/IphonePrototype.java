package com.br.exe1;

public class IphonePrototype extends SmartphonePrototype{
	
	protected IphonePrototype(IphonePrototype iphone) {
		
		this.preco = iphone.getPreco();
		this.modelo = iphone.getModelo();
	}
	
	public IphonePrototype(double preco, String modelo) {
		
		this.preco = preco;
		this.modelo = modelo;
	}

	@Override
	public String exibirInfo() {

		return "Marca: Iphone\nModelo: " + getModelo() + "\nPreço: R$ " + getPreco();
	}

	@Override
	public SmartphonePrototype clonar() {
		
		return new IphonePrototype(this);
	}
}
