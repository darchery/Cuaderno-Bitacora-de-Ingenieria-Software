package ej3;

class Amarillo extends Estado{
	private static Amarillo amarillo;
	
	private Amarillo() {
		// Constructor privado
	}
	// Patrón Amarillo
	static Amarillo amarillo() {
		if(amarillo == null)
			amarillo = new Amarillo();
		return amarillo;
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
		dispositivo.getMediador().cerrar(this, dispositivo);
	}

	@Override
	String estado(Dispositivo dispositivo) {
		assert(dispositivo != null);
		return "precaución";
	}
}
