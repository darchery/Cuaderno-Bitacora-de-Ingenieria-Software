package ej1;

class Verde extends Estado{
	private static Verde verde;
	
	private Verde() {
		// Constructor privado
	}

	// Patrón Singleton
	static Verde verde() {
		if(verde == null)
			verde = new Verde();
		return verde;
	}

	// Es la misma clase Verde la que gestiona sus cambios de estado
	@Override
	void abrir(Biestable biestable) {
		assert(biestable != null);
		throw new RuntimeException("No se puede ejecutar abrir en un estado ej1.Verde");
	}

	@Override
	void cerrar(Biestable biestable) {
		assert(biestable != null);
		biestable.cambiarEstado(Rojo.rojo());
	}

	@Override
	String estado(Biestable biestable) {
		assert(biestable != null);
		return "abierto";
	}

}
