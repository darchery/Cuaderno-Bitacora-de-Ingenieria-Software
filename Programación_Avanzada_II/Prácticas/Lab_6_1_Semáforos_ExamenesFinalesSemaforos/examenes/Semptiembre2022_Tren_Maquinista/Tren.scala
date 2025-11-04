package examenes.Semptiembre2022_Tren_Maquinista

import java.util.concurrent.Semaphore

class Tren {

  /**CS-Maquinista: no se pone en marcha el tren hasta que V1 y V2 estén llenos
   * CS-Pasajero1: quiere hacer un viaje, pero tiene que esperar para subir el tren -> el tren está lleno o si los
   * pasajeros están bajando
   * CS-Pasajero2: Pas del V1 no puede bajarse del tren hasta que no haya finalizado el viaje
   * CS-Pasajero3: Pas del V2 no puede bajarse hasta que no haya finalizado el viaje Y se hayan bajado todos los
   * pasajeros del V1*/

  private val N = 5
  private var V1 = 0
  private var V2 = 0

  private val mutex = new Semaphore(1)
  private val hayEspacio = new Semaphore(1) // CS-Pasajero
  private val trenLleno = new Semaphore(0) // CS-Maq
  private val salir = new Semaphore(0) // CS-Pasajero

  @throws[InterruptedException]
  def viaje(id: Int): Unit = {
    // Lógica del viaje del pasajero (a completar si es necesario)

    hayEspacio.acquire() // Bloqueamos el acceso de más pasajeros
    mutex.acquire()
    // Subida
    if (V1 == N) { // Vagón1 lleno

      if (V2 == N) { // Vagón2 lleno

        // Ambos vagones están llenos
        println(s"SE HAN LLENADO LOS DOS VAGONES: V1(${V1}) y V2(${V2})")
        trenLleno.release() // Avisamos que el tren está lleno => que se empiece el viaje
      } else { // V1 lleno, pero queda espacio en V2
        V2 += 1
        println(s"pasajero ${id} ha subido al vagón 2")
        hayEspacio.release() // Hay más espacio en V2
      }
    } else { // V1 aún no está lleno
        V1 += 1
        println(s"pasajero ${id} ha subido al vagón 1")
        hayEspacio.release() // Hay más espacio
    }
    mutex.release()

    // Bajada
    salir.acquire() // Bloqueamos para que no salgan más pasajeros
    mutex.acquire()

    if (V1 == 0) { // V1 vacío

      if (V2 == 0) { // V2 vacío

        // Ambas vacías
        println(s"SE HAN VACÍADO LOS DOS VAGONES: V1(${V1}) y V2(${V2})")
        println("*************************************")
        hayEspacio.release() // Vagones vacíos => Indicamos que hay espacio a los siguientes pasajeros
      } else { // V1 vacío y V2 aún no está vacío
        V2 -= 1
        println(s"pasajero ${id} ha bajado del vagón 2")
        salir.release() // Aún quedan pasajeros en el vagón 2
      }
    } else { // Aún no se vacío
      V1 -= 1
      println(s"pasajero ${id} ha bajado del vagón 1")
      salir.release() // Abrimos el semáforo para que salgan los pasajeros del
    }

    mutex.release()
  }

  @throws[InterruptedException]
  def empiezaViaje(): Unit = {
    trenLleno.acquire() // Bloqueamos la hebra maquinista
    println("        Maquinista:  empieza el viaje")
  }

  @throws[InterruptedException]
  def finViaje(): Unit = {
    println("        Maquinista:  fin del viaje")
    salir.release()
  }
}
