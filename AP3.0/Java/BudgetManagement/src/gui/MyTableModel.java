package gui;

import java.util.Vector;

import javax.swing.JOptionPane;
import javax.swing.event.TableModelEvent;
import javax.swing.event.TableModelListener;
import javax.swing.table.AbstractTableModel;

import utils.DatabaseSim;
import dataInVector.DataDepQuoti;

/**
 * Le mod�le de la table dans chaque onglet
 * 
 * @author MiHu
 *
 * @param <T> Le type de donn�es convenable (DataDepQuoti, DataFlux, DataEco...)
 */
@SuppressWarnings("serial")
public class MyTableModel<T> extends AbstractTableModel
{
	private Vector<String> m_columns;

	private Vector<T> m_data;

	private Vector<T> m_data_store;

	public MyTableModel()
	{
		super();

		m_columns = new Vector<String>();
		m_data = new Vector<T>();
		m_data_store = new Vector<T>();
		addTableModelListener(new MyTableListener<T>(this));
	}

	public Vector<T> getData()
	{
		return m_data;
	}

	public Vector<T> getDataStored()
	{
		return m_data_store;
	}

	@SuppressWarnings({ "rawtypes", "unchecked" })
	public Class getColumnClass(int c) {
		return getValueAt(0, c).getClass();
	}

	public void setColumns(Vector<String> col)
	{
		m_columns = col;
	}

	public void setData(Vector<T> data)
	{
		m_data = data;
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

	public void setDateToAll(String date)
	{
		for(int i = 0 ; i < m_data.size() ; i++)
		{
			if(m_data.get(i) instanceof DataDepQuoti)
			{
				//System.out.println(date.toString());
				((DataDepQuoti)m_data.get(i)).setDate(date);
			}
		}
	}

	@SuppressWarnings("unchecked")
	public void copyAllData(Vector<T> src, Vector<T> dest)
	{
		for(int i = 0 ; i < src.size() ; i++)
		{
			T temp_data = src.get(i);

			if(temp_data instanceof DataDepQuoti)
			{
				DataDepQuoti depQuoti = new DataDepQuoti
						(
								((DataDepQuoti)temp_data).getIntitule(),
								((DataDepQuoti)temp_data).getMontant(),
								((DataDepQuoti)temp_data).isEmprunt(),
								((DataDepQuoti)temp_data).isPret(),
								((DataDepQuoti)temp_data).getDate()
						);
				dest.addElement((T)depQuoti);
			}

			//dest.addElement(src.get(i));
			// Ce code ne marche pas quand on modifie des donn�es, 
			// m�me s'il va bien si l'on ne fait que la suppression
		}
	}

	public void copyToDB()
	{
		if(m_data.size() != 0 && m_data.get(0) instanceof DataDepQuoti)
		{
			// first, erase all datas of that chosen date only (already precised in the vector m_data
			DataDepQuoti example = (DataDepQuoti)m_data.get(0);
			DatabaseSim.eraseAllOnDate(example.getDate());
			
			for(int i = 0 ; i < m_data.size() ; i++)
			{
				T temp_data = m_data.get(i);

				if(temp_data instanceof DataDepQuoti)
				{
					DataDepQuoti depQuoti = new DataDepQuoti
							(
									((DataDepQuoti)temp_data).getIntitule(),
									((DataDepQuoti)temp_data).getMontant(),
									((DataDepQuoti)temp_data).isEmprunt(),
									((DataDepQuoti)temp_data).isPret(),
									((DataDepQuoti)temp_data).getDate()
							);
					
					if(!DatabaseSim.checkOccurence(depQuoti))
					{
						DatabaseSim.addToDB(depQuoti);
					}
				}
			}
		}
	}

	public void restoreData()
	{
		m_data.clear();
		copyAllData(m_data_store, m_data);
		m_data_store.clear();
		fireTableDataChanged();
	}

	public void clearDataStored()
	{
		m_data_store.clear();
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

	public void showAllData()
	{
		for(int i = 0 ; i < m_data.size() ; i++)
		{
			System.out.println(m_data.get(i).toString());
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
				if(m_tab_model.getData().size() != 0)
				{
					S temp_data = m_tab_model.getData().get(e.getFirstRow());

					if(temp_data instanceof DataDepQuoti)
					{
						DataDepQuoti depQuoti = (DataDepQuoti) temp_data;
						boolean old_emprunt = depQuoti.isEmprunt();
						boolean old_pret = depQuoti.isPret();
						
						if( (depQuoti.isEmprunt() == true) && (depQuoti.isPret() == true) )
						{
							JOptionPane.showMessageDialog(null, 
									"An amount can't be considered lent and borrowed at the same time !", 
									"Invalid data",
									JOptionPane.ERROR_MESSAGE);
							depQuoti.setEmprunt(old_emprunt);
							depQuoti.setPret(old_pret);
							fireTableRowsUpdated(e.getFirstRow(), e.getLastRow());
						}
					}
				}
			}

		}

	}
}