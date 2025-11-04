package examenes.Semptiembre2017_Babuinos

import java.util._


object BabuinoNS {
  private val r = new Random
}

class BabuinoNS(private var id: Int, private var cuerda: Cuerda) extends Thread {
  override def run(): Unit = {
    try {
      cuerda.entraDireccionNS(id)
      Thread.sleep(BabuinoNS.r.nextInt(1000))
      cuerda.saleDireccionNS(id)
    } catch {
      case e: InterruptedException =>

        // TODO Auto-generated catch block
        e.printStackTrace()
    }
  }
}