package Lab61.soluciones

import java.util.concurrent.Semaphore
import scala.util.Random

object mesa {
  // CS-fumador i: No puede fumar hasta que estén en la mesa los ingredientes que le faltan
  // CS-Agente: No pone un nuevo ingrediente hasta que el fumador no ha terminado de fumar

  private var ingr = -1 // el ingrediente que no está-- -1=mesa vacía, 0=no tabaco, 1=no papel, 2=no cerillas
  // ...

  def quieroFumar(i: Int) = {
    // el fumador i quiere fumar
    // ...
    log(s"Fumador $i fuma")
    // ...
  }

  def finFumar(i: Int) = {
    // el fumador i termina de fumar
    // ...
    log(s"Fumador $i termina de fumar")
    // ...
  }

  def nuevosIngr(ingr: Int) = {
    // el agente pone nuevos ingredientes (ingr es el ingrediente que no pone)
    // ...
    log(s"El agente no pone ingrediente $ingr")
    // ...
  }
}

object Ejercicio6 {
  def main(args: Array[String]): Unit = {
    val fumador = new Array[Thread](3)
    for (i <- fumador.indices)
      fumador(i) = thread {
        while (true)
          Thread.sleep(Random.nextInt(500))
        mesa.quieroFumar(i)
        Thread.sleep(Random.nextInt(200))
        mesa.finFumar(i)
      }
    val agente = thread {
      while (true)
        Thread.sleep(Random.nextInt(500))
      mesa.nuevosIngr(Random.nextInt(3))
    }
  }
}
