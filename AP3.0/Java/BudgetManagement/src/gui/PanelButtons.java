package gui;

import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

@SuppressWarnings("serial")
public class PanelButtons extends JPanel {

	private JButton m_bt_modifier;
	private JButton m_bt_sauvegarder;
	private JButton m_bt_annuler;

	private JButton m_bt_ajout_ligne;
	private JButton m_bt_supp_ligne;
	private JButton m_bt_supp_tout;

	private JPanel m_pn_bt_mod;

	public PanelButtons(TabPane tabPane)
	{
		super();

		setPreferredSize(new Dimension(700, 110));
		setLayout(new FlowLayout(FlowLayout.CENTER, 60, 0));

		m_bt_ajout_ligne = new JButton(new ImageIcon(getClass().getResource("/bt_add.png")));
		m_bt_ajout_ligne.setPressedIcon(new ImageIcon(getClass().getResource("/bt_add_pressed.png")));
		m_bt_ajout_ligne.setPreferredSize(new Dimension(27, 27));
		m_bt_ajout_ligne.setBorder(BorderFactory.createEmptyBorder());
		m_bt_ajout_ligne.setContentAreaFilled(false); 
		m_bt_ajout_ligne.setToolTipText("Ajouter un nouveau record");

		m_bt_supp_ligne = new JButton(new ImageIcon(getClass().getResource("/bt_supp.png")));
		m_bt_supp_ligne.setPressedIcon(new ImageIcon(getClass().getResource("/bt_supp_pressed.png")));
		m_bt_supp_ligne.setPreferredSize(new Dimension(27, 27));
		m_bt_supp_ligne.setBorder(BorderFactory.createEmptyBorder());
		m_bt_supp_ligne.setContentAreaFilled(false); 
		m_bt_supp_ligne.setToolTipText("Supprimer le(s) record(s) sélectionné(s)");

		m_bt_supp_tout = new JButton(new ImageIcon(getClass().getResource("/bt_supp_tout.png")));
		m_bt_supp_tout.setPressedIcon(new ImageIcon(getClass().getResource("/bt_supp_tout_pressed.png")));
		m_bt_supp_tout.setPreferredSize(new Dimension(27, 27));
		m_bt_supp_tout.setBorder(BorderFactory.createEmptyBorder());
		m_bt_supp_tout.setContentAreaFilled(false); 
		m_bt_supp_tout.setToolTipText("Supprimer tous les records");

		m_pn_bt_mod = new JPanel(new FlowLayout(FlowLayout.CENTER, 120, 0));
		m_pn_bt_mod.setPreferredSize(new Dimension(700, 45));

		m_pn_bt_mod.add(m_bt_ajout_ligne);
		m_pn_bt_mod.add(m_bt_supp_ligne);
		m_pn_bt_mod.add(m_bt_supp_tout);

		m_bt_modifier = new JButton("Modifier");
		m_bt_sauvegarder = new JButton("Sauvegarder");
		m_bt_annuler = new JButton("Annuler");

		m_bt_modifier.setPreferredSize(new Dimension(110, 30));
		m_bt_sauvegarder.setPreferredSize(new Dimension(110, 30));
		m_bt_annuler.setPreferredSize(new Dimension(110, 30));

		FunctionsListener funcListener = new FunctionsListener(tabPane);
		m_bt_modifier.addActionListener(funcListener);
		m_bt_ajout_ligne.addActionListener(funcListener);
		m_bt_supp_ligne.addActionListener(funcListener);
		m_bt_supp_tout.addActionListener(funcListener);
		m_bt_sauvegarder.addActionListener(funcListener);
		m_bt_annuler.addActionListener(funcListener);

		add(m_pn_bt_mod);
		add(m_bt_modifier);
		add(m_bt_sauvegarder);
		add(m_bt_annuler);

		m_bt_modifier.setVisible(true);
		m_bt_ajout_ligne.setVisible(false);
		m_bt_supp_ligne.setVisible(false);
		m_bt_supp_tout.setVisible(false);
		m_bt_sauvegarder.setVisible(false);
		m_bt_annuler.setVisible(false);
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
			m_tab_pane.setCurrentGestion();
			String op = "";

			if(e.getSource() == m_bt_modifier)
			{
				if(!m_tab_pane.modifiable())
				{
					JOptionPane.showMessageDialog
					(
							null, 
							"Please, make sure that you have already found an entry on that date "
							+ "by clicking on the button \"FIND ENTRY\" before doing modifications.", 
							"Warning", 
							JOptionPane.WARNING_MESSAGE
					);
					return;
				}

				m_bt_modifier.setVisible(false);
				m_bt_ajout_ligne.setVisible(true);
				m_bt_supp_ligne.setVisible(true);
				m_bt_supp_tout.setVisible(true);
				m_bt_sauvegarder.setVisible(true);
				m_bt_annuler.setVisible(true);

				op = "modifier";
			}

			if(e.getSource() == m_bt_sauvegarder)
			{
				m_bt_modifier.setVisible(true);
				m_bt_ajout_ligne.setVisible(false);
				m_bt_supp_ligne.setVisible(false);
				m_bt_supp_tout.setVisible(false);
				m_bt_sauvegarder.setVisible(false);
				m_bt_annuler.setVisible(false);

				op = "sauvegarder";
			}

			if(e.getSource() == m_bt_annuler)
			{
				m_bt_modifier.setVisible(true);
				m_bt_ajout_ligne.setVisible(false);
				m_bt_supp_ligne.setVisible(false);
				m_bt_supp_tout.setVisible(false);
				m_bt_sauvegarder.setVisible(false);
				m_bt_annuler.setVisible(false);

				op = "annuler";
			}

			if(e.getSource() == m_bt_ajout_ligne)
			{
				op = "ajouterligne";
			}

			if(e.getSource() == m_bt_supp_ligne)
			{
				op = "supprimerligne";
			}

			if(e.getSource() == m_bt_supp_tout)
			{
				op = "supprimertout";
			}

			m_tab_pane.doOperation(op);
		}

	}

}
