import java.util.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

/*
 * Created on 6 sept. 2005
 *
 * To change the template for this generated file go to
 * Window&gt;Preferences&gt;Java&gt;Code Generation&gt;Code and Comments
 */

/**
 * Cette classe mod�lise une application graphique de visualisation
 * de formes. Elle d�rive de JFrame, qui est une fen�tre SWING "light".
 * 
 * @author lachaud
 *
 * To change the template for this generated type comment go to
 * Window&gt;Preferences&gt;Java&gt;Code Generation&gt;Code and Comments
 */
public class VisualiseurDeFormes extends JFrame 
{
	/**
	 * R�f�rence l'objet servant � g�n�rer des nombres al�atoires.
	 */
	private Random m_random;
	
	/**
	 * R�f�rence la liste des formes � dessiner.
	 */
	private Vector m_formes;
	
	/**
	 * R�f�rence l'objet o� les formes se dessinent.
	 */
	private ZoneDeDessin m_panneau_dessin;
	
	/**
	 * R�f�rence l'objet o� sont plac�s les boutons.
	 */
	private JPanel m_panneau_boutons;
	
	/**
	 * Cette classe mod�lise la r�action de cr�ation d'un cercle suite
	 * � un clic sur un bouton. C'est une classe interne � 
	 * VisualiseurDeFormes.
	 * 
	 * @author lachaud
	 *
	 * To change the template for this generated type comment go to
	 * Window&gt;Preferences&gt;Java&gt;Code Generation&gt;Code and Comments
	 */
	class BoutonCercleAction implements ActionListener	
	{
		/**
		 * R�f�rence l'application qui a cr�� ce bouton.
		 */
		private VisualiseurDeFormes m_visualiseur;
		
		/**
		 * Constructeur.
		 * @param visu est l'application reli� � ce bouton.
		 */
		BoutonCercleAction( VisualiseurDeFormes visu )
		{
			m_visualiseur = visu;
		 }
		 
		/**
		 * Cr�e un nouveau cercle de coordonn�es et rayon al�atoire.
		 * suite � l'action [e].
		 * 
		 * @param e l'action qui a d�clench�e l'appel � cette m�thode.
		 */
		public void actionPerformed( ActionEvent e)
		{
			Random r = m_visualiseur.getRandom();
			Cercle c = new Cercle(
				r.nextInt( 200 ),
				r.nextInt( 200 ),
			    r.nextInt( 40 )+ 20 );
			m_visualiseur.getFormes().add( c );
			m_visualiseur.repaint();
		}
	}
	
	class BoutonRectangleAction implements ActionListener
	{
		private VisualiseurDeFormes m_visu;
		
		BoutonRectangleAction(VisualiseurDeFormes visu)
		{
			m_visu = visu;
		}
		
		public void actionPerformed( ActionEvent e )
		{
			Random r = m_visu.getRandom();
			
			Rectangle rect = new Rectangle (
					r.nextInt( 300 ) + 1, // de 1 � 300
					r.nextInt( 300 ) + 1, // si r.nextInt( 300 ) --> 0 � 299
					r.nextInt( 100 ) + 1,
					r.nextInt( 100 ) + 1
					);
			m_visu.getFormes().add( rect );
			m_visu.repaint();
		}
	}
	
	class BoutonReset implements ActionListener
	{
		private VisualiseurDeFormes m_visu;
		
		BoutonReset(VisualiseurDeFormes visu)
		{
			m_visu = visu;
		}
		
		/* (non-Javadoc)
		 * @see java.awt.event.ActionListener#actionPerformed(java.awt.event.ActionEvent)
		 */
		public void actionPerformed( ActionEvent e )
		{
			m_visu.getFormes().clear();
			m_visu.repaint();
		}
	}
	
	/**
	 * Constructeur par d�faut. 
	 * Cr�e une fen�tre avec un nom, une zone de dessin 
	 * et une zone pour placer des boutons.
	 */
	/**
	 * @param title
	 */
	public VisualiseurDeFormes(String title)
	{
		super( title );
		m_formes = new Vector();
		m_random = new Random();
		
		setPreferredSize( new Dimension( 400, 400 ) ); 
		setLayout( new BorderLayout() );
		
		m_panneau_dessin = new ZoneDeDessin();
		m_panneau_dessin.setFormes( m_formes );
		m_panneau_boutons = new JPanel();
		JLabel label = new JLabel("Visualiseur de Formes");
		getContentPane().add( label, BorderLayout.NORTH );
		getContentPane().add( m_panneau_boutons, BorderLayout.SOUTH );
		getContentPane().add( m_panneau_dessin, BorderLayout.CENTER );
		
		BoutonCercleAction action_cercle = new BoutonCercleAction( this );
		JButton b1 = new JButton( "Cercle" );
		b1.addActionListener( action_cercle );
		m_panneau_boutons.add( b1 );
		
		BoutonRectangleAction action_rect = new BoutonRectangleAction( this );
		JButton b2 = new JButton( "Rectangle" );
		b2.addActionListener( action_rect );
		m_panneau_boutons.add( b2 );
		
		BoutonReset action_reset = new BoutonReset( this );
		JButton b3 = new JButton( "Reset" );
		b3.addActionListener( action_reset );
		m_panneau_boutons.add( b3 );
				
		// Indique ce qu'il faut faire si on clic sur "fermer la fenetre".
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
	/**
	 * Cr�e une application "Visualiseur de Formes".
	 * 
	 * @param args
	 */
	public static void main(String[] args) {
		VisualiseurDeFormes visu = new VisualiseurDeFormes("prems");
		//VisualiseurDeFormes visu_sec = new VisualiseurDeFormes("deuze");
		//Display the window.
		visu.pack();
		visu.setVisible(true);	
		//visu_sec.pack();
		//visu_sec.setVisible(true);
	}
	
	/**
	 * @return le vecteur des formes
	 */
	public Vector getFormes() {
		return m_formes;
	}

	/**
	 * @return l'objet permettant de g�n�rer des nombres al�artoires.
	 */
	public Random getRandom() {
		return m_random;
	}

}
