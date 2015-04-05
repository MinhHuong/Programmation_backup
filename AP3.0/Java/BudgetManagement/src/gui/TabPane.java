package gui;

import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JPanel;
import javax.swing.JTabbedPane;

import controller.Context;
import controller.DepenseQuoti;
import controller.Economise;
import controller.FluxMonetaire;
import controller.Gestion;

@SuppressWarnings("serial")
public class TabPane extends JTabbedPane {

	//private PanelDepQuoti m_pnDep;
	
	//private PanelFlux pnFlux;
	
	private Context currContext;
	
	private DepenseQuoti gestDep;
	
	private FluxMonetaire gestFlux;
	
	private Economise gestEco;
	
	public TabPane()
	{
		super();
		
		currContext = new Context();
		
		// Initialiser l'onglet DÉPENSE QUOTIDIENNE
		ImageIcon icon_depense = new ImageIcon(getClass().getResource("/depense.png"));
		PanelDepQuoti m_pnDep = new PanelDepQuoti(this);
		gestDep = new DepenseQuoti(m_pnDep);
		addTab("DAILY EXPENSES", icon_depense, m_pnDep, "Manage daily expenses");

		// Initialiser l'onglet FLUX MONÉTAIRE
		ImageIcon icon_flux = new ImageIcon(getClass().getResource("/flux.png"));
		PanelFlux pnFlux = new PanelFlux(this);
		gestFlux = new FluxMonetaire(pnFlux);
		addTab("BORROWED - LENT", icon_flux, pnFlux, "Manage flux (borrewed/lent)");
		
		// Initialiser l'onglet ÉCONOMISE
		ImageIcon icon_eco = new ImageIcon(getClass().getResource("/economise.png"));
		JPanel pn_eco = new JPanel();
		gestEco = new Economise();
		addTab("SAVING", icon_eco, pn_eco, "Manage the saving amount");

		setBorder(BorderFactory.createEmptyBorder(10, 15, 10, 15));
	}
	
	public Gestion getGestion()
	{
		switch(getSelectedIndex())
		{
		case 0:
			return gestDep;
		case 1:
			return gestFlux;
		case 2:
			return gestEco;
		}
		
		return null;
	}
	
	public void doOperation(String op)
	{
		currContext.setGestion(this.getGestion());
		currContext.setOperation(op);
		currContext.execute();
	}
	
	public void setCurrentGestion()
	{
		currContext.setGestion(this.getGestion());
	}
	
	public boolean modifiable()
	{
		return currContext.getGestion().modifiable();
	}
	
}
