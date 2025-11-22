package ej3;

abstract class Estrategia {
	abstract void abrir(Estado estado, Dispositivo dispositivo);
	abstract void cerrar(Estado estado, Dispositivo dispositivo);
	abstract void cambio(Estado estado, Dispositivo dispositivo);
}
