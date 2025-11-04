package examenes.Junio2019_Tiovivo

class Operario(t: Tiovivo) extends Thread {

  override def run(): Unit = {
    try {
      while (true) {
        t.esperaLleno()
        Thread.sleep(500)
        t.finViaje()
      }
    } catch {
      case e: InterruptedException =>
        e.printStackTrace()
    }
  }
}
