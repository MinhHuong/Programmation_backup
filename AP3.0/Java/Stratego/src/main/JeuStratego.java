package main;

import java.util.Scanner;
import plateau.Plateau;
import joueur.*;

public class JeuStratego {

	public static void main(String[] args) {
		Plateau plateau = new Plateau();
		Scanner input = new Scanner(System.in);
		
		JoueurRouge jr = new JoueurRouge(false, plateau, input);
		jr.afficher();
		JoueurBleu jb = new JoueurBleu(true, plateau, input);
		jb.afficher();
		
		input.close();
		
		plateau.afficher();
	}

}
