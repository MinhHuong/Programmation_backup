package plateau;

import pieceMobile.*;
import pieceImmobile.*;
import pieces.Piece;
import caseTerrainLac.*;

public class Plateau {
	private Case[][] m_cases = new Case[10][10];
	
	/**
	 * Instancier un Plateau de 100 cases, dont 92 Terrains et 8 Lacs (2 lacs de taille 2x2)
	 */
	public Plateau()
	{		
		for(int i = 0 ; i < 10 ; i++)
		{		
			for(int j = 0 ; j < 10 ; j++)
			{
				if(i == 4 || i == 5)
				{
					if(j == 2 || j == 3 || j == 6 || j == 7)
						m_cases[i][j] = new Lac(i+1, j+1);
					else
						m_cases[i][j] = new Terrain(i+1, j+1);
				}
				else
				{
					m_cases[i][j] = new Terrain(i+1, j+1);
				}
			}
		}
	}
	
	public void afficher()
	{
		System.out.println("	   1    2    3    4    5    6    7    8    9   10");

		for(int i = 0 ; i <= 20 ; i++)
		{
			if( i%2 == 1 )	System.out.print( (i+1)/2 );
			System.out.print("	");
			
			for(int j = 0 ; j <= 10 ; j++)
			{
				if( i%2 == 0 )
				{
					if( j < 9 )			System.out.print("+----");
					else if( j == 9 )	System.out.print("+----+");
				}
				else
					System.out.print("|");
				
				if( j < 10 )
				{
					if( i%2 == 1 )
						if(m_cases[(i-1)/2][j] instanceof Lac)
						{
							System.out.print(" LL ");
						}
						else if(m_cases[(i-1)/2][j] instanceof Terrain)
						{
							Piece p = ((Terrain) m_cases[(i-1)/2][j]).getPiece();
							if( p != null ) System.out.print( p.getNom() );
							else
							{
								if( ((Terrain)m_cases[(i-1)/2][j]).getEtatPosition() )
									System.out.print(" xx ");
								else
									System.out.print("    ");
							}
						}
				}		
			}
			
			System.out.println();
		}
	}
	
	public boolean nonLac(Case c)
	{
		return ( !(c instanceof Lac) );
	}
	
	public void deplacerPiece(Case src, Case dest)
	{
		if( src instanceof Lac || dest instanceof Lac )
		{
			System.out.println("Impossible de choisir une Pièce dans un Lac !");
		}
		else
		{
			Piece p = ((Terrain) src).getPiece();
			int new_x = dest.getX();
			int new_y = dest.getY();
			p.setX(new_x);
			p.setY(new_y);
			((Terrain) dest).setPiece(p, this);
			((Terrain) src).enleverPiece();
			resetCases();
		}
	}

	public void mouvementValide(Case c)
	{
		if( !(c instanceof Lac) )
		{
			Piece p = ((Terrain) c).getPiece();
			
			if( p != null )
			{
				int i = p.getX() - 1;
				int j = p.getY() - 1;

				if( !(p instanceof Eclaireur) )
				{
					if( i+1 < 10 )
						m_cases[i+1][j].setEtatPosition(true);

					if( i-1 >= 0 )
						m_cases[i-1][j].setEtatPosition(true);

					if( j-1 >= 0 )
						m_cases[i][j-1].setEtatPosition(true);

					if( j+1 < 10 )
						m_cases[i][j+1].setEtatPosition(true);
				}
			}
		}
	}
	
	public Case[][] getCases()
	{
		return m_cases;
	}

	public void resetCases()
	{
		for( int i = 0 ; i < 10 ; i++ )
		{
			for( int j = 0 ; j < 10 ; j++ )
			{
				m_cases[i][j].setEtatPosition(false);
			}
		}
	}
}
