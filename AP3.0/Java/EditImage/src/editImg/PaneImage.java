package editImg;

import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.JPanel;

@SuppressWarnings("serial")
public class PaneImage extends JPanel {
	private BufferedImage m_bi;
	
	public PaneImage()
	{}

	public void preparerImg()
	{
		try
		{
			m_bi = ImageIO.read(new File("./src/editImg/meomoc.jpg"));
		}
		catch (IOException e)
		{}
		
		Graphics2D g = m_bi.createGraphics();
		paintComponent(g);
	}
	
	@Override
	public void paintComponent(Graphics g)
	{
		super.paintComponent(g);
		
		int x = this.getX();
		int y = this.getY();
		g.drawImage(m_bi, x, y, null);
	}
}
