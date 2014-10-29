package factory;

import shapeLibrary.Shape;
import colorLibrary.Color;

public abstract class AbstractFactory {
	abstract Color getColor( String color );
	abstract Shape getShape( String shape );
}
