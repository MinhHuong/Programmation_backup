package gui;

import java.awt.Dimension;

import javax.swing.JTable;

import utils.DatabaseSim;


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
	
	public void removeAllData()
	{
		m_tab_model.delAll();
	}
	
	public void save(String date)
	{
		m_tab_model.clearDataStored();		
		if(date != null) m_tab_model.setDateToAll(date);
		m_tab_model.copyToDB();
		DatabaseSim.showDataInDB();
	}
	
	public void cancel()
	{
		m_tab_model.restoreData();
	}

	public void copyAllDataToStore()
	{
		m_tab_model.copyAllData(m_tab_model.getData(), m_tab_model.getDataStored());
	}
}
