package pieceImmobile;

public class Bombe extends PieceImmobile {

	public Bombe(boolean p, int x, int y) {
		super(p, x, y);
	}

	public String getNom()
	{
		if( m_part )	return " bB ";
		else			return " rB ";
	}
}
