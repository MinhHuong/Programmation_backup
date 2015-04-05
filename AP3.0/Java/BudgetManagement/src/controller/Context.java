package controller;

public class Context {

	private Gestion m_gestion;
	
	private String m_operation;
	
	public Context() {}
	
	public Gestion getGestion()
	{
		return m_gestion;
	}
	
	public void setGestion(Gestion g)
	{
		m_gestion = g;
	}
	
	public void setOperation(String op)
	{
		m_operation = op;
	}
	
	public void execute()
	{
		try 
		{
			switch(m_operation)
			{
				case "modifier":
				{
					m_gestion.modify();
					break;
				}
				case "sauvegarder":
				{
					m_gestion.sauvegarder();
					break;
				}
				case "annuler":
				{
					m_gestion.annuler();
					break;
				}
				case "ajouterligne":
				{
					m_gestion.ajouter();
					break;
				}
				case "supprimerligne":
				{
					m_gestion.supprimer();
					break;
				}
				case "supprimertout":
				{
					m_gestion.supprimerTout();
					break;
				}
			}
		} 
		catch(NullPointerException e) 
		{
			System.err.println("Cannot execute operation + " + m_operation);
		}
		catch(Exception e)
		{
			System.err.println("Error while executing operation " + m_operation);
		}
	}
}
