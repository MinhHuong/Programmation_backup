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
	
	// m_piece : Pi�ce ( mobile ou immobile ) existante cette case
	// p : Pi�ce mobile qui entre dans cette case
	public void setPiece(Piece p, Plateau plat)
	{
		m_cases = plat.getCases();
		
		// attaquer
		if( m_piece != null )
		{
			if( m_piece.getPart() == p.getPart() )
			{
				System.out.println("Case occup�e par une autre Pi�ce de m�me part");
			}
			else
			{
				// toutes les 2 Pi�ces de m�me point de force --> toutes les 2 perdues
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
