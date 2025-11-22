package ej3;

public class Triestable extends Dispositivo{
	
	public Triestable() {
		this.cambiarEstado(Rojo.rojo());
		this.setMediador(new MediadorConcreto(EstrategiaTriestable.estrategiaTriestable()));
	}
}
