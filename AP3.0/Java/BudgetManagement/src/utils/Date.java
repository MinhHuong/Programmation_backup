package utils;

public class Date {

	private int m_dayWeek;
	private int m_day;
	private int m_month;
	private int m_year;
	
	public Date(int dw, int d, int m, int y)
	{
		m_dayWeek = dw;
		m_day = d;
		m_month = m;
		m_year = y;
	}
	
	public int getDayWeek()
	{
		return m_dayWeek;
	}
	
	public int getDay()
	{
		return m_day;
	}
	
	public int getMonth()
	{
		return m_month;
	}
	
	public int getYear()
	{
		return m_year;
	}
	
	public void setDayWeek(int dw)
	{
		m_dayWeek = dw;
	}
	
	public void setDay(int d)
	{
		m_day = d;
	}
	
	public void setMonth(int m)
	{
		m_month = m;
	}
	
	public void setYear(int y)
	{
		m_year = y;
	}
	
	public String dateToString()
	{
		return (intToDayWeek(m_dayWeek) +
				", " +
				Integer.toString(m_day) + 
				"/" + 
				Integer.toString(m_month) + 
				"/" + 
				Integer.toString(m_year));
	}
	
	public void StringToDate(String date)
	{
		String[] dayWeek_rest = date.split(",");
		m_dayWeek = Integer.parseInt(dayWeek_rest[0]);
		String[] res = dayWeek_rest[1].split("/");
		m_day = Integer.parseInt(res[0]);
		m_month = Integer.parseInt(res[1]);
		m_year = Integer.parseInt(res[2]);
	}
	
	public String intToDayWeek(int dw)
	{
		switch(dw)
		{
		case 2:
			return "Monday";
		case 3:
			return "Tuesday";
		case 4:
			return "Wednesday";
		case 5:
			return "Thursday";
		case 6:
			return "Friday";
		case 7:
			return "Saturday";
		case 8:
			return "Sunday";
		}
		
		return null;
	}
}
