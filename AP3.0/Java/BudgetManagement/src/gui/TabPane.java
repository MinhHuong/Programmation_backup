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

	private PanelDepQuoti m_pn_dep;
	
	public TabPane()
	{
		super();

		// Initialiser l'onglet D�PENSE QUOTIDIENNE
		ImageIcon icon_depense = new ImageIcon(getClass().getResource("/depense.png"));
		m_pn_dep = new PanelDepQuoti(this);
		addTab("D�pense quotidienne", icon_depense, m_pn_dep, "G�rer des d�penses quotidiennes");

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
		
		m_pn_dep.addLine(myObj);
	}
	
	public void removeLines()
	{
		m_pn_dep.removeLines();
	}
	
	public void removeAll()
	{
		m_pn_dep.removeAll();
	}

}
