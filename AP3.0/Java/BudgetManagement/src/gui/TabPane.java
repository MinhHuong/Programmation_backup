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
		addTab("D�pense quotidienne", icon_depense, pn_depense, "G�rer des d�penses quotidiennes");
		
		ImageIcon icon_flux = new ImageIcon(getClass().getResource("/flux.png"));
		JPanel pn_flux = new JPanel();
		addTab("Emprunt - Pr�t", icon_flux, pn_flux, "G�rer des flux mon�taires (emprunt/pr�t)");
		
		ImageIcon icon_eco = new ImageIcon(getClass().getResource("/economise.png"));
		JPanel pn_eco = new JPanel();
		addTab("�conomise", icon_eco, pn_eco, "G�rer le budget");
		
		setBorder(BorderFactory.createEmptyBorder(10, 15, 10, 15));
		
	}

}
