package rmi_crud.agenda;

import java.rmi.*;

public interface InterfaceCrud extends Remote
{
	public String adicionarContato(String dados) throws RemoteException;
	
	public String procurarContato(String dados) throws RemoteException;
	
	public String atualizarContato(String dados) throws RemoteException;
	
	public String atualizarDadosContato(String dados) throws RemoteException;
	
	public String deletarContato(String dados) throws RemoteException;
} 