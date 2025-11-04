package examenes.Junio_2020_Barca_Capitan

import scala.util.Random

class Pasajero(private var id: Int, private var orilla: Int, private val barca: Barca) extends Thread {

  private val r = new Random()

  override def run(): Unit = {
    while (true) {
      try {
        Thread.sleep(r.nextInt(1000))
        barca.subir(id, orilla)
        Thread.sleep(r.nextInt(500))
        orilla = barca.bajar(id)
      } catch {
        case e: InterruptedException =>
          e.printStackTrace()
      }
    }
  }
}
