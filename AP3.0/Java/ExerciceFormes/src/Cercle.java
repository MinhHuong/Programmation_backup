import java.awt.*;

/*
 * Created on 6 sept. 2005
 *
 * To change the template for this generated file go to
 * Window&gt;Preferences&gt;Java&gt;Code Generation&gt;Code and Comments
 */

/**
 * @author lachaud
 *
 * To change the template for this generated type comment go to
 * Window&gt;Preferences&gt;Java&gt;Code Generation&gt;Code and Comments
 */
public class Cercle extends FormeColoree {
	protected int m_x;
	protected int m_y;
	protected int m_r;
	
	/**
	 * Cr�er un nouveau cercle avec 4 param�tres
	 * @param x l'abcisse 
	 * @param y l'ordonn�e
	 * @param r le rayon
	 * @param c la couleur
	 */
	public Cercle( int x, int y, int r, Color c )
	{
		m_x = x;
		m_y = y;
		m_r = r;
		col = c;
	}
	
	/* (non-Javadoc)
	 * @see Forme#redessiner(java.awt.Graphics)
	 */
	public void redessiner(Graphics g) {
		g.setColor(col);
		g.fillOval( m_x - m_r , m_y - m_r,
			2 * m_r, 2 * m_r );
	}

}
