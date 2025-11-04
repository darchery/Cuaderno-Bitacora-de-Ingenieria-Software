package Lab61.soluciones

import java.util.concurrent.Semaphore
import scala.util.Random

object gestorAgua_alberto {
  // CS-Hid1: El hidrógeno que quiere formar una molécula espera si ya hay dos hidrógenos
  // CS-Hid2: Un hidrógeno debe esperar a los otros dos átomos para formar la molécula
  // CS-Ox1: El oxígeno que quiere formar una molécula espera si ya hay un oxígeno
  // CS-Ox2: El oxígeno debe esperar a los otros dos átomos para formar la molécula
  var numH = 0
  var numO = 0
  val mutex = new Semaphore(1)
  val puertaH = new Semaphore(1)
  val puertaO = new Semaphore(1)
  val molecula = new Semaphore(0)
  val esperaO = new Semaphore(1)

  def oxigeno(id: Int) = {
    // el oxígeno id quiere formar una molécula
    puertaO.acquire()
    log(s"Oxígeno $id quiere formar una molécula")
    puertaH.release() // permitir que un H entre
    esperaO.acquire() // espera a que haya un H
    puertaH.release() // permitir que un H entre
    esperaO.acquire() // espera a que haya otro H
    // log(s"      Molécula formada!!!")
    molecula.release() // libera un H
    molecula.release() // libera al otro H
    puertaO.release() // permite que otro O entre
  }

  def hidrogeno(id: Int) = {
    // el hidrógeno id quiere formar una molécula
    puertaH.acquire()
    // igual pero con H
  }
}
object Ejercicio5_alberto {

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
