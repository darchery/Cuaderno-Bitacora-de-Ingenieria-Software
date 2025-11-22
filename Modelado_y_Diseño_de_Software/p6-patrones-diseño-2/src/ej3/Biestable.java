package ej3;

public class Biestable extends Dispositivo{
	public Biestable() {
		this.cambiarEstado(Rojo.rojo());
		this.setMediador(new MediadorConcreto(EstrategiaBiestable.estrategiaBiestable()));
	}
	
}
