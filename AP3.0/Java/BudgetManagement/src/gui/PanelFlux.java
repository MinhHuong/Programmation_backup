package gui;

import java.awt.FlowLayout;
import java.util.Vector;

import javax.swing.JPanel;
import javax.swing.JScrollPane;

import dataInVector.DataFlux;

@SuppressWarnings("serial")
public class PanelFlux extends JPanel {
	
	private TableData<DataFlux> tableFlux;
	
	public PanelFlux(TabPane tabPane)
	{
		super(new FlowLayout(FlowLayout.CENTER, 0, 15));
		
		MyTableModel<DataFlux> tabModel = new MyTableModel<DataFlux>();
		
		Vector<String> col = new Vector<String>();
		col.add("TITLE");
		col.add("AMOUNT");
		col.add("TYPE");
		col.add("PERSON");
		col.add("DATE");
		col.add("PAID");
		tabModel.setColumns(col);
		
		Vector<DataFlux> data = new Vector<DataFlux>();
/*		data.add(new DataFlux("Book", 52000, 1, "Classmate", "Monday, 25/02/2015", false));
		data.add(new DataFlux("Bus ticket", 2000, 2, "Tam", "Monday, 25/02/2015", true));
		data.add(new DataFlux("Photo English book", 47000, 1, "Loc", "Monday, 25/02/2015", false));*/
		data.add(new DataFlux());
		tabModel.setData(data);
		
		this.tableFlux = new TableData<DataFlux>(tabModel);
		JScrollPane scrollPane = new JScrollPane(this.tableFlux);
		this.add(scrollPane);
		
		PanelButtons pn_buttons = new PanelButtons(tabPane);
		this.add(pn_buttons);
	}

}
