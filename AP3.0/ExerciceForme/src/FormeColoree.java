import java.awt.*;

public abstract class FormeColoree {
	protected Color col;
	
	public abstract void redessiner( Graphics g );
	
	public void setColour( Color c )
	{
		col = c;
	}
}
