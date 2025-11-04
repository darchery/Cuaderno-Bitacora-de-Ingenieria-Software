package examenes.Septiembre2018_Hombre_Mujer

import scala.util.Random

class Mujer(aseo: Aseo, id: Int) extends Thread {

  private val r = new Random()

  override def run(): Unit = {
    while (true) {
      try {
        Thread.sleep(5000)
        aseo.llegaMujer(id)
        Thread.sleep(r.nextInt(500))
        aseo.saleMujer(id)
      } catch {
        case e: InterruptedException => e.printStackTrace()
      }
    }
  }
}
