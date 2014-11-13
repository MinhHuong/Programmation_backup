package pieceImmobile;

public class Drapeau extends PieceImmobile {

	public Drapeau(boolean p, int x, int y) {
		super(p, x, y);
	}

	public String getNom()
	{
		if( m_part )	return " bD ";
		else			return " rD ";
	}
}
