import java.util.*;

import static java.util.Collections.enumeration;

public class Prenda {

	private List<Estado> estados;
	private TipoPrenda tipo;
	private int peso;

	public Prenda(TipoPrenda tipo, int peso) {
		this.tipo = tipo;
		this.peso = peso;
		estados = new ArrayList<>();
	}

	public Enumeration<Estado> getEstados() {
		return enumeration(estados);
	}
	protected void addEstado(Estado e) {
		estados.add(e);
	}
	protected void removeEstado(Estado e) {
		estados.remove(e);
	}

	public TipoPrenda getTipo() {
		return tipo;
	}
	protected void setTipo(TipoPrenda tipo) {
		this.tipo = tipo;
	}

	public int getPeso() {
		return peso;
	}
	protected void setPeso(int peso) {
		this.peso = peso;
	}
}