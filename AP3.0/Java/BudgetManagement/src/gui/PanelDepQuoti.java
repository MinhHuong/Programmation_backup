package gui;

import java.awt.FlowLayout;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Properties;
import java.util.Vector;

import javax.swing.JFormattedTextField.AbstractFormatter;
import javax.swing.JPanel;
import javax.swing.JScrollPane;

import org.jdatepicker.impl.JDatePanelImpl;
import org.jdatepicker.impl.JDatePickerImpl;
import org.jdatepicker.impl.UtilDateModel;

import dataInVector.DataDepQuoti;

@SuppressWarnings("serial")
public class PanelDepQuoti extends JPanel {

	private TableData<DataDepQuoti> m_tab_data;

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
		/*
		data.add(new DataDepQuoti("Bus", 4000, false, false));
		data.add(new DataDepQuoti("Livres", 85600, false, true));
		data.add(new DataDepQuoti("Essence", 40000, false, false));
		data.add(new DataDepQuoti("V�t�rinaire", 22000, true, false));
		data.add(new DataDepQuoti("Nourriture", 25000, true, false));
		 */
		tabModel.setData(data);

		/*		Calendar calendar = Calendar.getInstance();
		Date initDate = calendar.getTime();
        calendar.add(Calendar.YEAR, -100);
        Date earliestDate = calendar.getTime();
        calendar.add(Calendar.YEAR, 200);
        Date latestDate = calendar.getTime();
        SpinnerModel dateModel = new SpinnerDateModel(initDate,
                                     earliestDate,
                                     latestDate,
                                     Calendar.MONTH);
        JSpinner spinner = new JSpinner(dateModel);
        add(spinner);*/

		UtilDateModel model = new UtilDateModel();
		//model.setDate(20,04,2014);
		// Need this...
		Properties p = new Properties();
		p.put("text.today", "Today");
		p.put("text.month", "Month");
		p.put("text.year", "Year");
		JDatePanelImpl datePanel = new JDatePanelImpl(model, p);
		// Don't know about the formatter, but there it is...
		JDatePickerImpl datePicker = new JDatePickerImpl(datePanel, new DateLabelFormatter());
		add(datePicker);

		m_tab_data = new TableData<DataDepQuoti>(tabModel);
		JScrollPane scrollPane = new JScrollPane(m_tab_data);
		add(scrollPane);

		PanelButtons pn_buttons = new PanelButtons(tabPane);
		add(pn_buttons);
	}

	public void addLine(Object myObj)
	{
		m_tab_data.addLine(myObj);
	}

	public void removeLines()
	{
		m_tab_data.removeLines();
	}

	public void removeAll()
	{
		m_tab_data.removeAll();
	}
	
	public void save()
	{
		
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
}
