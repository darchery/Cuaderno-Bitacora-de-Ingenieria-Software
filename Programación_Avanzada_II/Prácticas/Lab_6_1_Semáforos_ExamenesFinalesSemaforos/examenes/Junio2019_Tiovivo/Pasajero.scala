package examenes.Junio2019_Tiovivo

import scala.util.Random

class Pasajero(id: Int, t: Tiovivo) extends Thread {

  private val r = new Random()

  override def run(): Unit = {
    var fin = false
    while (!isInterrupted && !fin) {
      try {
        Thread.sleep(10 + r.nextInt(50))
        t.subir(id)
        t.bajar(id)
      } catch {
        case _: InterruptedException =>
          fin = true
      }
    }
  }
}
