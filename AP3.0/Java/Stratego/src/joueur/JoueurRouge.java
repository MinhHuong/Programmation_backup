package joueur;

import java.util.Scanner;

import caseTerrainLac.Case;
import plateau.Plateau;

public class JoueurRouge extends Joueur {

	public JoueurRouge(boolean p, Plateau plateau, Scanner input) {
		super(p, plateau, input);
		
		Case[][] cases = plateau.getCases();
		
		for(int i = 0 ; i < 10 ; i++)
		{
			int l = m_pieces[i].getX() - 1;
			int c = m_pieces[i].getY() - 1;
			cases[l][c].setPiece(m_pieces[i], plateau);
		}
	}

	public void afficher()
	{
		System.out.println("Je suis JoueurRouge");
	}
}
