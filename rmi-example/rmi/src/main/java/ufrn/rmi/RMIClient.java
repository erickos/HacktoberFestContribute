package ufrn.rmi;

import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;

import javax.swing.JOptionPane;

import ufrn.rmi.RMIInterface;

public class RMIClient {

	private static RMIInterface lookUp;
	
	public static void main (String[] args)
		throws RemoteException, NotBoundException, MalformedURLException 
	{
		lookUp = (RMIInterface) Naming.lookup("rmi://localhost:5000/sonoo");
		String txt = JOptionPane.showInputDialog("what is your name?");
		
		String response = lookUp.helloTo(txt);
		JOptionPane.showMessageDialog(null, response);
		
	}
	
}
