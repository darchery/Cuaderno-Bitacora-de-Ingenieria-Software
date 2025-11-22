package ej1;

abstract class Estado {
	abstract void abrir(Biestable biestable);
	abstract void cerrar(Biestable biestable);
	abstract String estado(Biestable biestable);
}
