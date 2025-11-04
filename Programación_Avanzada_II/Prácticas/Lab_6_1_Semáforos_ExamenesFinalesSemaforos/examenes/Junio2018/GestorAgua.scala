package examenes.Junio2018

import Lab61.soluciones._
import java.util.concurrent._

class GestorAgua {

  private var numOxi = 0 // 1 máximo
  private var numHid = 0 // 2 máximo

  private val mutex = new Semaphore(1) // EXM
  private val puertaHid = new Semaphore(1) // Controla el generador de hidrógenos
  private val puertaOxi = new Semaphore(1) // Controla el generador de oxígeno
  private val moleculaFormada = new Semaphore(0) // Controla la formación de la molécula

  def hListo(id: Int): Unit = {
    puertaHid.acquire()

    mutex.acquire()
    numHid += 1
    log(s"Hidrógeno ${id} quiere formar una molécula")
    mutex.release()

    if (numHid < 2) puertaHid.release() // Aún hay hueco para un hidrógeno
    else moleculaFormada.release() // Si no podemos desbloquear a la hebra y formamos la molécula
  }

  def oListo(id: Int): Unit = {
    puertaOxi.acquire()

    mutex.acquire()
    numOxi += 1
    log(s"Oxígeno ${id} quiere formar una molécula")
    mutex.release()

    moleculaFormada.acquire() // Bloqueamos la hebra, sólo la puede desbloquear los hidrógenos (sólo necesitamos un oxígeno)
    // Cuando llega o bloqueamos

    log(s"    Molécula formada!!!")

    // Al haberse formado => reiniciamos los contadores => y desbloqueamos a los contadores de hidrógenos y oxígenos
    numHid = 0
    numOxi = 0
    puertaOxi.release()
    puertaHid.release()
  }
}
