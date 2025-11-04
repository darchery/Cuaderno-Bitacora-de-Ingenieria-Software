package examenes.Junio2016_Aseo

import java.util.Random


object Cliente {
  private val r = new Random
}

class Cliente(private var id: Int, private var aseo: Aseos) extends Thread {
  override def run(): Unit = {
    while (true) try {
      Thread.sleep(Cliente.r.nextInt(3000))
      aseo.entroAseo(id)
      Thread.sleep(Cliente.r.nextInt(1000))
      aseo.salgoAseo(id)
      Thread.sleep(Cliente.r.nextInt(3000))
    } catch {
      case e: InterruptedException =>

        // TODO Auto-generated catch block
        e.printStackTrace()
    }
  }
}
