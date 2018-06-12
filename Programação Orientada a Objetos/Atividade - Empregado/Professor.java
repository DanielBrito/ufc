public class Professor extends Empregado {
	
	private int horas;
	
	public Professor(String nome, double salario, int horas) {	
		
		super(nome, salario);
		this.horas = horas;
	}
	
	@Override
	public double getGastos(){
		
		double valor = super.getGastos() + (horas * 1);	
		return valor;
	}
	
	@Override
	public String toString() {
		
		return super.toString() + "\nHoras trabalhadas: " + horas + "\nSalario com as horas trabalhadas: " + getGastos();
	}
}
