import java.awt.*;

public class Rectangle extends FormeColoree {
	protected int m_x;
	protected int m_y;
	protected int width;
	protected int height;
	
	/**
	 * Créer un nouveau rectangle avec 5 paramètres
	 * @param x l'abcisse du point (haut-gauche)
	 * @param y l'ordonnée du point (haut-gauche)
	 * @param w la longueur
	 * @param h la largeur
	 * @param c la couleur
	 */
	public Rectangle( int x, int y, int w, int h, Color c )
	{
		m_x = x;
		m_y = y;
		width = w;
		height = h;
		col = c;
	}
	
	public void redessiner( Graphics g )
	{
		g.setColor( col );
		g.fillRect(m_x, m_y, width, height);
	}
}
