package pieceMobile;

public class Espion extends PieceNormale {

	public Espion(boolean p, int x, int y) {
		super(p, x, y);
		m_pointForce = 1;
	}
	
	public String getNom()
	{
		return " e ";
	}
}
