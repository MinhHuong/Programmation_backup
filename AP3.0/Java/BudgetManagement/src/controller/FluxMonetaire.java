package controller;

/**
 * singleton
 * @author MiHu
 *
 */
public class FluxMonetaire implements Gestion {

	public FluxMonetaire() {}
	
	@Override
	public void ajouter() {
		System.out.println("Ajouter dans le Flux mon�taire (emprunter - pr�ter)");
	}

	@Override
	public void supprimer() {
		System.out.println("Supprimer record(s) dans le Flux mon�taire (emprunter - pr�ter)");
	}

	@Override
	public void supprimerTout() {
		System.out.println("Supprimer tout dans le Flux mon�taire (emprunter - pr�ter)");
	}

	@Override
	public void sauvegarder() {
		System.out.println("Sauvegarder dans le Flux mon�taire (emprunter - pr�ter)");
	}

	@Override
	public void annuler() {
		System.out.println("Annuler tout changement dans le Flux mon�taire (emprunter - pr�ter)");
	}

	@Override
	public void doOperation(String op) {
		System.out.println("Le Flux mon�taire (emprunter - pr�ter) fait l'op�ration " + op);
	}

	@Override
	public void createTable() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void dropTable() {
		// TODO Auto-generated method stub
		
	}

}
