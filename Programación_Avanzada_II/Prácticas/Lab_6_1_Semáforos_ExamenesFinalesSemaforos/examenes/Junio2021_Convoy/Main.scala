package examenes.Junio2021_Convoy

object Main {
  def main(args: Array[String]): Unit = {
    val NUM_FURGOS = 10
    val convoy = new Convoy(NUM_FURGOS)

    val flota = Array.tabulate(NUM_FURGOS)(i => new Furgoneta(i, convoy))

    flota.foreach(_.start())
  }
}
