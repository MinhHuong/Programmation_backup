package main;

import java.util.Scanner;
import plateau.Plateau;
import joueur.*;

public class JeuStratego {

	public static void main(String[] args) {
		Plateau plateau = new Plateau();
		Scanner input = new Scanner(System.in);
		
		System.out.print("JOUEUR ROUGE :");
		JoueurRouge jr = new JoueurRouge(false, plateau, input);
		System.out.print("JOUEUR BLEU :");
		JoueurBleu jb = new JoueurBleu(true, plateau, input);
		
		input.close();
		
		plateau.afficher();
	}

}
