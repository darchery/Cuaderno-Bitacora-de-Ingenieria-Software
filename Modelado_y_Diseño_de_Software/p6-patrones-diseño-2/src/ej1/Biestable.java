package ej1;

public class Biestable {
	private Estado estado;
	
	public Biestable() {
		this.estado = Rojo.rojo();
	}
	
	Estado getEstado() {
		return estado;
	}
	
	void cambiarEstado(Estado estado) {
		assert(estado != null);
		this.estado = estado;
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
