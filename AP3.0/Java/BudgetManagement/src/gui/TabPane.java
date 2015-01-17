package gui;

import java.awt.Dimension;
import java.awt.FlowLayout;
import java.util.Vector;

import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTabbedPane;
import javax.swing.JTable;
import javax.swing.table.AbstractTableModel;

import controller.DepenseQuoti;
import controller.Economise;
import controller.FluxMonetaire;
import controller.Gestion;
import dataInVector.DataDepQuoti;

@SuppressWarnings("serial")
public class TabPane extends JTabbedPane {

	private PanelTab<DataDepQuoti> m_pn_dep;
	
	public TabPane()
	{
		super();

		// Initialiser l'onglet D�PENSE QUOTIDIENNE
		ImageIcon icon_depense = new ImageIcon(getClass().getResource("/depense.png"));
		MyTableModel<DataDepQuoti> tb_dep_quoti = new MyTableModel<DataDepQuoti>();
		
		// Ajouter des colonnes
		Vector<String> col = new Vector<String>();
		col.add("Intitul�");
		col.add("Montant");
		col.add("Emprunt� ?");
		col.add("Pr�t� ?");
		tb_dep_quoti.setColumns(col);
		 
		// Ajouter des donn�es exemplaires
		Vector<DataDepQuoti> data = new Vector<DataDepQuoti>();
		data.add(new DataDepQuoti("Bus", 4000, false, false));
		data.add(new DataDepQuoti("Livres", 85600, false, true));
		data.add(new DataDepQuoti("Essence", 40000, false, false));
		data.add(new DataDepQuoti("V�t�rinaire", 22000, true, false));
		data.add(new DataDepQuoti("Nourriture", 25000, true, false));
		tb_dep_quoti.setData(data);
		
		m_pn_dep = new PanelTab<DataDepQuoti>(tb_dep_quoti);
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
	
	public void addLineTab()
	{
		m_pn_dep.getModel().addLine();
	}

	/**
	 * Le grand panneau de chaque onglet, qui contient une table et un petit panneau de boutons
	 * 
	 * @author MiHu
	 *
	 * @param <S> Le type de donn�es convenable (DataDepQuoti, DataFlux, DataEco...)
	 */
	class PanelTab<S> extends JPanel {

		private MyTableModel<S> m_tab_model;
		
		public PanelTab(MyTableModel<S> table_model)
		{
			super(new FlowLayout(FlowLayout.CENTER, 0, 10));

			m_tab_model = table_model;
			JTable table = new JTable(m_tab_model);
			table.setPreferredScrollableViewportSize(new Dimension(630, 280));
			table.setFillsViewportHeight(true);
			table.setRowHeight(30);

			JScrollPane scrollPane = new JScrollPane(table);

			add(scrollPane);
			
			PanelButtons pn_buttons = new PanelButtons((TabPane.this));
			add(pn_buttons);
		}

		public PanelTab() 
		{
			super(new FlowLayout(FlowLayout.CENTER, 0, 10));
			
			PanelButtons pn_buttons = new PanelButtons((TabPane.this));
			add(pn_buttons);
		}
		
		public MyTableModel<S> getModel()
		{
			return m_tab_model;
		}
	}

	/**
	 * Le mod�le de la table dans chaque onglet
	 * 
	 * @author MiHu
	 *
	 * @param <T> Le type de donn�es convenable (DataDepQuoti, DataFlux, DataEco...)
	 */
	class MyTableModel<T> extends AbstractTableModel
	{
		private Vector<String> m_columns;

		private Vector<T> m_data;

		public MyTableModel()
		{
			super();

			m_columns = new Vector<String>();
			m_data = new Vector<T>();
		}

		public void setColumns(Vector<String> col)
		{
			m_columns = col;
		}

		public void setData(Vector<T> data)
		{
			m_data = data;
		}
		
		public void addLine()
		{
			m_data.addElement(null);
			fireTableDataChanged();
		}

		@SuppressWarnings({ "rawtypes", "unchecked" })
		public Class getColumnClass(int c) {
			return getValueAt(0, c).getClass();
		}

		@Override
		public int getRowCount() 
		{
			return m_data.size();
		}

		@Override
		public int getColumnCount() 
		{
			return m_columns.size();
		}
		
		public String getColumnName(int columnIndex)
		{
			return m_columns.elementAt(columnIndex);
		}
		
		public boolean isCellEditable(int row, int col)
		{
			return true;
		}

		@Override
		public Object getValueAt(int rowIndex, int columnIndex) 
		{
			T temp_data = m_data.get(rowIndex);

			if(temp_data instanceof DataDepQuoti)
			{
				DataDepQuoti my_data = (DataDepQuoti) temp_data;
				return my_data.getElementAt(columnIndex);
			}
			else
			{
				return null;
			}

		}

		@Override
		public void setValueAt(Object obj, int rowIndex, int columnIndex)
		{
			T temp_data = m_data.get(rowIndex);
			
			try
			{
				if(temp_data instanceof DataDepQuoti)
				{
					((DataDepQuoti)temp_data).setElementAt(columnIndex, obj);
				}
				
				fireTableCellUpdated(rowIndex, columnIndex);
			}
			catch(Exception ex)
			{
				System.out.println("Unexpected exception");
			}
		}

	}

}
