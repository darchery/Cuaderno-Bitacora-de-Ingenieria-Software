package ej3;

class Rojo extends Estado{
	private static Rojo rojo;
	
	private Rojo() {
		// Constructor privado
	}
	
	static Rojo rojo() {
		if(rojo == null)
			rojo = new Rojo();
		return rojo;
	}

	// Ahora el mediador(ej3) se ocupa de gestionar las estrategias(ej2) para abrir y cerrar los estados(rojo, amarillo y verde)
	@Override
	void abrir(Dispositivo dispositivo) {
		assert(dispositivo != null);
		dispositivo.getMediador().abrir(this, dispositivo);
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
