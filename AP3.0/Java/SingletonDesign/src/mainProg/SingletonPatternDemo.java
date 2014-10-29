package mainProg;

import singletonClass.*;

public class SingletonPatternDemo {

	public static void main(String[] args) {
		//SingleObject sObj = new SingleObject();
		// cannot instantiate this class
		
		SingleObject object = SingleObject.getInstance();
		object.showMessage();
	}

}
