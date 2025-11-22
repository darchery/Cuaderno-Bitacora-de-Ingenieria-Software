package ej3;

abstract class Dispositivo {
	private Estado estado;
	// Ahora dispositivo no tiene estrategia => tiene un mediador que ofrece las estrategias
	private Mediador mediador;
	
	Estado getEstado() {
		return estado;
	}
	
	void cambiarEstado(Estado estado) {
		assert(estado != null);
		this.estado = estado;
	}
	
	Mediador getMediador() {
		return this.mediador;
	}
	
	void setMediador(Mediador mediador) {
		assert(mediador != null);
		this.mediador = mediador;
	}
	
	public void abrir() {
		this.getEstado().abrir(this);
	}
	
	public void cerrar() {
		this.getEstado().cerrar(this);
	}
	
	public String estado() {
		return this.getEstado().estado(this);
	}
	
	public void cambio() {
		this.getMediador().cambio(this.getEstado(), this);
	}
	
	
}
