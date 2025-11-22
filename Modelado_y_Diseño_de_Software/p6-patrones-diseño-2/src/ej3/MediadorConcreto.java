package ej3;

class MediadorConcreto extends Mediador{
	
	MediadorConcreto(Estrategia estrategia){
		assert(estrategia != null);
		this.setEstrategia(estrategia);
	}

	// Comunica a la estrategia elegida con el dispositivo elegido en el estado actual
	@Override
	void abrir(Estado estado, Dispositivo dispositivo) {
		this.getEstrategia().abrir(estado, dispositivo);
	}

	@Override
	void cerrar(Estado estado, Dispositivo dispositivo) {
		this.getEstrategia().cerrar(estado, dispositivo);
	}

	@Override
	void cambio(Estado estado, Dispositivo dispositivo) {
		this.getEstrategia().cambio(estado, dispositivo);
	}
}
