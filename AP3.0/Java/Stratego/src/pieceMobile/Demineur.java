package pieceMobile;

public class Demineur extends PieceNormale {

	public Demineur(boolean p, int x, int y) {
		super(p, x, y);
		m_pointForce = 3;
	}
	
	public String getNom()
	{
		if( m_part ) 	return " bd ";
		else			return " rd ";
	}
}
