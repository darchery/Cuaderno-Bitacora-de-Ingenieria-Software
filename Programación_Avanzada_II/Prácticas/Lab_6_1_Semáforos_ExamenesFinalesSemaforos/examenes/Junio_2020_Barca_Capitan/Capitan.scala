package examenes.Junio_2020_Barca_Capitan

import scala.util.Random

class Capitan(barca: Barca) extends Thread {

  private val r = new Random()

  override def run(): Unit = {
    while (true) {
      try {
        barca.esperoSuban()
        Thread.sleep(r.nextInt(500))
        barca.finViaje()
      } catch {
        case e: InterruptedException =>
          e.printStackTrace()
      }
    }
  }
}
