package caseTerrainLac;

import pieces.Piece;

public class Terrain extends Case {
	private Piece m_piece;
	
	public Terrain() {
		super();
	}

	public Piece getPiece()
	{
		return m_piece;
	}
	
	public void setPiece(Piece p)
	{
		m_piece = p;
	}
}
