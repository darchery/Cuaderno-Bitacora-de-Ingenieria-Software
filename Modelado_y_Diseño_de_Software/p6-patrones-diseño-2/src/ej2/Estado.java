package ej2;

abstract class Estado {
	abstract void abrir(Dispositivo dispositivo);
	abstract void cerrar(Dispositivo dispositivo);
	abstract String estado(Dispositivo dispositivo);
}
