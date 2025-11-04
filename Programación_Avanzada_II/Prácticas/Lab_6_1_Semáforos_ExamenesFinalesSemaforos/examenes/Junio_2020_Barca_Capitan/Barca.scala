package examenes.Junio_2020_Barca_Capitan

import Lab61.soluciones.log

import java.util.concurrent.Semaphore
import scala.collection.mutable.ListBuffer

class Barca {
  private val MAXIMO_N_PASAJEROS = 3

  private var numPasajeros = 0
  private var orillaActual = 1

  private val mutex = new Semaphore(1)

  private val hayEspacioBarca = new Semaphore(1) // Control pasajeros subida
  private val barcaLlena = new Semaphore(0) // Control salida del barco
  private val salirBarca = new Semaphore(0) // Control pasajeros bajada

  private val orillaAbierta = new Array[Semaphore](2)
  orillaAbierta(0) = new Semaphore(0) // Orilla sur => Control apertura orilla sur
  orillaAbierta(1) = new Semaphore(1) // Orilla norte -> En inicio abierta => Control apertura orilla norte
  // Con estos semáforos controlamos el paso de nuevos pasajeros, dejandoles pasar si son los que se han subido
  // y si no está bloqueada para ellos

  /*
   * El Pasajero id quiere darse una vuelta en la barca desde la orilla pos
   */
  @throws[InterruptedException]
  def subir(id: Int, pos: Int): Unit = {
    // TODO

    orillaAbierta(pos).acquire() // Cerramos por ahora la orilla y el espacio en la barca
    hayEspacioBarca.acquire() // Si hay espacio en la barca
    mutex.acquire()

    numPasajeros += 1

    log(s"Viajero ${id} se sube al barco en la orilla ${pos}")

    if (numPasajeros < MAXIMO_N_PASAJEROS)  { // Si hay más espacio abrimos
      orillaAbierta(pos).release()
      hayEspacioBarca.release()
    } else {
        barcaLlena.release() // Barca llena => salimos
    }
    mutex.release()

  }

  /*
   * Cuando el viaje ha terminado, el Pasajero que está en la barca se baja
   */
  @throws[InterruptedException]
  def bajar(id: Int): Int = {
    // TODO

    salirBarca.acquire()
    mutex.acquire()

    orillaActual = (orillaActual + 1) % 2

    numPasajeros -= 1
    log(s"Viajero ${id} se baja al barco")

    if (numPasajeros > 0) {
      salirBarca.release()
    } else {
      log(s"Barca vacía...pueden subir nuevos pasajeros")
      orillaAbierta(orillaActual).release() // Nueva orilla abierta
      hayEspacioBarca.release() // Hay espacio de nuevo
    }

    mutex.release()

    orillaActual
  }

  /*
   * El Capitán espera hasta que se suben 3 pasajeros para comenzar el viaje
   */
  @throws[InterruptedException]
  def esperoSuban(): Unit = {
    // TODO
    barcaLlena.acquire()
    log(s"Empieza el viaje!!!!")
  }

  /*
   * El Capitán indica a los pasajeros que el viaje ha terminado y tienen que bajarse
   */
  @throws[InterruptedException]
  def finViaje(): Unit = {
    // TODO
    log(s"Fin del viaje!!!!")
    salirBarca.release()
  }

}
