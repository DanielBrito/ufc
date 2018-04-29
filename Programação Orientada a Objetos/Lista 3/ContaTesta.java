public class ContaTesta{
	
	public static void main(String[] args) {
		
		ContaSimplificada contaSimples = new ContaSimplificada("Daniel Brito", 100);
		ContaSimplificada contaEspecial = new ContaSimplificada("Maria da Silva", 200, true);

		System.out.println(contaSimples);
		System.out.println(contaEspecial);

		contaSimples.saque(50);
		contaEspecial.saque(1000);

		System.out.println(contaSimples);
		System.out.println(contaEspecial);

		contaSimples.saque(60);
		contaEspecial.saque(300);

		System.out.println(contaSimples);
		System.out.println(contaEspecial);
	}
}