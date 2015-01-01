package gui;

import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JPanel;
import javax.swing.JTabbedPane;

@SuppressWarnings("serial")
public class TabPane extends JTabbedPane {
	
	public TabPane()
	{
		super();
		
		ImageIcon icon_depense = new ImageIcon(getClass().getResource("/depense.png"));
		JPanel pn_depense = new JPanel();
		addTab("Dépense quotidienne", icon_depense, pn_depense, "Gérer des dépenses quotidiennes");
		
		ImageIcon icon_flux = new ImageIcon(getClass().getResource("/flux.png"));
		JPanel pn_flux = new JPanel();
		addTab("Emprunt - Prêt", icon_flux, pn_flux, "Gérer des flux monétaires (emprunt/prêt)");
		
		ImageIcon icon_eco = new ImageIcon(getClass().getResource("/economise.png"));
		JPanel pn_eco = new JPanel();
		addTab("Économise", icon_eco, pn_eco, "Gérer le budget");
		
		setBorder(BorderFactory.createEmptyBorder(10, 15, 10, 15));
		
	}

}
