package ej3;

class Verde extends Estado{
	private static Verde verde;
	
	private Verde() {
		// Constructor privado
	}
	
	static Verde verde() {
		if(verde == null)
			verde = new Verde();
		return verde;
	}

	// Ahora el mediador(ej3) se ocupa de gestionar las estrategias(ej2) para abrir y cerrar los estados(rojo, amarillo y verde)
	@Override
	void abrir(Dispositivo dispositivo) {
		assert(dispositivo != null);
		throw new RuntimeException("No se puede ejecutar abrir en un estado Verde");
	}

	@Override
	void cerrar(Dispositivo dispositivo) {
		assert(dispositivo != null);
		dispositivo.getMediador().cerrar(this, dispositivo);
	}

	@Override
	String estado(Dispositivo dispositivo) {
		assert(dispositivo != null);
		return "abierto";
	}

}
