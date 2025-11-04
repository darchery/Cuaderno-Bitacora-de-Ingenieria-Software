package examenes.Junio2018

import scala.util.Random

class Hidrogeno(id: Int, gestor: GestorAgua) extends Thread {

  private val r = new Random()

  override def run(): Unit = {
    while (true) {
      try {
        Thread.sleep(r.nextInt(1000)) // espera para entrar
        gestor.hListo(id)
      } catch {
        case e: InterruptedException => e.printStackTrace()
      }
    }
  }
}
