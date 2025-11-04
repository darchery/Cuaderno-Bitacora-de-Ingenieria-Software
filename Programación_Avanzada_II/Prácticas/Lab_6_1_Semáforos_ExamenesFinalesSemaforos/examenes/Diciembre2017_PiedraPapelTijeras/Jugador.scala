package examenes.Diciembre2017_PiedraPapelTijeras

import scala.util.Random

class Jugador(val id: Int, val mesa: Mesa) extends Thread {
  private val r = new Random()

  override def run(): Unit = {
    var aux = 0
    var ganador = -1
    try {
      while (ganador == -1) {
        aux = r.nextInt(3)
        ganador = mesa.nuevaJugada(id, aux)
      } 

      if (aux == ganador)
        println(s"El ganador he sido yo $id")
      else
        println(s"He perdido $id")
    } catch {
      case e: InterruptedException =>
        e.printStackTrace()
    }
  }
}
