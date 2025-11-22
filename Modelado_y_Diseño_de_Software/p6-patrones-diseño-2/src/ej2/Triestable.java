package ej2;

public class Triestable extends Dispositivo{
	
	public Triestable() {
		// En los dispositivos biestables se empieza en el estado Rojo y con la estrategia de los triestables
		this.cambiarEstado(Rojo.rojo());
		this.setEstrategia(EstrategiaTriestable.estrategiaTriestable());
	}
}
