package ej2;

class EstrategiaTriestable extends Estrategia{
	private static EstrategiaTriestable ejemplar;
	
	private EstrategiaTriestable() {
		//
	}
	// Patrón Singleton
	static EstrategiaTriestable estrategiaTriestable() {
		if(ejemplar == null)
			ejemplar = new EstrategiaTriestable();
		return ejemplar;
	}

	// Usa una estrategia diferente que el biestable => paso intermedio entre verde y rojo
	@Override
	void abrir(Estado estado, Dispositivo dispositivo) {
		// Si está en rojo => lo pone en amarillo
		if(estado instanceof Rojo)
			dispositivo.cambiarEstado(Amarillo.amarillo());
		else
			// Si no está en rojo => en verde
			dispositivo.cambiarEstado(Verde.verde());
	}
	@Override
	void cerrar(Estado estado, Dispositivo dispositivo) {
		// Si está en verde => amarillo
		if(estado instanceof Verde)
			dispositivo.cambiarEstado(Amarillo.amarillo());
		else
			// Si no está en verde => rojo
			dispositivo.cambiarEstado(Rojo.rojo());
	}

}
