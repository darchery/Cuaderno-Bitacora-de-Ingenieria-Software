package examenes.Septiembre2021_Generador_Procesador

import java.util.concurrent.Semaphore

class DatoCompartido(private val nProcesadores: Int) {

  // Dato a procesar
  private var dato: Int = 0
  // Número de procesadores totales
  // private var nProcesadores: Int = 0
  // Número de procesadores pendientes de procesar el dato
  private var procPend: Int = 0

  private val mutex = new Semaphore(1)
  private val pongoDato = new Semaphore(1) // CS-Generador // Semáforo que controla poner el dato
  private val hayDato = new Array[Semaphore](nProcesadores) // CS1-Procesador y CS2-Procesador
  for (i<- hayDato.indices) {
    hayDato(i) = new Semaphore(0) // Al principio no hay datos
  }
  private val esperoProcesadores = new Semaphore(0) // CS-Generador // Semáforo que bloque la hebra generador para esperar a los procesadores
  // Inicia en 0 para que cuando se le haga un aquire se bloquee

  /**
   * Recibe como parámetro el número de procesadores que tienen que manipular
   * cada dato generado. Debe ser un número mayor que 0.
   */

  /**
   * El Generador utiliza este método para almacenar un nuevo dato a procesar.
   * Una vez almacenado el dato se debe avisar a los procesadores de que se ha
   * almacenado un nuevo dato.
   *
   * Por último, el Generador tendrá que esperar en este método a que todos los
   * procesadores terminen de procesar el dato.
   *
   * CS_Generador: espera a que todos los procesadores terminen antes de generar el siguiente dato.
   */
  def generaDato(d: Int): Int = {
    // COMPLETAR
    pongoDato.acquire()
    mutex.acquire()
    dato = d
    println(s"Dato a procesar: $dato")

    procPend = nProcesadores
    println(s"Número de procesadores pendientes: $procPend")
    mutex.release()

    // Avisamos a todos los procesadores
    for (i<- hayDato.indices) {
      hayDato(i).release()
    }

    esperoProcesadores.acquire() // Bloqueamos la hebra

    dato
  }

  /**
   * El Procesador con identificador id utiliza este método para leer el
   * dato que debe procesar (el dato se devuelve como valor de retorno del método).
   * Deberá esperarse si no hay datos nuevos para procesar
   * o si otro procesador está manipulando el dato.
   *
   * CS1_Procesador: espera si no hay un nuevo dato que procesar.
   * CS2_Procesador: espera a que el dato esté disponible para procesarlo.
   */
  def leeDato(id: Int): Int = {
    // COMPLETAR
    hayDato(id).acquire()
    dato
  }

  /**
   * El Procesador con identificador id almacena en el recurso compartido el resultado
   * de haber procesado el dato. Una vez hecho esto actuará de una de las dos formas siguientes:
   * (1) Si aún hay procesadores esperando a procesar el dato los avisará.
   * (2) Si él era el último procesador avisará al Generador de que han terminado.
   */
  def actualizaDato(id: Int, datoActualizado: Int): Unit = {
    // COMPLETAR

    mutex.acquire()
    dato = dato + 1 // Único problema: no usamos dato actualizado sino que lo actualizamos aquí en exclusión mutua
    println(s"\tProcesador $id ha procesado el dato. Nuevo dato: $dato")

    procPend -= 1
    println(s"Número de procesadores pendientes: $procPend")

    if (procPend == 0) {
      esperoProcesadores.release() // Desbloqueamos a la hebra
      pongoDato.release() // Ponemos el dato

    }
    mutex.release()
  }
}
