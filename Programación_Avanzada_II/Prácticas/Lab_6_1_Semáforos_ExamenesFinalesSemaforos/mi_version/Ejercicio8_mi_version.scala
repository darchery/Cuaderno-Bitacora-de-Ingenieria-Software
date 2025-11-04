package Lab61.soluciones

import java.util.concurrent.Semaphore
import scala.util.Random


class Olla_mi_version(R: Int) {
  // CS-caníbal i: no coge una ración de la olla si está vacía
  // CS-cocinero: no cocina un nuevo explorador hasta que la olla está vacía
  private var olla = R // inicialmente llena
  private val mutex = new Semaphore(1)
  private val hayComida = new Semaphore(1) // CS-Canibal
  private val trabajar = new Semaphore(0) // Cs-Cocinero

  def racion(i: Int) = {
    // caníbal i coge una ración de la olla
    hayComida.acquire()
    mutex.acquire()
    olla -= 1
    if (olla > 0) hayComida.release()
    if (olla == 0) trabajar.release()
    log(s"Caníbal $i coge una ración de la olla. Quedan $olla raciones.")
    mutex.release()
  }

  def dormir = {
    // cocinero espera a que la olla esté vacía
    trabajar.acquire()
  }

  def llenarOlla = {
    mutex.acquire()
    olla = R
    log(s"El cocinero llena la olla. Quedan $olla raciones.")
    mutex.release()
    hayComida.release()
  }
}

object Ejercicio8_mi_version {
  def main(args: Array[String]): Unit = {
    val NCan = 20
    val olla = new Olla_mi_version(5)
    val canibal = new Array[Thread](NCan)

    for (i <- canibal.indices)
      canibal(i) = thread {
        while (true) {
          Thread.sleep(Random.nextInt(500)) // Esperando turno
          olla.racion(i) // Coge ración
        }
      }
    val cocinero = thread {
      while (true) {
        olla.dormir
        Thread.sleep(500) // cocinando
        olla.llenarOlla
      }
    }
  }
}


/*class Olla_mi_version(R: Int) {
  // CS-caníbal i: no coge una ración de la olla si está vacía
  // CS-cocinero: no cocina un nuevo explorador hasta que la olla está vacía
  private var olla = R // inicialmente llena
  private val mutex = new Semaphore(1)
  private val avisarCocinero = new Semaphore(0)// CS-Cocinero // CS-Canibal
  // Si está vacía => Canibal llama a cocinero y la llena // Como empieza llena => CERRADO
  private val puedeComer = new Semaphore(1) // CS-Canibal // Al principio pueden comer => ABIERTO

  def racion(i: Int) = {
    // caníbal i coge una ración de la olla
    puedeComer.acquire() // Uno solo come a la vez
    mutex.acquire()
    olla -= 1
    if (olla > 0) puedeComer.release() // Aún queda comida => Llamo a otro caníbal
    if (olla == 0) avisarCocinero.release() // Se acabó la comida => Llamo al cocinero
    log(s"Caníbal $i coge una ración de la olla. Quedan $olla raciones.")
    mutex.release()
  }

  def dormir = {
    // cocinero espera a que la olla esté vacía
    avisarCocinero.acquire() // Se para el semáforo para que pueda dormir y cocine
  }

  def llenarOlla = {
    mutex.acquire()
    olla = R // Lleno la olla
    log(s"El cocinero llena la olla. Quedan $olla raciones.")
    puedeComer.release() // Ahora se puede comer => Llamo a los caníbales
    mutex.release()
  }
}*/

