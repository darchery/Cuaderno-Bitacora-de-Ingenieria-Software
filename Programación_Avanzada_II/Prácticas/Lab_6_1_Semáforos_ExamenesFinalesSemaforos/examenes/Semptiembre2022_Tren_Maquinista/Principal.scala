package examenes.Semptiembre2022_Tren_Maquinista

object Principal {
  def main(args: Array[String]): Unit = {
    val tren = new Tren()
    val m = new Maquinista(tren)
    val pas = Array.tabulate(20)(i => new Pasajero(tren, i))

    m.start()
    pas.foreach(_.start())
  }
}
