package Lab61.soluciones

import java.util.concurrent.Semaphore
import scala.util.Random

object Ejercicio6_mi_version {
  def main(args: Array[String]): Unit = {
    val fumador = new Array[Thread](3)

    for (i <- fumador.indices)
      fumador(i) = thread {
        while (true) {
          Thread.sleep(Random.nextInt(500)) // Espera
          mesa_mi_version.quieroFumar(i)
          Thread.sleep(Random.nextInt(200)) // Tiempo fumando
          mesa_mi_version.finFumar(i)
        }
      }

    val agente = thread {
      while (true) {
        Thread.sleep(Random.nextInt(500)) // Espera
        mesa_mi_version.nuevosIngr(Random.nextInt(3))
      }
    }
  }
}

object mesa_mi_version {
  // CS-fumador i: No puede fumar hasta que estén en la mesa los ingredientes que le faltan
  // CS-Agente: No pone un nuevo ingrediente hasta que el fumador no ha terminado de fumar

  /**
   * Si pone 0 => puede fumar el fumador 0(tien tabaco 0 y el agente puso los demás ingredientes)
   * Si pone 1 => fuma el fumador 1
   * Si pone 2 => fuma el fumador 2*/
  private var ingr = -1 // el ingrediente que no está-- -1=mesa vacía, 0=no tabaco, 1=no papel, 2=no cerillas
  private val mutex = new Semaphore(1) // EXM
  private val ponerIngredientes = new Semaphore(1) // El agente empieza poniendo ingredientes en la mesa vacía => ABIERTO
  private val puedeFumar = new Array[Semaphore](3)
  for (i<-puedeFumar.indices) {
    puedeFumar(i) = new Semaphore(0) // Al principio la mesa está vacía => Nadie puede fumar => CERRADO
  }

  def quieroFumar(i: Int) = {
    // el fumador i quiere fumar
    puedeFumar(i).acquire() // Cerramos el semáforo => Ya no puede fumar => CERRADO
    log(s"Fumador $i fuma")
  }

  def finFumar(i: Int) = {
    // el fumador i termina de fumar
    log(s"Fumador $i termina de fumar")
    ponerIngredientes.release() // Indicamos que el agente puede poner ingredientes => ABIERTO
  }

  def nuevosIngr(ingr: Int) = {
    // el agente pone nuevos ingredientes (ingr es el ingrediente que no pone)
    ponerIngredientes.acquire() // Ahora el agente NO puede poner más ingredientes => CERRADO
    mutex.acquire() // EXM-ini
    this.ingr = ingr
    log(s"El agente no pone ingrediente $ingr")
    puedeFumar(ingr).release() // Ha llegado su ingrediente => Puede fumar
    mutex.release() // EXM-fin
  }
}

/*object mesa_mi_version_REPASO {
  // CS-fumador i: No puede fumar hasta que estén en la mesa los ingredientes que le faltan
  // CS-Agente: No pone un nuevo ingrediente hasta que el fumador no ha terminado de fumar

  private var ingr = -1 // el ingrediente que no está-- -1=mesa vacía, 0=no tabaco, 1=no papel, 2=no cerillas
  private val mutex = new Semaphore(1)
  private val ponerIngredientes = new Semaphore(1)
  private val puedeFumar = new Array[Semaphore](3)
  for (i<-puedeFumar.indices)
    puedeFumar(i) = new Semaphore(0)

  def quieroFumar(i: Int) = {
    // el fumador i quiere fumar
    puedeFumar(i).acquire()
    log(s"Fumador $i fuma")
  }

  def finFumar(i: Int) = {
    // el fumador i termina de fumar
    log(s"Fumador $i termina de fumar")
    ponerIngredientes.release()
  }

  def nuevosIngr(ingr: Int) = {
    // el agente pone nuevos ingredientes (ingr es el ingrediente que no pone)
    ponerIngredientes.acquire()
    mutex.acquire()
    this.ingr = ingr
    puedeFumar(ingr).release()
    log(s"El agente no pone ingrediente $ingr")
    mutex.release()
  }
}*/