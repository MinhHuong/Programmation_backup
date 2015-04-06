package controller;

import dataInVector.DataFlux;
import gui.PanelFlux;

/**
 * singleton
 * @author MiHu
 *
 */
public class FluxMonetaire implements Gestion {

	private PanelFlux pnFlux;
	
	public FluxMonetaire(PanelFlux pnF) 
	{
		pnFlux = pnF;
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
		pnFlux.copyAllDataToStore();
	}

	@Override
	public boolean modifiable() 
	{
		return true;
	}
	
	@Override
	public void ajouter() 
	{
		System.out.println("Ajouter dans le Flux mon�taire (emprunter - pr�ter)");
		
		pnFlux.addLine(new DataFlux());
	}

	@Override
	public void supprimer() 
	{
		System.out.println("Supprimer record(s) dans le Flux mon�taire (emprunter - pr�ter)");
		
		pnFlux.removeLines();
	}

	@Override
	public void supprimerTout() 
	{
		System.out.println("Supprimer tout dans le Flux mon�taire (emprunter - pr�ter)");
		
		pnFlux.removeAllData();
	}

	@Override
	public void sauvegarder() 
	{
		System.out.println("Sauvegarder dans le Flux mon�taire (emprunter - pr�ter)");
		
		pnFlux.save();
	}

	@Override
	public void annuler() 
	{
		System.out.println("Annuler tout changement dans le Flux mon�taire (emprunter - pr�ter)");
		
		pnFlux.cancel();
	}

	@Override
	public void doOperation(String op) 
	{
		System.out.println("Le Flux mon�taire (emprunter - pr�ter) fait l'op�ration " + op);
	}

}
