package utils;

import gui.MyTableModel;

import java.util.Vector;

import dataInVector.DataDepQuoti;
import dataInVector.DataFlux;

/**
 * A singleton class simulated as Database, therefore it only contains static methods and varaibles
 * @author MiHu
 */

public class DatabaseSim {
	
	private static DatabaseSim dbSim = new DatabaseSim();

	private static Vector<DataDepQuoti> m_vt_depQuoti = new Vector<DataDepQuoti>();
	
	private static Vector<DataFlux> m_vt_flux = new Vector<DataFlux>();
	
	private DatabaseSim()
	{}
	
	public static DatabaseSim getInstance()
	{
		return dbSim;
	}
	
	public static void setDataDepQuoti(Vector<DataDepQuoti> vt)
	{
		m_vt_depQuoti = vt;
	}
	
	public static void setDataFlux(Vector<DataFlux> vt)
	{
		m_vt_flux = vt;
	}
	
	public static void addDepQuotiToDB(DataDepQuoti obj)
	{
		m_vt_depQuoti.addElement(obj);
	}
	
	public static void addFluxToDB(DataFlux obj)
	{
		m_vt_flux.addElement(obj);
	}
	
	public static boolean checkOccurenceDepQuoti(DataDepQuoti obj)
	{
		for(DataDepQuoti dep : m_vt_depQuoti)
		{
			if(dep.compare(obj))
			{
				return true;
			}
		}
		
		return false;
	}
	
	public static boolean checkOccurenceFlux(DataFlux obj)
	{
		for(DataFlux flux : m_vt_flux)
		{
			if(flux.compare(obj))
			{
				return true;
			}
		}
		
		return false;
	}
	
	
	public static void showDataInDB()
	{
		for(DataDepQuoti dep : m_vt_depQuoti)
		{
			System.out.println(dep.toString());
		}
		
		for(DataFlux flux : m_vt_flux)
		{
			System.out.println(flux.toString());
		}
	}
	
	public static void findEntry(String date, MyTableModel<DataDepQuoti> tabModel)
	{
		Vector<DataDepQuoti> vt_result = new Vector<DataDepQuoti>();

		if(m_vt_depQuoti.size() != 0)
		{
			for(DataDepQuoti dep : m_vt_depQuoti)
			{
				if(date.equalsIgnoreCase(dep.getDate()))
				{
					vt_result.add(dep);
				}
			}
		}
		
		tabModel.setData(vt_result);
		tabModel.fireTableDataChanged();
	}

	public static void eraseAllOnDate(String date)
	{
		Vector<DataDepQuoti> vt_erase = new Vector<DataDepQuoti>();
		// on doit faire la suppression des donn�es indirectement, sinon le compileur lance l'exception
		// ConcurrentModification : cannot remove an element after creating an iterator, while we're using
		// that iterator to search in the list
		
		for(DataDepQuoti dep : m_vt_depQuoti)
		{
			if(date.equalsIgnoreCase(dep.getDate()))
			{
				vt_erase.add(dep);
			}
		}
		
		for(DataDepQuoti dep : vt_erase)
		{
			m_vt_depQuoti.remove(dep);
		}
	}
}