package gui;

import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JPanel;
import javax.swing.JTabbedPane;

import controller.DepenseQuoti;
import controller.Economise;
import controller.FluxMonetaire;
import controller.Gestion;
import dataInVector.DataDepQuoti;

@SuppressWarnings("serial")
public class TabPane extends JTabbedPane {

	private PanelDepQuoti m_pnDep;
	
	public TabPane()
	{
		super();

		// Initialiser l'onglet D�PENSE QUOTIDIENNE
		ImageIcon icon_depense = new ImageIcon(getClass().getResource("/depense.png"));
		m_pnDep = new PanelDepQuoti(this);
		addTab("D�pense quotidienne", icon_depense, m_pnDep, "G�rer des d�penses quotidiennes");

		// Initialiser l'onglet FLUX MON�TAIRE
		ImageIcon icon_flux = new ImageIcon(getClass().getResource("/flux.png"));
		JPanel pn_flux = new JPanel();
		addTab("Emprunt - Pr�t", icon_flux, pn_flux, "G�rer des flux mon�taires (emprunt/pr�t)");

		// Initialiser l'onglet �CONOMISE
		ImageIcon icon_eco = new ImageIcon(getClass().getResource("/economise.png"));
		JPanel pn_eco = new JPanel();
		addTab("�conomise", icon_eco, pn_eco, "G�rer le budget");

		setBorder(BorderFactory.createEmptyBorder(10, 15, 10, 15));
	}
	
	public Gestion getGestion()
	{
		switch(getSelectedIndex())
		{
		case 0:
			return DepenseQuoti.getDepenseQuotiContext();
		case 1:
			return FluxMonetaire.getFluxContext();
		case 2:
			return Economise.getEconomiseContext();
		}
		
		return null;
	}
	
	public void modifyEntry()
	{
		m_pnDep.copyAllDataToStore();
		m_pnDep.hideButtonFind();
	}
	
	public boolean canBeModified()
	{
		return m_pnDep.isPressedFind() || (!m_pnDep.isDateChanged());
	}
	
	public void addLine()
	{
		Object myObj = null;
		
		switch(getSelectedIndex())
		{
		case 0:
			myObj = new DataDepQuoti();
			break;
		case 1:
			break;
		case 2:
			break;
		}
		
		m_pnDep.addLine(myObj);
	}
	
	public void removeLines()
	{
		m_pnDep.removeLines();
	}
	
	public void removeAllData()
	{
		m_pnDep.removeAllData();
	}

	public void save()
	{
		m_pnDep.save();
	}
	
	public void cancel()
	{
		m_pnDep.cancel();
	}

}
