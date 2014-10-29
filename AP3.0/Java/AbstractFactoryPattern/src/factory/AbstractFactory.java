package factory;

import shapeLibrary.Shape;
import colorLibrary.Color;

public abstract class AbstractFactory {
	public abstract Color getColor( String color );
	public abstract Shape getShape( String shape );
}
