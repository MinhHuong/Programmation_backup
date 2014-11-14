package caseTerrainLac;

import pieces.Piece;
import plateau.Plateau;

public class Terrain extends Case {
	private Piece m_piece;
	private Case[][] m_cases;
	
	public Terrain() {
		super();
	}

	public Piece getPiece()
	{
		return m_piece;
	}
	
	public void setPiece(Piece p, Plateau plat)
	{
		m_cases = plat.getCases();
		
		// attaquer
		if( m_piece != null )
		{
			
		}
		else
		{
			m_piece = p;
		}
	}
	
	public void enleverPiece()
	{
		m_piece = null;
	}
}
