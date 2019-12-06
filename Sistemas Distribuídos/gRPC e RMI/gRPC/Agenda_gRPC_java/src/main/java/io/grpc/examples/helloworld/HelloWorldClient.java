package io.grpc.examples.helloworld;

import io.grpc.ManagedChannel;
import io.grpc.ManagedChannelBuilder;
import io.grpc.StatusRuntimeException;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.concurrent.TimeUnit;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 * A simple client that requests a greeting from the {@link HelloWorldServer}.
 */
public class HelloWorldClient {
    private static final Logger logger = Logger.getLogger(HelloWorldClient.class.getName());

    private final ManagedChannel channel;
    private final GreeterGrpc.GreeterBlockingStub blockingStub;

    /** Construct client connecting to HelloWorld server at {@code host:port}. */
    public HelloWorldClient(String host, int port) {
        this(ManagedChannelBuilder.forAddress(host, port)
                // Channels are secure by default (via SSL/TLS). For the example we disable TLS
                // to avoid
                // needing certificates.
                .usePlaintext().build());
    }

    /**
     * Construct client for accessing HelloWorld server using the existing channel.
     */
    HelloWorldClient(ManagedChannel channel) {
        this.channel = channel;
        blockingStub = GreeterGrpc.newBlockingStub(channel);
    }

    public void shutdown() throws InterruptedException {
        channel.shutdown().awaitTermination(5, TimeUnit.SECONDS);
    }

    /** Say hello to server. 
     * @throws IOException */
    public void greet(String name) throws IOException {
    	
        //logger.info("Will try to greet " + name + " ...");
        
        HelloRequest request = HelloRequest.newBuilder().setName(name).build();
        HelloReply response;
        
        if(name.charAt(0)=='1') {
	        try {
	            response = blockingStub.adicionarContato(request);
	        } catch (StatusRuntimeException e) {
	            logger.log(Level.WARNING, "RPC failed: {0}", e.getStatus());
	            return;
	        }
	        System.out.println("\nResposta do servidor: " + response.getMessage());
        }
        else if(name.charAt(0) == '2') {
	        try {
	            response = blockingStub.procurarContato(request);
	        } catch (StatusRuntimeException e) {
	            logger.log(Level.WARNING, "RPC failed: {0}", e.getStatus());
	            return;
	        }
	        System.out.println("\nResposta do servidor: " + response.getMessage());
        }
        else if(name.charAt(0) == '3') {
	        try {
	            response = blockingStub.atualizarContato(request);
	        } catch (StatusRuntimeException e) {
	            logger.log(Level.WARNING, "RPC failed: {0}", e.getStatus());
	            return;
	        }
	        System.out.println("\nResposta do servidor: " + response.getMessage());
	        
	        String respostaServer = response.getMessage();
	        
	        if(respostaServer.equals("Nao encontrei nenhum contato")) {
				System.out.println(respostaServer);				
			}
			else {
				
				BufferedReader kb = new BufferedReader(new InputStreamReader(System.in));
				
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
				
				//dos.writeBytes(contato2 + "\n");	
				
				HelloRequest request2 = HelloRequest.newBuilder().setName(contato2).build();
				try {
		            response = blockingStub.atualizarDadosContato(request2);
		        } catch (StatusRuntimeException e) {
		            logger.log(Level.WARNING, "RPC failed: {0}", e.getStatus());
		            return;
		        }
		        System.out.println("Resposta do servidor: " + response.getMessage());

			}
	        
	        
        }
        else if(name.charAt(0) == '4') {
	        try {
	            response = blockingStub.deletarContato(request);
	        } catch (StatusRuntimeException e) {
	            logger.log(Level.WARNING, "RPC failed: {0}", e.getStatus());
	            return;
	        }
	        System.out.println("Resposta do servidor: " + response.getMessage());
        }
        
    }

    public static void main(String[] args) throws Exception {
        // Access a service running on the local machine on port 50051
        HelloWorldClient client = new HelloWorldClient("localhost", 50051);

        boolean sair = false;

        while(sair==false){

            try {

                BufferedReader kb = new BufferedReader(new InputStreamReader(System.in));
                String str;
                
                System.out.println("        CRUD\n");
                System.out.println("1 - Adicionar contato");
                System.out.println("2 - Procurar contato");
                System.out.println("3 - Atualizar contato");
                System.out.println("4 - Remover contato");
                System.out.println("0 - Sair");
    
                System.out.print("- > ");
    
                str =  kb.readLine();
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
    				client.greet(contato);
    			}
                else if(str.equals("2")) { //READ
    				String contato = "2_";
    				System.out.println("\nPROCURAR CONTATO");
    				System.out.print("Digite o nome a ser procurado: ");
    				String nome = kb.readLine();
    				contato += nome;
    				client.greet(contato);
    			}
                else if(str.equals("3")) { // UPDATE
    				String contato = "3_";
    				System.out.println("\nATUALIZAR CONTATO");
    				System.out.print("Digite o nome a ser atualizado: ");
    				String nome = kb.readLine();
    				contato += nome;
    				
    				client.greet(contato);
                }
                else if(str.equals("4")) { // DELETE
                	String contato = "4_";
    				System.out.println("\nREMOVER CONTATO");
    				System.out.print("Digite o nome a ser removido: ");
    				String nome = kb.readLine();
    				contato += nome;
    				
    				client.greet(contato);
                }
                else if(str.equals("0")) {
                	client.shutdown();
                	System.exit(0);
                }
    
            } finally {
                
                //client.shutdown();
            }
        }
    }
}
