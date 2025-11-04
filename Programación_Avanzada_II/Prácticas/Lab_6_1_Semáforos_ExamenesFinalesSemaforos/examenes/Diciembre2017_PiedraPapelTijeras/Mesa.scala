package examenes.Diciembre2017_PiedraPapelTijeras

import java.util.concurrent._
import Lab61.soluciones._

class Mesa {
  // 0 - piedra, 1 - papel, 2 - tijeras

  /**
   *
   * @param jug jugador que llama al método (0,1,2)
   * @param juego jugada del jugador (0-piedra,1-papel, 2-tijeras)
   * @return  si ha habido un ganador en esta jugada se devuelve
   *          la jugada ganadora
   *         o -1, si no ha habido ganador
   * @throws InterruptedException
   *
   * El jugador que llama a este método muestra su jugada, y espera a que
   * estén la de los otros dos.
   * Hay dos condiciones de sincronización
   * CS1- Un jugador espera en el método hasta que estén las tres jugadas
   * CS2- Un jugador tiene que esperar a que finalice la jugada anterior para
   *     empezar la siguiente
   *
   */

  private val empate = -1
  private var contadorJugadas = 0
  private val jugadas = Array(0, 0, 0)
  private var resultado = -2 // Ningún resultado


  private val mutex = new Semaphore(1)
  private val jugar = new Semaphore(1)
  private val espero = new Array[Semaphore](3)
  espero(0) = new Semaphore(0)
  espero(1) = new Semaphore(0)
  espero(2) = new Semaphore(0)

  @throws(classOf[InterruptedException])
  def nuevaJugada(jug: Int, juego: Int): Int = {

    jugar.acquire()
    mutex.acquire()

    jugadas(jug) = juego
    contadorJugadas += 1

    if (contadorJugadas < 3) {
      jugar.release()
      mutex.release()
      espero(jug).acquire() // Esperamos a que acabe
    } else { // Evaluar jugada: 0 =>  piedra, 1 => papel, 2 => tijeras

      if (jugadas(0) == 0 && jugadas(1) == 1 && jugadas(2) == 2) {
        resultado = empate
      } else if (jugadas(0) == 0 && jugadas(1) == 0 && jugadas(2) == 1) {
        resultado = 1
      } else if (jugadas(0) == 0 && jugadas(1) == 0 && jugadas(2) == 2) {
        resultado = empate
      } else if (jugadas(0) == 1 && jugadas(1) == 1 && jugadas(2) == 2) {
        resultado = 2
      } else if (jugadas(0) == 1 && jugadas(1) == 1 && jugadas(2) == 0) {
        resultado = empate
      } else if (jugadas(0) == 2 && jugadas(1) == 2 && jugadas(2) == 0) {
        resultado = 0
      } else if (jugadas(0) == 2 && jugadas(1) == 2 && jugadas(2) == 1) {
        resultado = empate
      } else {
        resultado = empate
      }

      contadorJugadas = 0
      for (i<- jugadas.indices) jugadas(i) = 0
      for (i <- 0 until 2 if i != jug) { // Depierta a sus 2 compañeros que lo están esperando
        espero(i).release()
      }
      jugar.release()
      mutex.release()
    }
    resultado
  }
}
