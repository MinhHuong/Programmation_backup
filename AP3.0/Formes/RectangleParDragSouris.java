import java.awt.Color;
import java.awt.Point;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;

public class RectangleParDragSouris implements MouseListener {
	private Point m_src;
	private Point m_dest;
	//private Rectangle rect;
	private ZoneDeDessin m_zone;
	
	public RectangleParDragSouris( ZoneDeDessin z )
	{
		m_zone = z;
	}
	
	public void mousePressed( MouseEvent e )
	{
		m_src = e.getPoint();
	}
	
	public void mouseReleased( MouseEvent e )
	{
		m_dest = e.getPoint();
		int w = (int)m_dest.getX() - (int)m_src.getX();
		int h = (int)m_dest.getY() - (int)m_src.getY();
		
		int x_debut = 0, y_debut = 0;
		
		if( w > 0 && h > 0 )
		{
			x_debut = (int)m_src.getX();
			y_debut = (int)m_src.getY();
		}
		
		if( w > 0 && h < 0 )
		{
			x_debut = (int)m_src.getX();
			y_debut = (int)m_src.getY() + h;
		}
		
		if( w < 0 && h > 0 )
		{
			x_debut = (int)m_src.getX() + w;
			y_debut = (int)m_src.getY();
		}
		
		if( w < 0 && h < 0 )
		{
			x_debut = (int)m_src.getX() + w;
			y_debut = (int) m_src.getY() + h;
		}
		
		Rectangle rect = new Rectangle( x_debut, y_debut, Math.abs(w), Math.abs(h),
										Color.black );
		m_zone.getFormes().add( rect );
		m_zone.repaint();
		
		m_src = null;
		m_dest = null;
	}

	public void mouseClicked(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}

	public void mouseEntered(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}

	public void mouseExited(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}
	
	/*
	public void mouseDragged(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseMoved(MouseEvent e) {
		// TODO Auto-generated method stub
		//m_dest = e.getPoint();
		//Rectangle rect = new Rectangle( (int)m_src.getX(), (int)m_src.getY(),
				//(int)m_dest.getX(), (int)m_dest.getY(), Color.black );
		//m_zone.getFormes().add( rect );
		//m_zone.repaint();
	}
*/
}
