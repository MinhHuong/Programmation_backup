package gui;

import java.awt.BorderLayout;
import java.awt.Dimension;

import javax.swing.JFrame;

@SuppressWarnings("serial")
public class MainFrame extends JFrame {
	
	public MainFrame()
	{
		super();
		
		setTitle("Budget Management");
		setPreferredSize(new Dimension(700, 550));
		setLocation(300, 100);
		setLayout(new BorderLayout());
		
		TabPane tabPane = new TabPane();
		add(tabPane, BorderLayout.CENTER);
		
		//PanelButtons pn_buttons = new PanelButtons(tabPane);
		//add(pn_buttons, BorderLayout.SOUTH);
		
		setDefaultCloseOperation(DISPOSE_ON_CLOSE);
	}
	
}
