package factory;

import shapeLibrary.*;
import colorLibrary.Color;
// la classe ShapeFactory

public class ShapeFactory extends AbstractFactory {
	// use getShape method to get object of type Shape
	@Override
	public Shape getShape( String shapeType )
	{
		if( shapeType == null ) return null;
		else if( shapeType.equalsIgnoreCase("CIRCLE") ) return new Circle();
		else if( shapeType.equalsIgnoreCase("RECTANGLE") ) return new Rectangle();
		else if( shapeType.equalsIgnoreCase("SQUARE") ) return new Square();
		
		return null;
	}
	
	@Override
	public Color getColor( String color )
	{
		return null;
	}
}
