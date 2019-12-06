package com.example.tutorial.app;

import java.awt.List;
import java.io.*; 
import java.net.*;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.Arrays;

import com.example.tutorial.AddressBookProtos.AddressBook;
import com.example.tutorial.AddressBookProtos.Person;
import com.example.tutorial.AddressBookProtos.Person.Builder;

public class CrudServer {

//	static String encodeValue(String value) {
//		try {
//			return URLEncoder.encode(value, StandardCharsets.UTF_8.toString());
//		} catch (UnsupportedEncodingException ex) {
//			throw new RuntimeException(ex.getCause());
//		}
//	}

	public static void main(String args[]) 
			throws Exception 
	{ 

		if (args.length != 1) {
			System.err.println("Usage:  AddPerson ADDRESS_BOOK_FILE");
			System.exit(-1);
		}

		AddressBook.Builder addressBook = AddressBook.newBuilder();

		// Read the existing address book.
		try {
			FileInputStream input = new FileInputStream(args[0]);
			try {
				addressBook.mergeFrom(input);
			} finally {
				try { input.close(); } catch (Throwable ignore) {}
			}
		} catch (FileNotFoundException e) {
			System.out.println(args[0] + ": File not found.  Creating a new file.");
		}

		// Create server Socket 
		ServerSocket ss = new ServerSocket(5000); 
		System.out.println("Aguardando conexao...");
		// connect it to client socket 
		Socket s = ss.accept(); 

		// to send data to the client 
		PrintStream ps 
		= new PrintStream(s.getOutputStream()); 

		// to read data coming from the client 
		BufferedReader br 
		= new BufferedReader( 
				new InputStreamReader( 
						s.getInputStream())); 

		// to read data from the keyboard 
		BufferedReader kb 
		= new BufferedReader( 
				new InputStreamReader(System.in)); 

		// server executes continuously 
		while (true) { 

			String str, str1; 

			// repeat as long as the client 
			// does not send a null string 

			// read from client 
			while (true) {
				System.out.println("\n\nConexao esta estabelecida!");
				System.out.println("Aguardando requisicao...");
				br = new BufferedReader(new InputStreamReader(s.getInputStream())); 
				str = "";
				str = br.readLine();
				System.out.println("Recebi do cliente: " + str);
				if(str.equals("0")){
					ps.println("OK");
					System.out.println("Servidor encerrou a conexao!");
					break;
				}
				String[] contato = new String[5];
				String strAux = str;

				strAux.split("_");
				contato = strAux.split("_");

				if(contato[0].equals("1")) { //CREATE
					System.out.println("\n\nCREATE - Operacao de criacao...");
					//System.out.println(contato[0] + contato[1] + contato[2] + contato[3] + contato[4]);

					addressBook.addPeople(
							PromptForAddress(new BufferedReader(new InputStreamReader(System.in)),
									System.out, contato));

					// Write the new address book back to disk.
					FileOutputStream output = new FileOutputStream(args[0]);
					try {
						addressBook.build().writeTo(output);
					} finally {
						output.close();
					}
					ps.println("Contato criado com sucesso!");
					System.out.println("Contato salvo com sucesso!");
				}
				else if(contato[0].equals("2")) { //READ
					System.out.println("\n\nREAD - Operacao de busca...");
					String auxContato = contato[1];
					System.out.println("Contato a ser buscado: " + auxContato);
					String enviarContato = "";
					boolean valida = false;

					for(Person person : addressBook.getPeopleList()) {
						if(person.getName().equals(auxContato)) {
							enviarContato += "Id: " + person.getId() +" Nome: " + person.getName() +  " Endereco: " + person.getEndereco() + " Email: " + person.getEmail()+ " Telefones: "; 
							for (Person.PhoneNumber phoneNumber : person.getPhonesList()) {
								//System.out.println("Telefone: " + phoneNumber.getNumber());
								enviarContato += phoneNumber.getNumber() + " ";
							}
							valida = true;
							break; //para retornar a primeira ocorrencia
						}
					}
					if(valida == true) {
						System.out.println("Estou enviando para o cliente o contato:"+ enviarContato);
						ps.println(enviarContato);
					}
					else {					    	
						System.out.println("Nao encontrei nenhum contato");
						ps.println("Nao encontrei nenhum contato");
					}
				}
				else if(contato[0].equals("3")) { //UPDADE
					System.out.println("\n\nUPDATE - Operacao de atualizacao...");
					String auxContato = contato[1];
					String enviarContato = "";
					boolean valida = false;

					for(Person person : addressBook.getPeopleList()) {
						if(person.getName().equals(auxContato)) {
							enviarContato += "Id: " + person.getId() +" Nome: " + person.getName() +  " Endereco: " + person.getEndereco() + " Email: " + person.getEmail()+ " Telefones: "; 
							for (Person.PhoneNumber phoneNumber : person.getPhonesList()) {
								//System.out.println("Telefone: " + phoneNumber.getNumber());
								enviarContato += phoneNumber.getNumber() + "\n";
							}
							valida = true;
							break; //para retornar a primeira ocorrencia
						}
					}
					if(valida == true) {
						//System.out.println("Estou enviando para o cliente o contato:"+ enviarContato);
						ps.println(enviarContato);
						String recebidoClient = br.readLine();
						System.out.println("Dados do cliente: " + recebidoClient);

						String[] newContato = new String[5];
						String newStrAux = recebidoClient;

						newContato = newStrAux.split("_");
						/*
						System.out.println("Id: " + newContato[0]);
						System.out.println("Nome: "+ newContato[1]);
						System.out.println("Endereco " + newContato[2]);
						System.out.println("Email: "+ newContato[3]);
						System.out.println("Telefones: " + newContato[4]);
						System.out.println("Nome antigo:"+contato[1]);
						 */

						String nomeAntigo = contato[1];
						boolean encontrou=false;
						AddressBook.Builder addressBookBackup = AddressBook.newBuilder();
						for(Builder person : addressBook.getPeopleBuilderList()) {
							if(person.getName().equals(nomeAntigo)) {
								addressBookBackup.addPeople(
										PromptForAddress(new BufferedReader(new InputStreamReader(System.in)),
												System.out,newContato));	
								encontrou = true;
							}
							else {
								addressBookBackup.addPeople(person);
							}
						}
						if(encontrou==true) {
							// Write the new address book back to disk.
							FileOutputStream output = new FileOutputStream(args[0]);
							try {
								addressBookBackup.build().writeTo(output);
							} finally {
								output.close();
							}

							ps.println("Contato atualizado com sucesso!");
						}
						else {
							System.out.println("deu RUIM");
						}

					}
					else if(valida == false){					    	
						ps.println("Nao encontrei nenhum contato");
					}
				}
				else if(contato[0].equals("4")) { //DELETE
					System.out.println("\n\nDELETE - Operacao de remocao...");
					String auxContato = contato[1];
					String enviarContato = "";
					boolean valida = false;

					AddressBook.Builder addressBookBackup = AddressBook.newBuilder();

					for(Person person : addressBook.getPeopleList()) {
						if(!person.getName().equals(auxContato)) {
							addressBookBackup.addPeople(person);
						}
						else {
							valida = true;
						}
					}

					FileOutputStream output = new FileOutputStream(args[0]);
					try {
						addressBookBackup.build().writeTo(output);
					} finally {
						output.close();
					}
					if(valida == true) {
						ps.println("Contato removido com sucesso!");
					}
					else {					    	
						ps.println("Nao encontrei nenhum contato"); //Enviado para cliente
					}

				}
				

				System.out.println("Relendo novamente o arquivo!");

				addressBook = AddressBook.newBuilder();

				try {
					FileInputStream input = new FileInputStream(args[0]);
					try {
						addressBook.mergeFrom(input);
					} finally {
						try { input.close(); } catch (Throwable ignore) {}
					}
				} catch (FileNotFoundException e) {
					System.out.println(args[0] + ": File not found.  Creating a new file.");
				}

			} //while interno

			// close connection 
			ps.close(); 
			br.close(); 
			kb.close(); 
			ss.close(); 
			s.close(); 

			// terminate application 
			System.exit(0); 

		} // end of while 
	} 

	static Person PromptForAddress(BufferedReader stdin,
			PrintStream stdout, String[] contato) throws IOException {
		Person.Builder person = Person.newBuilder();

		person.setId(Integer.valueOf(contato[0]));
		person.setName(contato[1]);
		person.setEndereco(contato[2]);
		person.setEmail(contato[3]);

		ArrayList <String> array = new ArrayList<String>();
		String auxContato = contato[4];
		auxContato += "+"; 
		int inicio = 0;
		int fim = 0;
		for(int i=0; i < auxContato.length();i++) {
			if(auxContato.charAt(i) == '+') {
				array.add(auxContato.substring(inicio,fim));
				inicio = i + 1;
			}
			fim++;
		}

		//System.out.println(array);
		for(int i=0; i<array.size(); i++) {
			Person.PhoneNumber.Builder phoneNumber =
					Person.PhoneNumber.newBuilder().setNumber(array.get(i));
			person.addPhones(phoneNumber);
		}
		return person.build();
	}

}
