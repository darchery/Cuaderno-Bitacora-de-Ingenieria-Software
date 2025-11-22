package ej2;

class EstrategiaBiestable extends Estrategia{
	private static EstrategiaBiestable ejemplar;
	
	private EstrategiaBiestable() {
		//
	}
	// Patrón Singleton
	static EstrategiaBiestable estrategiaBiestable() {
		if(ejemplar == null)
			ejemplar = new EstrategiaBiestable();
		return ejemplar;
	}
	
	@Override
	void abrir(Estado estado, Dispositivo dispositivo) {
		// Se accede al método cambiar estado de dispositivo
		dispositivo.cambiarEstado(Verde.verde());
	}

	@Override
	void cerrar(Estado estado, Dispositivo dispositivo) {
		// Se accede al método cambiar estado de dispositivo
		dispositivo.cambiarEstado(Rojo.rojo());
	}

}
