package examenes.Junio2022_Supermercado

import scala.util.Random

class Cliente(mkt: Supermercado, user: Int) extends Thread {
  private val r = new Random()

  override def run(): Unit = {
    for (_ <- 0 until 2) {
      try {
        Thread.sleep(r.nextInt(2000))
        mkt.nuevoCliente(user)
      } catch {
        case e: InterruptedException => e.printStackTrace()
      }
    }
  }
}
