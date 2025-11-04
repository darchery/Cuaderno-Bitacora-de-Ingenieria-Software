package Lab61.soluciones

import java.util.concurrent.Semaphore
import scala.util.Random

object Ejercicio5_mi_version {

  def main(args:Array[String]) = {
    val N = 5
    val hidrogeno = new Array[Thread](2 * N)

    for (i <- 0 until hidrogeno.length)
      hidrogeno(i) = thread {
        Thread.sleep(Random.nextInt(500))
        gestorAgua_mi_version.hidrogeno(i)
      }

    val oxigeno = new Array[Thread](N)
    for (i <- 0 until oxigeno.length)
      oxigeno(i) = thread {
        Thread.sleep(Random.nextInt(500))
        gestorAgua_mi_version.oxigeno(i)
      }
    hidrogeno.foreach(_.join())
    oxigeno.foreach(_.join())
    log("Fin del programa")
  }
}


object gestorAgua_mi_version {
  // CS-Hid1: El hidrógeno que quiere formar una molécula espera si ya hay dos hidrógenos
  // CS-Hid2: Un hidrógeno debe esperar a los otros dos átomos para formar la molécula
  // CS-Ox1: El oxígeno que quiere formar una molécula espera si ya hay un oxígeno
  // CS-Ox2: El oxígeno debe esperar a los otros dos átomos para formar la molécula
  private var numH = 0
  private var numO = 0
  private val mutex = new Semaphore(1)
  private val puertaH = new Semaphore(1) // CS-O => Se generan O's => ABIERTO
  private val puertaO = new Semaphore(1) // CS-H => Se generan H's => ABIERTO
  private val molecula = new Semaphore(0) // CS-Mol // CS-H2xH1 => aún no formada => CERRADO

  def oxigeno(id: Int) = {
    // el oxígeno id quiere formar una molécula
    puertaO.acquire()
    mutex.acquire()
    numO += 1
    log(s"Oxígeno $id quiere formar una molécula")
    if (numO + numH < 3) { // Si aún no hay suficientes átomos bloqueamos el semáforo de molécula
      mutex.release()
      molecula.acquire()
      mutex.acquire()
    } else { // Si no => formamos la molécula
      log(s"      Molécula formada!!!")
    }

    numO -= 1
    if (numO + numH > 0) { // Si aún hay que intente formar moléculas
      molecula.release()
    } else { // Si no => salen los átomos
      puertaO.release()
      puertaH.release()
    }
    mutex.release()
  }

  def hidrogeno(id: Int) = {
    // el hidrógeno id quiere formar una molécula
    puertaH.acquire()
    mutex.acquire()
    numH += 1
    log(s"Hidrógeno $id quiere formar una molécula")
    if (numH < 2) puertaH.release()
    if (numO + numH < 3) { // Si aún no hay suficientes átomos
      mutex.release()
      molecula.acquire()
      mutex.acquire()
    } else {
      log(s"      Molécula formada!!!")
    }
    numH -= 1
    if (numO + numH > 0) {
      molecula.release()
    } else {
      puertaO.release()
      puertaH.release()
    }
    mutex.release()
  }
}

/*object gestorAgua_mi_version {
  // CS-Hid1: El hidrógeno que quiere formar una molécula espera si ya hay dos hidrógenos
  // CS-Hid2: Un hidrógeno debe esperar a los otros dos átomos para formar la molécula
  // CS-Ox1: El oxígeno que quiere formar una molécula espera si ya hay un oxígeno
  // CS-Ox2: El oxígeno debe esperar a los otros dos átomos para formar la molécula


  def oxigeno(id: Int) = {
    // el oxígeno id quiere formar una molécula
    // ...
    log(s"Oxígeno $id quiere formar una molécula")
    // ...
    // log(s"      Molécula formada!!!")
    // ...
    // log(s"Sale oxígeno $id: numO: $numO---molecula=${molecula.availablePermits()}")
    // ...
  }

  def hidrogeno(id: Int) = {
    // el hidrógeno id quiere formar una molécula
    // ...
    log(s"Hidrógeno $id quiere formar una molécula")
    // ...
    // log(s"      Molécula formada!!!")
    // ...
  }
}*/
