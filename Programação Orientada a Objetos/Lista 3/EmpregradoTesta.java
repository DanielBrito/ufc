public class EmpregradoTesta{
	
	public static void main(String[] args) {
		
		Empregado funcionario = new Empregado("Daniel Brito", 'A', 40, 50);

		funcionario.calculaSalarioMensal(funcionario);
	}
}