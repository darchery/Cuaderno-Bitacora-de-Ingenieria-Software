package Lab61.soluciones

import java.util.concurrent.Semaphore
import scala.util.Random

object gestorAgua {
  // CS-Hid1: El hidrógeno que quiere formar una molécula espera si ya hay dos hidrógenos
  // CS-Hid2: Un hidrógeno debe esperar a los otros dos átomos para formar la molécula
  // CS-Ox1: El oxígeno que quiere formar una molécula espera si ya hay un oxígeno
  // CS-Ox2: El oxígeno debe esperar a los otros dos átomos para formar la molécula
  var numH = 0
  var numO = 0
  val mutex = new Semaphore(1) // sobre numO y numH
  val puertaH = new Semaphore(1) // CS - H
  val puertaO = new Semaphore(1) // CS - O
  val molecula = new Semaphore(0) // CS - H2 x O1

  def oxigeno(id: Int) = { // No funciona?, copié mal? o me equivoqué => codigos muy similares
    // el hidrógeno id quiere formar una molécula
    puertaO.acquire()
    mutex.acquire()
    numO += 1
    log(s"Oxígeno $id quiere formar una molécula")
    if (numO + numH < 3) { // Si aún no hay suficientes moleculas
      mutex.release()
      molecula.acquire()
      mutex.acquire()
    } else {
      log(s"      Molécula formada!!!")
    }
    numO -= 1
    if (numO + numH > 0) {
      molecula.release()
    } else {
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
object Ejercicio5 {

  def main(args:Array[String]) = {
    val N = 5
    val hidrogeno = new Array[Thread](2 * N)
    for (i <- 0 until hidrogeno.length)
      hidrogeno(i) = thread {
        Thread.sleep(Random.nextInt(500))
        gestorAgua.hidrogeno(i)
      }
    val oxigeno = new Array[Thread](N)
    for (i <- 0 until oxigeno.length)
      oxigeno(i) = thread {
        Thread.sleep(Random.nextInt(500))
        gestorAgua.oxigeno(i)
      }
    hidrogeno.foreach(_.join())
    oxigeno.foreach(_.join())
    log("Fin del programa")
  }
}
