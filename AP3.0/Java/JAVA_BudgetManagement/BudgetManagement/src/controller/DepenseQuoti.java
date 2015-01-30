package controller;

/**
 * singleton
 * @author MiHu
 *
 */
public class DepenseQuoti implements Gestion {

	private static DepenseQuoti m_depense_quoti = new DepenseQuoti();
	
	private DepenseQuoti() {}
	
	public static DepenseQuoti getDepenseQuotiContext()
	{
		return m_depense_quoti;
	}
	
	@Override
	public void ajouter() {
		System.out.println("Ajouter dans D�pense quotidienne");
	}

	@Override
	public void supprimer() {
		System.out.println("Supprimer record(s) dans D�pense quotidienne");
	}

	@Override
	public void supprimerTout() {
		System.out.println("Tout supprimer dans D�pense quotidienne");
	}

	@Override
	public void sauvegarder() {
		System.out.println("Sauvegarder dans D�pense quotidienne");
	}

	@Override
	public void annuler() {
		System.out.println("Annuler dans D�pense quotidienne");
	}

	@Override
	public void doOperation(String op) {
		System.out.println("D�pense quotidienne fait l'op�ration " + op);
	}

}
