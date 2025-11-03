import java.util.Collection;

public class ColadaSecado extends Colada {

	private LavadoraSecadora lavadora;
	private int inicioS;
	private int tempSecado;

	//En las coladas de secado, no se conoce el inicio de secado cuando se crea
	public ColadaSecado(int temp, int rpm, int cantDetergente, EstadoPrenda estadoPrenda, Prenda prenda ,
						int tempSecado, LavadoraSecadora lavadora) {
		super(temp, rpm, cantDetergente,estadoPrenda, prenda);
		this.lavadora = lavadora;
		inicioS = -1;
		this.tempSecado = tempSecado;

		//Para mantener la consistencia, añado esta colada a la Lavadora:
		lavadora.addColada(this);
	}

	public LavadoraSecadora getLavadora() {
		return lavadora;
	}

	public int getInicioS() {
		return inicioS;
	}
	protected void setInicioS(int inicioS) {
		this.inicioS = inicioS;
	}

	public int getTempSecado() {
		return tempSecado;
	}
	protected void setTempSecado(int tempSecado) {
		this.tempSecado = tempSecado;
	}
}