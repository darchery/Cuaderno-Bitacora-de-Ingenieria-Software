import java.util.*;

import static java.util.Collections.enumeration;

public class LavadoraSecadora extends Lavadora {

	private List<ColadaSecado> coladas;
	private int maxTempSecado;

	public LavadoraSecadora(String marca, int capDetergente, int maxTempLavado, int maxCentrifugado, int maxPeso, int maxTempSecado) {
		super(marca, capDetergente, maxTempLavado, maxCentrifugado, maxPeso);
		this.coladas = new ArrayList<ColadaSecado>();
		this.maxTempSecado = maxTempSecado;
	}

	public Enumeration<ColadaSecado> getColadas() {
		return enumeration(coladas);
	}
	protected void addColada(ColadaSecado coladaSecado) {
		coladas.add(coladaSecado);
	}
	protected void removeColada(ColadaSecado coladaSecado) {
		coladas.remove(coladaSecado);
	}

	public int getMaxTempSecado() {
		return maxTempSecado;
	}
	protected void setMaxTempSecado(int maxTempSecado) {
		this.maxTempSecado = maxTempSecado;
	}

	/** Ejercicio 2:
	 * Vamos a considerar que la clase Lavadora tiene el atributo derivado
	 * enFuncionamiento(), como se explicó en la Práctica 2. Por tanto, dicho atributo derivado
	 * también debe ser convertido al métod0 correspondiente.*/
	@Override
	public boolean enFuncionamiento() {
		ColadaSecado ultimaColada = coladas.getLast();
		return ((ultimaColada.getInicioC() != -1 || ultimaColada.getInicioL() != -1) && ultimaColada.getInicioS() !=-1 && ultimaColada.getFin() == -1);
	}
	/* Implementación profe:
	  	public boolean enFuncionamiento(){
	  		ColadaSecado ultimaColada = coladas.get(coladas.size()-1);
	       	return ultimaColada.getFin()==-1;
	  	}
	 */
}