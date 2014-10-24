import java.awt.*;

public class Rectangle extends FormeColoree {
	protected int m_x;
	protected int m_y;
	protected int width;
	protected int height;
	
	public Rectangle( int x, int y, int w, int h, Color c )
	{
		m_x = x;
		m_y = y;
		width = w;
		height = h;
		col = c;
	}
	
	public void redessiner( Graphics g )
	{
		g.setColor( col );
		g.fillRect(m_x, m_y, width, height);
	}
}
