import java.util.ArrayList;

public class Banco{

	private ArrayList <Conta> contas = new ArrayList <Conta>();

	public void criarConta(int numero, double saldo, boolean especial, double limite){

		Conta conta = new Conta(numero, saldo, especial, limite);

		contas.add(conta);
	}
	
	public void excluirConta(int numero) {
		
		int encontrou = 0;
		
		for(int i=0; i<contas.size(); i++) {
			
			if(numero==contas.get(i).getNumero()) {
				
				contas.get(i).setStatus(false);
				
				System.out.println("Conta excluída com sucesso!\n");
				
				encontrou = 1;
			}
		}
		
		if(encontrou==0) {
			
			System.out.println("Erro! A conta não existe!\n");
		}
	}

		
	public void sacar(int numero, double valor){
		
		int encontrou = 0;
		
		for(int i=0; i<contas.size(); i++) {
			
			if((contas.get(i).getNumero()==numero) && (contas.get(i).getStatus()!=false)) {
				
				if(valor > (contas.get(i).getSaldo() + contas.get(i).getLimite())) {
					
					System.out.println("Erro! O valor a ser sacado excede o saldo!\n");
				}
				else {
					
					contas.get(i).setSaldo(contas.get(i).getSaldo()-valor);
					
					System.out.println("Saque realizado com sucesso!\n");
					
					Movimentacao m = new Movimentacao("Saque", valor, 'd');
					contas.get(i).setMovimentacao(m);
					
					encontrou = 1;
				}
			}
		}
		
		if(encontrou==0) {
			
			System.out.println("Erro! A conta não existe!\n");
		}
	}

	public void depositar(int numero, double valor){
		
		int encontrou = 0;

		if(valor<0){

			System.out.println("Erro! Não é possível depositar um valor negativo!\n");
		}
		else{
			
			for(int i=0; i<contas.size(); i++) {
				
				if((contas.get(i).getNumero()==numero) && (contas.get(i).getStatus()!=false)) {
					
					contas.get(i).setSaldo(contas.get(i).getSaldo()+valor);
					
					System.out.println("Depósito realizado com sucesso!\n");
					
					Movimentacao m = new Movimentacao("Depósito", valor, 'c');
					contas.get(i).setMovimentacao(m);
					
					encontrou = 1;					
				}
			}
		}
		
		if(encontrou==0) {
			
			System.out.println("Erro! A conta não existe!\n");
		}
	}

	public void transferir(int origem, int destino, double valor){
		
		int encontrouOrigem = 0;
		int encontrouDestino = 0;
		int erro = 0;
		
		if(valor<0){

			System.out.println("Erro! Não é possível transferir um valor negativo!\n");
			
			encontrouOrigem = -1;
			encontrouDestino = -1;
		}
		else {
			
			for(int i=0; i<contas.size(); i++) {
			
				if((contas.get(i).getNumero()==origem) && (contas.get(i).getStatus()!=false)) {
					
					encontrouOrigem = 1;
					
					for(int j=0; j<contas.size(); j++) {
						
						if((contas.get(j).getNumero()==destino) && (contas.get(j).getStatus()!=false)) {
							
							encontrouDestino = 1;
							
							if(valor > (contas.get(i).getSaldo()+contas.get(i).getLimite())) {
								
								erro = 1;
							}
							else {
								
								contas.get(i).setSaldo(contas.get(i).getSaldo()-valor);
								contas.get(j).setSaldo(contas.get(j).getSaldo()+valor);
								
								Movimentacao o = new Movimentacao("Transferência", valor, 'd');
								contas.get(i).setMovimentacao(o);

								Movimentacao d = new Movimentacao("Transferência", valor, 'c');
								contas.get(j).setMovimentacao(d);
								
								System.out.println("Transferência realizada com sucesso!\n");
							}
						}
					}
					
				}
			}
		}
		
		if(encontrouOrigem==0) {
			
			System.out.println("Erro! A conta origem não existe!\n");
		}
		
		if(encontrouDestino==0) {
			
			System.out.println("Erro! A conta destino não existe!\n");
		}
		
		if(erro==1) {
			
			System.out.println("Erro! O valor a ser transferido excede o saldo!\n");
		}
	}
	
	public void emitirSaldo(int numero) {
		
		int encontrou = 0;
		
		for(int i=0; i<contas.size(); i++) {
			
			if((contas.get(i).getNumero()==numero) && (contas.get(i).getStatus()!=false)) {
				
				System.out.println("Saldo: R$ " + contas.get(i).getSaldo() + "\n");
				
				encontrou = 1;
			}
		}
		
		if(encontrou==0) {
			
			System.out.println("Erro! A conta não existe!\n");
		}
	}

	public void gerarExtrato(int numero) {
		
		int encontrou = 0;
		
		for(int i=0; i<contas.size(); i++) {
			
			if((contas.get(i).getNumero()==numero) && (contas.get(i).getStatus()!=false)) {
				
				System.out.println("* DADOS DA CONTA *\n");
				System.out.println(contas.get(i).toString());;
				System.out.println("\n* EXTRATO *\n");
				System.out.println(contas.get(i).imprimirMovimentacoes());
				
				encontrou = 1;
			}
		}
		
		if(encontrou==0) {
			
			System.out.println("Erro! A conta não existe!\n");
		}
	}
}
