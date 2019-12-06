package io.grpc.examples.helloworld;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.logging.Logger;
import io.grpc.examples.helloworld.AddressBookProtos.Person.Builder;

import io.grpc.Server;
import io.grpc.ServerBuilder;
import io.grpc.examples.helloworld.AddressBookProtos.AddressBook;
import io.grpc.examples.helloworld.AddressBookProtos.Person;
import io.grpc.stub.StreamObserver;

public class HelloWorldServer {
	private static final Logger logger = Logger.getLogger(HelloWorldServer.class.getName());

	private Server server;

	private void start() throws IOException {
		/* The port on which the server should run */
		int port = 50051;
		server = ServerBuilder.forPort(port).addService(new GreeterImpl()).build().start();
		logger.info("Server started, listening on " + port);
		Runtime.getRuntime().addShutdownHook(new Thread() {
			@Override
			public void run() {
				// Use stderr here since the logger may have been reset by its JVM shutdown hook.
				System.err.println("*** shutting down gRPC server since JVM is shutting down");
				HelloWorldServer.this.stop();
				System.err.println("*** server shut down");
			}
		});
	}

	private void stop() {
		if (server != null) {
			server.shutdown();
		}
	}

	/**
	 * Await termination on the main thread since the grpc library uses daemon
	 * threads.
	 */
	private void blockUntilShutdown() throws InterruptedException {
		if (server != null) {
			server.awaitTermination();
		}
	}

	/**
	 * Main launches the server from the command line.
	 */
	static AddressBook.Builder addressBook;
	boolean atualizaFLAG = false;
	String nomeOld = "";

	public static void main(String[] args) throws IOException, InterruptedException {
		if (args.length != 1) {
			System.err.println("Usage:  AddPerson ADDRESS_BOOK_FILE");
			System.exit(-1);
		}

		addressBook = AddressBook.newBuilder();

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


		final HelloWorldServer server = new HelloWorldServer();
		server.start();
		System.out.println("Server started!");
		server.blockUntilShutdown();
	}

	private class GreeterImpl extends GreeterGrpc.GreeterImplBase {

		@Override
		public void adicionarContato(HelloRequest req, StreamObserver<HelloReply> responseObserver) {
			System.out.println("\n\nCREATE - Operacao de criacao...");
			String mensagemRecebida = req.getName();
			System.out.println("Contato a ser adicionado: " + mensagemRecebida);

			String[] contato = new String[5];
			String strAux = mensagemRecebida;

			contato = strAux.split("_");

			if(contato[0].equals("1")) { //CREATE
				try {
					addressBook.addPeople(
							PromptForAddress(new BufferedReader(new InputStreamReader(System.in)),
									System.out, contato));
				} catch (IOException e) {
					e.printStackTrace();
				}

				// Write the new address book back to disk.
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
					try {
						output.close();
					} catch (IOException e) {
						e.printStackTrace();
					}
				}
			}
			System.out.println("Contato adicionado com sucesso!");
			HelloReply reply = HelloReply.newBuilder().setMessage("Contato adicionado com sucesso!").build();
			responseObserver.onNext(reply);
			responseObserver.onCompleted();
		}

		@Override //Method read
		public void procurarContato(HelloRequest req, StreamObserver<HelloReply> responseObserver) {
			System.out.println("\n\nREAD - Operacao de busca...");
			String mensagemRecebida = req.getName();
			System.out.println("Contato a ser buscado: " + mensagemRecebida);

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
						break;
					}
				}
				
				if(valida == true) {
					System.out.println("Estou enviando para o cliente o contato:"+ enviarContato);
					HelloReply reply = HelloReply.newBuilder().setMessage(enviarContato).build();
					responseObserver.onNext(reply);
					responseObserver.onCompleted();
				}
				else {					    	
					System.out.println("Nao encontrei nenhum contato");
					HelloReply reply = HelloReply.newBuilder().setMessage("Nao encontrei nenhum contato").build();
					responseObserver.onNext(reply);
					responseObserver.onCompleted();
				}
			}

		}

		@Override // Method Update
		public void atualizarContato(HelloRequest req, StreamObserver<HelloReply> responseObserver) {
			System.out.println("\n\nUPDATE - Operacao de atualizao...");
			String mensagemRecebida = req.getName();
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
					break;
				}
			}
			
			if(valida == true) {
				nomeOld = contato[1];
				System.out.println("Estou enviando para o cliente o contato: "+ enviarContato);
				HelloReply reply = HelloReply.newBuilder().setMessage(enviarContato).build();
				responseObserver.onNext(reply);
				responseObserver.onCompleted();
			}
			else {
				System.out.println("Nao encontrei nenhum contato");
				HelloReply reply = HelloReply.newBuilder().setMessage("Nao encontrei nenhum contato").build();
				responseObserver.onNext(reply);
				responseObserver.onCompleted();
			}

		}

		@Override
		public void atualizarDadosContato(HelloRequest req, StreamObserver<HelloReply> responseObserver) {
			System.out.println("\n\nUPDATE_DADOS - Operacao de atualizacao...");
			String recebidoClient = req.getName();

			System.out.println("Dados do novo contato do cliente: " + recebidoClient);

			String[] newContato = new String[5];
			String newStrAux = recebidoClient;
			newContato = newStrAux.split("_");

			String nomeAntigo = nomeOld;
			nomeOld = "";
			boolean encontrou=false;
			AddressBook.Builder addressBookBackup = AddressBook.newBuilder();
			for(Builder person : addressBook.getPeopleBuilderList()) {
				if(person.getName().equals(nomeAntigo)) {
					try {
						addressBookBackup.addPeople(
								PromptForAddress(new BufferedReader(new InputStreamReader(System.in)),
										System.out,newContato));
					} catch (IOException e) {
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

				System.out.println("Contato atualizado com sucesso!");
				HelloReply reply2 = HelloReply.newBuilder().setMessage("Contato atualizado com sucesso!").build();
				responseObserver.onNext(reply2);
				responseObserver.onCompleted();
			}

		}

		@Override
		public void deletarContato(HelloRequest req, StreamObserver<HelloReply> responseObserver) {
			System.out.println("\n\nDELETE - Operacao de remocao...");
			
			String mensagemRecebida = req.getName();
			System.out.println("Contato a ser deletado: " + mensagemRecebida);
			String[] contato = new String[5];
			String strAux = mensagemRecebida;

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
			if(valida == true) {
				System.out.println("Contato removido com sucesso!");
				HelloReply reply = HelloReply.newBuilder().setMessage("Contato removido com sucesso!").build();
				responseObserver.onNext(reply);
				responseObserver.onCompleted();
			}
			else {
				System.out.println("Nao encontrei nenhum contato");
				HelloReply reply = HelloReply.newBuilder().setMessage("Nao encontrei nenhum contato").build();
				responseObserver.onNext(reply);
				responseObserver.onCompleted();
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

		}
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