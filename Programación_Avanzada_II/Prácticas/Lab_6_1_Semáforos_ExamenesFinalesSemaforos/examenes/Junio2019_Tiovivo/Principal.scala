package examenes.Junio2019_Tiovivo

object Principal {
  def main(args: Array[String]): Unit = {
    val t = new Tiovivo(5)
    val o = new Operario(t)
    val personas = Array.tabulate(7)(i => new Pasajero(i, t))

    personas.foreach(_.start())
    o.start()
  }
}
