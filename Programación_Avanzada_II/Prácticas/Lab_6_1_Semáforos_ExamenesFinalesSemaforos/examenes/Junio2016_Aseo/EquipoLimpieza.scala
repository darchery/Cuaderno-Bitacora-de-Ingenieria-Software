package examenes.Junio2016_Aseo

import java.util.Random


object EquipoLimpieza {
  private val r = new Random
}

class EquipoLimpieza(private var aseo: Aseos) extends Thread {
  override def run(): Unit = {
    while (true) try {
      aseo.entraEquipoLimpieza()
      Thread.sleep(EquipoLimpieza.r.nextInt(1000))
      aseo.saleEquipoLimpieza()
    } catch {
      case e: InterruptedException =>

        // TODO Auto-generated catch block
        e.printStackTrace()
    }
  }
}
