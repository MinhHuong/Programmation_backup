import java.awt.Graphics;

public class Rectangle implements Forme {
	protected int m_x;
	protected int m_y;
	protected int width;
	protected int height;
	
	public Rectangle( int x, int y, int w, int h )
	{
		m_x = x;
		m_y = y;
		width = w;
		height = h;
	}
	
	public void redessiner( Graphics g )
	{
		g.drawRect(m_x, m_y, width, height);
	}
}
