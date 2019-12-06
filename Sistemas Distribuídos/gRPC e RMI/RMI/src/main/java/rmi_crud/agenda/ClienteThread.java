package rmi_crud.agenda;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class ClienteThread { 
	public static void main(String[] args) throws InterruptedException 
	{ 
		final PC pc = new PC(); 

		Thread t1 = new Thread(new Runnable() 
		{ 
			public void run() 
			{ 
				try
				{ 
					try {
						pc.produce();
					} catch (IOException e) {
						e.printStackTrace();
					} 
				} 
				catch(InterruptedException e) 
				{ 
					e.printStackTrace(); 
				} 
			} 
		}); 
 
		Thread t2 = new Thread(new Runnable() 
		{ 
			public void run() 
			{ 
				try
				{ 
					try {
						pc.consume();
					} catch (IOException e) {
						e.printStackTrace();
					} 
				} 
				catch(InterruptedException e) 
				{ 
					e.printStackTrace(); 
				} 
			} 
		}); 
 
		t1.start(); 
		t2.start();  
		t1.join(); 
		t2.join(); 
	} 

	public static class PC 
	{ 
		String buffer_shared = " ";
		boolean update = false;
		
		public void produce() throws InterruptedException, IOException 
		{ 
			while (true) 
			{ 
				synchronized (this) 
				{ 
					while (!buffer_shared.equals(" ")) 
						wait();
					
					String str = " "; 
					
					BufferedReader kb = new BufferedReader(new InputStreamReader(System.in)); 
					if(this.update == false) {	
						System.out.println("\n\n# MENU PRINCIPAL #\n");
						System.out.println("1 - Novo contato");
						System.out.println("2 - Procurar contato");
						System.out.println("3 - Atualizar contato");
						System.out.println("4 - Remover contato");
						System.out.println("0 - Sair");
	
						System.out.print("- > ");
						kb = new BufferedReader(new InputStreamReader(System.in));
						str = kb.readLine();
					}
					else if(this.update == true) {
						str = "5";
					}
					
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
						
						telefones = telefones.substring(0, telefones.length()-1);
						contato += telefones;
						contato += "\0";
						
						buffer_shared = contato;
						//System.out.println("\nProducer produced (Recebi do cliente): "+ buffer_shared);						
						notify(); 
						Thread.sleep(1000); 
					}
					else if(str.equals("2")) { //READ
						String contato = "2_";
						System.out.println("\nPROCURAR CONTATO");
						System.out.print("Digite o nome a ser procurado: ");
						String nome = kb.readLine();
						contato += nome;
						
						buffer_shared = contato;
						//System.out.println("Producer produced (Recebi do cliente): "+ buffer_shared);						
						notify(); 
						Thread.sleep(1000);
					}
		            else if(str.equals("3")) { // UPDATE
						String contato = "3_";
						System.out.println("\nATUALIZAR CONTATO");
						System.out.print("Digite o nome a ser atualizado: ");
						String nome = kb.readLine();
						contato += nome;
						
						buffer_shared = contato;
						//System.out.println("Producer produced (Recebi do cliente): "+ buffer_shared);						
						notify(); 
						Thread.sleep(1000);
					}
		            else if(str.equals("5")) { // UPDATE_DADOS
		            	System.out.println("\nDADOS NOVOS DO CONTATO");
		            	
		            	kb = new BufferedReader(new InputStreamReader(System.in));
						
		            	String contato2 = "5_";

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
						
						telefones = telefones.substring(0, telefones.length()-1);
						contato2 += telefones;
						contato2 += "\0";
						
						buffer_shared = contato2;
						//System.out.println("Producer produced (Recebi do cliente): "+ buffer_shared);						
						notify(); 
						Thread.sleep(1000);
		            }
		            else if(str.equals("4")) { // DELETE
		            	System.out.println("\nREMOVER CONTATO");
		            	
		            	String contato = "4_";
						System.out.print("Digite o nome a ser removido: ");
						String nome = kb.readLine();
						contato += nome;
						
						buffer_shared = contato;
						//System.out.println("Producer produced (Recebi do cliente): "+ buffer_shared);						
						notify(); 
						Thread.sleep(1000);
		            }
		            else if(str.equals("0")) {
		            	System.out.println("Encerrado a conexao com o server.");
		            	System.exit(0);
		            }

				} //end-synchronized
			}//end-while 
		} 

		public void consume() throws InterruptedException, IOException
		{ 
			while (true) 
			{ 
				synchronized (this) 
				{ 
					while (buffer_shared.equals(" ")) 
						wait(); 
					//System.out.println("\nConsumer consumed (Recebi da Thread1)" + buffer_shared);
					
					InterfaceCrud stub = null;
					try
					{
						//Registry registry = LocateRegistry.getRegistry("ip_machine",1099);
						Registry registry = LocateRegistry.getRegistry("localhost",1099); 
						stub = (InterfaceCrud)registry.lookup("echoMsg");
					}
					catch (Exception e)
					{
						System.out.println("Falhou ao iniciar o Cliente.\n"+e);				
						System.exit(0);
					}

					String[] contato = new String[5];
					String strAux = buffer_shared;

					strAux.split("_");
					contato = strAux.split("_");
					
					
					if(contato[0].equals("1")) {
						System.out.println("\nRecebido do servidor: " + stub.adicionarContato(buffer_shared));
						buffer_shared = " ";
						notify(); 
						Thread.sleep(1000); 
					}
					else if(contato[0].equals("2")) {
						System.out.println("\nRecebido do servidor: " + stub.procurarContato(buffer_shared));
						buffer_shared = " ";
						notify(); 
						Thread.sleep(1000); 
					}
					else if(contato[0].equals("3")) {
						String respostaServer = stub.atualizarContato(buffer_shared);
				        if(respostaServer.equals("Nao encontrei nenhum contato")) {
							System.out.println(respostaServer);
							this.update = false;
						}
						else {
							System.out.println("\nRecebido do servidor: " + respostaServer);
							this.update = true;
						}
				        
						buffer_shared = " ";
						notify(); 
						Thread.sleep(1000); 
					}
					else if(contato[0].equals("5")) {
						System.out.println("\nRecebido do servidor: " + stub.atualizarDadosContato(buffer_shared));
						this.update = false;
						buffer_shared = " ";
						notify(); 
						Thread.sleep(1000); 
					}
					else if(contato[0].equals("4")) {
						System.out.println("\nRecebido do servidor: " + stub.deletarContato(buffer_shared));
						buffer_shared = " ";
						notify(); 
						Thread.sleep(1000); 
					}
				}//end-synchronized 
			}//end-while 
		} 
	} 
} 

