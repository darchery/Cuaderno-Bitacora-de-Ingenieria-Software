package ej1;

class Rojo extends Estado{
	private static Rojo rojo;
	
	private Rojo() {
		// Constructor privado
	}

	// Patrón Singleton
	static Rojo rojo() {
		if(rojo == null)
			rojo = new Rojo();
		return rojo;
	}

	// Es la misma clase Rojo la que gestiona sus cambios de estado
	@Override
	void abrir(Biestable biestable) {
		assert(biestable != null);
		biestable.cambiarEstado(Verde.verde());
	}

	@Override
	void cerrar(Biestable biestable) {
		assert(biestable != null);
		throw new RuntimeException("No se puede hacer cerrar en estado ej1.Rojo");
	}

	@Override
	String estado(Biestable biestable) {
		assert(biestable != null);
		return "cerrado";
	}
}
