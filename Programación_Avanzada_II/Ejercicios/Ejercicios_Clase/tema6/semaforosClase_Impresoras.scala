package tema6

import java.util.Random
import java.util.concurrent.*

object Impresoras {
  private var numImp = 2
  private val espera = new Semaphore(1) // CS-Usuario
  private val mutex = new Semaphore(1) // mutex sobre numImp

  def quieroImpresora(id: Int) = {
    espera.acquire()
    mutex.acquire()
    numImp -= 1
    if (numImp > 0) espera.release()
    println(s"Usuario $id coge una impresora. Hya. $numImp")
    mutex.release()
  }
  def devuelvoImpresora(id: Int) = {
    mutex.acquire()
    numImp += 1
    if (numImp == 1) espera.release()
    println(s"Usario $id devuelve una impresora. Hay: $numImp")
    mutex.release()
  }

  def main(args: Array[Int]) =
    val usuario = new Array[Thread](10)
    for (i<-0 until usuario.length)
      usuario(i) = new Thread {
        for (j<-0 until 3)
          quieroImpresora(i)
          Thread.sleep(Random().nextInt(10))
          devuelvoImpresora(i)
      }
}
// CS-Usuario i espera hasta que haya impresoras disponibles