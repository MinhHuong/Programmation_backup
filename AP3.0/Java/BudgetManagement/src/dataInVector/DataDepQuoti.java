package dataInVector;

public class DataDepQuoti {

	private String m_intitule;
	private int m_montant;
	private boolean estEmprunt;
	private boolean estPret;
	
	public DataDepQuoti(String inti, int montant, boolean emp, boolean pret)
	{
		m_intitule = inti;
		m_montant = montant;
		estEmprunt = emp;
		estPret = pret;
	}
	
	public Object getElementAt(int index)
	{
		switch(index)
		{
		case 0:
			return (String)m_intitule;
		case 1:
			return (int)m_montant;
		case 2:
			return (boolean)estEmprunt;
		case 3:
			return (boolean)estPret;
		}
		
		return null;
	}
	
	public String getIntitule()
	{
		return m_intitule;
	}
	
	public int getMontant()
	{
		return m_montant;
	}
	
	public boolean isEmprunt()
	{
		return estEmprunt;
	}
	
	public boolean isPret()
	{
		return estPret;
	}
	
	public void setIntitule(String inti)
	{
		m_intitule = inti;
	}
	
	public void setMontant(int mont)
	{
		m_montant = mont;
	}
	
	public void setEmprunt(boolean emp)
	{
		estEmprunt = emp;
	}
	
	public void setPret(boolean pret)
	{
		estPret = pret;
	}
}
