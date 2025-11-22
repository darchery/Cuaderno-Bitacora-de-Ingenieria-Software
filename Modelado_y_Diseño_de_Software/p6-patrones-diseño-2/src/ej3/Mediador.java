package ej3;

// El mediador escogerá entre estrategias
abstract class  Mediador {
	private Estrategia estrategia;

	// Conectará las diferentes estrategias con los dispositivos con estados asociados
	abstract void abrir(Estado estado, Dispositivo dispositivo);
	abstract void cerrar(Estado estado, Dispositivo dispositivo);
	abstract void cambio(Estado estado, Dispositivo dispositivo);
	
	Estrategia getEstrategia() {
		return this.estrategia;
	}
	
	void setEstrategia(Estrategia estrategia) {
		assert(estrategia != null);
		this.estrategia = estrategia;
	}
	
}
