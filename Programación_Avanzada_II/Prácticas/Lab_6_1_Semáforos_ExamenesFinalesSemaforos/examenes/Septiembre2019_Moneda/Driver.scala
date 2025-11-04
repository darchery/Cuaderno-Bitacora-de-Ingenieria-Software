package examenes.Septiembre2019_Moneda

object Driver {
  def main(args: Array[String]): Unit = {
    val c = new Concurso()
    val b0 = new Jugador(0, c)
    val b1 = new Jugador(1, c)
    b0.start()
    b1.start()
  }
}
