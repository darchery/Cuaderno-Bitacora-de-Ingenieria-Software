package Lab61.soluciones

import java.util.concurrent.Semaphore
import scala.util.Random

class Coche_mi_version_REPASO(C: Int) extends Thread {
  // CS-pasajero1: si el coche está lleno, un pasajero no puede subir al coche hasta que haya terminado
  // el viaje y se hayan bajado los pasajeros de la vuelta actual
  // CS-pasajero2: un pasajero que está en el coche no puede bajarse hasta que haya terminado el viaje
  // CS-coche: el coche espera a que se hayan subido C pasajeros para dar una vuelta
  private var numPas = 0

  private val mutex = new Semaphore(1)
  private val puertaEntrada = new Semaphore(1) // CS-pas1
  private val puertaSalida = new Semaphore(0) // CS-pas2
  private val cocheLleno = new Semaphore(0) // CS-coche

  def nuevoPaseo(id: Int) = {
    // el pasajero id quiere dar un paseo en la montaña rusa
    // Subida
    puertaEntrada.acquire()
    mutex.acquire()
    numPas += 1
    if (numPas < C) puertaEntrada.release()
    else cocheLleno.release()
    log(s"El pasajero $id se sube al coche. Hay $numPas pasajeros.")
    mutex.release()

    // Bajada
    puertaSalida.acquire()
    mutex.acquire()
    numPas -= 1
    if (numPas > 0) puertaSalida.release()
    else puertaEntrada.release()
    log(s"El pasajero $id se baja del coche. Hay $numPas pasajeros.")
    mutex.release()
  }

  def esperaLleno = {
    // el coche espera a que se llene para dar un paseo
    cocheLleno.acquire()
    log(s"        Coche lleno!!! empieza el viaje....")
  }

  def finViaje = {
    // el coche indica que se ha terminado el viaje
    log(s"        Fin del viaje... :-(")
    puertaSalida.release()
  }

  override def run = {
    while (true) {
      esperaLleno
      Thread.sleep(Random.nextInt(Random.nextInt(500))) // el coche da una vuelta
      finViaje
    }
  }
}

object Ejercicio4_mi_version {
  def main(args: Array[String]) = {
    val coche = new Coche_mi_version_REPASO(5)
    val pasajero = new Array[Thread](12)
    coche.start()

    for (i <- 0 until pasajero.length)
      pasajero(i) = thread {
        while (true) {
          Thread.sleep(Random.nextInt(500)) // el pasajero se da una vuelta por el parque
          coche.nuevoPaseo(i)
        }
      }
  }
}


class Coche_mi_version(C: Int) extends Thread {
  // CS-pasajero1: si el coche está lleno, un pasajero no puede subir al coche hasta que haya terminado
  // el viaje y se hayan bajado los pasajeros de la vuelta actual
  // CS-pasajero2: un pasajero que está en el coche no puede bajarse hasta que haya terminado el viaje
  // CS-coche: el coche espera a que se hayan subido C pasajeros para dar una vuelta
  private var numPas = 0
  private val mutex = new Semaphore(1)
  private val puertaEntrada = new Semaphore(1) // CS-pas1 => Abierta
  private val puertaSalida = new Semaphore(0) // CS-pas2 => Cerrada
  private val llenoCoche = new Semaphore(0)  // CS-coche => Vacío


  def nuevoPaseo(id: Int) = {
    // el pasajero id quiere dar un paseo en la montaña rusa
    puertaEntrada.acquire() // Cerramos la entrada a más pasajeros
    mutex.acquire()
    numPas += 1
    if (numPas < C) puertaEntrada.release() // Si queda hueco => Abrimos puerta
    else llenoCoche.release() // Si no queda => Coche lleno
    log(s"El pasajero $id se sube al coche. Hay $numPas pasajeros.")
    mutex.release()

    puertaSalida.acquire() // Cerramos la puerta de salida a más pasajeros
    mutex.acquire()
    numPas -= 1
    if (numPas > 0) puertaSalida.release() // Si aun quedan => Abrimos
    else puertaEntrada.release() // Si no quedan pasajeros => Se abre la puerta
    log(s"El pasajero $id se baja del coche. Hay $numPas pasajeros.")
    mutex.release()
  }

  def esperaLleno = {
    // el coche espera a que se llene para dar un paseo
    llenoCoche.acquire() // Coche vacío => espera a estar llenos
    log(s"        Coche lleno!!! empieza el viaje....")
  }

  def finViaje = {
    // el coche indica que se ha terminado el viaje
    log(s"        Fin del viaje... :-(")
    puertaSalida.release() // Se abre la puerta para que salga
  }

  override def run = {
    while (true) {
      esperaLleno
      Thread.sleep(Random.nextInt(Random.nextInt(500))) // el coche da una vuelta
      finViaje
    }
  }
}

