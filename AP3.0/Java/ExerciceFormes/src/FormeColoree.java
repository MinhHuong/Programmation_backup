import java.awt.*;

public abstract class FormeColoree {
	protected Color col;
	
	/**
	 * La m�thode servant � dessiner des formes
	 * @param g : Graphics
	 */
	public abstract void redessiner( Graphics g );
	
	public void setColour( Color c )
	{
		col = c;
	}
	
	public Color getColor()
	{
		return col;
	}
}
