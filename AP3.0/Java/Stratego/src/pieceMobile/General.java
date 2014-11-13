package pieceMobile;

public class General extends PieceNormale {

	public General(boolean p, int x, int y) {
		super(p, x, y);
		m_pointForce = 9;
	}
	
	public String getNom()
	{
		if( m_part )	return " bG ";
		else			return " rG ";
	}
}
