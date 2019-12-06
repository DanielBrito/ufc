package eda.atividade5;

public class Objeto {
	
	String nome;
	double peso, valor;
	
	public Objeto(String nome, double peso, double valor) {

		this.nome = nome;
		this.peso = peso;
		this.valor = valor;
	}
	
	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		this.nome = nome;
	}

	public double getPeso() {
		return peso;
	}

	public void setPeso(double peso) {
		this.peso = peso;
	}

	public double getValor() {
		return valor;
	}

	public void setValor(double valor) {
		this.valor = valor;
	}

	@Override
	public String toString() {
		return "Objeto [nome=" + nome + ", peso=" + peso + ", valor=" + valor + "]\n";
	}
}
