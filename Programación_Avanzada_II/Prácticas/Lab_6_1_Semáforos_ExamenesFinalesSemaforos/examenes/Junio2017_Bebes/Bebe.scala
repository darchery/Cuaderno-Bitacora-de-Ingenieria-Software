package examenes.Junio2017_Bebes

import java.util.Random

class Bebe(private var g: Guarderia, private var id: Int) extends Thread {
  private val r = new Random

  override def run(): Unit = {
    while (true) try {
      Thread.sleep(r.nextInt(2000))
      g.entraBebe(id)
      Thread.sleep(r.nextInt(1000))
      g.saleBebe(id)
    } catch {
      case e: InterruptedException =>

        // TODO Auto-generated catch block
        e.printStackTrace()
    }
  }
}