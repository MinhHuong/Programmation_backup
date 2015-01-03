package controller;

public class Economise implements Gestion {

	private static Economise m_econo = new Economise();
	
	private Economise() {}
	
	public static Economise getEconomiseContext()
	{
		return m_econo;
	}
	
	@Override
	public void ajouter() {
		System.out.println("Ajouter dans �conomise");
	}

	@Override
	public void supprimer() {
		System.out.println("Supprimer record(s) dans �conomise");
	}

	@Override
	public void supprimerTout() {
		System.out.println("Supprimer tout dans �conomise");
	}

	@Override
	public void sauvegarder() {
		System.out.println("Sauvegarder dans �conomise");
	}

	@Override
	public void annuler() {
		System.out.println("Annuler tout changement dans �conomise");
	}

	@Override
	public void doOperation(String op) {
		System.out.println("L'�conomise fait l'op�ration " + op);
	}

}
