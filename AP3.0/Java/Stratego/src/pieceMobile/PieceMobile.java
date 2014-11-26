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
	 * L'attaque entre 2 Pi�ces ( dont l'une gagne, et l'autre d�faite )
	 * @param p : la Pi�ce attaqu�e par la Pi�ce appelante
	 * @return la Pi�ce qui est d�faite
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
	 * Tester s'il s'git de l'attaque entre 2 Pi�ces de m�me point de fore
	 * Il est obligatoire que ces 2 Pi�ces sont des Pi�ces Mobiles
	 * @param p : la Pi�ce attaqu�e
	 * @return true si les 2 Pi�ces ont le m�me point, false sinon
	 */
	public boolean attaquerTie(PieceMobile p)
	{
		return ( this.getPointForce() == p.getPointForce() );
	}
}
