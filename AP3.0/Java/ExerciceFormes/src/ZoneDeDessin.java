import java.util.Vector;
import java.awt.Graphics;

import javax.swing.JPanel;

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
@SuppressWarnings("serial")
public class ZoneDeDessin extends JPanel {
	private Vector<FormeColoree> m_formes;
	private RectangleParDragSouris rect_drag;
	private VisualiseurDeFormes m_visu;
	
	public VisualiseurDeFormes getVisualiseur()
	{
		return m_visu;
	}
	
	public ZoneDeDessin(VisualiseurDeFormes v)
	{
		m_visu = v;
		rect_drag = new RectangleParDragSouris( this );
		addMouseMotionListener(rect_drag); // enable MouseDragged & MouseMoved
		addMouseListener( rect_drag ); // enable MousePressed, MouseReleased, MouseEntered, MouseExited
	}
	
	public void setFormes( Vector<FormeColoree> formes )
	{
		m_formes = formes;
	}
	
	public Vector<FormeColoree> getFormes()
	{
		return m_formes;
	}
	
	public void paintComponent( Graphics g )
	{
		super.paintComponent(g);
		
		if ( m_formes != null )
		{
			for ( int i = 0; i < m_formes.size(); i++ )
			{
				FormeColoree f = (FormeColoree) m_formes.get( i );
				f.redessiner( g );
			}
		}
		
		Vector<Rectangle> v_rect = rect_drag.getRectDragged();
		if( v_rect != null )
		{
			for( int i = 0 ; i < v_rect.size() ; i++ )
			{
				FormeColoree f = (FormeColoree) v_rect.get(i);
				f.redessiner( g );
			}
		}
	}
}