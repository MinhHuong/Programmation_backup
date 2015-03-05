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
		
		// Initialiser l'onglet DÉPENSE QUOTIDIENNE
		ImageIcon icon_depense = new ImageIcon(getClass().getResource("/depense.png"));
		m_pnDep = new PanelDepQuoti(this);
		addTab("DAILY EXPENSES", icon_depense, m_pnDep, "Manage daily expenses");

		// Initialiser l'onglet FLUX MONÉTAIRE
		ImageIcon icon_flux = new ImageIcon(getClass().getResource("/flux.png"));
		PanelFlux pn_flux = new PanelFlux(this);
		addTab("BORROWED - LENT", icon_flux, pn_flux, "Manage flux (borrewed/lent)");
		
		// Initialiser l'onglet ÉCONOMISE
		ImageIcon icon_eco = new ImageIcon(getClass().getResource("/economise.png"));
		JPanel pn_eco = new JPanel();
		addTab("SAVING", icon_eco, pn_eco, "Manage the saving amount");

		setBorder(BorderFactory.createEmptyBorder(10, 15, 10, 15));
	}
	
	public Gestion getGestion()
	{
		switch(getSelectedIndex())
		{
		case 0:
			return new DepenseQuoti();
		case 1:
			return new FluxMonetaire();
		case 2:
			return new Economise();
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
