public class Coordenador extends Professor {
	
	private double gratificacao; 
	
	public Coordenador(String nome, double salario, int horas, double gratificacao) {
		
		super(nome, salario, horas);
		this.gratificacao = gratificacao;
	}
	
	@Override
	public double getGastos() {	
		
		return super.getGastos() + gratificacao;
	}
	
	@Override
	public String toString() {	
		
		return super.toString() + "\nGratificação: " + gratificacao + "\nSalario gratificado e com as horas trabalhadas: " + getGastos() + "\n";
	}
	
	public double getGratificacao() {
		
		return gratificacao;
	}
}