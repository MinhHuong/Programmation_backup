package pieceMobile;


public class Marechal extends PieceNormale {

	public Marechal(boolean p, int x, int y) {
		super(p, x, y);
		m_pointForce = 10;
	}
	
	public String getNom()
	{
		if( m_part )	return " bM ";
		else			return " rM ";
	}
}
