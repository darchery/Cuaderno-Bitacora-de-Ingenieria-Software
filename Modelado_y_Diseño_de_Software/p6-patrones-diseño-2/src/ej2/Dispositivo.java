package ej2;

abstract class Dispositivo {
	private Estado estado;
	private Estrategia estrategia;
	
	Estado getEstado() {
		return estado;
	}
	
	void cambiarEstado(Estado estado) {
		assert(estado != null);
		this.estado = estado;
	}
	
	Estrategia getEstrategia() {
		return this.estrategia;
	}
	
	void setEstrategia(Estrategia estrategia) {
		assert(estrategia != null);
		this.estrategia = estrategia;
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
	
	
}
