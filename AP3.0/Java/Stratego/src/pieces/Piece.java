package pieces;

public abstract class Piece {
	private boolean m_part;
	private int m_x;
	private int m_y;
	
	public Piece(boolean p, int x, int y)
	{
		m_part = p;
		m_x = x;
		m_y = y;
	}
	
	public boolean getPart()
	{
		return m_part;
	}
	
	public void setPart(boolean p)
	{
		m_part = p;
	}
	
	public int getX()
	{
		return m_x;
	}
	
	public void setX(int x)
	{
		m_x = x;
	}
	
	public int getY()
	{
		return m_y;
	}
	
	public void setY(int y)
	{
		m_y = y;
	}
	
	public String getNom()
	{
		return "";
	}
}
