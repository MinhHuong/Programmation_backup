package plateau;

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
						m_cases[i][j] = new Lac();
					else
						m_cases[i][j] = new Terrain();
				}
				else
				{
					m_cases[i][j] = new Terrain();
				}
			}
		}
	}
	
	public void afficher()
	{
		for(int i = 0 ; i < 10 ; i ++)
		{
			for(int j = 0 ; j < 10 ; j++)
			{
				if(m_cases[i][j] instanceof Lac)
				{
					System.out.print(" L ");
				}
				else if(m_cases[i][j] instanceof Terrain)
				{
					Piece p = ((Terrain) m_cases[i][j]).getPiece();
					if( p != null ) System.out.print(p.getNom());
					else System.out.print("   ");
				}
			}
			
			System.out.println();
		}
	}
	
	public void deplacerPiece(Case c)
	{
		
	}

	public Case[][] getCases()
	{
		return m_cases;
	}
}
