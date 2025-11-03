public abstract class Lavadora {

	private String marca;
	private int capDetergente;
	private int maxTempLavado;
	private int maxCentrifugado;
	private int maxPeso;

	public Lavadora(String marca, int capDetergente, int maxTempLavado, int maxCentrifugado, int maxPeso) {
		this.marca = marca;
		this.capDetergente = capDetergente;
		this.maxTempLavado = maxTempLavado;
		this.maxCentrifugado = maxCentrifugado;
		this.maxPeso = maxPeso;
	}

	public String getMarca() {
		return this.marca;
	}
	protected void setMarca(String marca) {
		this.marca = marca;
	}

	public int getCapDetergente() {
		return capDetergente;
	}
	protected void setCapDetergente(int capDetergente) {
		this.capDetergente = capDetergente;
	}

	protected int getMaxTempLavado() {
		return maxTempLavado;
	}
	protected void setMaxTempLavado(int maxTempLavado) {
		this.maxTempLavado = maxTempLavado;
	}

	public int getMaxCentrifugado() {
		return maxCentrifugado;
	}
	protected void setMaxCentrifugado(int maxCentrifugado) {
		this.maxCentrifugado = maxCentrifugado;
	}

	public int getMaxPeso() {
		return maxPeso;
	}
	protected void setMaxPeso(int maxPeso) {
		this.maxPeso = maxPeso;
	}

	/** Ejercicio 2:
	 * Vamos a considerar que la clase Lavadora tiene el atributo derivado
	 * enFuncionamiento(), como se explicó en la Práctica 2. Por tanto, dicho atributo derivado
	 * también debe ser convertido al métod0 correspondiente.*/
	//Los atributos derivados los convertimos en métodos
	public abstract boolean enFuncionamiento();
}