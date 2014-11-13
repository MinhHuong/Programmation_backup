package main;

import java.util.Scanner;
import caseTerrainLac.*;
import plateau.Plateau;
import joueur.*;

public class JeuStratego {

	public static void main(String[] args) {
		Plateau plateau = new Plateau();
		Scanner input = new Scanner(System.in);
		int abs = 0;
		int ord = 0;
		int fini = -1;
		
		System.out.println("JOUEUR ROUGE :");
		JoueurRouge jr = new JoueurRouge(false, plateau, input);
		jr.afficher();
		System.out.println("JOUEUR BLEU :");
		JoueurBleu jb = new JoueurBleu(true, plateau, input);
		jb.afficher();
		
		plateau.afficher();
		
		do
		{
			Case source = jr.choisirPiece(abs, ord, input, plateau);
			Case destination = jr.choisirPiece(abs, ord, input, plateau);
			plateau.deplacerPiece(source, destination);
			plateau.afficher();
			
			System.out.print("Appuyez 1 pour continuer, 0 pour quitter : ");
			fini = input.nextInt();
		} 
		while( fini != 0 );
	}

}
