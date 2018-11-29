package com.br.exe1;

public class NokiaPrototype extends SmartphonePrototype{
	
	protected NokiaPrototype(NokiaPrototype nokia) {
		
		this.preco = nokia.getPreco();
		this.modelo = nokia.getModelo();
	}
	
	public NokiaPrototype(double preco, String modelo) {
		
		this.preco = preco;
		this.modelo = modelo;
	}

	@Override
	public String exibirInfo() {
		
		return "Marca: Nokia\nModelo: " + getModelo() + "\nPreço: R$ " + getPreco();
	}

	@Override
	public SmartphonePrototype clonar() {

		return new NokiaPrototype(this);
	}
}
