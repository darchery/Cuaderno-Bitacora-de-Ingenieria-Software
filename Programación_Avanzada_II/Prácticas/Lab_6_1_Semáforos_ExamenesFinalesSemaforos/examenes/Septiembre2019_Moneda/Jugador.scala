package examenes.Septiembre2019_Moneda

import scala.util.Random

class Jugador(id: Int, c: Concurso) extends Thread {
  private val rnd = new Random()

  override def run(): Unit = {
    try {
      while (!c.concursoTerminado()) {
        for (_ <- 0 until 10) {
          Thread.sleep(10 + rnd.nextInt(90))
          c.tirarMoneda(id, rnd.nextBoolean())
        }
      }
    } catch {
      case e: InterruptedException => e.printStackTrace()
    }
  }
}
