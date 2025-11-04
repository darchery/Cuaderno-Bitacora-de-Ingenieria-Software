package examenes.Septiembre2019_Moneda

import Lab61.soluciones._
import java.util.concurrent.Semaphore

class Concurso {

  private val N = 10

  private var partidasCnt = 0 // Contador de partidas jugadas
  private var fin = false // Determina si ha acabado el juego o no
  private var nCaras = new Array[Int](2) // Array contador de caras
  nCaras(0) = 0
  nCaras(1) = 0
  private var juegosGanados = new Array[Int](2) // Array contador de victorias
  juegosGanados(0) = 0
  juegosGanados(1) = 0
  private var tirosMonedas = new Array[Int](2) // Array contador de tiradas
  tirosMonedas(0) = 0
  tirosMonedas(1) = 0

  private val mutex = new Semaphore(1) // EXM
  private val puedoTirarMoneda = new Array[Semaphore](2) // Array  que habilita el tiro de moneda
  puedoTirarMoneda(0) = new Semaphore(1)
  puedoTirarMoneda(1) = new Semaphore(1)

  @throws[InterruptedException]
  def tirarMoneda(id: Int, cara: Boolean): Unit = {
    // TODO

    if (!fin){
      puedoTirarMoneda(id).acquire()

      mutex.acquire()

      tirosMonedas(id) += 1
      if (cara) nCaras(id) += 1

      if (tirosMonedas(id) < N) { // Si aún se puede hacer más lanzamientos de tipo id => lanzamos
        puedoTirarMoneda(id).release()
      } else { // No se pueden tirar más monedas del tipo id

        if (tirosMonedas((id + 1) % 2) < N) { // Se pueden tirar monedas del otro tipo
          puedoTirarMoneda((id + 1) % 2).release()

        } else { // No se pueden tirar más monedas de ningún tipo, 20 monedas lanzadas => VALORAMOS PARTIDA
          partidasCnt += 1

          if (nCaras(id) > nCaras((id + 1) % 2)) {
            log(s"Juego ${partidasCnt}: Ha ganado la partida el jugador ${id} con ${nCaras(id)} caras")
            juegosGanados(id) += 1

          } else if (nCaras((id + 1) % 2) > nCaras(id)) {
            log(s"Juego ${partidasCnt}: Ha ganado la partida el jugador ${(id+1)%2} con ${nCaras(1)} caras")
            juegosGanados((id + 1) % 2) += 1

          } else { // Han empatado => No suma nada
            log(s"Juego ${partidasCnt}: El juego ha empatado")
          }

          // Vemos como queda el marcador
          if (juegosGanados(id) == 3) { // Si ha conseguido la victoria id  => Se acaba
            log(s"Final del concurso. Ha ganado el jugador ${id}")
            fin = true

          } else if (juegosGanados((id + 1) % 2) == 3) {  // Si ha conseguido la victoria el otro  => Se acaba
              log(s"Final del concurso. Ha ganado el jugador ${(id + 1) % 2}")
              fin = true
          } else { // Si aún nadie la ha conseguido => Reiniciamos nCaras, tiradas y le indicamos que pueden tirar de nuevo
              nCaras = Array.fill(2)(0)
              tirosMonedas = Array.fill(2)(0)
              puedoTirarMoneda.foreach(_.release())
          }
        }
      }
      mutex.release()
    }
  }

  def concursoTerminado(): Boolean = {
    fin
  }
}
