package editImg;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.image.BufferedImage;
import java.awt.image.BufferedImageOp;
import java.awt.image.ConvolveOp;
import java.awt.image.Kernel;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.JPanel;

@SuppressWarnings("serial")
public class PaneImage extends JPanel implements MouseListener {
	private BufferedImage m_bi;
	
	public PaneImage()
	{
		addMouseListener(this);
	}

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

	@Override
	public void mouseClicked(MouseEvent e) 
	{
		cropImg();
	}

	@Override
	public void mousePressed(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseReleased(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseEntered(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseExited(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}
	
	public void negativeImg()
	{
		Color c = null;
		
		for(int i = 0 ; i < m_bi.getWidth() ; i++)
		{
			for(int j = 0 ; j < m_bi.getHeight() ; j++)
			{
				int rgb = m_bi.getRGB(i, j);
				int red = (rgb >> 16) & 0xFF;
				int green = (rgb >> 8) & 0xFF;
				int blue = rgb & 0xFF;
				
				red = 255 - red;
				green = 255 - green;
				blue = 255 - blue;
				
				c = new Color(red, green, blue);
				
				m_bi.setRGB(i, j, c.getRGB());
			}
		}
		
		repaint();
	}

	public void blurImg()
	{
		// Blur an Image
		float[] matrix = {
				0.111f, 0.111f, 0.111f, 
				0.111f, 0.111f, 0.111f, 
				0.111f, 0.111f, 0.111f, 
		};

		BufferedImageOp op = new ConvolveOp( new Kernel(3, 3, matrix) );
		BufferedImage m_copy = new BufferedImage(m_bi.getWidth(), m_bi.getHeight(), BufferedImage.TYPE_INT_ARGB);
		m_copy = op.filter(m_bi, m_copy);
		m_bi = m_copy;
		repaint();
	}

	public void cropImg()
	{
		BufferedImage bi_cropped = new BufferedImage(100, 100, BufferedImage.TYPE_INT_ARGB);
		bi_cropped = m_bi.getSubimage(0, 0, 200, 200);
		m_bi = bi_cropped;
		repaint();
		
		try
		{
			File output = new File("saved.png");
			ImageIO.write(m_bi, "png", output);
		}
		catch(IOException e)
		{}
	}

}













