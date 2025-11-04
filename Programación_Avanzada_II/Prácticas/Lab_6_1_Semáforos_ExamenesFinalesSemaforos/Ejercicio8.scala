package Lab61.soluciones

import java.util.concurrent.Semaphore
import scala.util.Random

class Olla(R: Int) {
  // CS-caníbal i: no coge una ración de la olla si está vacía
  // CS-cocinero: no cocina un nuevo explorador hasta que la olla está vacía
  private var olla = R // inicialmente llena
  // ...

  def racion(i: Int) = {
    // caníbal i coge una ración de la olla
    // ...
    log(s"Caníbal $i coge una ración de la olla. Quedan $olla raciones.")
    // ...
  }

  def dormir = {
    // cocinero espera a que la olla esté vacía
    // ...
  }

  def llenarOlla = {
    // ...
    log(s"El cocinero llena la olla. Quedan $olla raciones.")
    // ...
  }
}

object Ejercicio8 {
  def main(args: Array[String]): Unit = {
    val NCan = 20
    val olla = new Olla(5)
    val canibal = new Array[Thread](NCan)
    for (i <- canibal.indices)
      canibal(i) = thread {
        while (true)
          Thread.sleep(Random.nextInt(500))
        olla.racion(i)
      }
    val cocinero = thread {
      while (true)
        olla.dormir
      Thread.sleep(500) // cocinando
      olla.llenarOlla
    }
  }
}
