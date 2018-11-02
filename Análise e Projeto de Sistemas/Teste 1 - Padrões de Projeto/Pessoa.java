package com.br.teste;

public abstract class Pessoa {
	
	private String nome;
	
	public Pessoa(String nome) {
		
		this.nome = nome;
	}
	
	public String getNome() {
		
		return nome;
	}
	
	public void setNome(String nome) {
		
		this.nome = nome;
	}
	
	@Override
	public String toString() {
		
		return "Nome: " + nome + "\n";
	}
	
	protected abstract boolean validarDocumento(String cpf);
	
	abstract int calcularIdade();
}
