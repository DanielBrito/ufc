package rmi_crud.agenda;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.util.ArrayList;

import rmi_crud.protobuf.AddressBookProtos.AddressBook;
import rmi_crud.protobuf.AddressBookProtos.Person.Builder;
import rmi_crud.protobuf.AddressBookProtos.Person;

@SuppressWarnings("serial")
public class CrudAgenda extends UnicastRemoteObject implements InterfaceCrud
{
	public CrudAgenda() throws RemoteException
	{
		System.out.println("Novo Servidor instanciado...");
	}

	static AddressBook.Builder addressBook;
	String nomeOld = ""; //to update

	public String adicionarContato(String dados) throws RemoteException {
		try {
			System.out.println("\n\nCREATE - Operacao de criacao...");
			
			// Read the existing address book.
			addressBook = AddressBook.newBuilder();
			try {
				FileInputStream input = new FileInputStream("./file.data");
				try {
					addressBook.mergeFrom(input);
				} finally {
					try { input.close(); } catch (Throwable ignore) {}
				}
			} catch (FileNotFoundException e) {
				System.out.println("./file.data" + ": File not found.  Creating a new file.");
			}


			System.out.println("Contato a ser adionado:" + dados);

			String[] contato = new String[5];
			String strAux = dados;
			contato = strAux.split("_");

			if(contato[0].equals("1")) { //CREATE
				try {
					addressBook.addPeople(
							PromptForAddress(new BufferedReader(new InputStreamReader(System.in)),
									System.out, contato));
				} catch (IOException e) {
					e.printStackTrace();
				}

				FileOutputStream output = null;
				try {
					output = new FileOutputStream("./file.data");
				} catch (FileNotFoundException e) {
					e.printStackTrace();
				}

				try {
					try {
						addressBook.build().writeTo(output);
					} catch (IOException e) {
						e.printStackTrace();
					}
				} finally {					
					output.close();
				}
				System.out.println("Contato adicionado com sucesso!");
				return "Contato adicionado com sucesso!";
			}
		} catch (IOException e) { return "Erro adicicionar!"; }
		return "Erro adicicionar!";
	}

	public String procurarContato(String dados) throws RemoteException {
		try {
			System.out.println("\n\nREAD - Operacao de busca...");
			
			// Read the existing address book.
			addressBook = AddressBook.newBuilder();
			try {
				FileInputStream input = new FileInputStream("./file.data");
				try {
					addressBook.mergeFrom(input);
				} finally {
					try { input.close(); } catch (Throwable ignore) {}
				}
			} catch (FileNotFoundException e) {
				System.out.println("./file.data" + ": File not found.  Creating a new file.");
			}


			String mensagemRecebida = dados;
			System.out.println("Recebi do cliente: " + mensagemRecebida);
			String[] contato = new String[5];
			String strAux = mensagemRecebida;

			contato = strAux.split("_");

			if(contato[0].equals("2")) { 
				
				String auxContato = contato[1];
				String enviarContato = "";
				boolean valida = false;

				for(Person person : addressBook.getPeopleList()) {
					if(person.getName().equals(auxContato)) {
						enviarContato += "Id: " + person.getId() +" Nome: " + person.getName() +  " Endereco: " + person.getEndereco() + " Email: " + person.getEmail()+ " Telefones: "; 
						for (Person.PhoneNumber phoneNumber : person.getPhonesList()) {
							enviarContato += phoneNumber.getNumber() + " ";
						}
						valida = true;
						break; //return the first
					}
				}
				if(valida == true) {
					System.out.println("Enviando para o cliente o contato: " + enviarContato);
					return enviarContato;
				}
				else {					    	
					System.out.println("Nao encontrei nenhum contato");
					return "Nao encontrei nenhum contato";
				}
			}
		} catch (IOException e) { return "Erro ao procurar!"; }
		return "Erro ao procurar!";
	}

	public String atualizarContato(String dados) throws RemoteException {
		try {
			System.out.println("\n\nUPDATE - Operacao de atualizacao...");
			
			// Read the existing address book.
			addressBook = AddressBook.newBuilder();
			try {
				FileInputStream input = new FileInputStream("./file.data");
				try {
					addressBook.mergeFrom(input);
				} finally {
					try { input.close(); } catch (Throwable ignore) {}
				}
			} catch (FileNotFoundException e) {
				System.out.println("./file.data" + ": File not found.  Creating a new file.");
			}

			String mensagemRecebida = dados;
			System.out.println("Contato a ser atualizado: " + mensagemRecebida);
			
			String[] contato = new String[5];
			String strAux = mensagemRecebida;
			contato = strAux.split("_");
			
			String auxContato = contato[1];

			String enviarContato = "";
			boolean valida = false;

			for(Person person : addressBook.getPeopleList()) {
				if(person.getName().equals(auxContato)) {
					enviarContato += "Id: " + person.getId() +" Nome: " + person.getName() +  " Endereco: " + person.getEndereco() + " Email: " + person.getEmail()+ " Telefones: "; 
					for (Person.PhoneNumber phoneNumber : person.getPhonesList()) {
						enviarContato += phoneNumber.getNumber() + " ";
					}
					valida = true;
					break; //return the first
				}
			}
			if(valida == true) {
				nomeOld = contato[1];
				System.out.println("Enviando para o cliente o contato: " + enviarContato);
				return enviarContato;
			}
			else {
				System.out.println("Nao encontrei nenhum contato");
				return "Nao encontrei nenhum contato";
			}
		} catch (IOException e) { return "Erro ao atualizar!"; }
	}

	public String atualizarDadosContato(String dados) throws RemoteException {
		try {
			System.out.println("\n\nUPDATE_DADOS - Operacao de atualizacao...");
			addressBook = AddressBook.newBuilder();

			// Read the existing address book.
			try {
				FileInputStream input = new FileInputStream("./file.data");
				try {
					addressBook.mergeFrom(input);
				} finally {
					try { input.close(); } catch (Throwable ignore) {}
				}
			} catch (FileNotFoundException e) {
				System.out.println("./file.data" + ": File not found.  Creating a new file.");
			}

			String recebidoClient = dados; //preciso dos novos dados do cliente!!!

			System.out.println("Dados do cliente: " + recebidoClient);

			String[] newContato = new String[5];
			String newStrAux = recebidoClient;

			newContato = newStrAux.split("_");

			String nomeAntigo = nomeOld;
			nomeOld = "";
			boolean encontrou=false;
			AddressBook.Builder addressBookBackup = AddressBook.newBuilder();
			for(Builder person : addressBook.getPeopleBuilderList()) { //possivel erro aqui
				if(person.getName().equals(nomeAntigo)) {
					try {
						addressBookBackup.addPeople(
								PromptForAddress(new BufferedReader(new InputStreamReader(System.in)),
										System.out,newContato));
					} catch (IOException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
					}	
					encontrou = true;
				}
				else {
					addressBookBackup.addPeople(person);
				}
			}
			if(encontrou==true) {
				// Write the new address book back to disk.
				FileOutputStream output = null;
				try {
					output = new FileOutputStream("./file.data");
				} catch (FileNotFoundException e) {
					e.printStackTrace();
				}
				try {
					try {
						addressBookBackup.build().writeTo(output);
					} catch (IOException e) {
						e.printStackTrace();
					}
				} finally {
					try {
						output.close();
					} catch (IOException e) {
						e.printStackTrace();
					}
				}

				//Relendo novamente o arquivo!
				addressBook = AddressBook.newBuilder();
				try {
					FileInputStream input = new FileInputStream("./file.data");
					try {
						try {
							addressBook.mergeFrom(input);
						} catch (IOException e) {
							// TODO Auto-generated catch block
							e.printStackTrace();
						}
					} finally {
						try { input.close(); } catch (Throwable ignore) {}
					}
				} catch (FileNotFoundException e) {
					System.out.println("./file.data" + ": File not found.  Creating a new file.");
				}
				System.out.println("Contato atualizado com sucesso!");
				return "Contato atualizado com sucesso!";
			}
			return "Erro ao atualizar dados!";
		} catch (IOException e) { return "Erro ao atualizarDADOS!"; }

	}


	public String deletarContato(String dados) throws RemoteException {
		try {
			System.out.println("\n\nDELETE - Operacao de delecao...");
			
			// Read the existing address book.
			addressBook = AddressBook.newBuilder();
			try {
				FileInputStream input = new FileInputStream("./file.data");
				try {
					addressBook.mergeFrom(input);
				} finally {
					try { input.close(); } catch (Throwable ignore) {}
				}
			} catch (FileNotFoundException e) {
				System.out.println("./file.data" + ": File not found.  Creating a new file.");
			}

			String mensagemRecebida = dados;
			System.out.println("Recebi do cliente: " + mensagemRecebida);
			String[] contato = new String[5];
			String strAux = mensagemRecebida;

			strAux.split("_");
			contato = strAux.split("_");

			
			String auxContato = contato[1];
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

			FileOutputStream output = null;
			try {
				output = new FileOutputStream("./file.data");
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
			try {
				try {
					addressBookBackup.build().writeTo(output);
				} catch (IOException e) {
					e.printStackTrace();
				}
			} finally {
				try {
					output.close();
				} catch (IOException e) {
					e.printStackTrace();
				}
			}

			//Save changes
			addressBook = AddressBook.newBuilder();
			try {
				FileInputStream input = new FileInputStream("./file.data");
				try {
					try {
						addressBook.mergeFrom(input);
					} catch (IOException e) {
						e.printStackTrace();
					}
				} finally {
					try { input.close(); } catch (Throwable ignore) {}
				}
			} catch (FileNotFoundException e) {
				System.out.println("./file.data" + ": File not found.  Creating a new file.");
			}

			if(valida == true) {
				System.out.println("Contato removido com sucesso!");
				return "Contato removido com sucesso!";
			}
			else {
				System.out.println("Nao encontrei nenhum contato");
				return "Nao encontrei nenhum contato";
			}

		} catch (IOException e) { return "Erro ao deletar!"; }
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

		for(int i=0; i<array.size(); i++) {
			Person.PhoneNumber.Builder phoneNumber =
					Person.PhoneNumber.newBuilder().setNumber(array.get(i));
			person.addPhones(phoneNumber);
		}
		return person.build();
	}



} 

