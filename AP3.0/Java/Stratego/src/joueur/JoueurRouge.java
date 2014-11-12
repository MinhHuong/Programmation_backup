package joueur;

import java.util.Scanner;

import plateau.Plateau;

public class JoueurRouge extends Joueur {

	public JoueurRouge(boolean p, Plateau plateau, Scanner input) {
		super(p, plateau, input);
	}

	public void afficher()
	{
		System.out.println("Je suis JoueurRouge");
	}
}
