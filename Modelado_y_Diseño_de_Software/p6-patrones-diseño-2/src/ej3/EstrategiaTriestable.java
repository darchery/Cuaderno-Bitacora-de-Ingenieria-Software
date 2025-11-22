package ej3;

class EstrategiaTriestable extends Estrategia {
	private static EstrategiaTriestable ejemplar;

	private EstrategiaTriestable() {
		//
	}
	// Patrón Singleton
	static EstrategiaTriestable estrategiaTriestable() {
		if (ejemplar == null)
			ejemplar = new EstrategiaTriestable();
		return ejemplar;
	}

	// Ahora los estados rojo, verde y amarillo no se ocupan de la operación abrir y cerrar, lo hace el mediador
	// Esta implementa la acción que antes estrategia para amarillo, rojo y verde en el ej2
	@Override
	void abrir(Estado estado, Dispositivo dispositivo) {
		if (estado instanceof Rojo)
			dispositivo.cambiarEstado(Amarillo.amarillo());
		else
			dispositivo.cambiarEstado(Verde.verde());
	}

	@Override
	void cerrar(Estado estado, Dispositivo dispositivo) {
		if (estado instanceof Verde)
			dispositivo.cambiarEstado(Amarillo.amarillo());
		else
			dispositivo.cambiarEstado(Rojo.rojo());
	}

	@Override
	void cambio(Estado estado, Dispositivo dispositivo) {
		dispositivo.getMediador().setEstrategia(EstrategiaBiestable.estrategiaBiestable());
	}

}
