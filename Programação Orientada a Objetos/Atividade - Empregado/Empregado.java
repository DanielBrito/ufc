public class Empregado {

	private String nome;
	private double salario;
	
	public Empregado(String nome, double salario) {
		
		this.nome = nome;
		this.salario = salario;
	}
	
	public double getGastos(){ 	
		
		return salario;
	}
	
	@Override
	public String toString() {	
		
		return "\nNome: " + nome + "\nSalario: " + salario;
	}
}
