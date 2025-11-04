package examenes.Junio2018

import scala.util.Random

class Oxigeno(id: Int, gestor: GestorAgua) extends Thread {

  private val r = new Random()

  override def run(): Unit = {
    while (true) {
      try {
        gestor.oListo(id)
        Thread.sleep(r.nextInt(1000)) // espera para volver a entrar
      } catch {
        case e: InterruptedException => e.printStackTrace()
      }
    }
  }
}
