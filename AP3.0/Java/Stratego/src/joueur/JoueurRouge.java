package joueur;

import caseTerrainLac.Case;
import Plateau.Plateau;

public class JoueurRouge extends Joueur {

	public JoueurRouge(boolean p, Plateau plateau) {
		super(p, plateau);
		
		Case[][] cases = plateau.getCases();
		
		for(int i = 0 ; i < 10 ; i++)
		{
			int l = m_pieces[i].getX() - 1;
			int c = m_pieces[i].getY() - 1;
			cases[l][c].setPiece(m_pieces[i]);
		}
	}

	public void afficher()
	{
		System.out.println("Je suis JoueurRouge");
	}
}
