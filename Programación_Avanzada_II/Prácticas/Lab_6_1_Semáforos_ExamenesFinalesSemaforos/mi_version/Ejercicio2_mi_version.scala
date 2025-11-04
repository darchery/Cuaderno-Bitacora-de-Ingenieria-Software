package Lab61.soluciones

import scala.util.Random
import java.util.concurrent.Semaphore

object Ejercicio2_mi_version {
  def main(args:Array[String]) = {
    val cadena = new Cadena_mi_version(6)
    val empaquetador = new Array[Thread](3)

    for (i <- 0 until empaquetador.length)
      empaquetador(i) = thread {
        while (true) {
          cadena.retirarProducto(i)
          Thread.sleep(Random.nextInt(500)) // empaquetando
        }
      }

    val colocador = thread {
      while (true) {
        Thread.sleep(Random.nextInt(100)) // recogiendo el producto
        cadena.nuevoProducto(Random.nextInt(3))
      }
    }
  }
}


class Cadena_mi_version(n: Int) {
  // CS-empaquetador-i: espera hasta que hay productos de tipo i
  // CS-colocador: espera si hay n productos en la cadena
  private val tipo = Array.fill(3)(0) // el buffer
  private var cuentaTotal = 0 // No es cuantos quedan, es cuantos se han procesado
  private val mutex = new Semaphore(1)
  private val esperaColocador = new Semaphore(1) // CS- Colocador
  private val hayPaquete =  new Array[Semaphore](3)
  for (i<-0 until hayPaquete.length)
    hayPaquete(i) = new Semaphore(0)


  def retirarProducto(p: Int) = {
    hayPaquete(p).acquire() // Cerramos el aviso del paquete p
    mutex.acquire()
    tipo(p) -= 1 // SC
    log(s"Empaquetador $p retira un producto. Quedan ${tipo.mkString("[",",","]")}")
    if (tipo(p) > 0) hayPaquete(p).release() // Si aún hay más activar el semáforo
    if (tipo.sum == n-1) esperaColocador.release() // Si era el último => a colocar
    mutex.release()
  }
  def nuevoProducto(p:Int) = {
    esperaColocador.acquire() // Si ya hay el máximo => No coloques más
    mutex.acquire()
    tipo(p) += 1
    cuentaTotal += 1
    log(s"Colocador pone un producto $p. Quedan ${tipo.mkString("[",",","]")}")
    log(s"Total de productos empaquetados $cuentaTotal")
    if (tipo(p) == 1) hayPaquete(p).release() // Si es el primero aviso => HAY UNO
    if(tipo.sum < n) esperaColocador.release() // Si aún hay espacio mete más
    mutex.release()
  }
}

class Cadena_mi_version_REPASO(n: Int) {
  // CS-empaquetador-i: espera hasta que hay productos de tipo i
  // CS-colocador: espera si hay n productos en la cadena
  private val tipo = Array.fill(3)(0) // el buffer
  private var cuentaTotal = 0
  private val mutex = new Semaphore(1)
  private val esperaColocador = new Semaphore(1) // CS-Colocalor
  private val hayPaquete = new Array[Semaphore](3) // CS-Empaquetador i
  for (i<-hayPaquete.indices)
    hayPaquete(i) = new Semaphore(0)

  def retirarProducto(p: Int) = {
    if (tipo(p) > 0) {
      hayPaquete(p).acquire()
      mutex.acquire()
      tipo(p) -= 1
      log(s"Empaquetador $p retira un producto. Quedan ${tipo.mkString("[",",","]")}")
      if (tipo(p) > 0) hayPaquete(p).release()
      if (tipo.sum < n) esperaColocador.release()
      mutex.release()
    }

  }
  def nuevoProducto(p:Int) = {
    esperaColocador.acquire()
    mutex.acquire()
    tipo(p) += 1
    cuentaTotal += 1
    log(s"Colocador pone un producto $p. Quedan ${tipo.mkString("[",",","]")}")
    log(s"Total de productos empaquetados $cuentaTotal")
    hayPaquete(p).release()
    if (tipo.sum < n) esperaColocador.release()
    mutex.release()
  }
}