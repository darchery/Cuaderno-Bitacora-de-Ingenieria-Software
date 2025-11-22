package ej2;

class Amarillo extends Estado{
	private static Amarillo amarillo;
	
	private Amarillo() {
		// Constructor privado
	}
	// Patron Singleton
	static Amarillo amarillo() {
		if(amarillo == null)
			amarillo = new Amarillo();
		return amarillo;
	}

	// Ahora la estrategia(ej2) se ocupa de abrir y cerrar en los estados rojo, amarillo y verde
	@Override
	void abrir(Dispositivo dispositivo) {
		assert(dispositivo != null);
		// Se observa la estrategia usada por el dispositivo y se usa el método abrir para esa estrategia
		dispositivo.getEstrategia().abrir(this, dispositivo);
	}
	@Override
	void cerrar(Dispositivo dispositivo) {
		assert(dispositivo != null);
		// Se observa la estrategia usada por el dispositivo y se usa el método cerrar para esa estrategia
		dispositivo.getEstrategia().cerrar(this, dispositivo);
	}

	@Override
	String estado(Dispositivo dispositivo) {
		assert(dispositivo != null);
		return "precaución";
	}
}
