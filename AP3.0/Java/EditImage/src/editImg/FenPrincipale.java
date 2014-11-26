package editImg;

import java.awt.BorderLayout;
import java.awt.Dimension;

import javax.swing.JFrame;

@SuppressWarnings("serial")
public class FenPrincipale extends JFrame {
	private PaneImage m_pn_img;
	
	public FenPrincipale()
	{
		setTitle("My test program");
		setPreferredSize(new Dimension(600, 600));
		setLayout(new BorderLayout());
		
		m_pn_img = new PaneImage();
		add(m_pn_img);
		m_pn_img.preparerImg();
		
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
}
