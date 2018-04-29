public class Empregado{
	
	private String nome;
	private char nivel; /* A (ALTO) ou B (BAIXO) */
	private int horasTrabalhadasMes;
	private double salarioPorHora;

	Empregado(String nome, char nivel, int horasTrabalhadasMes, double salarioPorHora){

		this.nome = nome;
		this.nivel = nivel;
		this.horasTrabalhadasMes = horasTrabalhadasMes;
		this.salarioPorHora = salarioPorHora;
	}

	public String toString(){

		return "Nome: " + nome + "\nNivel: " + this.nivel + "\nHoras trabalhadas: " + horasTrabalhadasMes + "\nSalario por hora: R$ " + salarioPorHora;
	}

	void calculaSalarioMensal(Empregado func){

		double salario;

		salario = horasTrabalhadasMes*salarioPorHora;

		if(func.nivel=='A'){

			salario *= 1.20;
		}

		System.out.println(func.toString());

		System.out.println("Salário mensal: R$" + salario);
	}
}