public class TestaAutomovel {

	public static void main(String[] args) {
		
		Automovel a1 = new Automovel("Siena", "Cinza", 1);
		Automovel a2 = new AutomovelBasico("Fusca", "Azul", 2, true, true, true);
		Automovel a3 = new AutomovelLuxo("D-20", "Preta", 3, false, true, false, false, false, true);
		
		System.out.println("\nAutomóvel\n" + a1.toString());
		imprime(a1);
		
		System.out.println("\nAutomóvel básico\n" + a2.toString());
		imprime(a2);
		
		System.out.println("\nAutomóvel de luxo\n" + a3.toString());
		imprime(a3);
	}
	
	public static void imprime(Automovel a) {

		System.out.println("\nInformações");
		System.out.println("Valor: " + a.quantoCusta());
		System.out.printf("Até %d prestações de %.2f\n", a.quantasPrestacoes(), a.quantoCusta()/a.quantasPrestacoes());
	}
}
