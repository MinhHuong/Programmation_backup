package main;

import Plateau.Plateau;
import joueur.*;

public class JeuStratego {

	public static void main(String[] args) {
		Plateau plateau = new Plateau();
		JoueurRouge jr = new JoueurRouge(false, plateau);
		jr.afficher();
		JoueurBleu jb = new JoueurBleu(true, plateau);
		jb.afficher();
		plateau.afficher();
	}

}
