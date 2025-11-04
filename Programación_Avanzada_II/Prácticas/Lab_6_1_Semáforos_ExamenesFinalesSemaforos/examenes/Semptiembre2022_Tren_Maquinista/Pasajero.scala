package examenes.Semptiembre2022_Tren_Maquinista

class Pasajero(tren: Tren, id: Int) extends Thread {

  override def run(): Unit = {
    while (true) {
      try {
        Thread.sleep(2000)
        tren.viaje(id)
        Thread.sleep(2000)
      } catch {
        case e: InterruptedException =>
          e.printStackTrace()
      }
    }
  }
}
