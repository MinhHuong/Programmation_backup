package pieceMobile;

import pieces.Piece;

public abstract class PieceMobile extends Piece {
	protected int m_pointForce;
	
	public PieceMobile(boolean p, int x, int y)
	{
		super(p, x, y);
		m_pointForce = 0;
	}
	
	public int getPointForce()
	{
		return m_pointForce;
	}
	
	public String getNom()
	{
		return "";
	}
}
