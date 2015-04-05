package controller;

/**
 * singleton
 * @author MiHu
 *
 */
public class Economise implements Gestion {
	
	public Economise() {}
	
	@Override
	public void ajouter() {
		System.out.println("Ajouter dans Économise");
	}

	@Override
	public void supprimer() {
		System.out.println("Supprimer record(s) dans Économise");
	}

	@Override
	public void supprimerTout() {
		System.out.println("Supprimer tout dans Économise");
	}

	@Override
	public void sauvegarder() {
		System.out.println("Sauvegarder dans Économise");
	}

	@Override
	public void annuler() {
		System.out.println("Annuler tout changement dans Économise");
	}

	@Override
	public void doOperation(String op) {
		System.out.println("L'Économise fait l'opération " + op);
	}

	@Override
	public void createTable() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void dropTable() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void modify() {
		// TODO Auto-generated method stub
		
	}

	@Override
	public boolean modifiable() {
		// TODO Auto-generated method stub
		return false;
	}

}
