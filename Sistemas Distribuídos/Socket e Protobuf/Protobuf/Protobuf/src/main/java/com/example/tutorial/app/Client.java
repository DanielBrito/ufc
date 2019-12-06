package com.example.tutorial.app;

import java.io.*; 
import java.net.*; 

public class Client {

	public static void main(String args[]) throws Exception 
	{ 

		// Create client socket 
		Socket s = new Socket("localhost", 5000); 

		// to send data to the server 
		DataOutputStream dos 
		= new DataOutputStream( 
				s.getOutputStream()); 

		// to read data coming from the server 
		BufferedReader br 
		= new BufferedReader( 
				new InputStreamReader( 
						s.getInputStream())); 

		// to read data from the keyboard 
		BufferedReader kb 
		= new BufferedReader( 
				new InputStreamReader(System.in)); 
		String str, str1; 

		boolean sair = false;

		// repeat as long as exit 
		// is not typed at client 
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
				dos.writeBytes(contato + "\n");
				
				br = new BufferedReader(new InputStreamReader(s.getInputStream())); // LIMPA BUFFER
				String respostaServer = br.readLine(); /*Resposta do servidor*/
				System.out.println("Recebi do servidor: "+respostaServer);
			}
			else if(str.equals("2")) { //READ
				String contato = "2_";
				System.out.println("\nPROCURAR CONTATO");
				System.out.print("Digite o nome a ser procurado: ");
				String nome = kb.readLine();
				contato += nome;
				dos.writeBytes(contato + "\n");
				
				br = new BufferedReader(new InputStreamReader(s.getInputStream())); //LIMPA BUFFER
				String respostaServer = br.readLine(); /*Resposta do servidor*/
				System.out.println("Recebi do servidor: "+respostaServer);
				
			}
			else if(str.equals("3")) { //UPDATE
				String contato = "3_";
				System.out.println("\nATUALIZAR CONTATO");
				System.out.print("Digite o nome a ser atualizado: ");
				String nome = kb.readLine();
				contato += nome;
				dos.writeBytes(contato + "\n");
				
				br = new BufferedReader(new InputStreamReader(s.getInputStream())); //LIMPA BUFFER
				String respostaServer = br.readLine(); /*Resposta do servidor*/
				
				if(respostaServer.equals("Nao encontrei nenhum contato")) {
					System.out.println(respostaServer);
					
				}
				else {
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
					dos.writeBytes(contato2 + "\n");	
					
					br = new BufferedReader(new InputStreamReader(s.getInputStream())); //LIMPA BUFFER
					String respostaServer2 = br.readLine(); /*Resposta do servidor*/
					System.out.println("Recebi do servidor: "+respostaServer2);
				}
			}
			else if(str.equals("4")) { //DELETE
				String contato = "4_";
				System.out.println("\nREMOVER CONTATO");
				System.out.print("Digite o nome a ser removido: ");
				String nome = kb.readLine();
				contato += nome;
				dos.writeBytes(contato + "\n");
				
				br = new BufferedReader(new InputStreamReader(s.getInputStream())); //LIMPA BUFFER
				String respostaServer = br.readLine(); /*Resposta do servidor*/
				System.out.println("Recebi do servidor: "+respostaServer);
			}
			else if(str.equals("0")){
				sair = true;
			}

			// send to the server 
			//dos.writeBytes(str + "\n"); 

			// receive from the server 
			/*
			str1 = br.readLine(); 

			System.out.println(str1);*/ 
		} 

		// close connection. 
		dos.close(); 
		br.close(); 
		kb.close(); 
		s.close(); 
	} 

}
