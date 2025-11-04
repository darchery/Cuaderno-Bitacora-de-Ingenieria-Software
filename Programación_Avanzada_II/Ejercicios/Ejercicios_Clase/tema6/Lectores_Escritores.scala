package tema6

import java.util.concurrent.*

object BD {
  var nLectores = 0
  val mutex = new Semaphore(1)
  val escribiendo = new Semaphore(1)
  // Versión 2 => mutex2
  /*var nEscritores = 0 // SÓLO los que quieren entrar
  val mutex2 = new Semaphore(1)*/
  val leyendo = new Semaphore(0)
  

  def entraEscritor(id: Int) = {
    // Si va a escribir paro el semáforo para no entren más escritores
    escribiendo.acquire
  }

  def saleEscritor(id: Int) = {
    // Si para de escribir activa el semáforo para que escriban más escritores
    escribiendo.release()
    // Versión 2 => mutex2
    /*mutex2.acquire()
    nEscritores -= 1
    mutex2.release()*/
  }

  def entraLector(id: Int) = {
    mutex.acquire()
    nLectores += 1
    if (nLectores == 1)
      // Bloqueamos la entrada de más escritores
      escribiendo.acquire
    mutex.release()
  }

  def saleLector(id: Int) = {
    mutex.acquire()
    nLectores -= 1
    // Si era el último lector
    if (nLectores == 0)
      // Dejamos que escritores escriban en la BD
      escribiendo.release()
    mutex.release()
  }

  def almacenar() = {
    leyendo.acquire()
    mutex.acquire()
    //
    //
    mutex.release()
  }

  /*def main(args: Array[String]): Unit = {
    while (true) {
      entraEscritor(i)
      // BD
      saleEscritor(i)
    }
    
    while (true) {
      entraLector(i)
      // BD
      saleLector(i)
    }
  }*/
}

