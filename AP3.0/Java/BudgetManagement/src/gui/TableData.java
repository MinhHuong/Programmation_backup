package gui;

import java.awt.Dimension;

import javax.swing.JTable;

@SuppressWarnings("serial")
public class TableData<S> extends JTable {

	private MyTableModel<S> m_tab_model;
	
	public TableData(MyTableModel<S> tabModel)
	{
		super(tabModel);
		
		m_tab_model = tabModel;
		setPreferredScrollableViewportSize(new Dimension(630, 280));
		setFillsViewportHeight(true);
		setRowHeight(30);
	}
	
	public void addLine(Object myObj)
	{
		m_tab_model.addLine(myObj);
	}
	
	public void removeLines()
	{
		m_tab_model.delLines(getSelectedRows());
	}
	
	public void removeAll()
	{
		m_tab_model.delAll();
	}

}
