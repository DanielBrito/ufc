import java.util.ArrayList;

public class Testa {

	public static void main(String[] args) {
		
		Empregado emp = new Empregado("Maria", 2000.0);
		Professor prof = new Professor("Carlos", 5000.0, 5);
		Coordenador coord = new Coordenador("Daniel", 13000.0, 20, 1.5);
		
		ArrayList<Empregado> folha = new ArrayList<Empregado>();
		
		folha.add(emp);
		folha.add(prof);
		folha.add(coord);
		
		System.out.println(emp.toString());
		System.out.println(prof.toString());
		System.out.println(coord.toString());
		
		System.out.println("Empréstimo para Empregado: " + calculaEmprestimo(emp));
		System.out.println("Empréstimo para Professor: " + calculaEmprestimo(prof));
		System.out.println("Empréstimo para Coordenador: " + calculaEmprestimo(coord));
		
		System.out.println("\nGasto total: " + gastoTotal(folha));
	}
	
	public static double gastoTotal(ArrayList<Empregado> folha) {
		
		double total = 0.0;
		
		for(Empregado e : folha) {
			
			total+=e.getGastos();
		}
		
		return total;
	}
	
	public static double calculaEmprestimo(Empregado e) {
		
		return 4000.0;
	}
	
	public static double calculaEmprestimo(Professor e) {
		
		double emprestimo = 0.0;
		
		if(e instanceof Coordenador) {
			
			emprestimo = 5*e.getGastos();
		}
		else
		if(e instanceof Professor) {
			
			emprestimo = 4*e.getGastos();
		}
		
		return emprestimo;
	}
}
