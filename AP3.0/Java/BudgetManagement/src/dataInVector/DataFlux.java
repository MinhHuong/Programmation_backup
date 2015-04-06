package dataInVector;

/**
 * This class represents a data of type Flux (Borrowed or Lend)
 * @author MiHu
 *
 */
public class DataFlux {

	/**
	 * Date where the flux was made
	 */
	private String date;
	
	/**
	 * Title of the flux
	 */
	private String title;
	
	/**
	 * Amount of the flux
	 */
	private int amount;
	
	/**
	 * Indicate the type of Flux (Borrowed or Lent)
	 * 0 stands for Borrowed
	 * 1 stands for Lent
	 */
	private int type;
	
	/**
	 * Indicate the person who is involved for the flux (the one who borrows/lends)
	 */
	private String person;
	
	/**
	 * Verify if the flux has been finished
	 */
	private boolean isPaid;
	
	public DataFlux()
	{
		this.title = "undefined";
		this.amount = 0;
		this.type = 0;
		this.person = "unknown";
		this.date = "";
		this.isPaid = false;
	}
	
	public DataFlux(String title, int amount, int type, String person, String date, boolean isPaid)
	{
		this.title = title;
		this.amount = amount;
		this.type = type;
		this.person = person;
		this.date = date;
		this.isPaid = isPaid;
	}

	/**
	 * A specific method written in order to set the right data into the right position in the table
	 * @param index 0, 1, 2...and so on, corresponding to the index of rows in the table
	 * @return specific object corresponding to the row of the table
	 */
	public Object getElementAt(int index)
	{
		switch(index)
		{
		case 0:
			return (String)this.title;
		case 1:
			return (int)this.amount;
		case 2:
			return (int)this.type;
		case 3:
			return (String)this.person;
		case 4:
			return (String)this.date;
		case 5:
			return (boolean)this.isPaid;
		}
		
		return null;
	}
	
	/**
	 * A specific method written in order to get the right data from a position in the table
	 * @param index 0, 1, 2...and so on, corresponding to the index of rows in the table
	 * @param obj the general data get from table 
	 */
	public void setElementAt(int index, Object obj)
	{
		switch(index)
		{
		case 0:
			this.title = (String)obj;
			break;
		case 1:
			this.amount = (int)obj;
			break;
		case 2:
			this.type = (int)obj;
			break;
		case 3:
			this.person = (String)obj;
			break;
		case 4:
			this.date = (String)obj;
			break;
		case 5:
			this.isPaid = (boolean)obj;
			break;
		}
	}
	
	/**
	 * Get the title of this Flux
	 * @return title
	 */
	public String getTitle()
	{
		return this.title;
	}
	
	/**
	 * Get the amount of this Flux
	 * @return amount
	 */
	public int getAmount()
	{
		return this.amount;
	}
	
	/**
	 * Verify if this flux has been paid or not
	 */
	public boolean isPaid()
	{
		return this.isPaid;
	}
	
	/**
	 * Get the name of the involved person
	 * @return name of the person
	 */
	public String getPerson()
	{
		return this.person;
	}
	
	/**
	 * Get the type of this Flux (borrowed/lent)
	 * @return type
	 */
	public int getType()
	{
		return this.type;
	}
	
	/**
	 * Get the date where this flux was made
	 * @return date
	 */
	public String getDate()
	{
		return this.date;
	}
	
	/**
	 * Set date to the flux
	 * @param date
	 */
	public void setDate(String date)
	{
		this.date = date;
	}
	
	/**
	 * Compare 2 objects of type DataFlux
	 * @param obj the other object to compare
	 */
	public boolean compare(DataFlux obj)
	{
		return 
				(
					this.title.equalsIgnoreCase(obj.title) 	&&
					this.amount == obj.amount 				&&
					this.type == obj.type					&&
					this.person.equalsIgnoreCase(obj.person)&&
					this.isPaid == obj.isPaid				&&
					this.date.equalsIgnoreCase(obj.date)
				);
	}
	
	/**
	 * Return the String that represents this Flux
	 */
	@Override
	public String toString()
	{
		String type = this.type == 0 ? "borrowed" : "lent";
		
		String info = 
				"Title : " + this.title + ", "
				+ "Amount : " + this.amount + ", "
				+ "Type : " + type + ", "
				+ "From : " + this.person + ", "
				+ "Paid ? " + this.isPaid + ", "
				+ "Data : " + this.date;
		
		return info;
	}
}
