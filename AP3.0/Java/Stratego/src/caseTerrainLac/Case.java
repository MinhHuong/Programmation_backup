package caseTerrainLac;

import pieces.Piece;
import plateau.Plateau;

public abstract class Case {
	protected boolean positionValide;
	protected int m_x;
	protected int m_y;
	
	public Case(int x, int y)
	{
		m_x = x;
		m_y = y;
		positionValide = false;
	}
	
	public void setPiece(Piece p, Plateau plat)
	{}
	
	public void enleverPiece()
	{}
	
	public boolean getEtatPosition()
	{
		return positionValide;
	}
	
	public void setEtatPosition(boolean b)
	{
		positionValide = b;
	}
	
	public int getX()
	{
		return m_x;
	}
	
	public int getY()
	{
		return m_y;
	}
}
