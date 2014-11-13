package joueur;

import java.util.Scanner;
import caseTerrainLac.Case;
import pieceImmobile.Bombe;
import pieceImmobile.Drapeau;
import pieceMobile.Demineur;
import pieceMobile.Eclaireur;
import pieceMobile.Espion;
import pieceMobile.General;
import pieceMobile.Marechal;
import plateau.Plateau;

public class JoueurBleu extends Joueur {

	public JoueurBleu(boolean p, Plateau plateau, Scanner input) {
		super(p, plateau, input);
		
		m_pieces[0] =  new Marechal(p, 1, 1);
		m_pieces[1] =   new General(p, 1, 2);
		m_pieces[2] =    new Espion(p, 1, 3);
		m_pieces[3] = new Eclaireur(p, 1, 4);
		m_pieces[4] = new Eclaireur(p, 1, 5);
		m_pieces[5] =  new Demineur(p, 1, 6);
		m_pieces[6] =  new Demineur(p, 1, 7);
		m_pieces[7] =     new Bombe(p, 1, 8);
		m_pieces[8] =     new Bombe(p, 1, 9);
		m_pieces[9] =   new Drapeau(p, 1, 10);
		
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
		System.out.println("Je suis JoueurBleu");
	}
}