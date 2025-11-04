package examenes.Junio_2020_Barca_Capitan

object Principal {
  def main(args: Array[String]): Unit = {
    val b = new Barca()
    val p = new Capitan(b)
    val pas = Array.tabulate(18)(i => new Pasajero(i, if (i % 2 == 0) 0 else 1, b))

    p.start()
    pas.foreach(_.start())
  }
}
