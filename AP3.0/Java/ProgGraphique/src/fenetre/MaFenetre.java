package fenetre;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

@SuppressWarnings("serial")
public class MaFenetre extends JFrame {	
	private JButton bt_create;
	
	public MaFenetre()
	{
		setTitle("Création des boutons");
		setSize(500, 500);
		Container contenu = getContentPane();
		contenu.setLayout(new FlowLayout());
		
		bt_create = new JButton("CREATE");
		contenu.add(bt_create);
		ButtonEvent bt_event = new ButtonEvent(contenu);
		bt_create.addActionListener(bt_event);
	}
	
	class ButtonEvent implements ActionListener
	{
		private Container ctn;
		
		ButtonEvent(Container c) 
		{
			ctn = c;
		}
		
		public void actionPerformed(ActionEvent ev)
		{
			JButton bt_nouveau = new JButton("Bouton");
			ctn.add(bt_nouveau);
			ctn.validate();
		}
	}
}
