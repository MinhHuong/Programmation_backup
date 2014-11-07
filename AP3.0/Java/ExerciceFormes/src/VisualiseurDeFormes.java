import java.util.*;
import java.awt.*;
import java.awt.event.*;

import javax.swing.*;
//import javax.swing.event.MouseInputAdapter;

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
@SuppressWarnings("serial")
public class VisualiseurDeFormes extends JFrame 
{
	/**
	 * R�f�rence l'objet servant � g�n�rer des nombres al�atoires.
	 */
	private Random m_random;
	static int num = 0;
	
	/**
	 * R�f�rence la liste des formes � dessiner.
	 */
	private Vector<FormeColoree> m_formes;
	
	/**
	 * R�f�rence l'objet o� les formes se dessinent.
	 */
	private ZoneDeDessin m_panneau_dessin;
	
	/**
	 * R�f�rence l'objet o� sont plac�s les boutons.
	 */
	private JPanel m_panneau_boutons;
	
	private Color m_couleur = Color.black;
	
	public Color getCouleur()
	{
		return m_couleur;
	}
	
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
		
		/**
		 * Constructeur.
		 * @param visu est l'application reli� � ce bouton.
		 */
		BoutonCercleAction()
		{}
		 
		/**
		 * Cr�e un nouveau cercle de coordonn�es et rayon al�atoire.
		 * suite � l'action [e].
		 * 
		 * @param e l'action qui a d�clench�e l'appel � cette m�thode.
		 */
		public void actionPerformed( ActionEvent e)
		{
			Random r = getRandom();
			Cercle c = new Cercle(
				r.nextInt( 200 ),
				r.nextInt( 200 ),
			    r.nextInt( 40 )+ 20,
			    m_couleur );
			getFormes().add( c );
			repaint();
		}
	}
	
	class BoutonRectangleAction implements ActionListener
	{
		BoutonRectangleAction()
		{}
		
		public void actionPerformed( ActionEvent e )
		{
			Random r =getRandom();
			
			Rectangle rect = new Rectangle (
					r.nextInt( 300 ) + 1, // de 1 � 300
					r.nextInt( 300 ) + 1, // si r.nextInt( 300 ) --> 0 � 299
					r.nextInt( 100 ) + 1,
					r.nextInt( 100 ) + 1,
					m_couleur
					);
			getFormes().add( rect );
			repaint();
		}
	}
	
	class BoutonReset implements ActionListener
	{		
		BoutonReset()
		{}
		
		/* (non-Javadoc)
		 * @see java.awt.event.ActionListener#actionPerformed(java.awt.event.ActionEvent)
		 */
		public void actionPerformed( ActionEvent e )
		{
			getFormes().clear();
			repaint();
		}
	}
	
	class BoutonAleatoire implements ActionListener
	{
		private BoutonCercleAction b_cercle;
		private BoutonRectangleAction b_rect;
		
		BoutonAleatoire()
		{}
		
		public void actionPerformed( ActionEvent e )
		{
			Random r = getRandom();
			int number = r.nextInt(2); // 0 -> 1
			
			if( number == 0 ) // Cercle
			{
				b_cercle = new BoutonCercleAction();
				b_cercle.actionPerformed(e);
			}
			else // Rectangle
			{
				b_rect = new BoutonRectangleAction();
				b_rect.actionPerformed(e);
			}
		}
	}
	
	class BoutonChangeCouleur implements ActionListener
	{	
		BoutonChangeCouleur()
		{}
		
		public void actionPerformed( ActionEvent e )
		{
			if( !m_formes.isEmpty() )
			{
				m_couleur = JColorChooser.showDialog(VisualiseurDeFormes.this, "Choisir 1 couleur", m_couleur);
			}
		}
	}
	
	class BoutonRandomCouleur implements ActionListener
	{
		BoutonRandomCouleur(){}
		
		public void actionPerformed(ActionEvent a)
		{
			Vector<Color> m_couleur = new Vector<Color>();
			m_couleur.add(Color.black);
			m_couleur.add(Color.magenta);
			m_couleur.add(Color.green);
			m_couleur.add(Color.cyan);
			m_couleur.add(Color.yellow);
			m_couleur.add(Color.gray);
			m_couleur.add(Color.pink);
			m_couleur.add(Color.orange);
			
			Random r = getRandom();
			int _index = r.nextInt( m_couleur.size() );
			
			if( !m_formes.isEmpty() )	
				m_formes.lastElement().setColour( m_couleur.elementAt(_index) );
			
			repaint();
		}
	}
	
	public String testTitle( int n )
	{
		String info = "";
		
		switch( n )
		{
			case 1:
			{
				info = "premi�re";
				break;
			}
		
			case 2:
			{
				info = "deuxi�me";
				break;
			}
		}
		
		return info;
	}
	
	/**
	 * Constructeur par d�faut. 
	 * Cr�e une fen�tre avec un nom, une zone de dessin 
	 * et une zone pour placer des boutons.
	 */
	/**
	 * @param title
	 */
	public VisualiseurDeFormes()
	{
		super( "" );
		
		num++;
		String title = testTitle( num );
		setTitle( title );
		
		m_formes = new Vector<FormeColoree>();
		m_random = new Random();
		
		setPreferredSize( new Dimension( 700, 400 ) ); 
		setLayout( new BorderLayout() );
		
		m_panneau_dessin = new ZoneDeDessin(this);
		m_panneau_dessin.setFormes( m_formes );
		m_panneau_boutons = new JPanel();
		JLabel label = new JLabel("Visualiseur de Formes");
		//getContentPane() : r�f�rence � la partie contenu de JFrame VisualiseurDeFormes
		getContentPane().add( label, BorderLayout.NORTH );
		getContentPane().add( m_panneau_boutons, BorderLayout.SOUTH );
		getContentPane().add( m_panneau_dessin, BorderLayout.CENTER );
		
		BoutonCercleAction action_cercle = new BoutonCercleAction();
		JButton b1 = new JButton( "Cercle" );
		b1.addActionListener( action_cercle );
		m_panneau_boutons.add( b1 );
		
		BoutonRectangleAction action_rect = new BoutonRectangleAction();
		JButton b2 = new JButton( "Rectangle" );
		b2.addActionListener( action_rect );
		m_panneau_boutons.add( b2 );
		
		BoutonReset action_reset = new BoutonReset();
		JButton b3 = new JButton( "Reset" );
		b3.addActionListener( action_reset );
		m_panneau_boutons.add( b3 );
		
		BoutonAleatoire action_aleatoire = new BoutonAleatoire();
		JButton b4 = new JButton( "Al�atoire" );
		b4.addActionListener( action_aleatoire );
		m_panneau_boutons.add( b4 );
		
		BoutonChangeCouleur action_changeCouleur = new BoutonChangeCouleur();
		JButton b5 = new JButton( "Couleur (dialog)" );
		b5.addActionListener( action_changeCouleur );
		m_panneau_boutons.add( b5 );
		
		BoutonRandomCouleur action_randomCouleur = new BoutonRandomCouleur();
		JButton b6 = new JButton("Couleur (random)");
		b6.addActionListener(action_randomCouleur);
		m_panneau_boutons.add(b6);
				
		// Indique ce qu'il faut faire si on clic sur "fermer la fenetre".
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
	/**
	 * Cr�e une application "Visualiseur de Formes".
	 * 
	 * @param args
	 */
	public static void main(String[] args) {
		VisualiseurDeFormes visu = new VisualiseurDeFormes();
		
		//Display the window.
		visu.pack();
		visu.setVisible(true);	
	}
	
	/**
	 * @return le vecteur des formes
	 */
	public Vector<FormeColoree> getFormes() {
		return m_formes;
	}

	/**
	 * @return la derni�re forme ajout�e
	 */
	public FormeColoree getLastForme()
	{
		if ( !m_formes.isEmpty() )
			return m_formes.lastElement();
		else 
			return null;
	}

	/**
	 * @return l'objet permettant de g�n�rer des nombres al�artoires.
	 */
	public Random getRandom() {
		return m_random;
	}

}