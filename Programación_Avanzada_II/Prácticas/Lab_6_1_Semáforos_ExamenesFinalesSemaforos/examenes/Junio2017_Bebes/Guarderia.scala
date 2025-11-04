package examenes.Junio2017_Bebes

import java.util.concurrent.Semaphore
import Lab61.soluciones._

class Guarderia {

  private var numBebes = 0
  private var numAdultos = 0

  private val mutex = new Semaphore(1)
  private val entraBebe = new Semaphore(0)
  private val salidaAdulto = new Semaphore(0)

  /**
   * Un bebe que quiere entrar en la guarderia llama a este metodo.
   * Debe esperar hasta que sea seguro entrar, es decir, hasta que 
   * cuado entre haya, al menos, 1 adulto por cada 3 bebes
   *
   */
  @throws[InterruptedException]
  def entraBebe(id: Int): Unit = {
    entraBebe.acquire()
    mutex.acquire()

    numBebes += 1
    log(s"Bebe $id ha entrado. Hay $numBebes")
    if (numBebes < numAdultos*3) entraBebe.release() // Caben más bebes => entran

    mutex.release()
  }

  /**
   * Un bebe que quiere irse de la guarderia llama a este metodo * 
   */
  @throws[InterruptedException]
  def saleBebe(id: Int): Unit = {
    mutex.acquire()
    numBebes -= 1
    log(s"Bebe $id sale. Quedan $numBebes bebes")

    if (numBebes < (numAdultos-1)*3) salidaAdulto.release() // Si aún pueden salir más adultos => salen
    mutex.release()
  }

  /**
   * Un adulto que quiere entrar en la guarderia llama a este metodo * 
   */
  @throws[InterruptedException]
  def entraAdulto(id: Int): Unit = {
    mutex.acquire()

    numAdultos += 1
    log(s"Adulto $id ha entrado. Hay $numAdultos adultos")
    if (numBebes < (numAdultos) * 3) { // Caben más bebes => Si el número de bebes puede ser controlado por los adultos - 1  => entre bebe
      entraBebe.release()
    }
    mutex.release()
  }

  /**
   * Un adulto que quiere irse de la guarderia llama a este metodo.
   * Debe esperar hasta que sea seguro salir, es decir, hasta que
   * cuando se vaya haya, al menos, 1 adulto por cada 3 bebes
   *
   */
  @throws[InterruptedException]
  def saleAdulto(id: Int): Unit = {
    salidaAdulto.acquire()
    mutex.acquire()

    numAdultos -= 1
    log(s"Adulto $id sale. Quedan $numAdultos adultos")
    if (numBebes < (numAdultos-1)*3) salidaAdulto.release() // Aún se pueden ir más adultos

    mutex.release()
  }
}