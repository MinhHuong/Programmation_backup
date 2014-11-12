package joueur;

import java.util.Scanner;
import Plateau.Plateau;
import pieceMobile.*;
import pieceImmobile.*;
import pieces.Piece;

public abstract class Joueur {
	protected boolean m_part;
	protected Piece[] m_pieces = new Piece[10];
	
	public Joueur(boolean p, Plateau plateau)
	{
		Scanner input = new Scanner(System.in);
		int[] x_abs = new int[10];
		int[] y_ord = new int[10];
		System.out.println("En suivant cet ordre : Marechal, General, Espion, Eclaireur(2), Demineur(2), Bombe(2), Drapeau");
		
		for(int i = 0 ; i < 10 ; i++)
		{
			x_abs[i] = input.nextInt();
			y_ord[i] = input.nextInt();
		}
		
		
//		m_pieces[0] = new Marechal(p, 1, 1);
//		m_pieces[1] = new General(p, 1, 2);
//		m_pieces[2] = new Espion(p, 1, 3);
//		m_pieces[3] = new Eclaireur(p, 1, 4);
//		m_pieces[4] = new Eclaireur(p, 1, 5);
//		m_pieces[5] = new Demineur(p, 1, 6);
//		m_pieces[6] = new Demineur(p, 1, 7);
//		m_pieces[7] = new Bombe(p, 1, 8);
//		m_pieces[8] = new Bombe(p, 1, 9);
//		m_pieces[9] = new Drapeau(p, 1, 10);
		
		
	}
	
	public void afficher() {}
}
