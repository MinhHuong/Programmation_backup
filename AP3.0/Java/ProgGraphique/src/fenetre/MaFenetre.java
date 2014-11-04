package fenetre;

import java.awt.*;
import javax.swing.*;

@SuppressWarnings("serial")
public class MaFenetre extends JFrame {	
	public MaFenetre()
	{
		setTitle("Ma fenêtre");
		setSize(500, 500);
		//setLayout(new BorderLayout());
		
		JPanel pan = new JPanel();
		pan.setBackground(Color.yellow);
		getContentPane().add(pan, BorderLayout.EAST);
		pan.setPreferredSize(new Dimension(300,300));
	}
	
}
