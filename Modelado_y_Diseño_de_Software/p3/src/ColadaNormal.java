import java.util.Collection;

public class ColadaNormal extends Colada {

	private LavadoraNormal lavadora;
	private int cantSuavizante;

	public ColadaNormal(int temp, int rpm, int cantDetergente, EstadoPrenda estadoPrenda, Prenda prenda,
						int cantSuavizante,  LavadoraNormal lavadora) {
		super(temp, rpm, cantDetergente, estadoPrenda, prenda);
		this.lavadora = lavadora;
		this.cantSuavizante = cantSuavizante;

		//Para mantener la consistencia, añado esta colada a la Lavadora:
		lavadora.addColada(this);
	}


	public LavadoraNormal getLavadora() {
		return lavadora;
	}

	public int getCantSuavizante() {
		return cantSuavizante;
	}
	protected void setCantSuavizante(int cantSuavizante) {
		this.cantSuavizante = cantSuavizante;
	}
}