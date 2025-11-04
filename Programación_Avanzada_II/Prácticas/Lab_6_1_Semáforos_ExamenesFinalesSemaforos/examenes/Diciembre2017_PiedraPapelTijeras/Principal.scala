package examenes.Diciembre2017_PiedraPapelTijeras

object Principal {
  def main(args: Array[String]): Unit = {
    val mesa = new Mesa()

    val jugadores = Array.tabulate(3)(i => new Jugador(i, mesa))

    jugadores.foreach(_.start())
    jugadores.foreach(_.join())

    println("fin del programa")
  }
}
