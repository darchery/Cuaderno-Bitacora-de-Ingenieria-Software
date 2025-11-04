package Lab61.soluciones

import java.util.concurrent.Semaphore
import scala.util.Random

/**
 * Ri: Espera si no hay producto de tipo i
 * Prod: Espero si la cadena está llena*/

class Cadena(n: Int) {
  // CS-empaquetador-i: espera hasta que hay productos de tipo i
  // CS-colocador: espera si hay n productos en la cadena
  private val tipo = Array.fill(3)(0) // el buffer
  private var cuentaTotal = 0
  private val esperaColocador = new Semaphore(1) // CS- Colocador
  private val hayProducto = new Array[Semaphore](3)
  // Inicializamos el array de semáforos de productos por tipo i
  for (i<- hayProducto.indices)
    hayProducto(i) = new Semaphore(0)
  private val mutex = new Semaphore(1)

  def retirarProducto(p: Int) = {
    hayProducto(p).acquire()
    mutex.acquire()
    tipo(p) -= 1
    log(s"Empaquetador $p retira un producto. Quedan ${tipo.mkString("[",",","]")}")
    if (tipo(p) > 0) hayProducto(p).release()
    if (tipo.sum == n-1) esperaColocador.release()
    mutex.release()
  }
  def nuevoProducto(p:Int) = {
    esperaColocador.acquire()
    mutex.acquire()
    tipo(p) += 1 // Aumentamos en 1 el número de productos del tipo "p"

    log(s"Colocador pone un producto $p. Quedan ${tipo.mkString("[",",","]")}")
    cuentaTotal += 1
    log(s"Total de productos empaquetados $cuentaTotal")

    if (tipo(p) == 1) hayProducto(p).release()
    if (tipo.sum < n) esperaColocador.release() // Si hay menos productos del máximo posible, llamamos al colocador
    mutex.release()
  }
}

object Ejercicio2 {
  def main(args:Array[String]) = {
    val cadena = new Cadena(6)
    val empaquetador = new Array[Thread](3)
    for (i <- 0 until empaquetador.length)
      empaquetador(i) = thread {
        while (true)
          cadena.retirarProducto(i)
          Thread.sleep(Random.nextInt(500)) // empaquetando
      }

    val colocador = thread {
      while (true)
        Thread.sleep(Random.nextInt(100)) // recogiendo el producto
        cadena.nuevoProducto(Random.nextInt(3))
    }
  }
}
