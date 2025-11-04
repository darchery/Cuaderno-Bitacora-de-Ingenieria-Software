package tema7

import java.util.concurrent.Semaphore
import scala.util.Random
import concurrencia.*

class Barrera(n:Int){
  private var esperoTodos = true // Puerta de salida -> abierta
  private var sigIter = true // Puerta de entrada -> abierta
  private var finalizados = 0

  //para sincronizar las iteraciones
  def finIter(id:Int,iter:Int)= synchronized {
    // Mientras la puerta de entrada esté cerrada => ESPERAMOS
    while (!sigIter) wait()
    finalizados += 1
    log(s"Worker $id ha terminado la iteración $iter----$finalizados")

    //si soy el último en salir
    // Si aún caben trabajadores => ESPERAMOS a todos
    if (finalizados < n) {
      while (esperoTodos) wait()
    }
    // Si ya no caben => CERRAMOS puertas
    else {
      sigIter = false // Cerramos puerta de entrada
      esperoTodos = false // " " salida
      notifyAll()
    }

    // Reducimos su cantidad
    finalizados -= 1
    if (finalizados == 0) {
      // si soy el último en salir => Abro las puertas
      esperoTodos = true
      log(s"------------------------------------------")
    }
  }
}


object workers {

  def main(args:Array[String]) =
    val N = 5
    val barrera = new Barrera(N)
    val worker = new Array[Thread](N)

    for (i <- 0 until N)
      worker(i) = thread {
        for (j <- 0 until 30)
          Thread.sleep(Random.nextInt(100))
          barrera.finIter(i,j)
      }

}
