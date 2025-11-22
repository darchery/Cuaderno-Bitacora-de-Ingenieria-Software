package ej2;

public class Biestable extends Dispositivo{
	
	public Biestable() {
		// En los dispositivos biestables se empieza en el estado Rojo y con la estrategia de los biestables
		this.cambiarEstado(Rojo.rojo());
		this.setEstrategia(EstrategiaBiestable.estrategiaBiestable());
	}
	
}
