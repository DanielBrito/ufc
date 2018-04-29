public class ContaSimplificada{
		
		private String nome;
		private double saldo;
		private boolean contaEspecial;

	ContaSimplificada(String nome, double saldo){

		this.nome = nome;

		if(saldo<0){

			this.saldo = 0;
		}
		else{

			this.saldo = saldo;
		}
	}

	ContaSimplificada(String nome, double saldo, boolean contaEspecial){

		this.nome = nome;

		if(saldo<0){

			this.saldo = 1000;
		}
		else{

			this.saldo = saldo + 1000;
		}

		this.contaEspecial = true;
	}

	public void saque(double valor){

		if(valor>saldo){

			System.out.println("Saldo insuficiente!\n");
		}
		else{

			saldo -= valor;
		}
	}

	public String toString(){

		return "Nome: " + nome + "\nSaldo: R$ " + saldo + "\nConta Especial? " + contaEspecial + "\n";
	}
	

}