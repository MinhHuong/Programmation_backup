package controller;

import dataInVector.DataDepQuoti;
import gui.PanelDepQuoti;

/**
 * singleton
 * This class handles the connection between Application and Database<p>
 * At least I will prepare SQL statement here
 * @author MiHu
 *
 */
public class DepenseQuoti implements Gestion {
	
	private PanelDepQuoti pnDepQuoti;
	
	public DepenseQuoti(PanelDepQuoti pnDep) 
	{
		pnDepQuoti = pnDep;
	}
	
	@Override
	public void createTable() 
	{}

	@Override
	public void dropTable() 
	{}
	
	@Override
	public void modify() 
	{
		pnDepQuoti.copyAllDataToStore();
		pnDepQuoti.hideButtonFind();
	}
	
	@Override
	public boolean modifiable() 
	{
		return pnDepQuoti.isPressedFind() || (!pnDepQuoti.isDateChanged());
	}
	
	@Override
	public void ajouter() 
	{
		System.out.println("Ajouter une ligne dans D�pense quotidienne");
		
		pnDepQuoti.addLine(new DataDepQuoti());
	}

	@Override
	public void supprimer() 
	{
		System.out.println("Supprimer record(s) dans D�pense quotidienne");
		
		pnDepQuoti.removeLines();
	}

	@Override
	public void supprimerTout() 
	{
		System.out.println("Tout supprimer dans D�pense quotidienne");
		
		pnDepQuoti.removeAllData();
	}

	@Override
	public void sauvegarder() 
	{
		System.out.println("Sauvegarder dans D�pense quotidienne");
		
		pnDepQuoti.save();
	}

	@Override
	public void annuler() 
	{
		System.out.println("Annuler dans D�pense quotidienne");
		
		pnDepQuoti.cancel();
	}

	@Override
	public void doOperation(String op) 
	{
		System.out.println("D�pense quotidienne fait l'op�ration " + op);
	}

}
