package pieceMobile;

import pieceImmobile.*;
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
	
	/**
	 * L'attaque entre 2 Pièces ( dont l'une gagne, et l'autre défaite )
	 * @param p : la Pièce attaquée par la Pièce appelante
	 * @return la Pièce qui est défaite
	 */
	public Piece attaquerGagne(Piece p)
	{
		if( p instanceof PieceImmobile )
		{
			if( p instanceof Bombe )
			{
				if( this instanceof Demineur )	
					return p;
				else
					return this;
			}
			
			if( p instanceof Drapeau )
				System.out.print("Drapeau capte !");
		}
		
		if( p instanceof PieceMobile )
		{
			if( this instanceof Espion && p instanceof Marechal )
				return p;
			
			if( this.getPointForce() > ((PieceMobile) p).getPointForce() )
				return p;
			else
				return this;
		}
		
		return null;
	}

	/**
	 * Tester s'il s'git de l'attaque entre 2 Pièces de même point de fore
	 * Il est obligatoire que ces 2 Pièces sont des Pièces Mobiles
	 * @param p : la Pièce attaquée
	 * @return true si les 2 Pièces ont le même point, false sinon
	 */
	public boolean attaquerTie(PieceMobile p)
	{
		return ( this.getPointForce() == p.getPointForce() );
	}
}
