package databaseController;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.sql.*;
import java.util.InvalidPropertiesFormatException;
import java.util.Properties;

/**
 * This class creates a connection to JavaDB
 * @author MiHu
 */
public class DBUtilities {

	public String dbms;
	public String jarFile;
	public String dbName; 
	public String userName;
	public String password;
	public String urlString;

	private String driver;
	private String serverName;
	private int portNumber;
	private Properties prop;

	public DBUtilities(String fileName) throws FileNotFoundException, IOException, InvalidPropertiesFormatException 
	{
		super();
		this.setProperties(fileName);
	}

	private void setProperties(String fileName) throws FileNotFoundException, IOException, InvalidPropertiesFormatException 
	{
		this.prop = new Properties();
		FileInputStream fis = new FileInputStream(fileName);
		prop.loadFromXML(fis);

		this.dbms = this.prop.getProperty("dbms");
		this.jarFile = this.prop.getProperty("jar_file");
		this.driver = this.prop.getProperty("driver");
		this.dbName = this.prop.getProperty("database_name");
		this.userName = this.prop.getProperty("user_name");
		this.password = this.prop.getProperty("password");
		this.serverName = this.prop.getProperty("server_name");
		this.portNumber = Integer.parseInt(this.prop.getProperty("port_number"));

		System.out.println("Set the following properties:");
		System.out.println("dbms: " + dbms);
		System.out.println("driver: " + driver);
		System.out.println("dbName: " + dbName);
		System.out.println("userName: " + userName);
		System.out.println("serverName: " + serverName);
		System.out.println("portNumber: " + portNumber);		
	}

	public Connection getConnection() throws SQLException
	{
		Connection conn = null;
		Properties connectionProps = new Properties();
		connectionProps.put("user", this.userName);
		connectionProps.put("password", this.password);
		this.urlString = "jdbc:" + this.dbms + ":" + this.dbName;
		conn = DriverManager.getConnection(this.urlString + ";create=true", connectionProps);
		System.out.println("Create connection to Database");

		return conn;
	}

	public void closeConnection(Connection conn)
	{
		try 
		{
			if (conn != null) 
			{
				conn.close();
				conn = null;
				System.out.println("Close connection to Database");
			}
		} 
		catch (SQLException sqle) 
		{
			System.out.println("Cannot close connection to Database");
		}
	}
}
