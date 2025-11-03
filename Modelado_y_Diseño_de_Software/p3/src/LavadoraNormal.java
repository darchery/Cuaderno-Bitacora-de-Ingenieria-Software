import java.util.*;

import static java.util.Collections.enumeration;

public class LavadoraNormal extends Lavadora {

	private List<ColadaNormal> coladas;
	private Integer capSuavizante;

	public LavadoraNormal(String marca, int capDetergente, int maxTempLavado, int maxCentrifugado, int maxPeso, int capSuavizante) {
		super(marca, capDetergente, maxTempLavado, maxCentrifugado, maxPeso);
		this.coladas = new ArrayList<ColadaNormal>();
		this.capSuavizante = capSuavizante;
	}

	public Enumeration<ColadaNormal> getColada() {
		return enumeration(coladas);
	}
	protected void addColada(ColadaNormal coladaNormal) {
		coladas.add(coladaNormal);
	}
	protected void removeColada(ColadaNormal coladaNormal) {
		coladas.remove(coladaNormal);
	}

	public int getCapSuavizante() {
		return capSuavizante;
	}
	protected void setCapSuavizante(int capSuavizante) {
		this.capSuavizante = capSuavizante;
	}

	/** Ejercicio 2:
	 * Vamos a considerar que la clase Lavadora tiene el atributo derivado
	 * enFuncionamiento(), como se explicó en la Práctica 2. Por tanto, dicho atributo derivado
	 * también debe ser convertido al métod0 correspondiente.*/
	@Override
	public boolean enFuncionamiento() {
		// Si la última colada no ha terminado(Centrifugado o Lavado o ambos hecho (!=-1) e inicio no definido(==-1))
		ColadaNormal ultimaColada = coladas.getLast();
		return ((ultimaColada.getInicioL() != -1 || ultimaColada.getInicioC() != -1) && ultimaColada.getFin() == -1);
	}
}