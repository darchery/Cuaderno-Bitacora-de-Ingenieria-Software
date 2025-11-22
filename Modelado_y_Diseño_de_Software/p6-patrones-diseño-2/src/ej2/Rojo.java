package ej2;

class Rojo extends Estado{

	private static Rojo rojo;
	
	private Rojo() {
		// Constructor privado
	}
	// Patron Singleton
	static Rojo rojo() {
		if(rojo == null)
			rojo = new Rojo();
		return rojo;
	}
	// Ahora la estrategia(ej2) se ocupa de abrir y cerrar en los estados rojo, amarillo y verde
	@Override
	void abrir(Dispositivo dispositivo) {
		assert(dispositivo != null);
		dispositivo.getEstrategia().abrir(this, dispositivo);
	}

	@Override
	void cerrar(Dispositivo dispositivo) {
		assert(dispositivo != null);
		throw new RuntimeException("No se puede hacer cerrar en estado Rojo");
	}

	@Override
	String estado(Dispositivo dispositivo) {
		assert(dispositivo != null);
		return "cerrado";
	}

	
}
