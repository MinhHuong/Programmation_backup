package caseTerrainLac;

import pieces.Piece;
import plateau.Plateau;
import pieceMobile.*;

public class Terrain extends Case {
	private Piece m_piece;
	private Case[][] m_cases;
	
	public Terrain(int x, int y) {
		super(x, y);
		m_piece = null;
	}

	public Piece getPiece()
	{
		return m_piece;
	}
	
	// m_piece : Pièce ( mobile ou immobile ) existante cette case
	// p : Pièce mobile qui entre dans cette case
	public void setPiece(Piece p, Plateau plat)
	{
		m_cases = plat.getCases();
		
		// attaquer
		if( m_piece != null )
		{
			if( m_piece.getPart() == p.getPart() )
			{
				System.out.println("Case occupée par une autre Pièce de même part");
			}
			else
			{
				// toutes les 2 Pièces de même point de force --> toutes les 2 perdues
				if( m_piece instanceof PieceMobile && ((PieceMobile)p).attaquerTie((PieceMobile)m_piece) ) 
				{
					enleverPiece();
					m_cases[p.getX()-1][p.getY()-1].enleverPiece();
				}
				// l'une gagne et l'autre perdue
				else
				{
					Piece perdue = ((PieceMobile)p).attaquerGagne(m_piece);
					m_cases[perdue.getX()-1][perdue.getY()-1].enleverPiece();
					if( perdue != p ) m_piece = p;
				}
			}
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
