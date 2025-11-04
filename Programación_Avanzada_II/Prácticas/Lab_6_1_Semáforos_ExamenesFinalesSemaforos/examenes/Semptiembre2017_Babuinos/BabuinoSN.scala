package examenes.Semptiembre2017_Babuinos

import java.util._


object BabuinoSN {
  private val r = new Random
}

class BabuinoSN(private var id: Int, private var cuerda: Cuerda) extends Thread {
  override def run(): Unit = {
    try {
      cuerda.entraDireccionSN(id)
      Thread.sleep(BabuinoSN.r.nextInt(1000))
      cuerda.saleDireccionSN(id)
    } catch {
      case e: InterruptedException =>

        // TODO Auto-generated catch block
        e.printStackTrace()
    }
  }
}
