package examenes.Semptiembre2022_Tren_Maquinista

import scala.util.Random

class Maquinista(tren: Tren) extends Thread {

  private val r = new Random()

  override def run(): Unit = {
    while (true) {
      try {
        tren.empiezaViaje()
        Thread.sleep(r.nextInt(1000))
        tren.finViaje()
      } catch {
        case e: InterruptedException =>
          e.printStackTrace()
      }
    }
  }
}
