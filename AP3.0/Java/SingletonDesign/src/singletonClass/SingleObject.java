package singletonClass;

public class SingleObject {
	private static SingleObject instance = new SingleObject();
	
	private SingleObject() {};
	
	public static SingleObject getInstance()
	{
		return instance;
	}
	
	public void showMessage()
	{
		System.out.println("Hello World ! This is a singleton pattern design");
	}
}
