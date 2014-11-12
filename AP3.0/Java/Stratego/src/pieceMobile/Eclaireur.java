package pieceMobile;


public class Eclaireur extends PieceSpeciale {

	public Eclaireur(boolean p, int x, int y) {
		super(p, x, y);
		m_pointForce = 2;
	}

	public String getNom()
	{
		return " E ";
	}
}
