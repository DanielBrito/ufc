package rmi_crud.agenda;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;


public class Cliente {
	
	public static void main (String[] args) throws Exception
	{
		InterfaceCrud stub = null;
		try
		{
			Registry registry = LocateRegistry.getRegistry(1099); 
			stub = (InterfaceCrud)registry.lookup("echoMsg");
		}
		catch (Exception e)
		{
			System.out.println("Falhou ao iniciar o Cliente.\n"+e);				
			System.exit(0);
		}
		
		String str; 
		boolean sair = false;
		BufferedReader kb = new BufferedReader(new InputStreamReader(System.in)); 

		while (sair==false) { 
			System.out.println("\n\n# MENU PRINCIPAL #\n");
			System.out.println("1 - Novo contato");
			System.out.println("2 - Procurar contato");
			System.out.println("3 - Atualizar contato");
			System.out.println("4 - Remover contato");
			System.out.println("0 - Sair");

			System.out.print("- > ");
			str = kb.readLine();

			if(str.equals("1")) { //CREATE

				String contato = "1_";

				System.out.println("\nNOVO CONTATO");

				System.out.print("Digite o nome: ");
				String nome = kb.readLine();

				contato += nome + "_";

				System.out.print("Digite o endereco: ");
				String endereco = kb.readLine();

				contato += endereco + "_";

				System.out.print("Digite o email: ");
				String email = kb.readLine();

				contato += email + "_";

				String telefones = "";

				while(true) {

					System.out.print("Digite o telefone (ou deixe em branco para sair): ");
					String telefone = kb.readLine();

					if(telefone.length()==0) {

						break;
					}

					telefones = telefones + telefone + "+";
				}
				System.out.println(telefones);
				telefones = telefones.substring(0, telefones.length()-1);
				System.out.println(telefones);
				contato += telefones;
				System.out.println(contato);
				contato += "\0";
				
				System.out.println("Recebido do servidor: " + stub.adicionarContato(contato));			
			}
            else if(str.equals("2")) { //READ
				String contato = "2_";
				System.out.println("\nPROCURAR CONTATO");
				System.out.print("Digite o nome a ser procurado: ");
				String nome = kb.readLine();
				contato += nome;
				System.out.println("Recebido do servidor: " + stub.procurarContato(contato));
			}
            else if(str.equals("3")) { // UPDATE
				String contato = "3_";
				System.out.println("\nATUALIZAR CONTATO");
				System.out.print("Digite o nome a ser atualizado: ");
				String nome = kb.readLine();
				contato += nome;
				
				String respostaServer = stub.atualizarContato(contato);
		        
		        if(respostaServer.equals("Nao encontrei nenhum contato")) {
					System.out.println(respostaServer);				
				}
				else {
					
					kb = new BufferedReader(new InputStreamReader(System.in));
					
					System.out.println("Recebi do servidor: "+ respostaServer);
					
					String contato2 = "5_";

					System.out.println("\nDADOS NOVOS DO CONTATO");

					System.out.print("Digite o nome: ");
					String nome2 = kb.readLine();

					contato2 += nome2 + "_";

					System.out.print("Digite o endereco: ");
					String endereco = kb.readLine();

					contato2 += endereco + "_";

					System.out.print("Digite o email: ");
					String email = kb.readLine();

					contato2 += email + "_";

					String telefones = "";

					while(true) {

						System.out.print("Digite o telefone (ou deixe em branco para sair): ");
						String telefone = kb.readLine();

						if(telefone.length()==0) {

							break;
						}

						telefones = telefones + telefone + "+";
					}
					//System.out.println(telefones);
					telefones = telefones.substring(0, telefones.length()-1);
					//System.out.println(telefones);
					contato2 += telefones;
					//System.out.println(contato);
					contato2 += "\0";
					System.out.println("ATUALIZAR: "+contato2);
					
					
					System.out.println("Recebido do servidor: " + stub.atualizarDadosContato(contato2));

				}
				
			}
            else if(str.equals("4")) { // DELETE
            	String contato = "4_";
				System.out.println("\nREMOVER CONTATO");
				System.out.print("Digite o nome a ser removido: ");
				String nome = kb.readLine();
				contato += nome;
				System.out.println("Recebido do servidor: " + stub.deletarContato(contato));
            }
		}
	}
}