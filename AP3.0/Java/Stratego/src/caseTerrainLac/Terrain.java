package caseTerrainLac;

import pieces.Piece;
import plateau.Plateau;
import pieceMobile.*;

public class Terrain extends Case {
	private Piece m_piece = null;
	private Case[][] m_cases;
	
	public Terrain(int x, int y) {
		super(x, y);
	}

	public Piece getPiece()
	{
		return m_piece;
	}
	
	public void setPiece(Piece p, Plateau plat)
	{
		//m_cases = plat.getCases();
		
		// attaquer
		if( m_piece != null )
		{
			
		}
		else
		{
			m_piece = p;
			p.setX(p.getX());
			p.setY(p.getY());
		}
	}
	
	public void enleverPiece()
	{
		m_piece = null;
	}
	
}
