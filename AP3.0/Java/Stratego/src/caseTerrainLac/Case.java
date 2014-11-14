package caseTerrainLac;

import pieces.Piece;
import plateau.Plateau;

public abstract class Case {
	protected boolean positionValide;
	
	public Case()
	{}
	
	public void setPiece(Piece p, Plateau plat)
	{}
	
	public void enleverPiece()
	{}
	
	public boolean getPosition()
	{
		return positionValide;
	}
	
}
