package editImg;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.geom.AffineTransform;
import java.awt.image.AffineTransformOp;
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
		scaleImg();
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

	public void blendImg()
	{
		Color c = null;
		int rgb = 0, red = 0, green = 0, blue = 0;
		
		for(int i = 0 ; i < m_bi.getWidth() ; i++)
		{
			for(int j = 0 ; j < m_bi.getHeight() ; j++)
			{
				rgb = m_bi.getRGB(i, j);
				red = (rgb >> 16) & 0xFF;
				green = (rgb >> 8) & 0xFF;
				blue = rgb & 0xFF;
				
				if (red - 20 >= 0) 		red = red - 20;
				if (green + 50 <= 255)	green = green + 50;
				if (blue - 10 >= 0)		blue = blue - 10;
				
				c = new Color(red, green, blue);
				
				m_bi.setRGB(i, j, c.getRGB());
			}
		}
		
		repaint();
	}

	public void scaleImg()
	{
		int w = m_bi.getWidth();
		int h = m_bi.getHeight();
		BufferedImage after = new BufferedImage(w, h, BufferedImage.TYPE_INT_ARGB);
		AffineTransform at = new AffineTransform();
		at.scale(0.5, 0.25);
		AffineTransformOp scaleOp = new AffineTransformOp(at, AffineTransformOp.TYPE_BILINEAR);
		after = scaleOp.filter(m_bi, after);
		m_bi = after;
		repaint();
	}
}













