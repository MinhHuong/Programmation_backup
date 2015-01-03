package gui;

import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JPanel;

@SuppressWarnings("serial")
public class PanelButtons extends JPanel {

	private JButton m_bt_ajouter;
	private JButton m_bt_modifier;
	private JButton m_bt_sauvegarder;
	private JButton m_bt_annuler;
	
	public PanelButtons(TabPane tabPane)
	{
		super();
		
		setPreferredSize(new Dimension(700, 80));
		setLayout(new FlowLayout(FlowLayout.CENTER, 60, 20));
		
		m_bt_ajouter = new JButton("Ajouter");
		m_bt_modifier = new JButton("Modifier");
		m_bt_sauvegarder = new JButton("Sauvegarder");
		m_bt_annuler = new JButton("Annuler");
		
		m_bt_ajouter.setPreferredSize(new Dimension(110, 30));
		m_bt_modifier.setPreferredSize(new Dimension(110, 30));
		m_bt_sauvegarder.setPreferredSize(new Dimension(110, 30));
		m_bt_annuler.setPreferredSize(new Dimension(110, 30));
		
		FunctionsListener funcListener = new FunctionsListener(tabPane);
		m_bt_ajouter.addActionListener(funcListener);
		m_bt_modifier.addActionListener(funcListener);
		m_bt_sauvegarder.addActionListener(funcListener);
		m_bt_annuler.addActionListener(funcListener);
		
		add(m_bt_ajouter);
		add(m_bt_modifier);
		add(m_bt_sauvegarder);
		add(m_bt_annuler);
		
		//m_bt_modifier.setVisible(false);
		//m_bt_sauvegarder.setVisible(false);
		//m_bt_annuler.setVisible(false);
	}
	
	class FunctionsListener implements ActionListener
	{
		private TabPane m_tab_pane;
		
		public FunctionsListener(TabPane tabPane)
		{
			m_tab_pane = tabPane;
		}
		
		@Override
		public void actionPerformed(ActionEvent e) 
		{
			if(e.getSource() == m_bt_ajouter)
			{
				System.out.println("Ajouter la premi�re ligne pour instancier les tables");
			}
			
			if(e.getSource() == m_bt_modifier)
			{
				System.out.println("Modifier des donn�es");
			}
			
			if(e.getSource() == m_bt_sauvegarder)
			{
				System.out.println("Sauvegarder des nouvelles donn�es");
			}
			
			if(e.getSource() == m_bt_annuler)
			{
				System.out.println("Annuler tous les changements");
			}
			
		}
		
	}
	
}
