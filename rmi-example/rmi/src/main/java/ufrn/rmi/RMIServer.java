package ufrn.rmi;

import java.rmi.Naming;
import java.rmi.RemoteException;
import java.rmi.registry.LocateRegistry;
import java.rmi.server.UnicastRemoteObject;



public class RMIServer extends UnicastRemoteObject implements RMIInterface{

	protected RMIServer() throws RemoteException {
		super();
		// TODO Auto-generated constructor stub
	}

	private static final long serialVersionUID = 1L;

	public String helloTo(String name) throws RemoteException {
		System.err.println(name + " is trying to contact!");
		return "Server says hello to " + name;
	}
	

    public static void main(String[] args) {
    	try{  
    		RMIInterface stub=new RMIServer();  
    		LocateRegistry.createRegistry(5000);
    		Naming.rebind("rmi://localhost:5000/sonoo",stub);  
    	}catch(Exception e){e.printStackTrace();}  
    		
    }

}
