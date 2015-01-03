package controller;

public class Context {

	private Gestion m_gestion;
	
	private String m_operation;
	
	public Context() {}
	
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
			m_gestion.doOperation(m_operation);
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
