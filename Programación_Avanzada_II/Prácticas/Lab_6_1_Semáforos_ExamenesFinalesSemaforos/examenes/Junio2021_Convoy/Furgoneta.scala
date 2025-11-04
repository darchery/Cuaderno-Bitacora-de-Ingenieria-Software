package examenes.Junio2021_Convoy

import scala.util.Random

class Furgoneta(id: Int, convoy: Convoy) extends Thread {
  private var lider: Int = -1
  private val r = new Random()

  override def run(): Unit = {
    try {
      Thread.sleep(r.nextInt(50))
      // La furgoneta se une al convoy
      lider = convoy.unir(id)
      if (lider == id) {
        // Es la furgoneta líder
        convoy.calcularRuta(id)
        Thread.sleep(1000)
        convoy.destino(id)
      } else {
        // No es la furgoneta líder
        convoy.seguirLider(id)
      }
    } catch {
      case e: InterruptedException => e.printStackTrace()
    }
  }
}
