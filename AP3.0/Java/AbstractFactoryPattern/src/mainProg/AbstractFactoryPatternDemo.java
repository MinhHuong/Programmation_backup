package mainProg;

import factory.*;
import colorLibrary.Color;
import shapeLibrary.Shape;

public class AbstractFactoryPatternDemo {

	public static void main(String[] args) {
		// get the shapes desired
		AbstractFactory shapeFactory = FactoryProducer.getFactory("SHAPE");
		
		Shape shape1 = shapeFactory.getShape("CIRCLE");
		shape1.draw();
		
		Shape shape2 = shapeFactory.getShape("RECTANGLE");
		shape2.draw();
		
		Shape shape3 = shapeFactory.getShape("SQUARE");
		shape3.draw();
		
		// get the colors desired
		AbstractFactory colorFactory = FactoryProducer.getFactory("COLOR");
		
		Color color1 = colorFactory.getColor("RED");
		color1.fill();
		
		Color color2 = colorFactory.getColor("GREEN");
		color2.fill();
		
		Color color3 = colorFactory.getColor("BLUE");
		color3.fill();
	}

}
