package ej3;

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

	// Ahora la estrategia(ej2) no se ocupan de la operación abrir y cerrar, lo hace el mediador
	@Override
	void abrir(Estado estado, Dispositivo dispositivo) {
		dispositivo.cambiarEstado(Verde.verde());
	}

	@Override
	void cerrar(Estado estado, Dispositivo dispositivo) {
		dispositivo.cambiarEstado(Rojo.rojo());
	}

	@Override
	void cambio(Estado estado, Dispositivo dispositivo) {
		dispositivo.getMediador().setEstrategia(EstrategiaTriestable.estrategiaTriestable());
	}
	
}
