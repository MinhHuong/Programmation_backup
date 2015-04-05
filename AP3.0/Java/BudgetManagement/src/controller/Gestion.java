package controller;

public interface Gestion {

	void createTable();
	
	void dropTable();
	
	void modify();
	
	boolean modifiable();
	
	void ajouter();

	void supprimer();
	
	void supprimerTout();
	
	void sauvegarder();
	
	void annuler();
	
	public void doOperation(String op);
}
