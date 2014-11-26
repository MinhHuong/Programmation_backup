package joueur;

import java.util.Scanner;
import caseTerrainLac.*;
import pieceMobile.*;
import pieceImmobile.*;
import pieces.Piece;
import plateau.Plateau;

public abstract class Joueur {
	protected boolean m_part;
	protected Piece[] m_pieces = new Piece[10];
	
	public Joueur(boolean p, Plateau plateau, Scanner input)
	{
		int[] x_abs = new int[10];
		int[] y_ord = new int[10];
		String[] nomPiece = { "MARECHAL"	, 
							  "GENERAL"		, 
							  "ESPION"		, 
							  "ECLAIREUR"	, 
							  "ECLAIREUR"	,
							  "DEMINEUR"	,
							  "DEMINEUR"	,
							  "BOMBE"		,
							  "BOMBE"		,
							  "DRAPEAU"		};
		
		for(int i = 0 ; i < 10 ; i++)
		{
			System.out.println(nomPiece[i] + " : ");
			System.out.print("  | x = ");
			x_abs[i] = input.nextInt();
			System.out.print("  | y = ");
			y_ord[i] = input.nextInt();
		}

		m_pieces[0] =  new Marechal(p, x_abs[0], y_ord[0]);
		m_pieces[1] =   new General(p, x_abs[1], y_ord[1]);
		m_pieces[2] =    new Espion(p, x_abs[2], y_ord[2]);
		m_pieces[3] = new Eclaireur(p, x_abs[3], y_ord[3]);
		m_pieces[4] = new Eclaireur(p, x_abs[4], y_ord[4]);
		m_pieces[5] =  new Demineur(p, x_abs[5], y_ord[5]);
		m_pieces[6] =  new Demineur(p, x_abs[6], y_ord[6]);
		m_pieces[7] =     new Bombe(p, x_abs[7], y_ord[7]);
		m_pieces[8] =     new Bombe(p, x_abs[8], y_ord[8]);
		m_pieces[9] =   new Drapeau(p, x_abs[9], y_ord[9]);
	}		
	
	public void afficher() {}
	
	public Case choisirPiece(int x, int y, Scanner inp, Plateau plat, String quelPoint)
	{
		System.out.println(quelPoint + " : ");
		do
		{
			System.out.println("Choisir une Case (si x et y invalides, veuillez refaire le positionnement) : ");
			System.out.print(" | x = ");
			x = inp.nextInt();
			System.out.print(" | y = ");
			y = inp.nextInt();
		}
		while ( x < 1 || x > 10 || y < 1 || y > 10 );
		
		return (plat.getCases())[x-1][y-1];
		
	}
}
