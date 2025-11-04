package examenes.Junio2019_Tiovivo

import java.util.concurrent.Semaphore

class Tiovivo(capacidad: Int) {

  private var numPasajeros = 0

  private val mutex = new Semaphore(1)
  private val puertaEntrada = new Semaphore(1)
  private val empezarViaje = new Semaphore(0)
  private val puertaSalida = new Semaphore(0)

  def subir(id: Int): Unit = {

    puertaEntrada.acquire()

    mutex.acquire()

    numPasajeros += 1
    println(s"Pasajero ${id} se ha subido al tiovivo. Hay ${numPasajeros}")
    if (numPasajeros < capacidad) puertaEntrada.release()
    else empezarViaje.release()

    mutex.release()

  }

  def bajar(id: Int): Unit = {
    puertaSalida.acquire()

    mutex.acquire()
    numPasajeros -= 1
    println(s"Pasajero ${id} se ha bajado del tiovivo. Hay ${numPasajeros}")

    if (numPasajeros == 0) {
      println("*******************************************")
      println("TIOVIVO VACÍO");
      println("*******************************************")
      puertaEntrada.release();
    }
    else puertaSalida.release()
    mutex.release()
  }

  def esperaLleno(): Unit = {
    empezarViaje.acquire()
    println("         Viaje ha empezado, disfrutad!!!")
  }

  def finViaje(): Unit = {
    println("         Fin del viaje, pasad un buen día!!!")
    puertaSalida.release()
  }
}
