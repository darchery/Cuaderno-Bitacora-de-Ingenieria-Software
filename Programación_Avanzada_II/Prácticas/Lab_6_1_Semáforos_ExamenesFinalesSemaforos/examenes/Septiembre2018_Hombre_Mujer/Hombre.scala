package examenes.Septiembre2018_Hombre_Mujer

import scala.util.Random

class Hombre(aseo: Aseo, id: Int) extends Thread {

  private val r = new Random()

  override def run(): Unit = {
    while (true) {
      try {
        Thread.sleep(5000)
        aseo.llegaHombre(id)
        Thread.sleep(r.nextInt(500))
        aseo.saleHombre(id)
      } catch {
        case e: InterruptedException => e.printStackTrace()
      }
    }
  }
}
