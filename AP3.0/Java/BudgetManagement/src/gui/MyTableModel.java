package gui;

import java.util.Vector;

import javax.swing.JOptionPane;
import javax.swing.event.TableModelEvent;
import javax.swing.event.TableModelListener;
import javax.swing.table.AbstractTableModel;

import dataInVector.DataDepQuoti;

/**
 * Le mod�le de la table dans chaque onglet
 * 
 * @author MiHu
 *
 * @param <T> Le type de donn�es convenable (DataDepQuoti, DataFlux, DataEco...)
 */
@SuppressWarnings("serial")
class MyTableModel<T> extends AbstractTableModel
{
	private Vector<String> m_columns;

	private Vector<T> m_data;

	public MyTableModel()
	{
		super();

		m_columns = new Vector<String>();
		m_data = new Vector<T>();
		addTableModelListener(new MyTableListener<T>(this));
	}

	public Vector<T> getData()
	{
		return m_data;
	}
	
	public void setColumns(Vector<String> col)
	{
		m_columns = col;
	}

	public void setData(Vector<T> data)
	{
		m_data = data;
	}
	
	public void delLines(int[] line)
	{
		Vector<T> rem = new Vector<T>();
		
		for(int i = 0 ; i < line.length ; i++)
		{
			rem.add(m_data.get(line[i]));
		}
		
		for(int i = 0 ; i < rem.size() ; i++)
		{
			m_data.remove(rem.get(i));
		}
		
		int firstR = 0, lastR = 0;
		for(int i = 0 ; i < line.length ; i++)
		{
			if(firstR > line[i]) firstR = line[i];
			if(lastR  < line[i]) lastR = line[i];
		}
		
		fireTableRowsDeleted(firstR, lastR);
	}
	
	public void delAll()
	{
		m_data.removeAllElements();
		fireTableDataChanged();
	}
	
	@SuppressWarnings("unchecked")
	public void addLine(Object myObj) 
	{
		m_data.addElement((T)myObj);
		fireTableRowsInserted(m_data.size()-1, m_data.size());
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

	class MyTableListener<S> implements TableModelListener
	{
		private MyTableModel<S> m_tab_model;
		
		public MyTableListener(MyTableModel<S> tabModel)
		{
			m_tab_model = tabModel;
		}
		
		@Override
		public void tableChanged(TableModelEvent e) 
		{
			if(e.getType() == TableModelEvent.UPDATE)
			{
				S temp_data = m_tab_model.getData().get(e.getFirstRow());
				
				if(temp_data instanceof DataDepQuoti)
				{
					DataDepQuoti depQuoti = (DataDepQuoti) temp_data;
					
					if( (depQuoti.isEmprunt() == true) && (depQuoti.isPret() == true) )
					{
						JOptionPane.showMessageDialog(null, 
								"An amount can't be considered lent and borrowed at the same time !", 
								"Invalid data",
								JOptionPane.ERROR_MESSAGE);
						depQuoti.setEmprunt(false);
						depQuoti.setPret(false);
						fireTableRowsUpdated(e.getFirstRow(), e.getLastRow());
					}
				}
			}
			
		}
		
	}
}