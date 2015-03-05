package controller;

/**
 * singleton
 * This class handles the connection between Application and Database<p>
 * At least I will prepare SQL statement here
 * @author MiHu
 *
 */
public class DepenseQuoti implements Gestion {
	
	public DepenseQuoti() 
	{}
	
	@Override
	public void createTable() 
	{}

	@Override
	public void dropTable() {
		// TODO Auto-generated method stub
		
	}
	
	@Override
	public void ajouter() {
		System.out.println("Ajouter une ligne dans D�pense quotidienne");
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
