package gui;

import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.Properties;
import java.util.Vector;

import javax.swing.JButton;
import javax.swing.JFormattedTextField.AbstractFormatter;
import javax.swing.JPanel;
import javax.swing.JScrollPane;

import org.jdatepicker.impl.JDatePanelImpl;
import org.jdatepicker.impl.JDatePickerImpl;
import org.jdatepicker.impl.UtilDateModel;

import utils.DatabaseSim;
import dataInVector.DataDepQuoti;

@SuppressWarnings("serial")
public class PanelDepQuoti extends JPanel {

	private TableData<DataDepQuoti> m_tab_data;
	
	private JDatePickerImpl m_datePicker;
	
	private JButton m_buttonFind;
	
	private String m_oldDate;
	
	private boolean m_alreadyClickFind;

	public PanelDepQuoti(TabPane tabPane)
	{
		super(new FlowLayout(FlowLayout.CENTER, 0, 15));
		
		MyTableModel<DataDepQuoti> tabModel = new MyTableModel<DataDepQuoti>();

		Vector<String> col = new Vector<String>();
		col.add("Intitul�");
		col.add("Montant");
		col.add("Emprunt� ?");
		col.add("Pr�t� ?");
		tabModel.setColumns(col);

		Vector<DataDepQuoti> data = new Vector<DataDepQuoti>();
		data.add(new DataDepQuoti("Bus", 4000, false, false, "Monday, 23/02/2015"));
		data.add(new DataDepQuoti("Livres", 85600, false, true, "Monday, 23/02/2015"));
		data.add(new DataDepQuoti("Essence", 40000, false, false, "Monday, 23/02/2015"));
		data.add(new DataDepQuoti("V�t�rinaire", 22000, true, false, "Monday, 23/02/2015"));
		data.add(new DataDepQuoti("Nourriture", 25000, true, false, "Monday, 23/02/2015")); 
		tabModel.setData(data);
		DatabaseSim.setDatas(data);

		UtilDateModel model = new UtilDateModel();
		model.setSelected(true);
		Properties p = new Properties();
		p.put("text.today", "Today");
		p.put("text.month", "Month");
		p.put("text.year", "Year");
		JDatePanelImpl datePanel = new JDatePanelImpl(model, p);
		m_datePicker = new JDatePickerImpl(datePanel, new DateLabelFormatter());
		add(m_datePicker);
		DatabaseSim.findEntry(getDateFromPicker(), tabModel);
		
		this.m_oldDate = getDateFromPicker();
		this.m_alreadyClickFind = false;
		
		m_buttonFind = new JButton("FIND ENTRY");
		m_buttonFind.addActionListener(new ButtonFindListener(tabModel));
		this.add(m_buttonFind);
		
		m_tab_data = new TableData<DataDepQuoti>(tabModel);
		JScrollPane scrollPane = new JScrollPane(m_tab_data);
		this.add(scrollPane);

		PanelButtons pn_buttons = new PanelButtons(tabPane);
		this.add(pn_buttons);
	}
	
	public void addLine(Object myObj)
	{
		m_tab_data.addLine(myObj);
	}

	public void removeLines()
	{
		m_tab_data.removeLines();
	}

	public void removeAllData()
	{
		m_tab_data.removeAllData();
	}
	
	public void save()
	{
		this.m_tab_data.save(getDateFromPicker());
		this.m_oldDate = getDateFromPicker();
		this.m_buttonFind.setVisible(true);
		this.m_alreadyClickFind = false;
	}
	
	public void cancel()
	{
		this.m_tab_data.cancel();
		this.m_buttonFind.setVisible(true);
		this.m_alreadyClickFind = false;
	}
	
	public void copyAllDataToStore()
	{
		m_tab_data.copyAllDataToStore();
		m_buttonFind.setVisible(true);
	}
	
	public String getDateFromPicker()
	{
		try 
		{
			Date date = (Date)m_datePicker.getModel().getValue();
			Calendar cal = Calendar.getInstance();
			cal.setTime(date);
			//System.out.println(new DateLabelFormatter().valueToString(cal));
			return new DateLabelFormatter().valueToString(cal);
		} 
		catch (ParseException e) 
		{
			System.out.println("Error while parsing date !");
			return null;
		}
	}
	
	public boolean isDateChanged()
	{
		return this.m_oldDate != this.getDateFromPicker();
	}
	
	public void hideButtonFind()
	{
		m_buttonFind.setVisible(false);
	}
	
	public void displayButtonFind()
	{
		m_buttonFind.setVisible(true);
	}
	
	public boolean isPressedFind()
	{
		return this.m_alreadyClickFind;
	}
	
	class DateLabelFormatter extends AbstractFormatter {

	    private String datePattern = "EEEE, dd/MM/yyyy";
	    private SimpleDateFormat dateFormatter = new SimpleDateFormat(datePattern);

	    @Override
	    public Object stringToValue(String text) throws ParseException {
	        return dateFormatter.parseObject(text);
	    }

	    @Override
	    public String valueToString(Object value) throws ParseException {
	        if (value != null) {
	            Calendar cal = (Calendar) value;
	            return dateFormatter.format(cal.getTime());
	        }

	        return "";
	    }

	}
	
	class ButtonFindListener implements ActionListener
	{
		private MyTableModel<DataDepQuoti> m_tabModel;
		
		public ButtonFindListener(MyTableModel<DataDepQuoti> tabModel)
		{
			m_tabModel = tabModel;
		}
		
		@Override
		public void actionPerformed(ActionEvent e) 
		{
			DatabaseSim.findEntry((PanelDepQuoti.this).getDateFromPicker(), m_tabModel);
			(PanelDepQuoti.this).m_alreadyClickFind = true;
		}
		
	}
}
