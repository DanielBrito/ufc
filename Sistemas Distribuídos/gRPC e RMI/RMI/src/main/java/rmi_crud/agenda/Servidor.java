package rmi_crud.agenda;

import java.io.IOException;
import java.rmi.registry.LocateRegistry;
import java.rmi.registry.Registry;

public class Servidor {	
	public static void main(String args[]) throws IOException, InterruptedException
	{
		Thread t1 = new Thread(new Runnable() 
		{ 
			public void run() 
			{ 
				try
				{
					System.setProperty("java.rmi.server.hostname", "localhost");
					//System.setProperty("java.rmi.server.hostname", "10.5.30.126"); //anyway
					System.out.println("Servidor iniciado...");
					Registry registry = LocateRegistry.createRegistry(1099);
					CrudAgenda objEcho = new CrudAgenda();
					registry.rebind("echoMsg", objEcho);
				}
				catch (Exception e)
				{
					System.out.println("Ocorreu um problema ao iniciar o servidor.\n"+e.toString());
				}

			} 
		}); 
		t1.start(); 
		t1.join(); 
	}
}