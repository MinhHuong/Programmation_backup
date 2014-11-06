import java.awt.Color;
import java.awt.Point;
import java.awt.event.MouseEvent;
import java.util.Vector;
import javax.swing.event.MouseInputAdapter;

public class RectangleParDragSouris extends MouseInputAdapter {
	private Point m_src;
	private Point m_dest;
	private ZoneDeDessin m_zone;
	private Vector<Rectangle> v_rect;
	
	public RectangleParDragSouris( ZoneDeDessin z )
	{
		m_zone = z;
		v_rect = new Vector<Rectangle>();
	}
	
	public void mousePressed( MouseEvent e )
	{
		m_src = e.getPoint();
	}
	
	public void mouseReleased( MouseEvent e )
	{
		Rectangle rect_final = v_rect.lastElement();
		rect_final.setColour( Color.black );
		m_zone.getFormes().add( rect_final );
		m_zone.repaint();
		v_rect.clear();
	}

	public void mouseDragged(MouseEvent e) {
		if( !v_rect.isEmpty() ) 
		{
			v_rect.remove( v_rect.lastElement() );
			m_zone.repaint();
		}
		
		m_dest = e.getPoint();
		
		int w = (int)m_dest.getX() - (int)m_src.getX();
		int h = (int)m_dest.getY() - (int)m_src.getY();	
		int x_debut = 0, y_debut = 0;
		
		x_debut = ( w > 0 ) ? (int)m_src.getX() : (int)m_src.getX() + w;
		y_debut = ( h > 0 ) ? (int)m_src.getY() : (int)m_src.getY() + h;
		
		Rectangle rect = new Rectangle( x_debut, y_debut, Math.abs(w), Math.abs(h),
										Color.magenta );
		v_rect.add( rect );
		m_zone.repaint();
	}

	public Vector<Rectangle> getRectDragged() {
		return v_rect;
	}
}